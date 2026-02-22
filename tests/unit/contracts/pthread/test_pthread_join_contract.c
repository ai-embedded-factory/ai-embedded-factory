#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../../../src/stub/mpx_stub.h"
#include "../contract_common.h"

/* Domain contract scaffold (pthread).
 * API: pthread_join
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
  /* Description (extract): This service suspends the currently running thread until the specified thread completes its processing. When the specified thread exits, the value supplied in its exit call is returned in the destination specified by the caller–if a non- NULL exit value destination pointer is provided. */
  /* Errno symbols observed in manual extract: EDEADLK, EINVAL, ESRCH */
  /* Return codes / errno notes (extract, first lines):
   * MPX_SUCCESS (0)	Successful thread join.
   * EINVAL	Thread specified is not joinable.
   * ESRCH	Thread specified is not a valid thread.
   * EDEADLK	Thread is attempting to join with itself, which would create a deadlock.
   * Real-time Scenarios:
   * Upon the successful execution of this service, the following real-time scenarios are possible:
   * SUSPENSION. Once the currently executing thread is joined with the thread specified, it enters a suspended state. The highest priority ready thread will then start executing.
   * Stack Usage Estimate:
   */

  /* Phase 0: SKIP if stubbed */
  errno = ENOSYS;
  if (mpx_skip_if_stubbed("pthread_join")) return 0;

  int failures = 0;
  failures += mpx_run_subtest("param_validation", st_param_validation);
  failures += mpx_run_subtest("state_errors", st_state_errors);
  failures += mpx_run_subtest("success_path", st_success_path);

  if (failures != 0) return 1;
  printf("PASS (scaffold): pthread_join\n");
  return 0;
}
