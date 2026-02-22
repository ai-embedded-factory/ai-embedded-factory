# Architecture — MPX RTOS Clone (Baseline)

## ARCH-0001 Boot/Start
Implements `mpx_pthread_start()` flow per User Manual (init, binding verification, `main` upscaling).

## ARCH-0002 API Layer
Implements all APIs listed in the **updated** Reference Card, with normative semantics from the User Manual where available.

## ARCH-0003 Context & RT Semantics
Enforces callable context and real-time scenario (preemption) semantics.

## ARCH-0004 Error / errno Model
Centralized mapping to documented errno conditions.

## ARCH-0005 Traceability & Evidence
Semicolon-separated trace matrix with CI gate.
