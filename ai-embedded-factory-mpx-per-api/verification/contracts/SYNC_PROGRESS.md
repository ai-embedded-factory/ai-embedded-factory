# Sync Domain Hardening — Step 5 (Real Lifecycle Scenarios)

## What changed
- Replaced generic invalid-pointer lifecycle checks with **real lifecycle scenarios** where feasible:
  - Semaphores: double-destroy; use-after-destroy (post/wait/trywait)
  - Mutexes: destroy-while-locked; use-after-destroy (lock/trylock/unlock)
  - Condition variables: double-destroy; use-after-destroy (signal/broadcast) when available
- Updated `CONTRACTS_SYNC.csv` notes to reflect the lifecycle test matrix.

## Behavior while stubbed
- Tests still SKIP when `errno == ENOSYS` (Phase 0).

## Next
- Tighten exact errno/error-code mapping per API using the User Manual (replace set-membership with exact expectations).
- Add multi-thread scenarios (e.g., `sem_destroy` with waiters) once a minimal thread runner exists.
