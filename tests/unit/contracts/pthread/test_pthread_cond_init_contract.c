#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../../../src/stub/mpx_stub.h"
#include "../contract_common.h"

/* Domain contract scaffold (pthread).
 * API: pthread_cond_init
 */

static int st_param_validation(void) {
  errno = 0;
  int rc = (int)pthread_cond_init(0, 0);
  if (rc != -1) return 1;
  if (errno == 0) return 1;
  if ((errno != EBUSY) && (errno != EINVAL) && (errno != ENOMEM)) return 1;
  return 0;
}

static int st_state_errors(void) {
  return mpx_tbd("state/lifecycle errors (invalid state -> expected return/errno)");
}

static int st_success_path(void) {
  return mpx_tbd("success path (expected return, errno behavior, side-effects)");
}

int main(void) {
  /* Description (extract): This service initializes (creates) a condition variable with the optional condition variable attributes. If successful, the condition variable handle is set up for further use by the application. */
  /* Errno symbols observed in manual extract: EBUSY, EINVAL, ENOMEM */
  /* Return codes / errno notes (extract, first lines):
   * MPX_SUCCESS (0)	Successful condition variable initialization.
   * EINVAL	Invalid condition variable handle pointer or condition variable attributes.
   * EBUSY	Condition variable is already created.
   * ENOMEM	Insufficient memory to create condition variable.
   * Real-time Scenarios:
   * Upon the successful completion of this service, the following real-time scenarios are possible:
   * NO PREEMPTION. There is no preemption possible with this service.
   * Stack Usage Estimate:
   */

  /* Phase 0: call API once and SKIP if stubbed */
  errno = 0;
  (void)pthread_cond_init(0, 0);
  if (mpx_skip_if_stubbed("pthread_cond_init")) return 0;

  int failures = 0;
  failures += mpx_run_subtest("param_validation", st_param_validation);
  failures += mpx_run_subtest("state_errors", st_state_errors);
  failures += mpx_run_subtest("success_path", st_success_path);

  if (failures != 0) return 1;
  printf("PASS (scaffold): pthread_cond_init\n");
  return 0;
}
