# AI Factory Bootstrap (Orchestrator + Agents)

This drop-in adds:
- Provider-agnostic access (`ai-factory/providers.yaml`), default OpenAI.
- Agent role definitions.
- Single-agent runner (`ai-factory/ai.sh`) with optional PR creation.
- Orchestrator-driven pipeline runner (`ai-factory/pipeline.sh`) that:
  - asks the orchestrator to generate a plan
  - executes steps as commits on a dedicated branch
  - opens a single PR at the end

Security:
- Never commit API keys. Use env var OPENAI_API_KEY.
