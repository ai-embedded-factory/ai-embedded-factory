#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "../../../src/stub/mpx_stub.h"
#include "../contract_common.h"

/* Domain contract scaffold (pthread).
 * API: mpx_pthread_memorypool_free
 */

static int st_param_validation(void) {
  errno = 0;
  int rc = (int)mpx_pthread_memorypool_free(0);
  if (rc != -1) return 1;
  if (errno == 0) return 1;
  if ((errno != EINVAL)) return 1;
  return 0;
}

static int st_state_errors(void) {
  errno = 0;
  int rc = (int)mpx_pthread_memorypool_free(0);
  if (rc != -1) return 1;
  if (errno == 0) return 1;
  if ((errno != EINVAL)) return 1;
  return 0;
}

static int st_success_path(void) {
  (void)0;
  /* Success path requires valid object setup; keep non-blocking during scaffolding. */
  (void)mpx_pthread_memorypool_free(0);
  return mpx_tbd("success path requires valid object setup");
}

int main(void) {
  /* Description (extract): This pthreadsmore service releases the previously allocated memory back to the memory pool it was allocated from. Any threads that are suspended on the memory pool that are waiting for this memory are resumed. */
  /* Errno symbols observed in manual extract: EINVAL */
  /* Return codes / errno notes (extract, first lines):
   * MPX_SUCCESS (0)	Successful memory release.
   * EINVAL	Invalid memory pointer.
   * Real-time Scenarios:
   * Upon the successful completion of this service, the following real-time scenarios are possible:
   * NO PREEMPTION. No preemption occurs if no other threads are waiting for memory from the associated memory pool.
   * PREEMPTION. If a higher-priority thread is waiting for this amount of memory, it is resumed, and preemption will occur.
   * Stack Usage Estimate:
   * From the location where this API is called, at least (232 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.
   */

  /* Phase 0: call API once and SKIP if stubbed */
  errno = 0;
  (void)mpx_pthread_memorypool_free(0);
  if (mpx_skip_if_stubbed("mpx_pthread_memorypool_free")) return 0;

  int failures = 0;
  failures += mpx_run_subtest("param_validation", st_param_validation);
  failures += mpx_run_subtest("state_errors", st_state_errors);
  failures += mpx_run_subtest("success_path", st_success_path);

  if (failures != 0) return 1;
  printf("PASS (scaffold): mpx_pthread_memorypool_free\n");
  return 0;
}
