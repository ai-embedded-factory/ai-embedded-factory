#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include "../../../src/stub/mpx_stub.h"

/* Auto-generated smoke tests for family: mpx_pthread */

int main(void) {
  int failures = 0;
  errno = 0;
  (void)mpx_pthread_attr_getcontroladdr(0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0100 */
  errno = 0;
  (void)mpx_pthread_condattr_getcontrolsize(0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0101 */
  errno = 0;
  (void)mpx_pthread_event_flags_clear(0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0102 */
  errno = 0;
  (void)mpx_pthread_fastqueue_create(0, 0, 0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0103 */
  errno = 0;
  (void)mpx_pthread_fastqueueattr_getname(0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0104 */
  errno = 0;
  (void)mpx_pthread_memory_manager_enable();
  if (errno != ENOSYS) { failures++; } /* TST-API-0105 */
  errno = 0;
  (void)mpx_pthread_memorypool_free(0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0106 */
  errno = 0;
  (void)mpx_pthread_memorypoolattr_setname(0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0107 */
  errno = 0;
  (void)mpx_pthread_mutexattr_getcontrolsize(0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0108 */
  errno = 0;
  (void)mpx_pthread_partitionpool_allocate(0, 0, 0);
  if (errno != ENOSYS) { failures++; } /* TST-API-0109 */
  if (failures != 0) { printf("FAIL %d\n", failures); return 1; }
  printf("OK\n");
  return 0;
}
