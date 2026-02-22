#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include "../../../src/stub/mpx_stub.h"

/* Auto-generated smoke tests for family: nanosleep */

int main(void) {
  int failures = 0;
  errno = 0;
  (void)nanosleep(0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0130 */
  if (failures != 0) { printf("FAIL %d\n", failures); return 1; }
  printf("OK\n");
  return 0;
}
