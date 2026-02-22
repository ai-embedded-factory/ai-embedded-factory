#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../../../src/stub/mpx_stub.h"
#include "../contract_common.h"

/* Domain contract scaffold (pthread).
 * API: sched_yield
 */

static int st_param_validation(void) {
  errno = 0;
  int rc = (int)sched_yield();
  if (rc != -1) return 1;
  if (errno == 0) return 1;
  return 0;
}

static int st_state_errors(void) {
  errno = 0;
  int rc = (int)sched_yield();
  if (rc != -1) return 1;
  if (errno == 0) return 1;
  return 0;
}

static int st_success_path(void) {
  errno = 0;
  int rc = (int)sched_yield();
  /* When implemented, sched_yield success should return 0. */
  if (rc == -1) {
    /* If failure, errno must be set */
    return (errno != 0) ? 0 : 1;
  }
  return (rc == 0) ? 0 : 1;
}

int main(void) {
  /* Description (extract): This service relinquishes control to the next thread of the same priority currently ready for execution. If there is no other thread of the same priority ready for execution, this service simply returns a successful status. */
  /* Return codes / errno notes (extract, first lines):
   * MPX_SUCCESS (0)	Successful thread yield.
   * Real-time Scenarios:
   * Upon the successful completion of this service, the following real-time scenarios are possible:
   * NO PREEMPTION. If no other threads of the same priority are ready for execution, this service returns without preemption.
   * PREEMPTION. If other threads are ready for execution at the same priority level, the other thread(s) will execute before this service returns.
   * Stack Usage Estimate:
   * From the location where this API is called, at least (8 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.
   * Callable From:
   */

  /* Phase 0: call API once and SKIP if stubbed */
  errno = 0;
  (void)sched_yield();
  if (mpx_skip_if_stubbed("sched_yield")) return 0;

  int failures = 0;
  failures += mpx_run_subtest("param_validation", st_param_validation);
  failures += mpx_run_subtest("state_errors", st_state_errors);
  failures += mpx_run_subtest("success_path", st_success_path);

  if (failures != 0) return 1;
  printf("PASS (scaffold): sched_yield\n");
  return 0;
}
