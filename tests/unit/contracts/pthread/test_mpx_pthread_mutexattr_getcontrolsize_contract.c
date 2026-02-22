#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../../../src/stub/mpx_stub.h"
#include "../contract_common.h"

/* Domain contract scaffold (pthread).
 * API: mpx_pthread_mutexattr_getcontrolsize
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
  /* Description (extract): This pthreadsmore service returns the size of the internal mutex control structure. The primary purpose of this API is to inform the application how much memory is required for the mpx_pthread_mutexattr_setcontroladdr API. */
  /* Errno symbols observed in manual extract: EINVAL */
  /* Return codes / errno notes (extract, first lines):
   * MPX_SUCCESS (0)	Successful retrieval of internal mutex control structure size.
   * EINVAL	Invalid mutex attributes or mutex control structure size destination pointer.
   * Real-time Scenarios:
   * Upon the successful completion of this service, the following real-time scenarios are possible:
   * NO PREEMPTION. There is no preemption possible with this service.
   * Stack Usage Estimate:
   * From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.
   * Callable From:
   */

  /* Phase 0: SKIP if stubbed */
  errno = ENOSYS;
  if (mpx_skip_if_stubbed("mpx_pthread_mutexattr_getcontrolsize")) return 0;

  int failures = 0;
  failures += mpx_run_subtest("param_validation", st_param_validation);
  failures += mpx_run_subtest("state_errors", st_state_errors);
  failures += mpx_run_subtest("success_path", st_success_path);

  if (failures != 0) return 1;
  printf("PASS (scaffold): mpx_pthread_mutexattr_getcontrolsize\n");
  return 0;
}
