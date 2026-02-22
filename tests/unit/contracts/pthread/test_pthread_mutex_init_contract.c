#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../../../src/stub/mpx_stub.h"
#include "../contract_common.h"

/* Domain contract scaffold (pthread).
 * API: pthread_mutex_init
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
  /* Description (extract): This service initializes (creates) a mutex with the optional mutex attributes. If successful, the mutex handle is set up for further use by the application. */
  /* Errno symbols observed in manual extract: EBUSY, EINVAL, ENOMEM */
  /* Return codes / errno notes (extract, first lines):
   * MPX_SUCCESS (0)	Successful mutex initialization.
   * EINVAL	Invalid mutex handle pointer or mutex attributes.
   * EBUSY	Mutex has already been created.
   * ENOMEM	Insufficient memory to create a mutex.
   * Real-time Scenarios:
   * Upon the successful completion of this service, the following real-time scenarios are possible:
   * NO PREEMPTION. There is no preemption possible with this service.
   * Stack Usage Estimate:
   */

  /* Phase 0: SKIP if stubbed */
  errno = ENOSYS;
  if (mpx_skip_if_stubbed("pthread_mutex_init")) return 0;

  int failures = 0;
  failures += mpx_run_subtest("param_validation", st_param_validation);
  failures += mpx_run_subtest("state_errors", st_state_errors);
  failures += mpx_run_subtest("success_path", st_success_path);

  if (failures != 0) return 1;
  printf("PASS (scaffold): pthread_mutex_init\n");
  return 0;
}
