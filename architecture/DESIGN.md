# Design — MPX RTOS Clone (Baseline)

## DES-0001 Start Service
`mpx_pthread_start(run_time_id, memory_start, memory_size)` implemented per User Manual.

## DES-0002 API Compliance
- API signatures and constants follow the updated Reference Card.
- Behavioral semantics follow User Manual definitions when present.

## DES-0003 Context Rules
Per-API enforcement for callable context constraints.

## DES-0004 Error Handling
Return codes and errno conditions match the User Manual.

## DES-0005 Trace Gate
Trace matrix uses ';' delimiter; CI blocks APPROVED rows missing code/test links.
