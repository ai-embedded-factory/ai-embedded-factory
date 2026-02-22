#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include "../../../src/stub/mpx_stub.h"

/* Auto-generated smoke tests for family: pthread */

int main(void) {
  int failures = 0;
  errno = 0;
  (void)pthread_attr_getdetachstate(0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0132 */
  errno = 0;
  (void)pthread_attr_getstackaddr(0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0133 */
  errno = 0;
  (void)pthread_attr_getstacksize(0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0134 */
  errno = 0;
  (void)pthread_attr_init(0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0135 */
  errno = 0;
  (void)pthread_attr_setdetachstate(0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0136 */
  errno = 0;
  (void)pthread_attr_setstackaddr(0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0137 */
  errno = 0;
  (void)pthread_attr_setstacksize(0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0138 */
  errno = 0;
  (void)pthread_cancel(0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0139 */
  errno = 0;
  (void)pthread_cleanup_pop(0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0140 */
  errno = 0;
  (void)pthread_cleanup_push(0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0141 */
  if (failures != 0) { printf("FAIL %d\n", failures); return 1; }
  printf("OK\n");
  return 0;
}
