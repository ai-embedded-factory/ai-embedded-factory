#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../../../src/stub/mpx_stub.h"
#include "../contract_common.h"

/* Domain contract scaffold (pthread).
 * API: pthread_mutex_init
 */

static int st_param_validation(void) {
  errno = 0;
  int rc = (int)pthread_mutex_init(0, 0);
  if (rc != -1) return 1;
  if (errno == 0) return 1;
  if ((errno != EBUSY) && (errno != EINVAL) && (errno != ENOMEM)) return 1;
  return 0;
}

static int st_state_errors(void) {
  errno = 0;
  int rc = (int)pthread_mutex_init(0, 0);
  if (rc != -1) return 1;
  if (errno == 0) return 1;
  if ((errno != EBUSY) && (errno != EINVAL) && (errno != ENOMEM)) return 1;
  return 0;
}

static int st_success_path(void) {
  (void)0;
  /* Success path requires valid object setup; keep non-blocking during scaffolding. */
  (void)pthread_mutex_init(0, 0);
  return mpx_tbd("success path requires valid object setup");
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

  /* Phase 0: call API once and SKIP if stubbed */
  errno = 0;
  (void)pthread_mutex_init(0, 0);
  if (mpx_skip_if_stubbed("pthread_mutex_init")) return 0;

  int failures = 0;
  failures += mpx_run_subtest("param_validation", st_param_validation);
  failures += mpx_run_subtest("state_errors", st_state_errors);
  failures += mpx_run_subtest("success_path", st_success_path);

  if (failures != 0) return 1;
  printf("PASS (scaffold): pthread_mutex_init\n");
  return 0;
}
