# Verification & Validation Plan

## Objectives
- Prouver conformité aux exigences (REQ) + NFR.

## Verification Levels
- Unit
- Integration
- System (si applicable)
- Static analysis
- Coverage

## Entry/Exit Criteria (DoD)
- 100% des REQ "Approved" ont au moins 1 test mappé
- CI green (build+tests)
- Static analysis sans erreurs bloquantes
- Coverage >= seuil défini (COVERAGE_POLICY.md)
- Evidence pack généré