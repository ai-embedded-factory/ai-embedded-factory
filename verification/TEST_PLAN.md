# Verification Test Plan — MPX RTOS Clone (Baseline)

## 1. Objectives
- Provide evidence for a **1:1 behavioral clone** of MPX RTOS v1.0.0.
- Establish a repeatable, automated verification pipeline (CI-ready).
- Maintain end-to-end traceability: **REQ → TEST → EVIDENCE**.

## 2. Test Levels
### 2.1 Unit Tests
- API-level parameter validation and return-code behavior.
- Deterministic behavior checks for pure services.

### 2.2 Integration Tests
- Cross-API interactions (threads + mutex/cond/sem + time + cancellation).
- Multi-object lifecycle and resource behavior.

### 2.3 System/Behavioral Equivalence Tests
- Black-box equivalence against MPX RTOS reference (where feasible).
- Scenario-based: timing, preemption semantics, callable-context enforcement.

## 3. Evidence
- Test execution logs (CI artifacts)
- Trace matrix updates (`requirements/TRACE_MATRIX.csv`)
- For card-only APIs: additional equivalence evidence may be required.

## 4. Naming and IDs
- Requirements: `REQ-API-xxxx`
- Tests: `TST-API-xxxx` (unit/integration/system as appropriate)
- Evidence: CI job run + logs; optional `verification/evidence/`

## 5. Acceptance Criteria (Gate-ready)
- Any requirement moved to `APPROVED` MUST have:
  - `code_ref` populated
  - `test_id` populated
  - Passing tests in CI

