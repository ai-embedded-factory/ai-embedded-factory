# Contract Matrices (Domain-Based)

This folder contains domain contract matrices used to harden tests.

- `CONTRACTS_PTHREAD.csv` (delimiter: `;`)

## Usage
1. Populate expected behaviors per API (param validation, state errors, success path).
2. Harden the corresponding contract tests in `tests/unit/contracts/pthread/`.
3. When hardened and passing against real code, mark the API requirement `APPROVED` in `requirements/TRACE_MATRIX.csv` and populate `code_ref`.

- `CONTRACTS_SYNC.csv` (delimiter: `;`)

- `CONTRACTS_TIME.csv` (delimiter: `;`)
