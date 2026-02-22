# Sync Domain Hardening — Step 1

## Deliverables
- `CONTRACTS_SYNC.csv` created (delimiter ';') with extracted errno/return-code notes where available.
- Contract tests under `tests/unit/contracts/sync/` normalized into subtests:
  - param_validation
  - state_errors
  - success_path
- Tests remain CI-safe while stubs are present (skip on ENOSYS).

## Next
- Step 2: implement param_validation negative-path checks using generic invalid calls.
- Step 3: implement state_errors patterns (invalid object state).
- Step 4: success-path hardening for low-setup APIs (init/destroy patterns).
