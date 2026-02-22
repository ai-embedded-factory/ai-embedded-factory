#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include "../../../src/stub/mpx_stub.h"

/* Auto-generated smoke tests for family: clock */

int main(void) {
  int failures = 0;
  errno = 0;
  (void)clock_getres(0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0085 */
  errno = 0;
  (void)clock_gettime(0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0086 */
  errno = 0;
  (void)clock_settime(0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0087 */
  if (failures != 0) { printf("FAIL %d\n", failures); return 1; }
  printf("OK\n");
  return 0;
}
