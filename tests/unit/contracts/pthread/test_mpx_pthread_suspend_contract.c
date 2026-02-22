#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../../../src/stub/mpx_stub.h"
#include "../contract_common.h"

/* Domain contract scaffold (pthread).
 * API: mpx_pthread_suspend
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
  /* Description (extract): This pthread+ service suspends the specified thread. If the specified thread is already suspended, an error is returned. */
  /* Errno symbols observed in manual extract: EINVAL, ESRCH */
  /* Return codes / errno notes (extract, first lines):
   * MPX_SUCCESS (0)	Successful thread suspension.
   * ESRCH	Thread handle is not valid.
   * EINVAL	Specified thread is already suspended.
   * Real-time Scenarios:
   * Upon the successful execution of this service, the following real-time scenarios are possible:
   * NO PREEMPTION. If the thread suspended is not the executing thread, there is no preemption.
   * SUSPENSION. If the currently executing thread calls this service, it is suspended until another thread calls mpx_pthread_resume.
   * Stack Usage Estimate:
   */

  /* Phase 0: SKIP if stubbed */
  errno = ENOSYS;
  if (mpx_skip_if_stubbed("mpx_pthread_suspend")) return 0;

  int failures = 0;
  failures += mpx_run_subtest("param_validation", st_param_validation);
  failures += mpx_run_subtest("state_errors", st_state_errors);
  failures += mpx_run_subtest("success_path", st_success_path);

  if (failures != 0) return 1;
  printf("PASS (scaffold): mpx_pthread_suspend\n");
  return 0;
}
