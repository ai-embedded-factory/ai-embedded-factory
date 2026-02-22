#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include "../../../src/stub/mpx_stub.h"

/* Auto-generated smoke tests for family: mq */

int main(void) {
  int failures = 0;
  errno = 0;
  (void)mq_close(0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0122 */
  errno = 0;
  (void)mq_getattr(0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0123 */
  errno = 0;
  (void)mq_open(0, 0, 0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0124 */
  errno = 0;
  (void)mq_receive(0, 0, 0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0125 */
  errno = 0;
  (void)mq_send(0, 0, 0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0126 */
  errno = 0;
  (void)mq_setattr(0, 0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0127 */
  errno = 0;
  (void)mq_timedreceive(0, 0, 0, 0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0128 */
  errno = 0;
  (void)mq_timedsend(0, 0, 0, 0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0129 */
  if (failures != 0) { printf("FAIL %d\n", failures); return 1; }
  printf("OK\n");
  return 0;
}
