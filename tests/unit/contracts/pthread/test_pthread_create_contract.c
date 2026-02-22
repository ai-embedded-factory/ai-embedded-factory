#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../../../src/stub/mpx_stub.h"
#include "../contract_common.h"

/* Domain contract scaffold (pthread).
 * API: pthread_create
 */

static int st_param_validation(void) {
  errno = 0;
  int rc = (int)pthread_create(0, 0, 0, 0);
  if (rc != -1) return 1;
  if (errno == 0) return 1;
  if ((errno != EAGAIN) && (errno != EINVAL)) return 1;
  return 0;
}

static int st_state_errors(void) {
  errno = 0;
  int rc = (int)pthread_create(0, 0, 0, 0);
  if (rc != -1) return 1;
  if (errno == 0) return 1;
  if ((errno != EAGAIN) && (errno != EINVAL)) return 1;
  return 0;
}

static int st_success_path(void) {
  (void)0;
  /* Success path requires valid object setup; keep non-blocking during scaffolding. */
  (void)pthread_create(0, 0, 0, 0);
  return mpx_tbd("success path requires valid object setup");
}

int main(void) {
  /* Description (extract): This service creates a new thread that starts execution at the caller’s start_routine, passing verbatim the supplied arguments parameter. Note that the optional attributes parameter can specify additional attributes for the thread, including explicitly setting its priority, stack location, stack size, etc. */
  /* Errno symbols observed in manual extract: EAGAIN, EINVAL */
  /* Return codes / errno notes (extract, first lines):
   * MPX_SUCCESS (0)	Successful new thread creation.
   * EINVAL	Invalid argument(s).
   * EAGAIN	Not enough resources to create the thread.
   * Real-time Scenarios:
   * Upon the successful execution of this service, the following real-time scenarios are possible:
   * NO PREEMPTION. There is no preemption if the newly created thread has the same or less priority than the calling thread. This service returns immediately after the creation of the new thread.
   * PREEMPTION. If the newly created thread has a higher priority than the calling thread, the calling thread is preempted, and execution takes place in the newly created thread prior to returning from this service.
   * Stack Usage Estimate:
   */

  /* Phase 0: call API once and SKIP if stubbed */
  errno = 0;
  (void)pthread_create(0, 0, 0, 0);
  if (mpx_skip_if_stubbed("pthread_create")) return 0;

  int failures = 0;
  failures += mpx_run_subtest("param_validation", st_param_validation);
  failures += mpx_run_subtest("state_errors", st_state_errors);
  failures += mpx_run_subtest("success_path", st_success_path);

  if (failures != 0) return 1;
  printf("PASS (scaffold): pthread_create\n");
  return 0;
}
