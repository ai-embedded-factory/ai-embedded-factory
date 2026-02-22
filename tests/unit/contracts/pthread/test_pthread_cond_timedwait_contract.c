#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../../../src/stub/mpx_stub.h"
#include "../contract_common.h"

/* Domain contract scaffold (pthread).
 * API: pthread_cond_timedwait
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
  /* Description (extract): This service suspends on the condition variable specified by the condition_var_handle parameter. Before this service is called, the thread must have obtained the mutex specified by mutex_handle. Internally, MPX releases the mutex atomically with the thread suspension. Once the calling thread is resumed via a signal or broadcast to the condition variable, the mutex is reobtained before this service returns to the caller. */
  /* Errno symbols observed in manual extract: EINVAL, ETIMEDOUT */
  /* Return codes / errno notes (extract, first lines):
   * MPX_SUCCESS (0)	Successful condition variable wait with timeout.
   * EINVAL	Invalid condition variable handle, mutex handle pointer, or absolute time. In addition, if the specified mutex is not owned or a different mutex is associated with this condition variable, this error is returned.
   * ETIMEDOUT	Maximum wait time was reached, and this service timed out.
   * Real-time Scenarios:
   * Upon the successful completion of this service, the following real-time scenarios are possible:
   * SUSPENSION. The calling thread is suspended until another thread signals or broadcasts to the condition variable. The calling thread times out and returns with an error if absolute time is reached.
   * Stack Usage Estimate:
   * From the location where this API is called, there should be at least (256 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.
   */

  /* Phase 0: SKIP if stubbed */
  errno = ENOSYS;
  if (mpx_skip_if_stubbed("pthread_cond_timedwait")) return 0;

  int failures = 0;
  failures += mpx_run_subtest("param_validation", st_param_validation);
  failures += mpx_run_subtest("state_errors", st_state_errors);
  failures += mpx_run_subtest("success_path", st_success_path);

  if (failures != 0) return 1;
  printf("PASS (scaffold): pthread_cond_timedwait\n");
  return 0;
}
