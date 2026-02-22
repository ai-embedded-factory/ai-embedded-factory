#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../../../src/stub/mpx_stub.h"
#include "../contract_common.h"

/* Domain contract scaffold (pthread).
 * API: pthread_exit
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
  /* Description (extract): This service terminates the currently executing thread. If this thread is detached, all of the thread’s resources are released. Any cancellation cleanup handlers are popped and executed. The exit_value passed to this API will be sent to a thread that has joined this thread via the pthread_join API, assuming the value was requested in the join request (non-NULL destination value). */
  /* Return codes / errno notes (extract, first lines):
   * none
   * Real-time Scenarios:
   * Upon the successful execution of this service, the following real-time scenarios are possible:
   * PREEMPTION. If a higher-priority thread has joined this thread, the exit processing will resume its execution, and preemption will occur.
   * SUSPENSION. Once the currently executing thread exit processing is complete, the thread enters a permanent terminated state of suspension.
   * Stack Usage Estimate:
   * From the location where this API is called, there should be at least (80 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.
   * Callable From:
   */

  /* Phase 0: SKIP if stubbed */
  errno = ENOSYS;
  if (mpx_skip_if_stubbed("pthread_exit")) return 0;

  int failures = 0;
  failures += mpx_run_subtest("param_validation", st_param_validation);
  failures += mpx_run_subtest("state_errors", st_state_errors);
  failures += mpx_run_subtest("success_path", st_success_path);

  if (failures != 0) return 1;
  printf("PASS (scaffold): pthread_exit\n");
  return 0;
}
