#include <string.h>
#include "../../../src/stub/mpx_stub.h"
#include "../contract_common.h"

/* Auto-generated contract test scaffold (domain-based).
 * REQ: REQ-API-0156
 * API: pthread_join
 */

int main(void) {
  /* Description (extract): This service suspends the currently running thread until the specified thread completes its processing. When the specified thread exits, the value supplied in its exit call is returned in the destination specified by the caller–if a non- NULL exit value destination pointer is provided. */
  /* Callable from (extract):
   * This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
   */
  /* Return codes / errno notes (extract):
   * MPX_SUCCESS (0)	Successful thread join.
   */

  /* Phase 0 (plumbing): call API and skip if stubbed */
  errno = 0;
  (void)pthread_join(0, 0);
  if (mpx_skip_if_stubbed("pthread_join")) return 0;

  /* Phase 1 (contract hardening): implement the exact checks per User Manual.
   * Required structure:
   * 1) Parameter validation: invalid args -> expected return + errno
   * 2) State-dependent errors: invalid lifecycle/state -> expected return + errno
   * 3) Success path: expected return, errno unchanged
   * 4) Optional: concurrency/preemption behavior (domain integration tests)
   */

  /* TODO: Add normative assertions here. */
  MPX_EXPECT_TRUE(1);
  printf("PASS (contract TBD): pthread_join\n");
  return 0;
}
