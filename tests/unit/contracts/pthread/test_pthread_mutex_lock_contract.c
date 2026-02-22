#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../../../src/stub/mpx_stub.h"
#include "../contract_common.h"

/* Domain contract scaffold (pthread).
 * API: pthread_mutex_lock
 */

static int st_param_validation(void) {
  return mpx_tbd("parameter validation (invalid args -> expected return/errno)");
}

static int st_state_errors(void) {
  return mpx_tbd("state/lifecycle errors (invalid state -> expected return/errno)");
}

static int st_success_path(void) {
  return mpx_tbd("success path (expected return, errno behavior, side-effects)");
}

int main(void) {
  /* Description (extract): This service assigns ownership to the calling thread if the mutex is available. Otherwise, if another thread already owns the mutex, the calling thread suspends until the other thread releases the mutex. */
  /* Errno symbols observed in manual extract: EDEADLK, EINVAL */
  /* Return codes / errno notes (extract, first lines):
   * MPX_SUCCESS (0)	Successful mutex lock.
   * EDEADLK	Thread already owns mutex (non-recursive mutex).
   * EINVAL	Invalid mutex handle pointer.
   * Real-time Scenarios:
   * Upon the successful completion of this service, the following real-time scenarios are possible:
   * NO PREEMPTION. No preemption occurs if the mutex is available and ownership is assigned to the calling thread.
   * SUSPENSION. If another thread already owns the mutex, the calling thread is suspended until the other thread releases ownership via pthread_mutex_unlock.
   * Stack Usage Estimate:
   */

  /* Phase 0: SKIP if stubbed */
  errno = ENOSYS;
  if (mpx_skip_if_stubbed("pthread_mutex_lock")) return 0;

  int failures = 0;
  failures += mpx_run_subtest("param_validation", st_param_validation);
  failures += mpx_run_subtest("state_errors", st_state_errors);
  failures += mpx_run_subtest("success_path", st_success_path);

  if (failures != 0) return 1;
  printf("PASS (scaffold): pthread_mutex_lock\n");
  return 0;
}
