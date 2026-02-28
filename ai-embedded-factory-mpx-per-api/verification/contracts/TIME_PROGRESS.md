# Time Domain Hardening — Step 3 (State Errors)

## What changed
Implemented `st_state_errors()` for time-domain contract tests using realistic invalid-state patterns:

- `clock_*`: invalid `clockid_t` (e.g., -1) with valid output storage
- `timer_*`: invalid `timer_t` handles and invalid `clockid_t` where applicable
- `nanosleep`: invalid `timespec` (tv_nsec = 1_000_000_000)

## Behavior while stubbed
- Each test still SKIPs when `errno == ENOSYS`.

## Next (Step 4)
- Low-setup success paths:
  - `clock_gettime`, `clock_getres` with valid pointers
  - `nanosleep` with zero duration
  - `time()` basic call
