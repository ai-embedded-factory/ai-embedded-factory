# MPX RTOS API Catalog (Updated)

This catalog is derived strictly from the provided sources.

## API Surface (Reference Card — Updated)
- `mqd_t mpx _mq_extend_open(const char * queue_name, int operation, mode_t mode, struct mq_attr * queue_attributes, mq_extendattr_t * extend_attributes);`
- `int mpx _pthread_attr_getcontrolsize(pthread_attr_t * thread_attributes, size_t * thread_control_size);`
- `int mpx _pthread_attr_getname(pthread_attr_t * thread_attributes, char ** name);`
- `int mpx _pthread_attr_getpriority(pthread_attr_t * thread_attributes, int * priority);`
- `int mpx _pthread_attr_gettimeslice(pthread_attr_t * thread_attributes, u_long * thread_time_slice);`
- `int mpx _pthread_attr_setcontroladdr(pthread_attr_t * thread_attributes, void * thread_control_address, size_t thread_control_size);`
- `int mpx _pthread_attr_setname(pthread_attr_t * thread_attributes, char * name);`
- `int mpx _pthread_attr_setpriority(pthread_attr_t * thread_attributes, int priority);`
- `int mpx _pthread_attr_settimeslice(pthread_attr_t * thread_attributes, u_long thread_time_slice);`
- `int mpx _pthread_condattr_getcontroladdr(pthread_condattr_t * condition_var_attributes, void ** condition_var_control_address);`
- `int mpx _pthread_condattr_getname(pthread_condattr_t * condition_var_attributes, char ** name);`
- `int mpx _pthread_condattr_setcontroladdr(pthread_condattr_t * condition_var_attributes, void * condition_var_control_address, size_t condition_var_control_size);`
- `int mpx _pthread_condattr_setname(pthread_condattr_t * condition_var_attributes, char * name);`
- `int mpx _pthread_event_flags_create(pthread_event_flags_t * event_flags_handle, pthread_event_flagsattr_t * event_flags_attributes);`
- `int mpx _pthread_event_flags_destroy(pthread_event_flags_t * event_flags_handle);`
- `int mpx _pthread_event_flags_set(pthread_event_flags_t * event_flags_handle, u_long events_to_set);`
- `int mpx _pthread_event_flags_timedwait(pthread_event_flags_t * event_flags_handle, u_long requested_events, int all_or_any, u_long * received_events, tick_t timeout_ticks);`
- `int mpx _pthread_event_flags_trywait(pthread_event_flags_t * event_flags_handle, u_long requested_events, int all_or_any, u_long * received_events);`
- `int mpx _pthread_event_flags_wait(pthread_event_flags_t * event_flags_handle, u_long requested_events, int all_or_any, u_long * received_events);`
- `int mpx _pthread_event_flagsattr_destroy(pthread_event_flagsattr_t * event_flags_attributes);`
- `int mpx _pthread_event_flagsattr_getcontrolsize(pthread_event_flagsattr_t * event_flags_attributes, size_t * event_flags_control_size);`
- `int mpx _pthread_event_flagsattr_getname(pthread_event_flagsattr_t * event_flags_attributes, char ** name);`
- `int mpx _pthread_event_flagsattr_init(pthread_event_flagsattr_t * event_flags_attributes);`
- `int mpx _pthread_event_flagsattr_setcontroladdr(pthread_event_flagsattr_t * event_flags_attributes, void * event_flags_control_address, size_t event_flags_control_size);`
- `int mpx _pthread_event_flagsattr_setname(pthread_event_flagsattr_t * event_flags_attributes, char * name);`
- `int mpx _pthread_fastqueue_destroy(pthread_fastqueue_t * fastqueue_handle);`
- `int mpx _pthread_fastqueue_receive(pthread_fastqueue_t * fastqueue_handle, u_long * message_destination, size_t message_size);`
- `int mpx _pthread_fastqueue_send(pthread_fastqueue_t * fastqueue_handle, u_long * message_source, size_t message_size);`
- `int mpx _pthread_fastqueue_timedsend(pthread_fastqueue_t * fastqueue_handle, u_long * message_source, size_t message_size, tick_t timeout_ticks);`
- `int mpx _pthread_fastqueue_tryreceive(pthread_fastqueue_t * fastqueue_handle, u_long * message_destination, size_t message_size);`
- `int mpx _pthread_fastqueue_trysend(pthread_fastqueue_t * fastqueue_handle, u_long * message_source, size_t message_size);`
- `int mpx _pthread_fastqueueattr_destroy(pthread_fastqueueattr_t * fastqueue_attributes);`
- `int mpx _pthread_fastqueueattr_getcontroladdr(pthread_fastqueueattr_t * fastqueue_attributes, void ** fastqueue_control_address);`
- `int mpx _pthread_fastqueueattr_getcontrolsize(pthread_fastqueueattr_t * fastqueue_attributes, size_t * fastqueue_control_size);`
- `int mpx _pthread_fastqueueattr_getqueueaddr(pthread_fastqueueattr_t* fastqueue_attributes, void ** fastqueue_memory_address);`
- `int mpx _pthread_fastqueueattr_getqueuesize(pthread_fastqueueattr_t* fastqueue_attributes, size_t * fastqueue_memory_size);`
- `int mpx _pthread_fastqueueattr_init(pthread_fastqueueattr_t * fastqueue_attributes);`
- `int mpx _pthread_fastqueueattr_setcontroladdr(pthread_fastqueueattr_t * fastqueue_attributes, void * fastqueue_control_address, size_t fastqueue_control_size);`
- `int mpx _pthread_fastqueueattr_setname(pthread_fastqueueattr_t * fastqueue_attributes, char * fastqueue_name);`
- `int mpx _pthread_fastqueueattr_setqueueaddr(pthread_fastqueueattr_t* fastqueue_attributes, void * fastqueue_memory_address, size_t fastqueue_memory_size);`
- `int mpx _pthread_information_get(pthread_t thread_handle, char ** name, int * state, int * priority, void ** stack_limit, void ** stack_pointer, u_long * minimum_stack, pthread_t * next_thread);`
- `int mpx _pthread_memory_manager_get(void * (** memory_allocate_pointer)(u_int type, u_long size), void (** memory_release_pointer)(u_int type, void *memory_to_release));`
- `int mpx _pthread_memory_manager_set(void * (* memory_allocate_pointer)(u_int type, u_long size), void (* memory_release_pointer)(u_int type, void *memory_to_release));`
- `int mpx _pthread_memorypool_allocate(pthread_memorypool_t * memorypool_handle, void ** allocated_memory, size_t request_size);`
- `int mpx _pthread_memorypool_create(pthread_memorypool_t * memorypool_handle, pthread_memorypoolattr_t * memorypool_attributes, void * pool_start, size_t pool_size);`
- `int mpx _pthread_memorypool_destroy(pthread_memorypool_t * memorypool_handle);`
- `int mpx _pthread_memorypool_timedallocate(pthread_memorypool_t * memorypool_handle, void ** allocated_memory, size_t request_size, tick_t timeout_ticks);`
- `int mpx _pthread_memorypool_tryallocate(pthread_memorypool_t * memorypool_handle, void ** allocated_memory, size_t request_size);`
- `int mpx _pthread_memorypoolattr_destroy(pthread_memorypoolattr_t * memorypool_attributes);`
- `int mpx _pthread_memorypoolattr_getcontroladdr(pthread_memorypoolattr_t * memorypool_attributes, void ** memorypool_control_address);`
- `int mpx _pthread_memorypoolattr_getname(pthread_memorypoolattr_t * memorypool_attributes, char ** name);`
- `int mpx _pthread_memorypoolattr_init(pthread_memorypoolattr_t * memorypool_attributes);`
- `int mpx _pthread_memorypoolattr_setcontroladdr(pthread_memorypoolattr_t * memorypool_attributes, void * memorypool_control_address, size_t memorypool_control_size);`
- `int mpx _pthread_mutexattr_getcontroladdr(pthread_mutexattr_t * mutex_attributes, void ** mutex_control_address);`
- `int mpx _pthread_mutexattr_getname(pthread_mutexattr_t * mutex_attributes, char ** name);`
- `int mpx _pthread_mutexattr_setcontroladdr(pthread_mutexattr_t * mutex_attributes, void * mutex_control_address, size_t mutex_control_size);`
- `int mpx _pthread_mutexattr_setname(pthread_mutexattr_t * mutex_attributes, char * name);`
- `int mpx _pthread_partitionpool_create(pthread_partitionpool_t * partitionpool_handle, pthread_partitionpoolattr_t * partitionpool_attributes, void * pool_start, size_t pool_size, size_t partition_size);`
- `int mpx _pthread_partitionpool_destroy(pthread_partitionpool_t * partitionpool_handle);`
- `int mpx _pthread_partitionpool_timedallocate(pthread_partitionpool_t * partitionpool_handle, void ** allocated_memory, size_t request_size, tick_t timeout_ticks);`
- `int mpx _pthread_partitionpool_tryallocate(pthread_partitionpool_t * partitionpool_handle, void ** allocated_memory, size_t request_size);`
- `int mpx _pthread_partitionpoolattr_destroy(pthread_partitionpoolattr_t * partitionpool_attributes);`
- `int mpx _pthread_partitionpoolattr_getcontroladdr(pthread_partitionpoolattr_t * partitionpool_attributes, void ** partitionpool_control_address);`
- `int mpx _pthread_partitionpoolattr_getcontrolsize(pthread_partitionpoolattr_t * partitionpool_attributes, size_t * partitionpool_control_size);`
- `int mpx _pthread_partitionpoolattr_getname(pthread_partitionpoolattr_t * partitionpool_attributes, char ** name);`
- `int mpx _pthread_partitionpoolattr_init(pthread_partitionpoolattr_t * partitionpool_attributes);`
- `int mpx _pthread_partitionpoolattr_setcontroladdr(pthread_partitionpoolattr_t * partitionpool_attributes, void * partitionpool_control_address, size_t partitionpool_control_size);`
- `int mpx _pthread_partitionpoolattr_setname(pthread_partitionpoolattr_t * partitionpool_attributes, char * name);`
- `int mpx _pthread_priority_change(pthread_t thread_handle, int new_priority, int * old_priority);`
- `int mpx _pthread_stack_check(pthread_t thread_handle, u_long * minimum_available_stack);`
- `int mpx _pthread_start(u_long run_time_id, void * memory_start, u_long memory_size);`
- `int mpx _pthread_ticktimer_create(pthread_ticktimer_t *ticktimer_handle, pthread_ticktimerattr_t * attributes, void (*expiration_routine)(pthread_ticktimer_t *, void *), void *argument, tick_t initial_ticks, tick_t reload_ticks);`
- `int mpx _pthread_ticktimerattr_destroy(pthread_ticktimerattr_t *ticktimer_attributes);`
- `int mpx _pthread_ticktimerattr_getcontroladdr(pthread_ticktimerattr_t * ticktimer_attributes, void ** ticktimer_control_address);`
- `int mpx _pthread_ticktimerattr_getcontrolsize(pthread_ticktimerattr_t * ticktimer_attributes, size_t * ticktimer_control_size);`
- `int mpx _pthread_ticktimerattr_getname(pthread_ticktimerattr_t * ticktimer_attributes, char ** name);`
- `int mpx _pthread_ticktimerattr_setcontroladdr(pthread_ticktimerattr_t * ticktimer_attributes, void * ticktimer_control_address, size_t ticktimer_control_size);`
- `int mpx _pthread_ticktimerattr_setname(pthread_ticktimerattr_t * ticktimer_attributes, char * name);`
- `int mpx _sem_extend_init(sem_t * semaphore_handle, int pshared, unsigned int value, semattr_t * semaphore_attributes);`
- `int mpx _semattr_getcontrolsize(semattr_t *semaphore_attributes, size_t * semaphore_control_size);`
- `int mpx _semattr_getname(semattr_t *semaphore_attributes, char ** semaphore_name);`
- `int mpx _semattr_init(semattr_t *semaphore_attributes);`
- `int mpx _semattr_setcontroladdr(semattr_t *semaphore_attributes, void * semaphore_control_address, size_t semaphore_control_size);`
- `int mpx_pthread_f astqueue_timedreceive(pthread_fastqueue_t * fastqueue_handle, u_long * message_destination, size_t message_size, tick_t timeout_ticks);`
- `int clock_getres(clockid_t clock_id, struct mpx_timespec *resolution);`
- `int clock_gettime(clockid_t clock_id, struct mpx_timespec *current_time);`
- `int clock_settime(clockid_t clock_id, struct mpx_timespec *new_time);`
- `int mpx_pthrea d_memorypoolattr_getcontrolsize(pthread_memorypoolattr_t * memorypool_attributes, size_t * memorypool_control_size);`
- `int mpx_pthread_ticktim erattr_init(pthread_ticktimerattr_t *ticktimer_attributes);`
- `int mpx_semattr_getcontro laddr(semattr_t *semaphore_attributes, void ** semaphore_control_address);`
- `mqd_t mpx_mq_extend_open_check_params(const char * queue_name, int operation, mode_t mode, struct mq_attr * queue_attributes, mq_extendattr_t * extend_attributes);`
- `int mpx_mq_extendattr_destroy(mq_extendattr_t * queue_attributes);`
- `int mpx_mq_extendattr_getcontroladdr(mq_extendattr_t * queue_attributes, void ** queue_control_address);`
- `int mpx_mq_extendattr_getcontrolsize(mq_extendattr_t * queue_attributes, size_t * queue_control_size);`
- `int mpx_mq_extendattr_getqueueaddr(mq_extendattr_t * queue_attributes, void ** queue_memory_address);`
- `int mpx_mq_extendattr_getqueuesize(mq_extendattr_t * queue_attributes, size_t * queue_memory_size);`
- `int mpx_mq_extendattr_init(mq_extendattr_t * queue_attributes);`
- `int mpx_mq_extendattr_setcontroladdr(mq_extendattr_t * queue_attributes, void * queue_control_address, size_t queue_control_size);`
- `int mpx_mq_extendattr_setqueueaddr(mq_extendattr_t * queue_attributes, void * queue_memory_address, size_t queue_memory_size);`
- `int mpx_pthread_attr_getcontroladdr(pthread_a ttr_t * thread_attributes, void ** thread_control_address);`
- `int mpx_pthread_condattr_getcontrolsize(pthre ad_condattr_t * condition_var_attributes, size_t * condition_var_control_size);`
- `int mpx_pthread_event_flags_clear(pthread_event_flags_t * event_flags_handle);`
- `int mpx_pthread_fastqueue_create(pthread_fastqueue_t *fastqueue_handle, pthread_fastqueueattr_t * fastqueue_attributes, size_t message_size, int max_messages);`
- `int mpx_pthread_fastqueueattr_getname(pthread_fastqueue attr_t * fastqueue_attributes, char ** fastqueue_name);`
- `int mpx_pthread_memory_manager_enable(void);`
- `int mpx_pthread_memorypool_free(void * allocated_memory);`
- `int mpx_pthread_memorypoolattr_setname(p thread_memorypoolattr_t * memorypool_attributes, char * name);`
- `int mpx_pthread_mutexattr_getcontrolsize(pthread_mutex attr_t * mutex_attributes, size_t * mutex_control_size);`
- `int mpx_pthread_partitionpool_allocate(pthread_partitionpool_t * partitionpool_handle, void ** allocated_memory, size_t request_size);`
- `int mpx_pthread_partitionpool_free(void * allocated_memory);`
- `int mpx_pthread_resume(pthread_t thread_handle);`
- `int mpx_pthread_suspend(pthread_t thread_handle);`
- `int mpx_pthread_tick_sleep(tick_t ticks_to_sleep);`
- `tick_t mpx_pthread_ticks_get(void);`
- `int mpx_pthread_ticktimer_destroy(pthread_ticktimer_t *ticktimer_handle);`
- `int mpx_pthread_ticktimer_start(pthread_ticktimer_t *ticktimer_handle);`
- `int mpx_pthread_ticktimer_stop(pthread_ticktimer_t *ticktimer_handle);`
- `int mpx_pthread_ticktimer_update(pthread_ticktimer_t *ticktimer_handle , tick_t initial_ticks, tick_t reload_ticks);`
- `int mpx_sem_timedwait(sem_t * semaphore_handle, tick_t timeout_ticks);`
- `int mpx_semattr_destroy(semattr_t *semaphore_attributes);`
- `int mpx_semattr_setname(semattr_t *semaphore_attributes, char * semaphor e_name);`
- `int mq_close(mqd_t message_queue);`
- `int mq_getattr(mqd_t message_queue, struct mq_attr * queue_attributes);`
- `mqd_t mq_open(const char * queue_name, int operation, mode_t mode, struct mq_attr * queue_attributes);`
- `ssize_t mq_receive(mqd_t message_queue, char * message, size_t message_size, unsigned int *message_priority);`
- `int mq_send(mqd_t message_queue, const char * message, size_t message_size, unsigned int message_priority);`
- `int mq_setattr(mqd_t message_queue, const struct mq_attr * queue_attributes, struct mq_attr * previous_attributes);`
- `ssize_t mq_timedreceive(mqd_t message_queue, char * message, size_t message_size, unsigned int * message_priority, const struct mpx _timespec *absolute_timeout);`
- `int mq_timedsend(mqd_t message_queue, const char * message, size_t message_size, unsigned int message_priority, const struct mpx _timespec *absolute_timeout);`
- `int nanosleep(const struct mpx_timespec *request_time, struct mpx_timespec *remaining_time);`
- `int mpx_pthread_event_flagsattr_getc ontroladdr(pthread_event_flagsattr_t * event_flags_attributes, void ** event_flags_control_address);`
- `int pthread_attr_getdetachstate(pthread_attr_t * thread_attributes, int * detach_state);`
- `int pthread_attr_getstackaddr(pthread_attr_t * thread_attributes, void ** stack_address);`
- `int pthread_attr_getstacksize(pthread_attr_t * thread_attributes, size_t * stack_size);`
- `int pthread_attr_init(pthread_attr_t * thread_attributes);`
- `int pthread_attr_setdetachstate(pthread_attr_t * thread_attributes, int detach_state);`
- `int pthread_attr_setstackaddr(pthread_attr_t * thread_attributes, void * stack_address);`
- `int pthread_attr_setstacksize(pthread_attr_t * thread_attributes, size_t stack_size);`
- `int pthread_cancel(pthread_t thread_handle);`
- `void pthread_cleanup_pop(int execute);`
- `void pthread_cleanup_push(void (*cleanup_handler)(void *), void * argument);`
- `int pthread_cond_broadcast(pthread_cond_t * condition_var_handle);`
- `int pthread_cond_destroy(pthread_cond_t * condition_var_handle);`
- `int pthread_cond_init(pthread_cond_t * condition_var_handle, pthread_condattr_t * condition_var_attributes);`
- `int pthread_cond_signal(pthread_cond_t * condition_var_handle);`
- `int pthread_cond_timedwait(pthread_cond_t * condition_var_handle, pthread_mutex_t * mutex_handle, const struct mpx_timespec *absolute_time);`
- `int pthread_cond_wait(pthread_cond_t * condition_var_handle, pthread_mutex_t * mutex_handle);`
- `int pthread_condattr_destroy(pthread_condattr_t * condition_var_attributes);`
- `int pthread_condattr_getpshared(pthread_condattr_t * condition_var_attributes, int * process_sharing_designation);`
- `int pthread_condattr_init(pthread_condattr_t * condition_var_attributes);`
- `int pthread_condattr_setpshared(pthread_condattr_t * condition_var_attributes, int process_sharing_designation);`
- `int pthread_create(pthread_t * thread_handle, pthread_attr_t * attr, void *(*start_routine)(void *), void *arg);`
- `int pthread_detach(pthread_t thread_handle);`
- `int pthread_equal(pthread_t first_thread, pthread_t second_thread);`
- `void pthread_exit(void * exit_value);`
- `int pthread_join(pthread_t thread_handle, void ** value_destination);`
- `int pthread_mutex_destroy(pthread_mutex_t * mutex_handle);`
- `int pthread_mutex_init(pthread_mutex_t * mutex_handle, pthread_mutexattr_t * mutex_attributes);`
- `int pthread_mutex_lock(pthread_mutex_t * mutex_handle);`
- `int pthread_mutex_trylock(pthread_mutex_t * mutex_handle);`
- `int pthread_mutex_unlock(pthread_mutex_t * mutex_handle);`
- `int pthread_mutexattr_destroy(pthread_mutexattr_t * mutex_attributes);`
- `int pthread_mutexattr_getprotocol(pthread_mutexattr_t * mutex_attributes, int * protocol);`
- `int pthread_mutexattr_getpshared(pthread_mutexattr_t * mutex_attributes, int * process_sharing_designation);`
- `int pthread_mutexattr_gettype(pthread_mutexattr_t * mutex_attributes, int * type);`
- `int pthread_mutexattr_init(pthread_mutexattr_t * mutex_attributes);`
- `int pthread_mutexattr_setprotocol(pthread_mutexattr_t * mutex_attributes, int protocol);`
- `int pthread_mutexattr_setpshared(pthread_mutexattr_t * mutex_attributes, int process_sharing_designation);`
- `int pthread_mutexattr_settype(pthread_mutexattr_t * mutex_attributes, int type);`
- `pthread_t pthread_self(void);`
- `int pthread_setcancelstate(int new_state, int * old_state);`
- `int pthread_setcanceltype(int new_type, int * old_type);`
- `void pthread_testcancel(void);`
- `int sched_yield(void);`
- `int sem_destroy(sem_t * semaphore_handle);`
- `int sem_init(sem_t * semaphore_handle, int pshared, unsigned int value);`
- `int sem_post(sem_t * semaphore_handle);`
- `int sem_trywait(sem_t * semaphore_handle);`
- `int sem_wait(sem_t * semaphore_handle);`
- `u_int sleep(unsigned int seconds);`
- `time_t time(mpx_time_t *return_seconds);`
- `int usleep(useconds_t microseconds);`

## APIs with User Manual definitions (Chapter 7)

### clock_getres
```c
#include <pthread.h>
int clock_getres(clockid_t clock_id, struct timespec *resolution);
```
- This service returns the current time resolution in resolution, which is effectively the underlying ticktimer periodic interrupt frequency.

### clock_gettime
```c
#include <pthread.h>
int clock_gettime(clockid_t clock_id, struct timespec *current_time);
```
- This service returns the current time in the destination specified by

### clock_settime
```c
#include <pthread.h>
int clock_settime(clockid_t clock_id, struct timespec *new_time);
```
- This service sets the current time to the value specified by new_time.

### mpx_mq_extendattr_destroy
```c
#include <mqueue.h>
int mpx_mq_extendattr_destroy(mq_extendattr_t * queue_attributes);
```
- This pthreadsmore service destroys the previously created extended message queue attributes structure pointed to by queue_attributes. Once destroyed, the extended message queue attributes structure cannot be used again unless it is recreated.

### mpx_mq_extendattr_getcontroladdr
```c
#include <mqueue.h>
int mpx_mq_extendattr_getcontroladdr(mq_extendattr_t* queue_attributes,
void ** queue_control_address);
```
- This pthreadsmore service returns the previously supplied message queue control structure address.

### mpx_mq_extendattr_getcontrolsize
```c
#include <mqueue.h>
int mpx_mq_extendattr_getcontrolsize(mq_extendattr_t* queue_attributes,
size_t * queue_control_size);
```
- This pthreadsmore service returns the size of the internal message queue control structure. The primary purpose of this API is to inform the application how much memory is required for the mpx_mq_extendattr_setcontroladdr API.

### mpx_mq_extendattr_getqueueaddr
```c
#include <mqueue.h>
int mpx_mq_extendattr_getqueueaddr(mq_extendattr_t* queue_attributes,
void ** queue_memory_address);
```
- This pthreadsmore service returns the previously supplied message queue memory address.

### mpx_mq_extendattr_getqueuesize
```c
#include <mqueue.h>
int mpx_mq_extendattr_getqueuesize(mq_extendattr_t* queue_attributes,
size_t * queue_memory_size);
```
- This pthreadsmore service returns the size of the previously supplied message queue memory.

### mpx_mq_extendattr_init
```c
#include <mqueue.h>
int mpx_mq_extendattr_init(mq_extendattr_t * queue_attributes);
```
- This pthreadsmore service initializes the extended message queue attributes structure with default condition variable creation values. Note that the extended message queue attributes are used only by the mpx_mq_extend_open API.

### mpx_mq_extendattr_setcontroladdr
```c
#include <mqueue.h>
int mpx_mq_extendattr_setcontroladdr(mq_extendattr_t* queue_attributes,
void * queue_control_address, size_t queue_memory_size);
```
- This pthreadsmore service enables the developer to provide the memory for the internal MPX RTOS message queue structure as specified by the address in the queue_control_address parameter. This memory will subsequently be used for the next message queue created with this attribute structure. The memory size required for the internal message queue control structure can be found via a call to the mpx_mq_extendattr_getcontrol_size service.

### mpx_mq_extendattr_setqueueaddr
```c
#include <mqueue.h>
int mpx_mq_extendattr_setqueueaddr(mq_extendattr_t* queue_attributes,
void * queue_memory_address, size_t queue_memory_size);
```
- This pthreadsmore service sets the internal message queue memory address to the address specified by queue_memory_address. This address will subsequently be used to supply the memory for the internal message queue memory on the next queue created with this attribute structure.

### mpx_pthread_attr_getcontroladdr
```c
#include <pthread.h>
int mpx_pthread_attr_getcontroladdr(pthread_attr_t *attributes,
void ** thread_control_address);
```
- This pthreadsmore service returns the thread control structure address stored in the thread attributes structure. By default, this value is NULL unless specified by the application via a call to mpx_pthread_attr_setcontroladdr.

### mpx_pthread_condattr_getcontrolsize
```c
#include <pthread.h>
int mpx_pthread_condattr_getcontrolsize(pthread_condattr_t
* condition_var_attributes,
size_t * condition_var_control_size);
```
- This pthreadsmore service returns the size of the internal condition variable control structure. The primary purpose of this API is to inform the application how much memory is required for the mpx_pthread_condattr_setcontroladdr API.

### mpx_pthread_event_flags_clear
```c
#include <pthread.h>
int mpx_pthread_event_flags_clear(pthread_event_flags_t *
event_flags_handle);
```
- This pthreadsmore service clears all event flags in the specified event flags group.

### mpx_pthread_fastqueue_create
```c
#include <pthread.h>
int mpx_pthread_fastqueue_create(pthread_fastqueue_t *fastqueue_handle, pthread_fastqueueattr_t * fast_queue_attributes,
size_t message_size, int max_messages);
```
- This pthreadsmore service initializes (creates) a fastqueue with the optional fast queue attributes. If successful, the fastqueue handle is set up for further use by the application.

### mpx_pthread_fastqueueattr_getname
```c
#include <pthread.h>
int mpx_pthread_fastqueueattr_getname(pthread_fastqueueattr_t
* fastqueue_attributes, char ** fastqueue_name);
```
- This pthreadsmore service returns the previously supplied fastqueue name.

### mpx_pthread_memory_manager_enable
```c
#include <pthread.h>
int mpx_pthread_memory_manager_enable(void);
```
- This pthreadsmore service enables full management of the remaining memory supplied by the application when the MPX RTOS is started via mpx_pthread_start. The memory allocated with all subsequent system object creation and destruction will be fully managed.

### mpx_pthread_memorypool_free
```c
#include <pthread.h>
int mpx_pthread_memorypool_free(void * memory_to_release);
```
- This pthreadsmore service releases the previously allocated memory back to the memory pool it was allocated from. Any threads that are suspended on the memory pool that are waiting for this memory are resumed.

### mpx_pthread_memorypoolattr_setname
```c
#include <pthread.h>
int mpx_pthread_memorypoolattr_setname(pthread_memorypoolattr_t
* memorypool_attributes, char * memorypool_name);
```
- This pthreadsmore service sets the memory pool name in the specified attribute structure.

### mpx_pthread_mutexattr_getcontrolsize
```c
#include <pthread.h>
int mpx_pthread_mutexattr_getcontrolsize(pthread_mutexattr_t
*mutex_attributes, size_t * mutex_control_size);
```
- This pthreadsmore service returns the size of the internal mutex control structure. The primary purpose of this API is to inform the application how much memory is required for the mpx_pthread_mutexattr_setcontroladdr API.

### mpx_pthread_partitionpool_allocate
```c
#include <pthread.h>
int mpx_pthread_partitionpool_allocate(pthread_partitionpool_t *
partitionpool_handle, void ** allocated_memory, size_t request_size);
```
- This pthreadsmore service attempts to allocate a memory partition from the specified partition memory pool. If there is no partition memory in the pool, the calling thread is suspended until the request can be satisfied.

### mpx_pthread_partitionpool_free
```c
#include <pthread.h>
int mpx_pthread_partitionpool_free(void * memory_to_release);
```
- This pthreadsmore service releases the previously allocated partition memory back to the partition memory pool it was allocated from. If a thread is suspended on this partition memory pool, the memory partition is given to the suspended thread, and it is resumed.

### mpx_pthread_resume
```c
#include <pthread.h>
int mpx_pthread_resume(pthread_t thread_handle);
```
- This pthread+ service resumes a previously suspended thread. If the specified thread is not suspended, an error is returned.

### mpx_pthread_suspend
```c
#include <pthread.h>
int mpx_pthread_suspend(pthread_t thread_handle);
```
- This pthread+ service suspends the specified thread. If the specified thread is already suspended, an error is returned.

### mpx_pthread_tick_sleep
```c
#include <pthread.h>
int mpx_pthread_tick_sleep(tick_t ticks_to_sleep);
```
- This pthreadsmore service suspends the calling thread for the number of timer ticks specified by ticks_to_sleep. If a value of 0 ticks is supplied, this service returns immediately, i.e., the calling thread is not suspended.

### mpx_pthread_ticks_get
```c
#include <pthread.h>
tick_t mpx_pthread_ticks_get(void);
```
- This pthreadsmore service returns the internal tick count, representing the number of timer interrupts.

### mpx_pthread_ticktimer_destroy
```c
#include <pthread.h>
int mpx_pthread_ticktimer_destroy(pthread_ticktimer_t
*ticktimer_handle);
```
- This pthreadsmore service destroys a previously created but stopped ticktimer.

### mpx_pthread_ticktimer_start
```c
#include <pthread.h>
int mpx_pthread_ticktimer_start(pthread_ticktimer_t *ticktimer_handle);
```
- This pthreadsmore service starts a previously created ticktimer.

### mpx_pthread_ticktimer_stop
```c
#include <pthread.h>
int mpx_pthread_ticktimer_stop(pthread_ticktimer_t *ticktimer_handle);
```
- This pthreadsmore service stops a previously created ticktimer. When stopped, the remaining number of ticks before expiration is saved. If the ticktimer is restarted, it is restarted with the previous remaining number of ticks.

### mpx_pthread_ticktimer_update
```c
#include <pthread.h>
int mpx_pthread_ticktimer_update(pthread_ticktimer_t *ticktimer_handle,
tick_t initial_ticks, tick_t reload_ticks);
```
- This pthreadsmore service updates the initial ticks and reload ticks of a previously created but stopped ticktimer.

### mpx_semattr_destroy
```c
#include <semaphore.h>
int mpx_semattr_destroy(semttr_t * semaphore_attributes);
```
- This pthreadsmore service destroys the previously created semaphore attributes structure pointed to by semaphore_attributes. Once destroyed, the semaphore attributes structure cannot be used again unless recreated.

### mpx_semattr_setname
```c
#include <semaphore.h>
int mpx_semattr_setname(semattr_t * semaphore_attributes,
char * semaphore_name);
```
- This pthreadsmore service sets the semaphore name in the specified attribute structure.

### mq_close
```c
#include <mqueue.h>
int mq_close(mqd_t message_queue);
```
- This service closes and destroys the specified message queue. An error is returned if any threads are suspended on the message queue.

### mq_getattr
```c
#include <mqueue.h>
int mq_getattr(mqd_t message_queue, struct mq_attr* queue_attributes);
```
- This service retrieves the current attributes of the specified message queue.

### mq_open
```c
#include <mqueue.h>
mqd_t mq_open(const char * queue_name, int operation, mode_t mode,
mq_attr * queue_attributes);
```
- If successful, this service opens (creates) the message queue specified and returns the message queue handle.

### mq_receive
```c
#include <mqueue.h>
int mq_receive(mqd_t message_queue, char * message,
size_t message_size, unsigned int * message_priority);
```
- This service receives the oldest message with the highest priority from the specified message queue. If the queue is empty and the O_NONBLOCK attribute is not set, the calling thread will suspend waiting for a message to arrive. If multiple threads are waiting on an empty queue, the first thread waiting is given the message.

### mq_send
```c
#include <mqueue.h>
int mq_send(mqd_t message_queue, char * message,
size_t message_size, unsigned int message_priority);
```
- This service sends the message to the specified message queue. If the queue is full and the O_NONBLOCK attribute is not set, the calling thread will suspend waiting for room in the queue.

### mq_setattr
```c
#include <mqueue.h>
int mq_setattr(mqd_t message_queue, struct mq_attr * new_attributes,
struct mq_attr * previous_attributes);
```
- This service sets the attributes of the specified message queue. If the previous_attributes pointer is non-NULL, the attributes prior to this service are returned.

### mq_timedreceive
```c
#include <pthread.h> #include <mqueue.h>
int mq_timedreceive(mqd_t message_queue, char * message,
size_t message_size, unsigned int * message_priority, const struct timespec absolute_timeout);
```
- This service receives the highest priority message from the specified message queue. If the queue is empty and the O_NONBLOCK attribute is not set, the calling thread will suspend waiting for a message to arrive. If the timeout is exceeded before a message arrives, the thread is resumed with an error.

### mq_timedsend
```c
#include <mqueue.h>
int mq_timedsend(mqd_t message_queue, char * message,
size_t message_size, unsigned int message_priority, const struct timespec absolute_timeout);
```
- This service sends the message to the specified message queue. If the queue is full and the O_NONBLOCK attribute is not set, the calling thread will suspend waiting for room in the queue. If the timeout is exceeded before room for the message is available in the queue, the thread is resumed with an error.

### nanosleep
```c
#include <pthread.h>
int nanosleep(struct timespec *request_time,
struct timespec *remainng_time);
```
- This service causes the calling thread to suspend for the time specified in request_time. If an unmasked signal is sent to the thread while sleeping, the thread is resumed, and the remaining time is returned in remaining_time.

### pthread_attr_getdetachstate
```c
#include <pthread.h>
int pthread_attr_getdetachstate(pthread_attr_t *attributes,
int * detach_state);
```
- This service returns the detach state stored in the thread attributes structure. Valid detach states are PTHREAD_CREATE_JOINABLE (default) and PTHREAD_CREATE_DETACHED.

### pthread_attr_getstackaddr
```c
#include <pthread.h>
int pthread_attr_getstackaddr(pthread_attr_t *attributes,
void ** stack_address);
```
- This service returns the stack address stored in the thread attributes structure. By default, this value is NULL unless specified by the application via a call to pthread_attr_setstackaddr.

### pthread_attr_getstacksize
```c
#include <pthread.h>
int pthread_attr_getstacksize(pthread_attr_t *attributes,
size_t *	stack_size);
```
- This service returns the current stack size stored in the thread attributes structure. By default, this value is MPX_DEFAULT_STACK_SIZE unless specified by the application via a call to pthread_attr_setstacksize.

### pthread_attr_init
```c
#include <pthread.h>
int pthread_attr_init(pthread_attr_t *attributes);
```
- This service initializes the attributes structure with default thread creation values. These defaults are as follows:

### pthread_attr_setdetachstate
```c
#include <pthread.h>
int pthread_attr_setdetachstate(pthread_attr_t *attributes,
int	new_detach_state);
```
- This service sets the detach state specified by new_detach_state in the thread attributes structure. Valid detach states are PTHREAD_CREATE_JOINABLE and PTHREAD_CREATE_DETACHED.

### pthread_attr_setstackaddr
```c
#include <pthread.h>
int pthread_attr_setstackaddr(pthread_attr_t *attributes,
void *	stack_address);
```
- This service sets the stack address to the value specified by stack_address. The stack address must be at least PTHREAD_STACK_MIN number of bytes.

### pthread_attr_setstacksize
```c
#include <pthread.h>
int pthread_attr_setstacksize(pthread_attr_t *attributes,
size_t	stack_size);
```
- This service sets the specified stack size in the thread attributes structure. The stack address must be at least PTHREAD_STACK_MIN number of bytes.

### pthread_cancel
```c
#include <pthread.h>
int pthread_cancel(pthread_t thread_handle);
```
- This service cancels the specified thread. If the specified thread has cancellation disabled or deferred, this service marks the thread for cancellation at a later point determined by the thread itself. Otherwise, if the specified thread has asynchronous cancellation enabled, it is immediately canceled (terminated) by this service.

### pthread_cleanup_pop
```c
#include <pthread.h>
void pthread_cleanup_pop(int execute);
```
- This service pops the most recently pushed cleanup handler from the thread’s cleanup handler stack. If the specified execute parameter is non-zero and the cleanup handler function pointer is non-NULL, the cleanup handler is executed before returning to the caller.

### pthread_cleanup_push
```c
#include <pthread.h>
void pthread_cleanup_push(void (*cleanup_handler)(void *),
void *argument);
```
- This service pushes the specified cleanup_handler on the calling thread’s cleanup handler stack.

### pthread_cond_broadcast
```c
#include <pthread.h>
int pthread_cond_broadcast(pthread_cond_t * condition_var_handle);
```
- This service resumes all threads currently waiting on this condition variable.

### pthread_cond_destroy
```c
#include <pthread.h>
int pthread_cond_destroy(pthread_cond_t * condition_var_handle);
```
- This service destroys the previously created condition variable specified by condition_var_handle. If the condition variable is still in use by another thread, an error is returned.

### pthread_cond_init
```c
#include <pthread.h>
int pthread_cond_init(pthread_cond_t * condition_var_handle,
pthread_condattr_t * condition_var_attributes);
```
- This service initializes (creates) a condition variable with the optional condition variable attributes. If successful, the condition variable handle is set up for further use by the application.

### pthread_cond_signal
```c
#include <pthread.h>
int pthread_cond_signal(pthread_cond_t * condition_var_handle);
```
- This service resumes the highest priority thread currently waiting on this condition variable.

### pthread_cond_timedwait
```c
#include <pthread.h>
int pthread_cond_timedwait(pthread_cond_t * condition_var_handle,
pthread_mutex_t * mutex_handle,
const struct timespec *absolute_time);
```
- This service suspends on the condition variable specified by the condition_var_handle parameter. Before this service is called, the thread must have obtained the mutex specified by mutex_handle. Internally, MPX releases the mutex atomically with the thread suspension. Once the calling thread is resumed via a signal or broadcast to the condition variable, the mutex is reobtained before this service returns to the caller.

### pthread_cond_wait
```c
#include <pthread.h>
int pthread_cond_wait(pthread_cond_t * condition_var_handle,
pthread_mutex_t * mutex_handle);
```
- This service suspends on the condition variable specified by the condition_var_handle parameter. Before this service is called, the thread must have obtained the mutex specified by mutex_handle. Internally, MPX releases the mutex atomically with the thread suspension. Once the calling thread is resumed via a signal or broadcast to the condition variable, the mutex is reobtained before this service returns to the caller.

### pthread_condattr_destroy
```c
#include <pthread.h>
int pthread_condattr_destroy(pthread_condattr_t *
condition_var_attributes);
```
- This service destroys the previously created condition variable attributes structure pointed to by condition_var_attributes. Once destroyed, the condition variable attributes structure cannot be used again unless it is recreated.

### pthread_condattr_getpshared
```c
#include <pthread.h>
int pthread_condattr_getpshared(pthread_condattr_t * condition_var_attributes, int * process_sharing_designation);
```
- This service returns the current process sharing designation in the condition variable attribute structure. By default, the process sharing designation is PTHREAD_PROCESS_PRIVATE.

### pthread_condattr_init
```c
#include <pthread.h>
int pthread_condattr_init(pthread_condattr_t *
condition_var_attributes);
```
- This service initializes the condition variable attributes structure with default condition variable creation values. These defaults are as follows:

### pthread_condattr_setpshared
```c
#include <pthread.h>
int pthread_condattr_setpshared(pthread_condattr_t * condition_var_attributes, int	process_sharing_designation);
```
- This service sets the process sharing designation in the condition variable attribute structure to either PTHREAD_PROCESS_PRIVATE or PTHREAD_PROCESS_SHARED. By default, the process sharing designation is PTHREAD_PROCESS_PRIVATE.

### pthread_create
```c
#include <pthread.h>
int pthread_create(pthread_t * thread_handle,
const pthread_attr * attributes, void * (*start_routine)(void *), void *arguments);
```
- This service creates a new thread that starts execution at the caller’s start_routine, passing verbatim the supplied arguments parameter. Note that the optional attributes parameter can specify additional attributes for the thread, including explicitly setting its priority, stack location, stack size, etc.

### pthread_detach
```c
#include <pthread.h>
int pthread_detach(pthread_t thread_handle);
```
- This service places the specified thread in a detached state, such that it can’t be joined in the future. It is equivalent to creating the thread with the PTHREAD_CREATE_DETACHED attribute. When the specified, detached thread exits or returns, all of its resources are immediately released.

### pthread_equal
```c
#include <pthread.h>
int pthread_equal(pthread_t first_thread, pthread_t second_thread);
```
- This service compares two thread handles. If the handles are the same, a non- zero value is returned. If they are not the same, a value of zero is returned.

### pthread_exit
```c
#include <pthread.h>
void pthread_exit(void *exit_value);
```
- This service terminates the currently executing thread. If this thread is detached, all of the thread’s resources are released. Any cancellation cleanup handlers are popped and executed. The exit_value passed to this API will be sent to a thread that has joined this thread via the pthread_join API, assuming the value was requested in the join request (non-NULL destination value).

### pthread_join
```c
#include <pthread.h>
int pthread_join(pthread_t thread_to_join, void ** value_destination);
```
- This service suspends the currently running thread until the specified thread completes its processing. When the specified thread exits, the value supplied in its exit call is returned in the destination specified by the caller–if a non- NULL exit value destination pointer is provided.

### pthread_mutex_destroy
```c
#include <pthread.h>
int pthread_mutex_destroy(pthread_mutex_t * mutex_handle);
```
- This service destroys the previously created mutex specified by mutex_handle. If a thread still owns the mutex, an error is returned.

### pthread_mutex_init
```c
#include <pthread.h>
int pthread_mutex_init(pthread_mutex_t * mutex_handle,
pthread_mutexattr_t * mutex_attributes);
```
- This service initializes (creates) a mutex with the optional mutex attributes. If successful, the mutex handle is set up for further use by the application.

### pthread_mutex_lock
```c
#include <pthread.h>
int pthread_mutex_lock(pthread_mutex_t * mutex_handle);
```
- This service assigns ownership to the calling thread if the mutex is available. Otherwise, if another thread already owns the mutex, the calling thread suspends until the other thread releases the mutex.

### pthread_mutex_trylock
```c
#include <pthread.h>
int pthread_mutex_trylock(pthread_mutex_t * mutex_handle);
```
- This service assigns ownership to the calling thread if the mutex is available. Otherwise, if another thread already owns the mutex, this service immediately returns an error, i.e., there is no thread suspension like the pthread_mutex_lock service.

### pthread_mutex_unlock
```c
#include <pthread.h>
int pthread_mutex_unlock(pthread_mutex_t * mutex_handle);
```
- This service releases a previously owned mutex. If other threads are suspended waiting for the mutex, the first thread is given ownership and resumed.

### pthread_mutexattr_destroy
```c
#include <pthread.h>
int pthread_mutexattr_destroy(pthread_mutexattr_t * mutex_attributes);
```
- This service destroys the previously created mutex attributes structure pointed to by mutex_attributes. Once destroyed, the mutex attributes structure cannot be used again unless it is recreated.

### pthread_mutexattr_getprotocol
```c
#include <pthread.h>
int pthread_mutexattr_getprotocol(pthread_mutexattr_t
*mutex_attributes, int * protocol);
```
- This service returns the previously supplied mutex protocol. By default, the process sharing designation is PTHREAD_PRIO_NONE.

### pthread_mutexattr_getpshared
```c
#include <pthread.h>
int pthread_mutexattr_getpshared(pthread_mutexattr_t *mutex_attributes,
int * process_sharing_designation);
```
- This service returns the current process sharing designation in the mutex attribute structure. By default, the process sharing designation is PTHREAD_PROCESS_PRIVATE.

### pthread_mutexattr_gettype
```c
#include <pthread.h>
int pthread_mutexattr_gettype(pthread_mutexattr_t
*mutex_attributes, int * type);
```
- This service returns the previously supplied mutex type. By default, the mutex type designation is PTHREAD_MUTEX_ERRORCHECK.

### pthread_mutexattr_init
```c
#include <pthread.h>
int pthread_mutexattr_init(pthread_mutexattr_t *mutex_attributes);
```
- This service initializes the mutex attributes structure with default mutex creation values. These defaults are as follows:

### pthread_mutexattr_setprotocol
```c
#include <pthread.h>
int pthread_mutexattr_setprotocol(pthread_mutexattr_t
*mutex_attributes, int protocol);
```
- This service sets the specified protocol in the previously created mutex attributes structure. By default, the protocol is PTHREAD_PRIO_NONE, which means priority inheritance is not enabled. Setting the protocol to PTHREAD_PRIO_INHERIT enables priority inheritance when a mutex is created with this attribute structure. Please see the mutex section in Chapter 6 for more information on priority inheritance.

### pthread_mutexattr_setpshared
```c
#include <pthread.h>
int pthread_mutexattr_setpshared(pthread_mutexattr_t *mutex_attributes,
int	process_sharing_designation);
```
- This service sets the process sharing designation in the mutex attribute structure to either PTHREAD_PROCESS_PRIVATE or PTHREAD_PROCESS_SHARED. By default, the process sharing designation is PTHREAD_PROCESS_PRIVATE.

### pthread_mutexattr_settype
```c
#include <pthread.h>
int pthread_mutexattr_settype(pthread_mutexattr_t
* mutex_attributes, int type);
```
- This service sets the specified mutex type in the previously created attributes structure. By default, the type is PTHREAD_MUTEX_ERRORCHECK.

### pthread_self
```c
#include <pthread.h> pthread_t pthread_self(void);
```
- This service returns the thread handle of the currently running thread.

### pthread_setcancelstate
```c
#include <pthread.h>
int pthread_setcancelstate(int new_state, int * old_state);
```
- This service sets the calling thread’s cancel state as specified by new_state. If old_state is non-NULL, the previous cancel state is stored in the specified destination.

### pthread_setcanceltype
```c
#include <pthread.h>
int pthread_setcanceltype(int new_type, int * old_type);
```
- This service sets the calling thread’s cancel type as specified by new_type. If old_type is non-NULL, the previous cancel type is stored in the specified destination.

### pthread_testcancel
```c
#include <pthread.h>
void pthread_testcancel(void);
```
- This service checks for a pending cancel request for the calling thread. If detected, the calling thread cancels itself via pthread_exit.

### sched_yield
```c
#include <sched.h> int sched_yield(void);
```
- This service relinquishes control to the next thread of the same priority currently ready for execution. If there is no other thread of the same priority ready for execution, this service simply returns a successful status.

### sem_destroy
```c
#include <semaphore.h>
int sem_destroy(sem_t * semaphore_handle);
```
- This service destroys the previously created semaphore specified by semaphore_handle. An error is returned if one or more threads are suspended on this semaphore.

### sem_init
```c
#include <semaphore.h>
int sem_init(sem_t * semaphore_handle, int pshared,
unsigned int value);
```
- This service initializes (creates) a semaphore with the specified initial value. If successful, the semaphore handle is available for use by the application.

### sem_post
```c
#include <semaphore.h>
int sem_post(sem_t * semaphore_handle);
```
- This service posts to the specified semaphore. If one or more threads are waiting, the highest priority thread waiting is resumed. Otherwise, if no threads are waiting, the internal semaphore count is incremented by one.

### sem_trywait
```c
#include <semaphore.h>
int sem_trywait(sem_t * semaphore_handle);
```
- If the semaphore is available (count greater than zero), this service decrements the count and returns success. Otherwise, an error is returned.

### sem_wait
```c
#include <semaphore.h>
int sem_wait(sem_t * semaphore_handle);
```
- If the semaphore is available (count greater than zero), this service decrements the semaphore count by one and returns success to the caller. Otherwise, if the semaphore is zero, the calling thread suspends until the semaphore is available.

### sleep
```c
#include <unistd.h>
unsigned int sleep(unsigned int seconds);
```
- This service causes the calling thread to suspend for the number of seconds specified in seconds. If an unmasked signal is sent to the thread while sleeping, the thread is resumed, and the remaining seconds are returned.

### time
```c
#include <pthread.h>
time_t time(time_t * return_seconds);
```
- This service returns the current number of seconds. If a non-null value for return_seconds is provided, the current number of seconds is also placed in the destination pointed to by return_seconds.

### usleep
```c
#include <unistd.h>
int usleep(useconds_t microseconds);
```
- This service causes the calling thread to suspend for the time specified in microseconds. If an unmasked signal is sent to the thread while sleeping, the thread is resumed, and an error is returned.
