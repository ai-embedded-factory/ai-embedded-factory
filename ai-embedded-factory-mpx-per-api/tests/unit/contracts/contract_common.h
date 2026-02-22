#pragma once
#include <errno.h>
#include <stdio.h>
#include <string.h>

/* While the implementation is stubbed, tests SKIP if errno==ENOSYS. */
static inline int mpx_skip_if_stubbed(const char *api_name) {
  if (errno == ENOSYS) {
    printf("SKIP (stubbed): %s\n", api_name);
    return 1;
  }
  return 0;
}

#define MPX_EXPECT_TRUE(expr) do { if (!(expr)) { printf("ASSERT FAIL: %s:%d\n", __FILE__, __LINE__); return 1; } } while(0)

typedef int (*mpx_subtest_fn)(void);

static inline int mpx_run_subtest(const char *name, mpx_subtest_fn fn) {
  int rc = fn();
  if (rc == 0) {
    printf("  PASS: %s\n", name);
  } else {
    printf("  FAIL: %s\n", name);
  }
  return rc;
}

/* Placeholder for contract parts that are not yet fully specified. */
static inline int mpx_tbd(const char *what) {
  printf("  TBD: %s\n", what);
  return 0; /* do not fail during scaffolding phase */
}
