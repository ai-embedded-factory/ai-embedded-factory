# MPX Docs Alignment Report (revB)

## Objet

Ce rapport consolide les écarts et points d’alignement entre :
- **MPX-User-Manual-V1-0-0.docx** (manuel utilisateur)
- **MPX-RTOS-pthreads-card.rtf** (carte API pthreads)
- Les en-têtes de portage IAR disponibles pour :
  - **STM32MP135F-DK (Cortex-A7 / ARMv7-A)**
  - **8MNANOD4-EVK (Cortex-A53 / ARMv8-A AArch64)**

## Synthèse des apports (Cortex-A53 / 8MNANOD4-EVK)

### 1) Ajout du port ARMv8-A (AArch64)

Ajout d’un nouveau squelette de portage IAR :
- `ports/armv8-a/nxp/8mnanod4-evk/iar/include/mpx_rtos/…`
- `ports/armv8-a/nxp/8mnanod4-evk/iar/README.md`

Ce port apporte un **binding SMP** (lecture `MPIDR_EL1`, masques d’affinité, utilitaires CPU) adapté à une cible multi-cœurs.

### 2) Dépendance IAR — `intrinsics.h`

Le pack A53 fourni contenait `intrinsics.h` (composant IAR). Par souci de conformité licensing, le dépôt **ne versionne pas** ce header.
- Le binding A53 inclut désormais : `#include <intrinsics.h>`
- Pré-requis : EWARM installé et include path runtime IAR présent dans le projet.

### 3) Configuration Time remapping

Le port A53 expose la macro :
- `MPX_DISABLE_TIME_REMAPPING`

Le manuel référençait :
- `MPX_TIME_REMAPPING_DISABLE`

Action :
- Mise à jour du manuel pour référencer **la macro A53** et préciser l’alias/compatibilité (`MPX_TIME_REMAPPING_DISABLE`).

### 4) Errno : valeurs numériques dépendantes du port

Les codes `E*` sont exposés via `mpx_errno.h`. Les valeurs numériques **peuvent varier selon le port/outillage** (ex : mapping compact vs mapping "POSIX/Linux-like").
Action :
- Ajout d’une note dans le manuel : **ne pas supposer les valeurs numériques**, utiliser les symboles `E*`.

### 5) Header réseau : assainissement des includes

Sur certaines branches, `<sys/socket.h>` référençait des headers non présents (`mpx_net.h`, `mpx_socket.h`).
Action :
- Ajout de stubs `mpx_net.h` et `mpx_socket.h` (A7 et A53) pour supprimer les erreurs d’include.
- Clarification README : la pile réseau n’est pas dans le périmètre "pthreads/POSIX core".

## Points à confirmer côté BSP (hors scope)

Pour finaliser un port Cortex-A53 production-grade :
- Init timer/clock, IRQ/GIC, caches/MMU
- Séquence de boot SMP et politique d’affinité
- Stratégie de mémoire (cohérence, barrières, sections linker)

Ces éléments relèvent du BSP/port kernel bas niveau et ne sont pas couverts par les en-têtes fournis.
