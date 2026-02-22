#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../../../src/stub/mpx_stub.h"
#include "../contract_common.h"

/* Domain contract scaffold (pthread).
 * API: mpx_pthread_ticktimer_stop
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
  /* Description (extract): This pthreadsmore service stops a previously created ticktimer. When stopped, the remaining number of ticks before expiration is saved. If the ticktimer is restarted, it is restarted with the previous remaining number of ticks. */
  /* Errno symbols observed in manual extract: EINVAL */
  /* Return codes / errno notes (extract, first lines):
   * MPX_SUCCESS (0)	Successful ticktimer stop.
   * EINVAL	Invalid ticktimer handle, or the ticktimer was already stopped.
   * Real-time Scenarios:
   * Upon the successful completion of this service, the following real-time scenarios are possible:
   * NO PREEMPTION. There is no preemption possible with this service.
   * Stack Usage Estimate:
   * From the location where this API is called, at least (48 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.
   * Callable From:
   */

  /* Phase 0: SKIP if stubbed */
  errno = ENOSYS;
  if (mpx_skip_if_stubbed("mpx_pthread_ticktimer_stop")) return 0;

  int failures = 0;
  failures += mpx_run_subtest("param_validation", st_param_validation);
  failures += mpx_run_subtest("state_errors", st_state_errors);
  failures += mpx_run_subtest("success_path", st_success_path);

  if (failures != 0) return 1;
  printf("PASS (scaffold): mpx_pthread_ticktimer_stop\n");
  return 0;
}
