#!/usr/bin/env python3
import argparse, json
from ai_factory.runner.util import (
    sh, repo_state, load_providers, load_agent, build_instructions,
    provider_call, parse_agent_response, apply_diff, run_gates, log_write, pr_create
)

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
    log_write(args.agent, out_text, ".txt")

    diff_text, agent_out = parse_agent_response(out_text)
    apply_diff(diff_text)

    gates = run_gates()
    agent_out["verification"] = gates
    log_write(args.agent, json.dumps(agent_out, indent=2), "-agent_output.json")

    sh(["git","add","-A"])
    msg = f"AI: {args.agent} — {args.task[:60]}"
    sh(["git","commit","-m", msg], check=False)

    if args.open_pr:
        head = sh(["git","rev-parse","--abbrev-ref","HEAD"], capture=True).stdout.strip()
        title = args.pr_title or msg
        body = args.pr_body or (f"Automated PR opened by ai-factory runner.\n\nTask:\n{args.task}\n")
        url = pr_create(args.pr_base, head, title, body)
        print(url)

if __name__ == "__main__":
    main()
