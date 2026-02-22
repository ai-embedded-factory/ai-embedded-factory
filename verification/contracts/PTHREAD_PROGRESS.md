# Pthread Domain Hardening — Step 3

## Changes
- Implemented `st_state_errors()` in pthread-domain contract tests using a distinct invalid-state call pattern.
- Kept `st_success_path()` as a non-blocking placeholder (requires valid setup + real implementation).
- Refreshed expectations in `CONTRACTS_PTHREAD.csv`.

## Next
- Select low-setup APIs for real success-path assertions (e.g., `pthread_self`, `sched_yield`).
- Replace generic calls with spec-driven cases and exact errno mapping once implementation is linked.
