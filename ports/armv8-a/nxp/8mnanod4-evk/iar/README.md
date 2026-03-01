# MPX RTOS — Port IAR — NXP 8MNANOD4-EVK (Cortex-A53)

Ce répertoire contient les en-têtes de binding (IAR) et les stubs POSIX/pthreads associés au portage **ARMv8-A (AArch64)** pour la carte **NXP i.MX 8M Nano EVK (8MNANOD4-EVK)**.

## Périmètre

- **CPU** : Cortex-A53 (ARMv8-A, AArch64)
- **Outillage** : IAR Embedded Workbench for ARM (AArch64)
- **SMP** : pris en compte au niveau du binding (ID cœur via `MPIDR_EL1`, masque d'affinité, utilitaires CPU).
- **Réseau** : non inclus (des stubs `mpx_net.h` / `mpx_socket.h` sont fournis uniquement pour satisfaire les includes de `<sys/socket.h>`).

## Dépendances outillage IAR

Le fichier `intrinsics.h` est fourni par IAR (installation EWARM) et est inclus via :

```c
#include <intrinsics.h>
```

> **Note licensing** : `intrinsics.h` est un composant IAR ; il n'est pas versionné ici.

## Intégration (IAR)

1. Ajouter ce répertoire à l'include path du projet IAR :
   - `ports/armv8-a/nxp/8mnanod4-evk/iar/include`
2. Vérifier que l'include path IAR standard contient bien les headers runtime (dont `intrinsics.h`).
3. Définir/valider les macros de configuration MPX dans `mpx_user_config.h` (pile, IRQ stack, alignement, etc.).
4. Côté BSP (hors de ce pack), fournir :
   - Initialisation horloge/timer
   - Init IRQ (GIC)
   - Gestion cache/MMU selon la stratégie MPX
   - Bootstrap SMP (si activé)

## Notes SMP / Affinité

Le binding propose :
- `MPX_BINDING_SMP_MAX_CORES` (par défaut 4)
- `mpx_binding_get_core_id()` / `mpx_binding_get_core_affinity_mask()`
- `mpx_binding_set_core_affinity_mask(uint32_t mask)` (extension affinité)

Ces éléments sont utilisés par le scheduler MPX pour l'assignation/affinité des threads (extensions non-POSIX).
