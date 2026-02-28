# AI Factory (Agents + Runner)

## Components
- `providers.yaml`: provider-agnostic configuration (default: OpenAI Responses API).
- `agents/*.yaml`: agent role definitions.
- `prompts/*.md`: prompt building blocks.
- `pipeline.sh`: orchestrator-driven pipeline runner (single PR).
- `ai.sh`: single-agent runner.

## Install (WSL)
```bash
python3 -m venv .venv
source .venv/bin/activate
pip install -r ai-factory/requirements.txt
sudo apt-get install -y gh
gh auth login
export OPENAI_API_KEY="..."
```

## Run a single agent (opens PR)
```bash
./ai-factory/ai.sh --agent requirements --task "Update SRS for mpx_pthread_start callable context" --branch step/req-001 --open-pr --pr-base master
```

## Run orchestrator pipeline (single PR)
```bash
./ai-factory/pipeline.sh --objective "Add contract tests for mq_* domain: scaffolding + param/state + success for low-setup APIs" --run
```

The pipeline creates a plan under `ai-factory/work/plan.json`, applies each step as commits on the plan branch, runs gates, and opens one PR.
