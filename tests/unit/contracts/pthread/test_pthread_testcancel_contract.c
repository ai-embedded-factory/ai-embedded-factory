#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../../../src/stub/mpx_stub.h"
#include "../contract_common.h"

/* Domain contract scaffold (pthread).
 * API: pthread_testcancel
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
  /* Description (extract): This service checks for a pending cancel request for the calling thread. If detected, the calling thread cancels itself via pthread_exit. */
  /* Return codes / errno notes (extract, first lines):
   * none
   * Real-time Scenarios:
   * Upon the successful completion of this service, the following real-time scenarios are possible:
   * NO PREEMPTION. If a cancel request is not pending for the calling thread, there is no preemption possible with this service.
   * SUSPENSION. If cancellation is pending, the calling thread is suspended due to termination.
   * Stack Usage Estimate:
   * From the location where this API is called, at least (96 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.
   * Callable From:
   */

  /* Phase 0: SKIP if stubbed */
  errno = ENOSYS;
  if (mpx_skip_if_stubbed("pthread_testcancel")) return 0;

  int failures = 0;
  failures += mpx_run_subtest("param_validation", st_param_validation);
  failures += mpx_run_subtest("state_errors", st_state_errors);
  failures += mpx_run_subtest("success_path", st_success_path);

  if (failures != 0) return 1;
  printf("PASS (scaffold): pthread_testcancel\n");
  return 0;
}
