# Contract Testing Approach

## Goal
Evolve from smoke tests (plumbing) to contract tests (behavior) per API.

## Current State
- Contract test skeletons are generated for APIs that have **normative definitions** in the User Manual.
- While the implementation is stubbed, tests **skip** when `errno == ENOSYS`.

## Next Step
For each API:
1. Replace the stub with real implementation (or link to real code).
2. Replace the placeholder assertions with:
   - parameter validation checks
   - state transition checks
   - success path checks
   - exact errno mapping
3. Once the contract test passes, update:
   - `requirements/TRACE_MATRIX.csv` row for the API: set `verify_status=APPROVED` and populate `code_ref`
   - keep `test_id` pointing to the contract test used for evidence.
