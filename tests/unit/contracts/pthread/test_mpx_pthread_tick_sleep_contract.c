#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../../../src/stub/mpx_stub.h"
#include "../contract_common.h"

/* Domain contract scaffold (pthread).
 * API: mpx_pthread_tick_sleep
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
  /* Description (extract): This pthreadsmore service suspends the calling thread for the number of timer ticks specified by ticks_to_sleep. If a value of 0 ticks is supplied, this service returns immediately, i.e., the calling thread is not suspended. */
  /* Return codes / errno notes (extract, first lines):
   * MPX_SUCCESS (0)	Successful thread tick sleep.
   * Real-time Scenarios:
   * Upon the successful completion of this service, the following real-time scenarios are possible:
   * NO PREEMPTION. If the number of ticks to sleep is zero, no preemption occurs.
   * SUSPENSION. If the number of ticks to sleep is non-zero, the calling thread is suspended for that amount of ticks.
   * PREEMPTION. After the number of ticks has expired, the calling thread is resumed and will preempt the currently running thread if it is a higher priority.
   * Stack Usage Estimate:
   * From the location where this API is called, at least (60 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.
   */

  /* Phase 0: SKIP if stubbed */
  errno = ENOSYS;
  if (mpx_skip_if_stubbed("mpx_pthread_tick_sleep")) return 0;

  int failures = 0;
  failures += mpx_run_subtest("param_validation", st_param_validation);
  failures += mpx_run_subtest("state_errors", st_state_errors);
  failures += mpx_run_subtest("success_path", st_success_path);

  if (failures != 0) return 1;
  printf("PASS (scaffold): mpx_pthread_tick_sleep\n");
  return 0;
}
