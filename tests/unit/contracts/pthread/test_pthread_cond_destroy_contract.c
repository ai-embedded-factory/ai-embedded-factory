#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../../../src/stub/mpx_stub.h"
#include "../contract_common.h"

/* Domain contract scaffold (pthread).
 * API: pthread_cond_destroy
 */

static int st_param_validation(void) {
  errno = 0;
  int rc = (int)pthread_cond_destroy(0);
  if (rc != -1) return 1;
  if (errno == 0) return 1;
  if ((errno != EBUSY) && (errno != EINVAL)) return 1;
  return 0;
}

static int st_state_errors(void) {
  errno = 0;
  int rc = (int)pthread_cond_destroy(0);
  if (rc != -1) return 1;
  if (errno == 0) return 1;
  if ((errno != EBUSY) && (errno != EINVAL)) return 1;
  return 0;
}

static int st_success_path(void) {
  (void)0;
  /* Success path requires valid object setup; keep non-blocking during scaffolding. */
  (void)pthread_cond_destroy(0);
  return mpx_tbd("success path requires valid object setup");
}

int main(void) {
  /* Description (extract): This service destroys the previously created condition variable specified by condition_var_handle. If the condition variable is still in use by another thread, an error is returned. */
  /* Errno symbols observed in manual extract: EBUSY, EINVAL */
  /* Return codes / errno notes (extract, first lines):
   * MPX_SUCCESS (0)	Successful condition variable destroy.
   * EINVAL	Invalid condition variable handle.
   * EBUSY	Another thread is currently using the condition variable.
   * Real-time Scenarios:
   * Upon the successful completion of this service, the following real-time scenarios are possible:
   * NO PREEMPTION. There is no preemption possible with this service.
   * Stack Usage Estimate:
   * From the location where this API is called, there should be at least (56 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.
   */

  /* Phase 0: call API once and SKIP if stubbed */
  errno = 0;
  (void)pthread_cond_destroy(0);
  if (mpx_skip_if_stubbed("pthread_cond_destroy")) return 0;

  int failures = 0;
  failures += mpx_run_subtest("param_validation", st_param_validation);
  failures += mpx_run_subtest("state_errors", st_state_errors);
  failures += mpx_run_subtest("success_path", st_success_path);

  if (failures != 0) return 1;
  printf("PASS (scaffold): pthread_cond_destroy\n");
  return 0;
}
