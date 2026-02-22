# MPX RTOS Clone — Per-API SRS & Trace Baseline

This repository contains an **English** per-API SRS baseline for a **1:1 behavioral clone** of MPX RTOS v1.0.0.

## Artifacts
- `requirements/SRS.md` — per-API requirements (REQ-API-xxxx)
- `requirements/TRACE_MATRIX.csv` — trace backbone (delimiter: `;`)
- `tools/trace/trace_check.py` — CI trace gate

## Notes
- For APIs defined in the User Manual, semantics are normative.
- For APIs only present in the Reference Card, surface is normative; behavior must match MPX.

## Verification
- `verification/TEST_PLAN.md`
- `verification/TEST_SPEC.csv` (delimiter: ';')
