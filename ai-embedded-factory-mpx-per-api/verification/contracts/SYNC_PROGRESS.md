# Sync Domain Hardening — Step 4 (Low-Setup Success Paths)

## What changed
- Implemented **success path** assertions for low-setup sync APIs where a minimal setup is feasible:
  - Semaphores: init/destroy/post/wait/trywait (when available)
  - Mutexes: init/destroy/lock/trylock/unlock (when available)
  - Condition variables: init/destroy (when available)

## Behavior while stubbed
- Each test still **SKIPs** when `errno == ENOSYS`.

## Next (Step 5)
- Replace generic lifecycle patterns with real scenarios (busy/destroyed objects).
- Tighten errno mapping per API based on the User Manual.
