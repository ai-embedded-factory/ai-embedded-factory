#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../../../src/stub/mpx_stub.h"
#include "../contract_common.h"

/* Domain contract scaffold (pthread).
 * API: pthread_cancel
 */

static int st_param_validation(void) {
  errno = 0;
  int rc = (int)pthread_cancel(0);
  if (rc != -1) return 1;
  if (errno == 0) return 1;
  if ((errno != ESRCH)) return 1;
  return 0;
}

static int st_state_errors(void) {
  errno = 0;
  int rc = (int)pthread_cancel(1);
  if (rc != -1) return 1;
  if (errno == 0) return 1;
  if ((errno != ESRCH)) return 1;
  return 0;
}

static int st_success_path(void) {
  (void)0;
  /* Success path requires valid object setup; keep non-blocking during scaffolding. */
  (void)pthread_cancel(0);
  return mpx_tbd("success path requires valid object setup");
}

int main(void) {
  /* Description (extract): This service cancels the specified thread. If the specified thread has cancellation disabled or deferred, this service marks the thread for cancellation at a later point determined by the thread itself. Otherwise, if the specified thread has asynchronous cancellation enabled, it is immediately canceled (terminated) by this service. */
  /* Errno symbols observed in manual extract: ESRCH */
  /* Return codes / errno notes (extract, first lines):
   * MPX_SUCCESS (0)	Successful thread cancellation.
   * ESRCH	Specified thread handle is invalid.
   * Real-time Scenarios:
   * Upon the successful execution of this service, the following real-time scenarios are possible:
   * NO PREEMPTION. No preemption takes place as a result of this service.
   * Stack Usage Estimate:
   * From the location where this API is called, there should be at least (112 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.
   * Callable From:
   */

  /* Phase 0: call API once and SKIP if stubbed */
  errno = 0;
  (void)pthread_cancel(0);
  if (mpx_skip_if_stubbed("pthread_cancel")) return 0;

  int failures = 0;
  failures += mpx_run_subtest("param_validation", st_param_validation);
  failures += mpx_run_subtest("state_errors", st_state_errors);
  failures += mpx_run_subtest("success_path", st_success_path);

  if (failures != 0) return 1;
  printf("PASS (scaffold): pthread_cancel\n");
  return 0;
}
