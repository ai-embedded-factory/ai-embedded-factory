# Design — MPX RTOS Clone (Per-API Baseline)

## DES-0001 Start Service
- `mpx_pthread_start(run_time_id, memory_start, memory_size)` start flow per User Manual.

## DES-0002 API Compliance
- API signatures follow updated Reference Card.
- Semantics follow User Manual (when defined) and MPX behavior otherwise.

## DES-0005 Trace Gate
- APPROVED trace rows must include code_ref and test_id.
