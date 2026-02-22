#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../../../src/stub/mpx_stub.h"
#include "../contract_common.h"

/* Domain contract scaffold (pthread).
 * API: pthread_detach
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
  /* Description (extract): This service places the specified thread in a detached state, such that it can’t be joined in the future. It is equivalent to creating the thread with the PTHREAD_CREATE_DETACHED attribute. When the specified, detached thread exits or returns, all of its resources are immediately released. */
  /* Errno symbols observed in manual extract: EINVAL, ESRCH */
  /* Return codes / errno notes (extract, first lines):
   * MPX_SUCCESS (0)	Successful detach of thread.
   * EINVAL	Specified thread was already detached or not in a joinable state.
   * ESRCH	Specified thread could not be found.
   * Real-time Scenarios:
   * Upon the successful execution of this service, the following real-time scenarios are possible:
   * NO PREEMPTION. There is no preemption possible with this service.
   * Stack Usage Estimate:
   * From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.
   */

  /* Phase 0: SKIP if stubbed */
  errno = ENOSYS;
  if (mpx_skip_if_stubbed("pthread_detach")) return 0;

  int failures = 0;
  failures += mpx_run_subtest("param_validation", st_param_validation);
  failures += mpx_run_subtest("state_errors", st_state_errors);
  failures += mpx_run_subtest("success_path", st_success_path);

  if (failures != 0) return 1;
  printf("PASS (scaffold): pthread_detach\n");
  return 0;
}
