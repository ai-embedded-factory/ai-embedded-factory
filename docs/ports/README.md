# Ports

See: `docs/ports/iar/`

This directory documents MPX RTOS ports and toolchains. IAR-specific artifacts and alignment reports are under `docs/ports/iar/`.

<!-- MPX_IAR_PORTS_START -->
## IAR Embedded Workbench (ports & assets)

This section groups **MPX RTOS porting artifacts** for **IAR Embedded Workbench**, along with the alignment documents used to consolidate the API spec (User Manual ↔ API Card ↔ implementation/ports).

### Layout

- `docs/ports/iar/common/revA/`: shared documents (pthreads API card + alignment report) — revA
- `docs/ports/iar/common/revB/`: shared documents — revB
- `docs/ports/iar/stm32mp135f-dk/revA/`: user manual targeting **STM32MP135F-DK (Cortex-A7)** — revA
- `docs/ports/iar/stm32mp135f-dk_8mnanod4-evk/revB/`: user manual targeting **STM32MP135F-DK + 8MNANOD4-EVK (Cortex-A53)** — revB

### Port sources (code)

- `ports/armv7-a/stm32mp135f-dk/`: **Cortex-A7** port
- `ports/armv8-a/nxp/`: **Cortex-A53 (NXP)** port

### Conventions

- Binary artifacts (`*.docx`, `*.rtf`, `*.zip`) are versioned via **Git LFS** (see `.gitattributes`).
- Revisions are isolated under `revX/` to preserve history and ease comparisons.
<!-- MPX_IAR_PORTS_END -->

