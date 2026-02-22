#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../../../src/stub/mpx_stub.h"
#include "../contract_common.h"

/* Domain contract scaffold (pthread).
 * API: pthread_mutex_unlock
 */

static int st_param_validation(void) {
  errno = 0;
  int rc = (int)pthread_mutex_unlock(0);
  if (rc != -1) return 1;
  if (errno == 0) return 1;
  if ((errno != EINVAL) && (errno != EPERM)) return 1;
  return 0;
}

static int st_state_errors(void) {
  errno = 0;
  int rc = (int)pthread_mutex_unlock(0);
  if (rc != -1) return 1;
  if (errno == 0) return 1;
  if ((errno != EINVAL) && (errno != EPERM)) return 1;
  return 0;
}

static int st_success_path(void) {
  (void)0;
  /* Success path requires valid object setup; keep non-blocking during scaffolding. */
  (void)pthread_mutex_unlock(0);
  return mpx_tbd("success path requires valid object setup");
}

int main(void) {
  /* Description (extract): This service releases a previously owned mutex. If other threads are suspended waiting for the mutex, the first thread is given ownership and resumed. */
  /* Errno symbols observed in manual extract: EINVAL, EPERM */
  /* Return codes / errno notes (extract, first lines):
   * MPX_SUCCESS (0)	Successful mutex unlock.
   * EINVAL	Invalid mutex handle pointer.
   * EPERM	Calling thread does not own the mutex.
   * Real-time Scenarios:
   * Upon the successful completion of this service, the following real-time scenarios are possible:
   * NO PREEMPTION. If no other threads are waiting for the mutex, no preemption occurs.
   * PREEMPTION. If a higher-priority thread is waiting for the mutex, when it is given the mutex, the waiting thread is resumed, and preemption will occur.
   * Stack Usage Estimate:
   */

  /* Phase 0: call API once and SKIP if stubbed */
  errno = 0;
  (void)pthread_mutex_unlock(0);
  if (mpx_skip_if_stubbed("pthread_mutex_unlock")) return 0;

  int failures = 0;
  failures += mpx_run_subtest("param_validation", st_param_validation);
  failures += mpx_run_subtest("state_errors", st_state_errors);
  failures += mpx_run_subtest("success_path", st_success_path);

  if (failures != 0) return 1;
  printf("PASS (scaffold): pthread_mutex_unlock\n");
  return 0;
}
