#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../../../src/stub/mpx_stub.h"
#include "../contract_common.h"

/* Domain contract scaffold (pthread).
 * API: mpx_pthread_fastqueue_create
 */

static int st_param_validation(void) {
  errno = 0;
  int rc = (int)mpx_pthread_fastqueue_create(0, 0, 0, -1);
  if (rc != -1) return 1;
  if (errno == 0) return 1;
  if ((errno != EBUSY) && (errno != EINVAL) && (errno != ENOMEM)) return 1;
  return 0;
}

static int st_state_errors(void) {
  errno = 0;
  int rc = (int)mpx_pthread_fastqueue_create(0, 0, 1, 0);
  if (rc != -1) return 1;
  if (errno == 0) return 1;
  if ((errno != EBUSY) && (errno != EINVAL) && (errno != ENOMEM)) return 1;
  return 0;
}

static int st_success_path(void) {
  (void)0;
  /* Success path requires valid object setup; keep non-blocking during scaffolding. */
  (void)mpx_pthread_fastqueue_create(0, 0, 0, 0);
  return mpx_tbd("success path requires valid object setup");
}

int main(void) {
  /* Description (extract): This pthreadsmore service initializes (creates) a fastqueue with the optional fast queue attributes. If successful, the fastqueue handle is set up for further use by the application. */
  /* Errno symbols observed in manual extract: EBUSY, EINVAL, ENOMEM */
  /* Return codes / errno notes (extract, first lines):
   * MPX_SUCCESS (0)	Successful fastqueue creation.
   * EINVAL	Invalid fastqueue handle pointer or attributes.
   * EBUSY	Fastqueue is already created.
   * ENOMEM	Insufficient memory to create fastqueue.
   * Real-time Scenarios:
   * Upon the successful completion of this service, the following real-time scenarios are possible:
   * NO PREEMPTION. There is no preemption possible with this service.
   * Stack Usage Estimate:
   */

  /* Phase 0: call API once and SKIP if stubbed */
  errno = 0;
  (void)mpx_pthread_fastqueue_create(0, 0, 0, -1);
  if (mpx_skip_if_stubbed("mpx_pthread_fastqueue_create")) return 0;

  int failures = 0;
  failures += mpx_run_subtest("param_validation", st_param_validation);
  failures += mpx_run_subtest("state_errors", st_state_errors);
  failures += mpx_run_subtest("success_path", st_success_path);

  if (failures != 0) return 1;
  printf("PASS (scaffold): mpx_pthread_fastqueue_create\n");
  return 0;
}
