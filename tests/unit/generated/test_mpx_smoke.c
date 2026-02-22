#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include "../../../src/stub/mpx_stub.h"

/* Auto-generated smoke tests for family: mpx */

int main(void) {
  int failures = 0;
  errno = 0;
  (void)mpx_mq_extend_open_check_params(0, 0, 0, 0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0091 */
  errno = 0;
  (void)mpx_mq_extendattr_destroy(0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0092 */
  errno = 0;
  (void)mpx_mq_extendattr_getcontroladdr(0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0093 */
  errno = 0;
  (void)mpx_mq_extendattr_getcontrolsize(0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0094 */
  errno = 0;
  (void)mpx_mq_extendattr_getqueueaddr(0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0095 */
  errno = 0;
  (void)mpx_mq_extendattr_getqueuesize(0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0096 */
  errno = 0;
  (void)mpx_mq_extendattr_init(0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0097 */
  errno = 0;
  (void)mpx_mq_extendattr_setcontroladdr(0, 0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0098 */
  errno = 0;
  (void)mpx_mq_extendattr_setqueueaddr(0, 0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0099 */
  errno = 0;
  (void)mpx_sem_timedwait(0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0119 */
  if (failures != 0) { printf("FAIL %d\n", failures); return 1; }
  printf("OK\n");
  return 0;
}
