#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../../../src/stub/mpx_stub.h"
#include "../contract_common.h"

/* Domain contract scaffold (pthread).
 * API: pthread_attr_setdetachstate
 */

static int st_param_validation(void) {
  errno = 0;
  int rc = (int)pthread_attr_setdetachstate(0, -1);
  if (rc != -1) return 1;
  if (errno == 0) return 1;
  if ((errno != EINVAL)) return 1;
  return 0;
}

static int st_state_errors(void) {
  errno = 0;
  int rc = (int)pthread_attr_setdetachstate(0, 1);
  if (rc != -1) return 1;
  if (errno == 0) return 1;
  if ((errno != EINVAL)) return 1;
  return 0;
}

static int st_success_path(void) {
  (void)0;
  /* Success path requires valid object setup; keep non-blocking during scaffolding. */
  (void)pthread_attr_setdetachstate(0, 0);
  return mpx_tbd("success path requires valid object setup");
}

int main(void) {
  /* Description (extract): This service sets the detach state specified by new_detach_state in the thread attributes structure. Valid detach states are PTHREAD_CREATE_JOINABLE and PTHREAD_CREATE_DETACHED. */
  /* Errno symbols observed in manual extract: EINVAL */
  /* Return codes / errno notes (extract, first lines):
   * MPX_SUCCESS (0)	Successful detach state set.
   * EINVAL	Attributes structure pointer or detach state specification.
   * Real-time Scenarios:
   * Upon the successful execution of this service, the following real-time scenarios are possible:
   * NO PREEMPTION. There is no preemption possible with this service.
   * Stack Usage Estimate:
   * From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.
   * Callable From:
   */

  /* Phase 0: call API once and SKIP if stubbed */
  errno = 0;
  (void)pthread_attr_setdetachstate(0, -1);
  if (mpx_skip_if_stubbed("pthread_attr_setdetachstate")) return 0;

  int failures = 0;
  failures += mpx_run_subtest("param_validation", st_param_validation);
  failures += mpx_run_subtest("state_errors", st_state_errors);
  failures += mpx_run_subtest("success_path", st_success_path);

  if (failures != 0) return 1;
  printf("PASS (scaffold): pthread_attr_setdetachstate\n");
  return 0;
}
