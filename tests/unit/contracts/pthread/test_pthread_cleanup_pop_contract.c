#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../../../src/stub/mpx_stub.h"
#include "../contract_common.h"

/* Domain contract scaffold (pthread).
 * API: pthread_cleanup_pop
 */

static int st_param_validation(void) {
  return mpx_tbd("parameter validation (void-return API)");
}

static int st_state_errors(void) {
  return mpx_tbd("state/lifecycle errors (void-return API)");
}

static int st_success_path(void) {
  (void)0;
  /* Success path requires valid object setup; keep non-blocking during scaffolding. */
  (void)pthread_cleanup_pop(0);
  return mpx_tbd("success path requires valid object setup");
}

int main(void) {
  /* Description (extract): This service pops the most recently pushed cleanup handler from the thread’s cleanup handler stack. If the specified execute parameter is non-zero and the cleanup handler function pointer is non-NULL, the cleanup handler is executed before returning to the caller. */
  /* Return codes / errno notes (extract, first lines):
   * none
   * Real-time Scenarios:
   * Upon the successful execution of this service, the following real-time scenarios are possible:
   * NO PREEMPTION. No preemption takes place as a result of this service.
   * Stack Usage Estimate:
   * context.
   * From the location where this API is called, there should be at least (48 + MPX_BINDING_STACK_FRAME_SIZE + cleanup handler stack usage) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application
   * Callable From:
   */

  /* Phase 0: call API once and SKIP if stubbed */
  errno = 0;
  (void)pthread_cleanup_pop(-1);
  if (mpx_skip_if_stubbed("pthread_cleanup_pop")) return 0;

  int failures = 0;
  failures += mpx_run_subtest("param_validation", st_param_validation);
  failures += mpx_run_subtest("state_errors", st_state_errors);
  failures += mpx_run_subtest("success_path", st_success_path);

  if (failures != 0) return 1;
  printf("PASS (scaffold): pthread_cleanup_pop\n");
  return 0;
}
