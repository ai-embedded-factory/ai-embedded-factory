import json, os, subprocess, time
from pathlib import Path
import yaml, requests
from jsonschema import validate

def sh(cmd, check=True, capture=False):
    if capture:
        return subprocess.run(cmd, check=check, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
    return subprocess.run(cmd, check=check)

def repo_root() -> Path:
    return Path(__file__).resolve().parents[2]

def af_root() -> Path:
    return repo_root() / "ai-factory"

def repo_state():
    out = {}
    out["branch"] = sh(["git","rev-parse","--abbrev-ref","HEAD"], capture=True).stdout.strip()
    out["head"] = sh(["git","rev-parse","HEAD"], capture=True).stdout.strip()
    out["status"] = sh(["git","status","--porcelain"], capture=True).stdout
    return out

def load_yaml(path: Path):
    with open(path, "r", encoding="utf-8") as f:
        return yaml.safe_load(f)

def load_providers():
    return load_yaml(af_root() / "providers.yaml")

def load_agent(agent_name: str):
    p = af_root() / "agents" / f"{agent_name}.yaml"
    if not p.exists():
        raise RuntimeError(f"Unknown agent: {agent_name}")
    return load_yaml(p)

def build_instructions(agent_name: str):
    parts = []
    for p in ["system_base.md","style_english.md","constraints_mpx.md","output_contract.md"]:
        parts.append((af_root()/"prompts"/p).read_text(encoding="utf-8"))
    parts.append(f"\nAgent role: {agent_name}\n")
    return "\n".join(parts)

def openai_responses_http(provider, instructions, user_input):
    api_key = os.getenv(provider.get("api_key_env","OPENAI_API_KEY"))
    if not api_key:
        raise RuntimeError(f"Missing API key env var: {provider.get('api_key_env','OPENAI_API_KEY')}")
    base_url = provider.get("base_url","https://api.openai.com/v1").rstrip("/")
    model = provider.get("model","gpt-5")
    timeout = provider.get("timeout_s", 120)
    url = f"{base_url}/responses"
    headers = {"Authorization": f"Bearer {api_key}", "Content-Type": "application/json"}
    payload = {"model": model, "instructions": instructions, "input": user_input}
    r = requests.post(url, headers=headers, json=payload, timeout=timeout)
    if r.status_code >= 400:
        raise RuntimeError(f"OpenAI API error {r.status_code}: {r.text[:1000]}")
    data = r.json()
    # 'output_text' may be absent in raw HTTP responses; aggregate from output[].
    text = data.get("output_text")
    if isinstance(text, str) and text.strip():
        return text, data

    parts = []
    for item in (data.get("output") or []):
        if not isinstance(item, dict):
            continue
        if item.get("type") == "message":
            for c in (item.get("content") or []):
                if isinstance(c, dict) and c.get("type") in ("output_text", "text") and isinstance(c.get("text"), str):
                    parts.append(c["text"])
        elif item.get("type") in ("output_text", "text") and isinstance(item.get("text"), str):
            parts.append(item["text"])
        else:
            for c in (item.get("content") or []):
                if isinstance(c, dict) and isinstance(c.get("text"), str):
                    parts.append(c["text"])

    return "\n".join([p for p in parts if p.strip()]), data

def dummy_echo(provider, instructions, user_input):
    return f"[DUMMY]\nINSTRUCTIONS:\n{instructions}\nINPUT:\n{user_input}\n", {"dummy": True}

def provider_call(provider_cfg, instructions, user_input):
    t = provider_cfg.get("type")
    if t == "openai_responses_http":
        return openai_responses_http(provider_cfg, instructions, user_input)
    if t == "dummy_echo":
        return dummy_echo(provider_cfg, instructions, user_input)
    raise RuntimeError(f"Unknown provider type: {t}")

def parse_agent_response(text: str):
    import re
    def extract(lang):
        m = re.search(r"```" + re.escape(lang) + r"\s+([\s\S]*?)```", text)
        return m.group(1).strip() if m else None
    diff = extract("diff")  # optional
    js = extract("json")
    if not js:
        raise RuntimeError("Agent response missing ```json``` block.")
    agent_output = json.loads(js)
    schema_path = af_root() / "schemas" / "agent_output.schema.json"
    schema = json.loads(schema_path.read_text(encoding="utf-8"))
    validate(instance=agent_output, schema=schema)
    return diff, agent_output

def apply_diff(diff_text: str):
    if not diff_text:
        return
    work = af_root() / "work"
    work.mkdir(parents=True, exist_ok=True)
    patch = work / "last.patch"
    patch.write_text(diff_text, encoding="utf-8")
    sh(["git","apply", str(patch)])

def run_gates():
    ROOT = repo_root()
    gates = []
    trace = ROOT / "tools" / "trace" / "trace_check.py"
    if trace.exists():
        r = sh(["python3", str(trace), "requirements/TRACE_MATRIX.csv"], check=False)
        gates.append({"gate":"trace_check","status":"pass" if r.returncode==0 else "fail"})
    if (ROOT/"CMakeLists.txt").exists():
        sh(["cmake","-S",".","-B","build","-G","Ninja","-DCMAKE_BUILD_TYPE=Debug"], check=False)
        sh(["cmake","--build","build"], check=False)
        r = sh(["ctest","--test-dir","build","--output-on-failure"], check=False)
        gates.append({"gate":"ctest","status":"pass" if r.returncode==0 else "fail"})
    return gates

def log_write(agent: str, content: str, suffix: str):
    logdir = af_root() / "logs"
    logdir.mkdir(parents=True, exist_ok=True)
    ts = time.strftime("%Y%m%d-%H%M%S")
    p = logdir / f"{ts}-{agent}{suffix}"
    p.write_text(content, encoding="utf-8")
    return p

def ensure_gh():
    r = sh(["gh","--version"], check=False, capture=True)
    if r.returncode != 0:
        raise RuntimeError("GitHub CLI 'gh' not found. Install in WSL: sudo apt-get install -y gh")
    sh(["gh","auth","status"], check=False)

def pr_create(base_branch, head_branch, title, body):
    ensure_gh()
    cmd = ["gh","pr","create","--base",base_branch,"--head",head_branch,"--title",title,"--body",body]
    return sh(cmd, check=True, capture=True).stdout.strip()
