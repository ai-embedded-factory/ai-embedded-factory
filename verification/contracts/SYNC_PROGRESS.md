# Sync Domain Hardening — Step 3 (State/Lifecycle Errors)

## What changed
- Implemented `st_state_errors()` for sync-domain contract tests using invalid-state patterns:
  - non-NULL invalid pointers (e.g., `(void*)1`)
  - invalid scalar values
- `errno` expectations are checked when symbols are available in the contract matrix.

## Notes
- This is a best-effort negative-path harness. Exact lifecycle scenarios (destroyed/busy objects)
  will be encoded once real object setup exists (Step 4/5).

## Next (Step 4)
- Implement low-setup success paths:
  - init/destroy pairs
  - trylock where available
  - basic semaphore post/wait when init is available
