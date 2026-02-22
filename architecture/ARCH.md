# Architecture — MPX RTOS Clone (Per-API Baseline)

## ARCH-0001 Boot/Start
- Implements `mpx_pthread_start()` per User Manual.

## ARCH-0002 API Surface & Services
- Implements full API surface listed in updated Reference Card.
- For APIs defined in User Manual Chapter 7, semantics are normative.

## ARCH-0005 Traceability & Evidence
- `requirements/TRACE_MATRIX.csv` (';') is the trace backbone.
- CI enforces trace gate for APPROVED rows.
