#!/usr/bin/env python3
import argparse, json
from ai_factory.runner.util import (
    sh, repo_state, load_providers, load_agent, build_instructions,
    provider_call, parse_agent_response, apply_diff, run_gates, log_write, pr_create
)

PLAN_SCHEMA = {
  "type":"object",
  "required":["branch","pr_base","pr_title","pr_body","steps"],
  "properties":{
    "branch":{"type":"string"},
    "pr_base":{"type":"string"},
    "pr_title":{"type":"string"},
    "pr_body":{"type":"string"},
    "steps":{"type":"array","items":{
      "type":"object",
      "required":["agent","task"],
      "properties":{"agent":{"type":"string"},"task":{"type":"string"}}
    }}
  }
}

def validate_plan(plan):
    # Minimal validation without external deps
    for k in ["branch","pr_base","pr_title","pr_body","steps"]:
        if k not in plan:
            raise RuntimeError(f"Plan missing '{k}'")
    if not isinstance(plan["steps"], list) or len(plan["steps"]) == 0:
        raise RuntimeError("Plan steps must be a non-empty list")

def call_agent(agent_name: str, task: str, provider_cfg):
    agent_cfg = load_agent(agent_name)
    instructions = build_instructions(agent_name)
    payload = {
        "repo_state": repo_state(),
        "task_spec": task,
        "constraints": {"language": "English", "csv_delimiter": ";", "mpx_clone": True},
        "agent_config": agent_cfg
    }
    out_text, _raw = provider_call(provider_cfg, instructions, json.dumps(payload, indent=2))
    log_write(agent_name, out_text, ".txt")
    diff_text, agent_out = parse_agent_response(out_text)
    apply_diff(diff_text)
    gates = run_gates()
    agent_out["verification"] = gates
    log_write(agent_name, json.dumps(agent_out, indent=2), "-agent_output.json")
    sh(["git","add","-A"])
    msg = f"AI: {agent_name} — {task[:60]}"
    sh(["git","commit","-m", msg], check=False)

def orchestrate(objective: str, provider_cfg):
    # Orchestrator is expected to include a 'plan' object inside agent_output JSON.
    agent_name = "orchestrator"
    agent_cfg = load_agent(agent_name)
    instructions = build_instructions(agent_name)
    payload = {
        "repo_state": repo_state(),
        "objective": objective,
        "constraints": {"language": "English", "csv_delimiter": ";", "mpx_clone": True},
        "agent_config": agent_cfg,
        "plan_format": {
          "branch":"step/<slug>",
          "pr_base":"master",
          "pr_title":"<title>",
          "pr_body":"<body>",
          "steps":[{"agent":"requirements","task":"..."},{"agent":"architecture","task":"..."},{"agent":"test_vnv","task":"..."},{"agent":"quality","task":"Review changes"}]
        }
    }
    out_text, _raw = provider_call(provider_cfg, instructions, json.dumps(payload, indent=2))
    log_write(agent_name, out_text, ".txt")
    _diff_text, agent_out = parse_agent_response(out_text)
    plan = agent_out.get("plan")
    if not plan:
        raise RuntimeError("Orchestrator output missing 'plan' object in agent_output.json")
    validate_plan(plan)
    # persist plan
    work = (sh(["python3","-c","import pathlib;print((pathlib.Path('ai-factory')/'work').as_posix())"], capture=True).stdout.strip())
    # simpler: write to ai-factory/work/plan.json
    from pathlib import Path
    outp = Path("ai-factory")/"work"
    outp.mkdir(parents=True, exist_ok=True)
    (outp/"plan.json").write_text(json.dumps(plan, indent=2), encoding="utf-8")
    return plan

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--provider", default=None)
    ap.add_argument("--objective", required=True, help="High-level objective for the orchestrator")
    ap.add_argument("--run", action="store_true", help="Execute the plan after generating it")
    args = ap.parse_args()

    provs = load_providers()
    provider_name = args.provider or provs.get("default_provider","openai")
    provider_cfg = provs["providers"][provider_name]

    plan = orchestrate(args.objective, provider_cfg)
    # checkout plan branch
    sh(["git","checkout","-B", plan["branch"]])

    if args.run:
        for step in plan["steps"]:
            call_agent(step["agent"], step["task"], provider_cfg)
        head = sh(["git","rev-parse","--abbrev-ref","HEAD"], capture=True).stdout.strip()
        url = pr_create(plan["pr_base"], head, plan["pr_title"], plan["pr_body"])
        print(url)
    else:
        print(json.dumps(plan, indent=2))

if __name__ == "__main__":
    main()
