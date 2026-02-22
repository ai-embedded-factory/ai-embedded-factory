# Time Domain Hardening — Step 1 (Scaffolding)

## Scope
Time-related APIs:
- `clock_*`
- `timer_*`
- `nanosleep`, `sleep`, `usleep`, `time`

## Deliverables
- `verification/contracts/CONTRACTS_TIME.csv` (delimiter: `;`)
- Contract test scaffolds in `tests/unit/contracts/time/`

## Next
- Step 2: parameter validation (NULL pointers, invalid clock IDs, invalid timespec).
- Step 3: state errors (invalid timer handles, disarmed timers).
- Step 4: low-setup success paths (clock_gettime, nanosleep with 0, etc.).
