#!/usr/bin/env python3
import argparse, json, os, subprocess, time
from pathlib import Path
import yaml
import requests
from jsonschema import validate

ROOT = Path(__file__).resolve().parents[2]
AF = ROOT / "ai-factory"
SCHEMA_PATH = AF / "schemas" / "agent_output.schema.json"

def sh(cmd, check=True, capture=False):
    if capture:
        return subprocess.run(cmd, check=check, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
    return subprocess.run(cmd, check=check)

def repo_state():
    out = {}
    out["branch"] = sh(["git","rev-parse","--abbrev-ref","HEAD"], capture=True).stdout.strip()
    out["head"] = sh(["git","rev-parse","HEAD"], capture=True).stdout.strip()
    out["status"] = sh(["git","status","--porcelain"], capture=True).stdout
    return out

def load_providers():
    with open(AF / "providers.yaml", "r", encoding="utf-8") as f:
        return yaml.safe_load(f)

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
    return (data.get("output_text") or ""), data

def dummy_echo(provider, instructions, user_input):
    return f"[DUMMY]\\nINSTRUCTIONS:\\n{instructions}\\nINPUT:\\n{user_input}\\n", {"dummy": True}

def provider_call(provider_cfg, instructions, user_input):
    t = provider_cfg.get("type")
    if t == "openai_responses_http":
        return openai_responses_http(provider_cfg, instructions, user_input)
    if t == "dummy_echo":
        return dummy_echo(provider_cfg, instructions, user_input)
    raise RuntimeError(f"Unknown provider type: {t}")

def build_instructions(agent_name):
    parts = []
    for p in ["system_base.md","style_english.md","constraints_mpx.md","output_contract.md"]:
        parts.append((AF/"prompts"/p).read_text(encoding="utf-8"))
    parts.append(f"\\nAgent role: {agent_name}\\n")
    return "\\n".join(parts)

def load_agent(agent_name):
    p = AF / "agents" / f"{agent_name}.yaml"
    if not p.exists():
        raise RuntimeError(f"Unknown agent: {agent_name}")
    with open(p, "r", encoding="utf-8") as f:
        return yaml.safe_load(f)

def parse_agent_response(text):
    import re
    def extract(lang):
        m = re.search(r"```" + re.escape(lang) + r"\\s+([\\s\\S]*?)```", text)
        return m.group(1).strip() if m else None
    diff = extract("diff")
    js = extract("json")
    if not js:
        raise RuntimeError("Agent response missing ```json``` block.")
    agent_output = json.loads(js)
    schema = json.loads(SCHEMA_PATH.read_text(encoding="utf-8"))
    validate(instance=agent_output, schema=schema)
    return diff, agent_output

def apply_diff(diff_text):
    if not diff_text:
        return
    p = AF / "work" / "last.patch"
    p.parent.mkdir(parents=True, exist_ok=True)
    p.write_text(diff_text, encoding="utf-8")
    sh(["git","apply", str(p)])

def run_gates():
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

def ensure_gh():
    r = sh(["gh","--version"], check=False, capture=True)
    if r.returncode != 0:
        raise RuntimeError("GitHub CLI 'gh' not found. Install in WSL: sudo apt-get install -y gh")
    sh(["gh","auth","status"], check=False)

def pr_create(base_branch, head_branch, title, body):
    ensure_gh()
    cmd = ["gh","pr","create","--base",base_branch,"--head",head_branch,"--title",title,"--body",body]
    return sh(cmd, check=True, capture=True).stdout.strip()

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--provider", default=None)
    ap.add_argument("--agent", required=True)
    ap.add_argument("--task", required=True)
    ap.add_argument("--branch", default=None)
    ap.add_argument("--open-pr", action="store_true")
    ap.add_argument("--pr-base", default="master")
    ap.add_argument("--pr-title", default=None)
    ap.add_argument("--pr-body", default=None)
    args = ap.parse_args()

    provs = load_providers()
    provider_name = args.provider or provs.get("default_provider","openai")
    provider_cfg = provs["providers"][provider_name]

    if args.branch:
        sh(["git","checkout","-B", args.branch])

    agent_cfg = load_agent(args.agent)
    instructions = build_instructions(args.agent)
    payload = {
        "repo_state": repo_state(),
        "task_spec": args.task,
        "constraints": {"language": "English", "csv_delimiter": ";", "mpx_clone": True},
        "agent_config": agent_cfg
    }
    user_input = json.dumps(payload, indent=2)

    out_text, _raw = provider_call(provider_cfg, instructions, user_input)

    logdir = AF / "logs"
    logdir.mkdir(parents=True, exist_ok=True)
    ts = time.strftime("%Y%m%d-%H%M%S")
    (logdir / f"{ts}-{args.agent}.txt").write_text(out_text, encoding="utf-8")

    diff_text, agent_out = parse_agent_response(out_text)
    apply_diff(diff_text)

    gates = run_gates()
    agent_out["verification"] = gates
    (logdir / f"{ts}-{args.agent}-agent_output.json").write_text(json.dumps(agent_out, indent=2), encoding="utf-8")

    sh(["git","add","-A"])
    msg = f"AI: {args.agent} — {args.task[:60]}"
    sh(["git","commit","-m", msg], check=False)

    if args.open_pr:
        head = sh(["git","rev-parse","--abbrev-ref","HEAD"], capture=True).stdout.strip()
        title = args.pr_title or msg
        body = args.pr_body or (f"Automated PR opened by ai-factory runner.\\n\\nTask:\\n{args.task}\\n")
        url = pr_create(args.pr_base, head, title, body)
        print(url)

if __name__ == "__main__":
    main()
