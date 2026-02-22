# Software Requirements Specification (SRS) — MPX RTOS Clone (v1.0.0 baseline)

## 1. Scope
This specification defines a **1:1 behavioral clone** of MPX RTOS v1.0.0 using the provided documents as normative sources:
- MPX-RTOS-pthreads-card.rtf (updated) — normative API surface
- MPX-User-Manual-V1-0-0.docx — normative semantics (Chapter 7)

## 2. Conformance Rules
- For any API defined in the User Manual, that definition is normative.
- All APIs listed in the updated Reference Card SHALL be implemented.
- For APIs only present in the Reference Card, behavior SHALL match MPX RTOS; V&V may require additional evidence.

## 3. System Requirements
### REQ-SYS-0001 — System start (`mpx_pthread_start`)
The implementation SHALL provide `mpx_pthread_start()` and SHALL follow the User Manual start flow semantics.

### REQ-SYS-0002 — Complete API surface
The implementation SHALL expose the complete API surface listed in the updated Reference Card.

### REQ-SYS-0003 — Callable context constraints
For each API defined in the User Manual, callable-context constraints SHALL be enforced as documented.

### REQ-SYS-0004 — Real-time scenario semantics
For each API defined in the User Manual, real-time scenario semantics (preemption statements) SHALL be matched.

### REQ-SYS-0005 — Return codes and errno
For each API defined in the User Manual, return codes and `errno` behavior SHALL match the documented conditions.

### REQ-SYS-0006 — Traceability
Traceability SHALL be maintained in `requirements/TRACE_MATRIX.csv` (semicolon-separated) and enforced by CI.

## 4. API Catalog
The normative catalog is in `requirements/API_CATALOG.md`.
