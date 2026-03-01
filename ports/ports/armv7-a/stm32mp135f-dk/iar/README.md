# MPX RTOS — Port STM32MP135F‑DK (Cortex‑A7) / IAR Embedded Workbench

## Contenu
Ce répertoire fournit un **pack d’en-têtes** (headers) correspondant au port ARMv7‑A / Cortex‑A7 (STM32MP135F‑DK) et aux **bindings IAR**.

- `include/mpx_rtos/` : en-têtes MPX RTOS (POSIX + extensions MPX)
  - `mpx_binding.h` : macros/attributs spécifiques IAR
  - `pthread.h`, `semaphore.h`, `signal.h`, `mqueue.h`, `sched.h`, `mpx_time.h` : API POSIX supportées
  - `mpx.h` : primitives MPX (queues, mémoire, timers, etc.)

## Intégration recommandée dans le dépôt
1. Ajouter ce dossier à l’arborescence du dépôt (ex: `ports/armv7-a/stm32mp135f-dk/iar/`).
2. Ajouter au include path IAR :
   - `ports/armv7-a/stm32mp135f-dk/iar/include`
3. Vérifier que le binding sélectionné est bien celui d’IAR (inclusion de `mpx_binding.h` via `mpx.h`).

## Notes
- Les APIs POSIX sont généralement exposées par **remapping** vers des symboles internes `mpx_*`.
- Les extensions MPX non standard restent dans le namespace `mpx_*` (ex: `mpx_semattr_*`, `mpx_mqattr_*`, `mpx_pthread_event_flags_*`).


## Notes réseau

Le header `<sys/socket.h>` est présent mais la pile réseau n'est pas intégrée dans ce pack. Des stubs `mpx_net.h` et `mpx_socket.h` sont fournis pour éviter des erreurs d'include ; l'implémentation reste à fournir via un composant réseau optionnel.
