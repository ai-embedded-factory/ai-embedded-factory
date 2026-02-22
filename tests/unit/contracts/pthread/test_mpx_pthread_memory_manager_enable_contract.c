#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../../../src/stub/mpx_stub.h"
#include "../contract_common.h"

/* Domain contract scaffold (pthread).
 * API: mpx_pthread_memory_manager_enable
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
  /* Description (extract): This pthreadsmore service enables full management of the remaining memory supplied by the application when the MPX RTOS is started via mpx_pthread_start. The memory allocated with all subsequent system object creation and destruction will be fully managed. */
  /* Errno symbols observed in manual extract: EINVAL, ENOME */
  /* Return codes / errno notes (extract, first lines):
   * MPX_SUCCESS (0)	Successful enablement of internal MPX RTOS
   * memory management.
   * EINVAL	Invalid (NULL) pointer supplied to the
   * mpx_pthread_start API.
   * ENOME	Not enough memory remaining.
   * Real-time Scenarios:
   * Upon the successful execution of this service, the following real-time scenarios are possible:
   * NO PREEMPTION. This service does not result in preemption.
   */

  /* Phase 0: SKIP if stubbed */
  errno = ENOSYS;
  if (mpx_skip_if_stubbed("mpx_pthread_memory_manager_enable")) return 0;

  int failures = 0;
  failures += mpx_run_subtest("param_validation", st_param_validation);
  failures += mpx_run_subtest("state_errors", st_state_errors);
  failures += mpx_run_subtest("success_path", st_success_path);

  if (failures != 0) return 1;
  printf("PASS (scaffold): mpx_pthread_memory_manager_enable\n");
  return 0;
}
