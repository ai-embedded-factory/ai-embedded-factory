# Sync Domain Hardening — Step 2 (Parameter Validation)

## What changed
- Implemented `st_param_validation()` for sync-domain contract tests using invalid pointer/object patterns.
- Enriched `CONTRACTS_SYNC.csv` with baseline expectations for:
  - parameter validation
  - state errors
  - success path

## Test behavior while stubbed
- Phase 0 performs a call and **SKIPs** if `errno == ENOSYS`.
- Contract subtests run only when real implementation is linked.

## Next (Step 3)
- Implement `st_state_errors()`:
  - destroyed/uninitialized objects
  - busy objects (e.g., sem_destroy with waiting threads)
- Start low-setup success paths where feasible (init/destroy, trylock).
