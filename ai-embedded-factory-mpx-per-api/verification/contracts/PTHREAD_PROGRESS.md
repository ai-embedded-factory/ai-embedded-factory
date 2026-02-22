# Pthread Domain Hardening — Step 4

## Changes
- Implemented **success path assertions** for low-setup APIs:
  - `sched_yield`
  - `pthread_self`
  - `pthread_equal` (if present)
- Kept other APIs with success-path placeholders (requires object setup).

## Notes
- `pthread_self` success check uses stable value across two calls within the same thread context.
- These checks are designed to remain CI-safe while stubs are present (tests skip on ENOSYS in Phase 0).

## Next
- Start Sync domain hardening (mutex/cond/sem) using the same matrix-driven approach.
