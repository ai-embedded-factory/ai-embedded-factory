# Engineering Policy (Baseline)

## Language
All documents and artifacts are in **English**.

## CSV Format
All CSV files MUST use semicolon (`;`) as delimiter.

## Traceability Gate
- If a row in `TRACE_MATRIX.csv` is marked `APPROVED`, it MUST include:
  - `code_ref`
  - `test_id`
- Otherwise CI fails.

## Conformance Target
1:1 behavior clone of MPX RTOS v1.0.0 (per provided documents).
