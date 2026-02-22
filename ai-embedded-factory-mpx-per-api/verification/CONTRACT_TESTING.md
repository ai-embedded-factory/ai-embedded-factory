# Contract Testing Approach (Domain-Based)

## Domain Order
1. Threads & Scheduling (pthread / mpx_pthread / sched)
2. Synchronization (mutex/cond/sem)
3. Time Services (clock/timer/sleep)
4. Message Queues (mq)
5. Other APIs

## Current State
- Domain contract scaffolds are generated under `tests/unit/contracts/<domain>/`.
- While the implementation is stubbed, tests **SKIP** when `errno == ENOSYS`.

## Hardening Checklist (per API)
1. Parameter validation: invalid args → expected return + `errno`
2. State machine errors: invalid lifecycle/state → expected return + `errno`
3. Success path: expected return + `errno` unchanged/expected
4. Side-effects: object state changes consistent with MPX
5. Evidence: CI logs + trace update

## Traceability Rule
Only when a contract test is hardened and passing against real code:
- Set the API row in `requirements/TRACE_MATRIX.csv` to `APPROVED`
- Populate `code_ref` and choose the evidence `test_id` (prefer the contract test)
