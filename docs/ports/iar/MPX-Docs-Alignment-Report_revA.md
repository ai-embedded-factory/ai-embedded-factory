# MPX — Rapport d’alignement documentation vs headers de portage (revA)

## Sources utilisées
- `MPX-User-Manual-V1-0-0.docx`
- `MPX-RTOS-pthreads-card.rtf`
- Pack headers: port STM32MP135F‑DK (Cortex‑A7) / IAR (dossier `ports/armv7-a/stm32mp135f-dk/iar/include/mpx_rtos/`)

## Corrections appliquées (documentation)
### Manuel utilisateur
- Normalisation des symboles **extensions MPX** :
  - `pthread_attr_getcontroladdr` → `mpx_pthread_attr_getcontroladdr`
  - `pthread_attr_setcontroladdr` → `mpx_pthread_attr_setcontroladdr`
  - `pthread_ticks_get` → `mpx_pthread_ticks_get`
- Ajout d’une **annexe de portage** (STM32MP135F‑DK / IAR) : périmètre + arborescence recommandée + conventions de namespace.

### Pthreads card
- Regénération d’une carte **alignée sur les headers de portage** :
  - ajout explicite des API d’affinité `pthread_getaffinity_np()` / `pthread_setaffinity_np()`
  - inclusion des signatures POSIX supportées (pthreads/sem/signal/mqueue/time/sched) + extensions `mpx_*`
  - mise en forme monospacée pour les prototypes.

## Modifications appliquées (pack headers)
- `mpx_binding.h` : correction de libellé (commentaire/identifiant) **Cortex‑A9 → Cortex‑A7** (sans impact ABI).

## Points à valider côté dépôt
- Chemin d’inclusion IAR (include path) et ordre d’inclusion par rapport aux headers génériques.
- Si vous disposez de sources complémentaires (startup, scripts, projets IAR, linker scripts), fournir idéalement un export `.zip` (les archives `.rar` ne sont pas traitées automatiquement dans ce packaging).
