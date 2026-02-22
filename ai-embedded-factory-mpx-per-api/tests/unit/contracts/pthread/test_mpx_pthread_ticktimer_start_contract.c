#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../../../src/stub/mpx_stub.h"
#include "../contract_common.h"

/* Domain contract scaffold (pthread).
 * API: mpx_pthread_ticktimer_start
 */

static int st_param_validation(void) {
  errno = 0;
  int rc = (int)mpx_pthread_ticktimer_start(0);
  if (rc != -1) return 1;
  if (errno == 0) return 1;
  if ((errno != EBUSY) && (errno != EINVAL)) return 1;
  return 0;
}

static int st_state_errors(void) {
  errno = 0;
  int rc = (int)mpx_pthread_ticktimer_start(0);
  if (rc != -1) return 1;
  if (errno == 0) return 1;
  if ((errno != EBUSY) && (errno != EINVAL)) return 1;
  return 0;
}

static int st_success_path(void) {
  (void)0;
  /* Success path requires valid object setup; keep non-blocking during scaffolding. */
  (void)mpx_pthread_ticktimer_start(0);
  return mpx_tbd("success path requires valid object setup");
}

int main(void) {
  /* Description (extract): This pthreadsmore service starts a previously created ticktimer. */
  /* Errno symbols observed in manual extract: EBUSY, EINVAL */
  /* Return codes / errno notes (extract, first lines):
   * MPX_SUCCESS (0)	Successful ticktimer start.
   * EINVAL	Invalid ticktimer handle.
   * EBUSY	Ticktimer was already started.
   * Real-time Scenarios:
   * Upon the successful completion of this service, the following real-time scenarios are possible:
   * NO PREEMPTION. There is no preemption possible with this service.
   * Stack Usage Estimate:
   * From the location where this API is called, at least (48 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.
   */

  /* Phase 0: call API once and SKIP if stubbed */
  errno = 0;
  (void)mpx_pthread_ticktimer_start(0);
  if (mpx_skip_if_stubbed("mpx_pthread_ticktimer_start")) return 0;

  int failures = 0;
  failures += mpx_run_subtest("param_validation", st_param_validation);
  failures += mpx_run_subtest("state_errors", st_state_errors);
  failures += mpx_run_subtest("success_path", st_success_path);

  if (failures != 0) return 1;
  printf("PASS (scaffold): mpx_pthread_ticktimer_start\n");
  return 0;
}
