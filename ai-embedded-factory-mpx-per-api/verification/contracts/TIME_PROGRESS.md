# Time Domain Hardening — Step 2 (Parameter Validation)

## What changed
- Implemented `st_param_validation()` for time-domain contract tests using invalid parameter patterns:
  - NULL pointers for output structures
  - invalid clock IDs / timer IDs where applicable
  - invalid scalar values (best-effort)

- Enriched `CONTRACTS_TIME.csv` with baseline expectations for parameter validation, state errors, and success path.

## Behavior while stubbed
- Phase 0 calls the API and **SKIPs** when `errno == ENOSYS`.

## Next (Step 3)
- Implement `st_state_errors()`:
  - invalid timer handles, disarmed timers
  - invalid clock IDs beyond parameter validation
- Start Step 4 success paths (clock_gettime, clock_getres, nanosleep 0).
