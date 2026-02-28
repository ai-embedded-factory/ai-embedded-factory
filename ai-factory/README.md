# AI Factory (Agents + Runner)

Provider-agnostic AI agent runner with default OpenAI Responses API provider.

## Install (WSL)
```bash
python3 -m venv .venv
source .venv/bin/activate
pip install -r ai-factory/requirements.txt
```

## Configure
- Set `OPENAI_API_KEY` in your environment (recommended).
- Edit `ai-factory/providers.yaml` to change default provider/model.

## Run (example)
```bash
./ai-factory/ai.sh --agent requirements --task "Add SRS requirement for mpx_pthread_start callable context" --branch step/req-001 --open-pr --pr-base master
```

## GitHub PR automation
The runner uses `gh pr create`. Ensure GitHub CLI is installed and authenticated:
```bash
sudo apt-get install -y gh
gh auth login
```
