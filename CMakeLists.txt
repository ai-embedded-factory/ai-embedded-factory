cmake_minimum_required(VERSION 3.16)
project(mpx_rtos_clone_testskeleton C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(mpx_stub src/stub/mpx_stub.c)
target_include_directories(mpx_stub PUBLIC src/stub)

enable_testing()

add_executable(test__smoke tests/unit/generated/test__smoke.c)
target_link_libraries(test__smoke PRIVATE mpx_stub)
add_test(NAME test__smoke COMMAND test__smoke)

add_executable(test_astqueue_smoke tests/unit/generated/test_astqueue_smoke.c)
target_link_libraries(test_astqueue_smoke PRIVATE mpx_stub)
add_test(NAME test_astqueue_smoke COMMAND test_astqueue_smoke)

add_executable(test_clock_smoke tests/unit/generated/test_clock_smoke.c)
target_link_libraries(test_clock_smoke PRIVATE mpx_stub)
add_test(NAME test_clock_smoke COMMAND test_clock_smoke)

add_executable(test_d_smoke tests/unit/generated/test_d_smoke.c)
target_link_libraries(test_d_smoke PRIVATE mpx_stub)
add_test(NAME test_d_smoke COMMAND test_d_smoke)

add_executable(test_erattr_smoke tests/unit/generated/test_erattr_smoke.c)
target_link_libraries(test_erattr_smoke PRIVATE mpx_stub)
add_test(NAME test_erattr_smoke COMMAND test_erattr_smoke)

add_executable(test_laddr_smoke tests/unit/generated/test_laddr_smoke.c)
target_link_libraries(test_laddr_smoke PRIVATE mpx_stub)
add_test(NAME test_laddr_smoke COMMAND test_laddr_smoke)

add_executable(test_mpx_smoke tests/unit/generated/test_mpx_smoke.c)
target_link_libraries(test_mpx_smoke PRIVATE mpx_stub)
add_test(NAME test_mpx_smoke COMMAND test_mpx_smoke)

add_executable(test_mpx_pthread_smoke tests/unit/generated/test_mpx_pthread_smoke.c)
target_link_libraries(test_mpx_pthread_smoke PRIVATE mpx_stub)
add_test(NAME test_mpx_pthread_smoke COMMAND test_mpx_pthread_smoke)

add_executable(test_mq_smoke tests/unit/generated/test_mq_smoke.c)
target_link_libraries(test_mq_smoke PRIVATE mpx_stub)
add_test(NAME test_mq_smoke COMMAND test_mq_smoke)

add_executable(test_nanosleep_smoke tests/unit/generated/test_nanosleep_smoke.c)
target_link_libraries(test_nanosleep_smoke PRIVATE mpx_stub)
add_test(NAME test_nanosleep_smoke COMMAND test_nanosleep_smoke)

add_executable(test_ontroladdr_smoke tests/unit/generated/test_ontroladdr_smoke.c)
target_link_libraries(test_ontroladdr_smoke PRIVATE mpx_stub)
add_test(NAME test_ontroladdr_smoke COMMAND test_ontroladdr_smoke)

add_executable(test_pthread_smoke tests/unit/generated/test_pthread_smoke.c)
target_link_libraries(test_pthread_smoke PRIVATE mpx_stub)
add_test(NAME test_pthread_smoke COMMAND test_pthread_smoke)

add_executable(test_sched_smoke tests/unit/generated/test_sched_smoke.c)
target_link_libraries(test_sched_smoke PRIVATE mpx_stub)
add_test(NAME test_sched_smoke COMMAND test_sched_smoke)

add_executable(test_sem_smoke tests/unit/generated/test_sem_smoke.c)
target_link_libraries(test_sem_smoke PRIVATE mpx_stub)
add_test(NAME test_sem_smoke COMMAND test_sem_smoke)

add_executable(test_sleep_smoke tests/unit/generated/test_sleep_smoke.c)
target_link_libraries(test_sleep_smoke PRIVATE mpx_stub)
add_test(NAME test_sleep_smoke COMMAND test_sleep_smoke)

add_executable(test_time_smoke tests/unit/generated/test_time_smoke.c)
target_link_libraries(test_time_smoke PRIVATE mpx_stub)
add_test(NAME test_time_smoke COMMAND test_time_smoke)

add_executable(test_usleep_smoke tests/unit/generated/test_usleep_smoke.c)
target_link_libraries(test_usleep_smoke PRIVATE mpx_stub)
add_test(NAME test_usleep_smoke COMMAND test_usleep_smoke)

