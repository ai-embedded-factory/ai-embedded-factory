#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../../../src/stub/mpx_stub.h"
#include "../contract_common.h"

/* Domain contract scaffold (pthread).
 * API: mpx_pthread_ticks_get
 */

static int st_param_validation(void) {
  errno = 0;
  int rc = (int)mpx_pthread_ticks_get();
  if (rc != -1) return 1;
  if (errno == 0) return 1;
  return 0;
}

static int st_state_errors(void) {
  errno = 0;
  int rc = (int)mpx_pthread_ticks_get();
  if (rc != -1) return 1;
  if (errno == 0) return 1;
  return 0;
}

static int st_success_path(void) {
  (void)0;
  /* Success path requires valid object setup; keep non-blocking during scaffolding. */
  (void)mpx_pthread_ticks_get();
  return mpx_tbd("success path requires valid object setup");
}

int main(void) {
  /* Description (extract): This pthreadsmore service returns the internal tick count, representing the number of timer interrupts. */
  /* Return codes / errno notes (extract, first lines):
   * current tick count
   * Real-time Scenarios:
   * Upon the successful completion of this service, the following real-time scenarios are possible:
   * NO PREEMPTION. No preemption takes place as a result of this service.
   * Stack Usage Estimate:
   * From the location where this API is called, at least (8 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.
   * Callable From:
   * This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
   */

  /* Phase 0: call API once and SKIP if stubbed */
  errno = 0;
  (void)mpx_pthread_ticks_get();
  if (mpx_skip_if_stubbed("mpx_pthread_ticks_get")) return 0;

  int failures = 0;
  failures += mpx_run_subtest("param_validation", st_param_validation);
  failures += mpx_run_subtest("state_errors", st_state_errors);
  failures += mpx_run_subtest("success_path", st_success_path);

  if (failures != 0) return 1;
  printf("PASS (scaffold): mpx_pthread_ticks_get\n");
  return 0;
}
