#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include "../../../src/stub/mpx_stub.h"

/* Auto-generated smoke tests for family:  */

int main(void) {
  int failures = 0;
  errno = 0;
  (void)_mq_extend_open(0, 0, 0, 0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0001 */
  errno = 0;
  (void)_pthread_attr_getcontrolsize(0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0002 */
  errno = 0;
  (void)_pthread_attr_getname(0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0003 */
  errno = 0;
  (void)_pthread_attr_getpriority(0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0004 */
  errno = 0;
  (void)_pthread_attr_gettimeslice(0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0005 */
  errno = 0;
  (void)_pthread_attr_setcontroladdr(0, 0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0006 */
  errno = 0;
  (void)_pthread_attr_setname(0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0007 */
  errno = 0;
  (void)_pthread_attr_setpriority(0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0008 */
  errno = 0;
  (void)_pthread_attr_settimeslice(0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0009 */
  errno = 0;
  (void)_pthread_condattr_getcontroladdr(0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0010 */
  if (failures != 0) { printf("FAIL %d\n", failures); return 1; }
  printf("OK\n");
  return 0;
}
