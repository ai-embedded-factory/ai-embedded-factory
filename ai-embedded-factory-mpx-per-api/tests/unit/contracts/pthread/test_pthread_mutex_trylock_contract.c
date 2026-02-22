#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../../../src/stub/mpx_stub.h"
#include "../contract_common.h"

/* Domain contract scaffold (pthread).
 * API: pthread_mutex_trylock
 */

static int st_param_validation(void) {
  errno = 0;
  int rc = (int)pthread_mutex_trylock(0);
  if (rc != -1) return 1;
  if (errno == 0) return 1;
  if ((errno != EBUSY) && (errno != EDEADLK) && (errno != EINVAL)) return 1;
  return 0;
}

static int st_state_errors(void) {
  errno = 0;
  int rc = (int)pthread_mutex_trylock(0);
  if (rc != -1) return 1;
  if (errno == 0) return 1;
  if ((errno != EBUSY) && (errno != EDEADLK) && (errno != EINVAL)) return 1;
  return 0;
}

static int st_success_path(void) {
  (void)0;
  /* Success path requires valid object setup; keep non-blocking during scaffolding. */
  (void)pthread_mutex_trylock(0);
  return mpx_tbd("success path requires valid object setup");
}

int main(void) {
  /* Description (extract): This service assigns ownership to the calling thread if the mutex is available. Otherwise, if another thread already owns the mutex, this service immediately returns an error, i.e., there is no thread suspension like the pthread_mutex_lock service. */
  /* Errno symbols observed in manual extract: EBUSY, EDEADLK, EINVAL */
  /* Return codes / errno notes (extract, first lines):
   * MPX_SUCCESS (0)	Successful mutex lock.
   * EDEADLK	Thread already owns mutex (non-recursive mutex).
   * EBUSY	Another thread already owns the mutex.
   * EINVAL	Invalid mutex handle pointer.
   * Real-time Scenarios:
   * Upon the successful completion of this service, the following real-time scenarios are possible:
   * NO PREEMPTION. No preemption occurs if the mutex is available and ownership is assigned to the calling thread.
   * Stack Usage Estimate:
   */

  /* Phase 0: call API once and SKIP if stubbed */
  errno = 0;
  (void)pthread_mutex_trylock(0);
  if (mpx_skip_if_stubbed("pthread_mutex_trylock")) return 0;

  int failures = 0;
  failures += mpx_run_subtest("param_validation", st_param_validation);
  failures += mpx_run_subtest("state_errors", st_state_errors);
  failures += mpx_run_subtest("success_path", st_success_path);

  if (failures != 0) return 1;
  printf("PASS (scaffold): pthread_mutex_trylock\n");
  return 0;
}
