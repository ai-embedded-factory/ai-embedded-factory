#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include "../../../src/stub/mpx_stub.h"

/* Auto-generated smoke tests for family: sem */

int main(void) {
  int failures = 0;
  errno = 0;
  (void)sem_destroy(0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0175 */
  errno = 0;
  (void)sem_init(0, 0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0176 */
  errno = 0;
  (void)sem_post(0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0177 */
  errno = 0;
  (void)sem_trywait(0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0178 */
  errno = 0;
  (void)sem_wait(0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0179 */
  if (failures != 0) { printf("FAIL %d\n", failures); return 1; }
  printf("OK\n");
  return 0;
}
