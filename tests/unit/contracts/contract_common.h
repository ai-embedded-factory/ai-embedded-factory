#pragma once
#include <errno.h>
#include <stdio.h>

/* While the implementation is stubbed, tests SKIP if errno==ENOSYS. */
static inline int mpx_skip_if_stubbed(const char *api_name) {
  if (errno == ENOSYS) {
    printf("SKIP (stubbed): %s\n", api_name);
    return 1;
  }
  return 0;
}

/* Placeholder assertion helpers (to be hardened per API contract). */
#define MPX_EXPECT_TRUE(expr) do { if (!(expr)) { printf("ASSERT FAIL: %s:%d\n", __FILE__, __LINE__); return 1; } } while(0)
