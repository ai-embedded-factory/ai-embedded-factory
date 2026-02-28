# AI Factory Bootstrap

This drop-in adds:
- ai-factory/providers.yaml (provider-agnostic; default OpenAI)
- agent definitions (YAML)
- runner that:
  - calls a provider (OpenAI Responses API by default)
  - expects a patch + agent_output.json
  - applies patch, runs gates, commits
  - optionally opens a PR via GitHub CLI

Security:
- Never commit API keys. Use env var OPENAI_API_KEY.
