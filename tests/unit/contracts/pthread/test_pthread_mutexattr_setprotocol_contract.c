#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../../../src/stub/mpx_stub.h"
#include "../contract_common.h"

/* Domain contract scaffold (pthread).
 * API: pthread_mutexattr_setprotocol
 */

static int st_param_validation(void) {
  errno = 0;
  int rc = (int)pthread_mutexattr_setprotocol(0, -1);
  if (rc != -1) return 1;
  if (errno == 0) return 1;
  if ((errno != EINVAL)) return 1;
  return 0;
}

static int st_state_errors(void) {
  return mpx_tbd("state/lifecycle errors (invalid state -> expected return/errno)");
}

static int st_success_path(void) {
  return mpx_tbd("success path (expected return, errno behavior, side-effects)");
}

int main(void) {
  /* Description (extract): This service sets the specified protocol in the previously created mutex attributes structure. By default, the protocol is PTHREAD_PRIO_NONE, which means priority inheritance is not enabled. Setting the protocol to PTHREAD_PRIO_INHERIT enables priority inheritance when a mutex is created with this attribute structure. Please see the mutex section in Chapter 6 for more information on priority inheritance. */
  /* Errno symbols observed in manual extract: EINVAL */
  /* Return codes / errno notes (extract, first lines):
   * MPX_SUCCESS (0)	Successful mutex attributes mutex protocol set.
   * EINVAL	Invalid mutex attributes or mutex protocol. Note that PTHREAD_PRIO_PROTECT is not currently supported.
   * Real-time Scenarios:
   * Upon the successful completion of this service, the following real-time scenarios are possible:
   * NO PREEMPTION. There is no preemption possible with this service.
   * Stack Usage Estimate:
   * From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.
   * Callable From:
   */

  /* Phase 0: call API once and SKIP if stubbed */
  errno = 0;
  (void)pthread_mutexattr_setprotocol(0, -1);
  if (mpx_skip_if_stubbed("pthread_mutexattr_setprotocol")) return 0;

  int failures = 0;
  failures += mpx_run_subtest("param_validation", st_param_validation);
  failures += mpx_run_subtest("state_errors", st_state_errors);
  failures += mpx_run_subtest("success_path", st_success_path);

  if (failures != 0) return 1;
  printf("PASS (scaffold): pthread_mutexattr_setprotocol\n");
  return 0;
}
