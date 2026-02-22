# MPX RTOS API Catalog (Updated Reference Card)

Derived strictly from:
- **MPX-User-Manual-V1-0-0.docx** (normative API semantics, Chapter 7)
- **MPX-RTOS-pthreads-card.rtf** (updated; normative API surface list)

Conformance target: **1:1 behavioral clone**.

## Coverage Summary
- APIs defined in User Manual: **203**
- APIs listed in updated Reference Card: **182**
- APIs only in Reference Card: **16**
- APIs only in User Manual: **37**

## User Manual API Definitions (Chapter 7)

### clock_getres
**Prototype**
```c
#include <pthread.h>
int clock_getres(clockid_t clock_id, struct timespec *resolution);
```
**Description (extract)**
- This service returns the current time resolution in resolution, which is effectively the underlying ticktimer periodic interrupt frequency.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location of where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### clock_gettime
**Prototype**
```c
#include <pthread.h>
int clock_gettime(clockid_t clock_id, struct timespec *current_time);
```
**Description (extract)**
- This service returns the current time in the destination specified by
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location of where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### clock_settime
**Prototype**
```c
#include <pthread.h>
int clock_settime(clockid_t clock_id, struct timespec *new_time);
```
**Description (extract)**
- This service sets the current time to the value specified by new_time.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location of where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mq_close
**Prototype**
```c
#include <mqueue.h>
int mq_close(mqd_t message_queue);
```
**Description (extract)**
- This service closes and destroys the specified message queue. An error is returned if any threads are suspended on the message queue.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (72 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mq_getattr
**Prototype**
```c
#include <mqueue.h>
int mq_getattr(mqd_t message_queue, struct mq_attr* queue_attributes);
```
**Description (extract)**
- This service retrieves the current attributes of the specified message queue.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (48 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mq_open
**Prototype**
```c
#include <mqueue.h>
mqd_t mq_open(const char * queue_name, int operation, mode_t mode,
mq_attr * queue_attributes);
```
**Description (extract)**
- If successful, this service opens (creates) the message queue specified and returns the message queue handle.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (176 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mq_receive
**Prototype**
```c
#include <mqueue.h>
int mq_receive(mqd_t message_queue, char * message,
size_t message_size, unsigned int * message_priority);
```
**Description (extract)**
- This service receives the oldest message with the highest priority from the specified message queue. If the queue is empty and the O_NONBLOCK attribute is not set, the calling thread will suspend waiting for a message to arrive. If multiple threads are waiting on an empty queue, the first thread waiting is given the message.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. No preemption is possible with this service if a message is in the message queue.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (184 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mq_send
**Prototype**
```c
#include <mqueue.h>
int mq_send(mqd_t message_queue, char * message,
size_t message_size, unsigned int message_priority);
```
**Description (extract)**
- This service sends the message to the specified message queue. If the queue is full and the O_NONBLOCK attribute is not set, the calling thread will suspend waiting for room in the queue.
**Callable from (extract)**
- This service is callable only from the thread context and interrupt handlers (ISRs).
- If suspension is possible, the developer must not call this API from an interrupt handler. An easy way to ensure the queue attribute O_NONBLOCK is in force. Otherwise, unpredictable behavior is possible.
**Real-time scenario (extract)**
- NO PREEMPTION. No preemption is possible with this service if there is room in the message queue.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (168 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mq_setattr
**Prototype**
```c
#include <mqueue.h>
int mq_setattr(mqd_t message_queue, struct mq_attr * new_attributes,
struct mq_attr * previous_attributes);
```
**Description (extract)**
- This service sets the attributes of the specified message queue. If the previous_attributes pointer is non-NULL, the attributes prior to this service are returned.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (48 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mq_timedreceive
**Prototype**
```c
#include <pthread.h> #include <mqueue.h>
int mq_timedreceive(mqd_t message_queue, char * message,
size_t message_size, unsigned int * message_priority, const struct timespec absolute_timeout);
```
**Description (extract)**
- This service receives the highest priority message from the specified message queue. If the queue is empty and the O_NONBLOCK attribute is not set, the calling thread will suspend waiting for a message to arrive. If the timeout is exceeded before a message arrives, the thread is resumed with an error.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. No preemption is possible with this service if a message is in the message queue.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (208 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mq_timedsend
**Prototype**
```c
#include <mqueue.h>
int mq_timedsend(mqd_t message_queue, char * message,
size_t message_size, unsigned int message_priority, const struct timespec absolute_timeout);
```
**Description (extract)**
- This service sends the message to the specified message queue. If the queue is full and the O_NONBLOCK attribute is not set, the calling thread will suspend waiting for room in the queue. If the timeout is exceeded before room for the message is available in the queue, the thread is resumed with an error.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. No preemption is possible with this service if there is room in the message queue.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (192 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### nanosleep
**Prototype**
```c
#include <pthread.h>
int nanosleep(struct timespec *request_time,
struct timespec *remainng_time);
```
**Description (extract)**
- This service causes the calling thread to suspend for the time specified in request_time. If an unmasked signal is sent to the thread while sleeping, the thread is resumed, and the remaining time is returned in remaining_time.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (100 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_attr_destroy
**Prototype**
```c
#include <pthread.h>
int pthread_attr_destroy(pthread_attr_t *attributes);
```
**Description (extract)**
- This service destroys a previously initialized thread creation attributes structure. Once destroyed, the attributes structure can no longer be used.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_attr_getdetachstate
**Prototype**
```c
#include <pthread.h>
int pthread_attr_getdetachstate(pthread_attr_t *attributes,
int * detach_state);
```
**Description (extract)**
- This service returns the detach state stored in the thread attributes structure. Valid detach states are PTHREAD_CREATE_JOINABLE (default) and PTHREAD_CREATE_DETACHED.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_attr_getstackaddr
**Prototype**
```c
#include <pthread.h>
int pthread_attr_getstackaddr(pthread_attr_t *attributes,
void ** stack_address);
```
**Description (extract)**
- This service returns the stack address stored in the thread attributes structure. By default, this value is NULL unless specified by the application via a call to pthread_attr_setstackaddr.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_attr_getstacksize
**Prototype**
```c
#include <pthread.h>
int pthread_attr_getstacksize(pthread_attr_t *attributes,
size_t *	stack_size);
```
**Description (extract)**
- This service returns the current stack size stored in the thread attributes structure. By default, this value is MPX_DEFAULT_STACK_SIZE unless specified by the application via a call to pthread_attr_setstacksize.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_attr_init
**Prototype**
```c
#include <pthread.h>
int pthread_attr_init(pthread_attr_t *attributes);
```
**Description (extract)**
- This service initializes the attributes structure with default thread creation values. These defaults are as follows:
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_attr_setdetachstate
**Prototype**
```c
#include <pthread.h>
int pthread_attr_setdetachstate(pthread_attr_t *attributes,
int	new_detach_state);
```
**Description (extract)**
- This service sets the detach state specified by new_detach_state in the thread attributes structure. Valid detach states are PTHREAD_CREATE_JOINABLE and PTHREAD_CREATE_DETACHED.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_attr_setstackaddr
**Prototype**
```c
#include <pthread.h>
int pthread_attr_setstackaddr(pthread_attr_t *attributes,
void *	stack_address);
```
**Description (extract)**
- This service sets the stack address to the value specified by stack_address. The stack address must be at least PTHREAD_STACK_MIN number of bytes.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_attr_setstacksize
**Prototype**
```c
#include <pthread.h>
int pthread_attr_setstacksize(pthread_attr_t *attributes,
size_t	stack_size);
```
**Description (extract)**
- This service sets the specified stack size in the thread attributes structure. The stack address must be at least PTHREAD_STACK_MIN number of bytes.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_cancel
**Prototype**
```c
#include <pthread.h>
int pthread_cancel(pthread_t thread_handle);
```
**Description (extract)**
- This service cancels the specified thread. If the specified thread has cancellation disabled or deferred, this service marks the thread for cancellation at a later point determined by the thread itself. Otherwise, if the specified thread has asynchronous cancellation enabled, it is immediately canceled (terminated) by this service.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. No preemption takes place as a result of this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (112 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_cleanup_pop
**Prototype**
```c
#include <pthread.h>
void pthread_cleanup_pop(int execute);
```
**Description (extract)**
- This service pops the most recently pushed cleanup handler from the thread’s cleanup handler stack. If the specified execute parameter is non-zero and the cleanup handler function pointer is non-NULL, the cleanup handler is executed before returning to the caller.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. No preemption takes place as a result of this service.
**Stack usage (extract)**
- context.

### pthread_cleanup_push
**Prototype**
```c
#include <pthread.h>
void pthread_cleanup_push(void (*cleanup_handler)(void *),
void *argument);
```
**Description (extract)**
- This service pushes the specified cleanup_handler on the calling thread’s cleanup handler stack.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. No preemption takes place as a result of this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (8 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_cond_broadcast
**Prototype**
```c
#include <pthread.h>
int pthread_cond_broadcast(pthread_cond_t * condition_var_handle);
```
**Description (extract)**
- This service resumes all threads currently waiting on this condition variable.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. No preemption occurs if no other threads are waiting for the condition variable.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (96 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_cond_destroy
**Prototype**
```c
#include <pthread.h>
int pthread_cond_destroy(pthread_cond_t * condition_var_handle);
```
**Description (extract)**
- This service destroys the previously created condition variable specified by condition_var_handle. If the condition variable is still in use by another thread, an error is returned.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (56 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_cond_init
**Prototype**
```c
#include <pthread.h>
int pthread_cond_init(pthread_cond_t * condition_var_handle,
pthread_condattr_t * condition_var_attributes);
```
**Description (extract)**
- This service initializes (creates) a condition variable with the optional condition variable attributes. If successful, the condition variable handle is set up for further use by the application.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (120 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_cond_signal
**Prototype**
```c
#include <pthread.h>
int pthread_cond_signal(pthread_cond_t * condition_var_handle);
```
**Description (extract)**
- This service resumes the highest priority thread currently waiting on this condition variable.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. No preemption occurs if no other threads are waiting for the condition variable.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (112 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_cond_timedwait
**Prototype**
```c
#include <pthread.h>
int pthread_cond_timedwait(pthread_cond_t * condition_var_handle,
pthread_mutex_t * mutex_handle,
const struct timespec *absolute_time);
```
**Description (extract)**
- This service suspends on the condition variable specified by the condition_var_handle parameter. Before this service is called, the thread must have obtained the mutex specified by mutex_handle. Internally, MPX releases the mutex atomically with the thread suspension. Once the calling thread is resumed via a signal or broadcast to the condition variable, the mutex is reobtained before this service returns to the caller.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (256 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_cond_wait
**Prototype**
```c
#include <pthread.h>
int pthread_cond_wait(pthread_cond_t * condition_var_handle,
pthread_mutex_t * mutex_handle);
```
**Description (extract)**
- This service suspends on the condition variable specified by the condition_var_handle parameter. Before this service is called, the thread must have obtained the mutex specified by mutex_handle. Internally, MPX releases the mutex atomically with the thread suspension. Once the calling thread is resumed via a signal or broadcast to the condition variable, the mutex is reobtained before this service returns to the caller.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (232 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_condattr_destroy
**Prototype**
```c
#include <pthread.h>
int pthread_condattr_destroy(pthread_condattr_t *
condition_var_attributes);
```
**Description (extract)**
- This service destroys the previously created condition variable attributes structure pointed to by condition_var_attributes. Once destroyed, the condition variable attributes structure cannot be used again unless it is recreated.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_condattr_getpshared
**Prototype**
```c
#include <pthread.h>
int pthread_condattr_getpshared(pthread_condattr_t * condition_var_attributes, int * process_sharing_designation);
```
**Description (extract)**
- This service returns the current process sharing designation in the condition variable attribute structure. By default, the process sharing designation is PTHREAD_PROCESS_PRIVATE.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_condattr_init
**Prototype**
```c
#include <pthread.h>
int pthread_condattr_init(pthread_condattr_t *
condition_var_attributes);
```
**Description (extract)**
- This service initializes the condition variable attributes structure with default condition variable creation values. These defaults are as follows:
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_condattr_setpshared
**Prototype**
```c
#include <pthread.h>
int pthread_condattr_setpshared(pthread_condattr_t * condition_var_attributes, int	process_sharing_designation);
```
**Description (extract)**
- This service sets the process sharing designation in the condition variable attribute structure to either PTHREAD_PROCESS_PRIVATE or PTHREAD_PROCESS_SHARED. By default, the process sharing designation is PTHREAD_PROCESS_PRIVATE.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_create
**Prototype**
```c
#include <pthread.h>
int pthread_create(pthread_t * thread_handle,
const pthread_attr * attributes, void * (*start_routine)(void *), void *arguments);
```
**Description (extract)**
- This service creates a new thread that starts execution at the caller’s start_routine, passing verbatim the supplied arguments parameter. Note that the optional attributes parameter can specify additional attributes for the thread, including explicitly setting its priority, stack location, stack size, etc.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption if the newly created thread has the same or less priority than the calling thread. This service returns immediately after the creation of the new thread.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (192 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_detach
**Prototype**
```c
#include <pthread.h>
int pthread_detach(pthread_t thread_handle);
```
**Description (extract)**
- This service places the specified thread in a detached state, such that it can’t be joined in the future. It is equivalent to creating the thread with the PTHREAD_CREATE_DETACHED attribute. When the specified, detached thread exits or returns, all of its resources are immediately released.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_equal
**Prototype**
```c
#include <pthread.h>
int pthread_equal(pthread_t first_thread, pthread_t second_thread);
```
**Description (extract)**
- This service compares two thread handles. If the handles are the same, a non- zero value is returned. If they are not the same, a value of zero is returned.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (8 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_exit
**Prototype**
```c
#include <pthread.h>
void pthread_exit(void *exit_value);
```
**Description (extract)**
- This service terminates the currently executing thread. If this thread is detached, all of the thread’s resources are released. Any cancellation cleanup handlers are popped and executed. The exit_value passed to this API will be sent to a thread that has joined this thread via the pthread_join API, assuming the value was requested in the join request (non-NULL destination value).
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- PREEMPTION. If a higher-priority thread has joined this thread, the exit processing will resume its execution, and preemption will occur.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (80 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_getaffinity_np
**Prototype**
```c
#include <pthread.h>
int pthread_getaffinity_np(pthread_t thread_handle, size_t cpusetsize, cpu_set_t * cpuset);
```
**Description (extract)**
- When the MPX RTOS is configured for SMP (MPX_MAXIMUM_CORES greater than one), this service retrieves the current set of cores this thread can execute in the parameter cpuset. If MPX_MAXIMUM_CORES is equal to one, this service is irrelevant and, therefore, not defined.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (48 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_join
**Prototype**
```c
#include <pthread.h>
int pthread_join(pthread_t thread_to_join, void ** value_destination);
```
**Description (extract)**
- This service suspends the currently running thread until the specified thread completes its processing. When the specified thread exits, the value supplied in its exit call is returned in the destination specified by the caller–if a non- NULL exit value destination pointer is provided.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (100 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_kill
**Prototype**
```c
#include <signal.h>
int pthread_kill(pthread_t thread, int signal);
```
**Description (extract)**
- This service raises a signal for the specified thread. If the signal is masked, it is added to the pending signals set. In addition, if the specified thread is suspended waiting for this signal, it is resumed. Otherwise, the registered signal handler is invoked if the specified thread does not mask the signal. If no signal handler has been registered, an error is returned.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. If the thread is not waiting for this signal, or there is no signal handler, or the signal handler does not unblock any higher-priority suspended thread, no preemption occurs.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (120 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_mutex_destroy
**Prototype**
```c
#include <pthread.h>
int pthread_mutex_destroy(pthread_mutex_t * mutex_handle);
```
**Description (extract)**
- This service destroys the previously created mutex specified by mutex_handle. If a thread still owns the mutex, an error is returned.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (80 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_mutex_init
**Prototype**
```c
#include <pthread.h>
int pthread_mutex_init(pthread_mutex_t * mutex_handle,
pthread_mutexattr_t * mutex_attributes);
```
**Description (extract)**
- This service initializes (creates) a mutex with the optional mutex attributes. If successful, the mutex handle is set up for further use by the application.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (120 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_mutex_lock
**Prototype**
```c
#include <pthread.h>
int pthread_mutex_lock(pthread_mutex_t * mutex_handle);
```
**Description (extract)**
- This service assigns ownership to the calling thread if the mutex is available. Otherwise, if another thread already owns the mutex, the calling thread suspends until the other thread releases the mutex.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. No preemption occurs if the mutex is available and ownership is assigned to the calling thread.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (136 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_mutex_trylock
**Prototype**
```c
#include <pthread.h>
int pthread_mutex_trylock(pthread_mutex_t * mutex_handle);
```
**Description (extract)**
- This service assigns ownership to the calling thread if the mutex is available. Otherwise, if another thread already owns the mutex, this service immediately returns an error, i.e., there is no thread suspension like the pthread_mutex_lock service.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. No preemption occurs if the mutex is available and ownership is assigned to the calling thread.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_mutex_unlock
**Prototype**
```c
#include <pthread.h>
int pthread_mutex_unlock(pthread_mutex_t * mutex_handle);
```
**Description (extract)**
- This service releases a previously owned mutex. If other threads are suspended waiting for the mutex, the first thread is given ownership and resumed.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. If no other threads are waiting for the mutex, no preemption occurs.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (168 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_mutexattr_destroy
**Prototype**
```c
#include <pthread.h>
int pthread_mutexattr_destroy(pthread_mutexattr_t * mutex_attributes);
```
**Description (extract)**
- This service destroys the previously created mutex attributes structure pointed to by mutex_attributes. Once destroyed, the mutex attributes structure cannot be used again unless it is recreated.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_mutexattr_getprotocol
**Prototype**
```c
#include <pthread.h>
int pthread_mutexattr_getprotocol(pthread_mutexattr_t
*mutex_attributes, int * protocol);
```
**Description (extract)**
- This service returns the previously supplied mutex protocol. By default, the process sharing designation is PTHREAD_PRIO_NONE.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_mutexattr_getpshared
**Prototype**
```c
#include <pthread.h>
int pthread_mutexattr_getpshared(pthread_mutexattr_t *mutex_attributes,
int * process_sharing_designation);
```
**Description (extract)**
- This service returns the current process sharing designation in the mutex attribute structure. By default, the process sharing designation is PTHREAD_PROCESS_PRIVATE.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_mutexattr_gettype
**Prototype**
```c
#include <pthread.h>
int pthread_mutexattr_gettype(pthread_mutexattr_t
*mutex_attributes, int * type);
```
**Description (extract)**
- This service returns the previously supplied mutex type. By default, the mutex type designation is PTHREAD_MUTEX_ERRORCHECK.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_mutexattr_init
**Prototype**
```c
#include <pthread.h>
int pthread_mutexattr_init(pthread_mutexattr_t *mutex_attributes);
```
**Description (extract)**
- This service initializes the mutex attributes structure with default mutex creation values. These defaults are as follows:
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_mutexattr_setprotocol
**Prototype**
```c
#include <pthread.h>
int pthread_mutexattr_setprotocol(pthread_mutexattr_t
*mutex_attributes, int protocol);
```
**Description (extract)**
- This service sets the specified protocol in the previously created mutex attributes structure. By default, the protocol is PTHREAD_PRIO_NONE, which means priority inheritance is not enabled. Setting the protocol to PTHREAD_PRIO_INHERIT enables priority inheritance when a mutex is created with this attribute structure. Please see the mutex section in Chapter 6 for more information on priority inheritance.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_mutexattr_setpshared
**Prototype**
```c
#include <pthread.h>
int pthread_mutexattr_setpshared(pthread_mutexattr_t *mutex_attributes,
int	process_sharing_designation);
```
**Description (extract)**
- This service sets the process sharing designation in the mutex attribute structure to either PTHREAD_PROCESS_PRIVATE or PTHREAD_PROCESS_SHARED. By default, the process sharing designation is PTHREAD_PROCESS_PRIVATE.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_mutexattr_settype
**Prototype**
```c
#include <pthread.h>
int pthread_mutexattr_settype(pthread_mutexattr_t
* mutex_attributes, int type);
```
**Description (extract)**
- This service sets the specified mutex type in the previously created attributes structure. By default, the type is PTHREAD_MUTEX_ERRORCHECK.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the context of the application.

### pthread_self
**Prototype**
```c
#include <pthread.h> pthread_t pthread_self(void);
```
**Description (extract)**
- This service returns the thread handle of the currently running thread.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (8 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_setaffinity_np
**Prototype**
```c
#include <pthread.h>
int pthread_setaffinity_np(pthread_t thread_handle, size_t cpusetsize, cpu_set_t * cpuset);
```
**Description (extract)**
- When the MPX RTOS is configured for SMP (MPX_MAXIMUM_CORES greater than one), this service specifies the set of cores this thread can execute via the parameter cpuset. If MPX_MAXIMUM_CORES equals one, this service is irrelevant and, therefore, not defined.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. If the new core affinity does not necessitate any changes in the assignment of threads to cores, no preemption occurs.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (308 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_setcancelstate
**Prototype**
```c
#include <pthread.h>
int pthread_setcancelstate(int new_state, int * old_state);
```
**Description (extract)**
- This service sets the calling thread’s cancel state as specified by new_state. If old_state is non-NULL, the previous cancel state is stored in the specified destination.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (120 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_setcanceltype
**Prototype**
```c
#include <pthread.h>
int pthread_setcanceltype(int new_type, int * old_type);
```
**Description (extract)**
- This service sets the calling thread’s cancel type as specified by new_type. If old_type is non-NULL, the previous cancel type is stored in the specified destination.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (120 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_sigmask
**Prototype**
```c
#include <signal.h>
int pthread_sigmask(int operation, sigset_t * signal_set,
sigset_t * previous_mask);
```
**Description (extract)**
- This service sets or clears signals in the currently executing thread’s signal mask. How the signal mask is modified depends on the operation parameter as described in the parameter section below. Note that each thread inherits its initial signal mask from the thread that created it.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (88 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### pthread_testcancel
**Prototype**
```c
#include <pthread.h>
void pthread_testcancel(void);
```
**Description (extract)**
- This service checks for a pending cancel request for the calling thread. If detected, the calling thread cancels itself via pthread_exit.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. If a cancel request is not pending for the calling thread, there is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (96 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_errno_get
**Prototype**
```c
#include <mpx_errno.h> int mpx_errno_get(void);
```
**Description (extract)**
- This pthreadsmore service retrieves the errno value of the currently executing thread.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. No preemption is possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (8 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_errno_set
**Prototype**
```c
#include <mpx_errno.h>
void mpx_errno_set(int new_error);
```
**Description (extract)**
- This pthreadsmore service sets the errno value of the currently executing thread.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. No preemption is possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (8 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_mq_extend_open
**Prototype**
```c
#include <fcntl.h> #include <sys/stat.h> #include <mqueue.h>
mqd_t mpx_mq_extend_open(const char * queue_name, int operation,
mode_t mode, mq_attr * queue_attributes, mq_extendattr * extend_attributes);
```
**Description (extract)**
- This pthreadsmore service opens (creates) the message queue specified (with optional extended attributes) and returns the message queue handle if successful.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (184 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_mq_extendattr_destroy
**Prototype**
```c
#include <mqueue.h>
int mpx_mq_extendattr_destroy(mq_extendattr_t * queue_attributes);
```
**Description (extract)**
- This pthreadsmore service destroys the previously created extended message queue attributes structure pointed to by queue_attributes. Once destroyed, the extended message queue attributes structure cannot be used again unless it is recreated.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_mq_extendattr_getcontroladdr
**Prototype**
```c
#include <mqueue.h>
int mpx_mq_extendattr_getcontroladdr(mq_extendattr_t* queue_attributes,
void ** queue_control_address);
```
**Description (extract)**
- This pthreadsmore service returns the previously supplied message queue control structure address.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_mq_extendattr_getcontrolsize
**Prototype**
```c
#include <mqueue.h>
int mpx_mq_extendattr_getcontrolsize(mq_extendattr_t* queue_attributes,
size_t * queue_control_size);
```
**Description (extract)**
- This pthreadsmore service returns the size of the internal message queue control structure. The primary purpose of this API is to inform the application how much memory is required for the mpx_mq_extendattr_setcontroladdr API.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_mq_extendattr_getqueueaddr
**Prototype**
```c
#include <mqueue.h>
int mpx_mq_extendattr_getqueueaddr(mq_extendattr_t* queue_attributes,
void ** queue_memory_address);
```
**Description (extract)**
- This pthreadsmore service returns the previously supplied message queue memory address.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_mq_extendattr_getqueuesize
**Prototype**
```c
#include <mqueue.h>
int mpx_mq_extendattr_getqueuesize(mq_extendattr_t* queue_attributes,
size_t * queue_memory_size);
```
**Description (extract)**
- This pthreadsmore service returns the size of the previously supplied message queue memory.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_mq_extendattr_init
**Prototype**
```c
#include <mqueue.h>
int mpx_mq_extendattr_init(mq_extendattr_t * queue_attributes);
```
**Description (extract)**
- This pthreadsmore service initializes the extended message queue attributes structure with default condition variable creation values. Note that the extended message queue attributes are used only by the mpx_mq_extend_open API.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_mq_extendattr_setcontroladdr
**Prototype**
```c
#include <mqueue.h>
int mpx_mq_extendattr_setcontroladdr(mq_extendattr_t* queue_attributes,
void * queue_control_address, size_t queue_memory_size);
```
**Description (extract)**
- This pthreadsmore service enables the developer to provide the memory for the internal MPX RTOS message queue structure as specified by the address in the queue_control_address parameter. This memory will subsequently be used for the next message queue created with this attribute structure. The memory size required for the internal message queue control structure can be found via a call to the mpx_mq_extendattr_getcontrol_size service.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_mq_extendattr_setqueueaddr
**Prototype**
```c
#include <mqueue.h>
int mpx_mq_extendattr_setqueueaddr(mq_extendattr_t* queue_attributes,
void * queue_memory_address, size_t queue_memory_size);
```
**Description (extract)**
- This pthreadsmore service sets the internal message queue memory address to the address specified by queue_memory_address. This address will subsequently be used to supply the memory for the internal message queue memory on the next queue created with this attribute structure.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_attr_getaffinity
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_attr_getaffinity(pthread_attr_t *attributes,
size_t cpusetsize, cpu_set_t * core_affinity);
```
**Description (extract)**
- When the MPX RTOS is configured for SMP (MPX_MAXIMUM_CORES greater than one), this pthreadsmore service returns the core affinity specified in the supplied attribute structure. By default, the thread core affinity is set to the constant MPX_DEFAULT_CORE_AFFINITY when the attribute structure is initialized. If MPX_MAXIMUM_CORES equals one, this service is irrelevant and not defined.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_attr_getautostart
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_attr_getautostart(pthread_attr_t *attributes,
int * automatic_start);
```
**Description (extract)**
- This pthreadsmore service returns the automatic start option in the supplied attribute structure. By default, the thread automatic start option is set to MPX_AUTO_START, which means the thread will start automatically after it is created.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_attr_getcontroladdr
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_attr_getcontroladdr(pthread_attr_t *attributes,
void ** thread_control_address);
```
**Description (extract)**
- This pthreadsmore service returns the thread control structure address stored in the thread attributes structure. By default, this value is NULL unless specified by the application via a call to mpx_pthread_attr_setcontroladdr.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_attr_getcontrolsize
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_attr_getcontrolsize(pthread_attr_t *attributes,
size_t *	thread_control_size);
```
**Description (extract)**
- This pthreadsmore service returns the size of the internal thread control structure. The main purpose of this API is to inform the application how much memory is required for the mpx_pthread_attr_setcontroladdr API.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_attr_getname
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_attr_getname(pthread_attr_t *attributes,
char **	return_name);
```
**Description (extract)**
- This pthreadsmore service returns the current thread name in the thread attributes structure.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_attr_getpriority
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_attr_getpriority(pthread_attr_t *attributes,
int *	priority);
```
**Description (extract)**
- This pthreadsmore service returns the current thread priority in the thread attributes structure. By default, this value is MPX_DEFAULT_PRIORITY if the application does not specify it via a call to mpx_pthread_attr_setpriority.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_attr_gettimeslice
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_attr_gettimeslice(pthread_attr_t *attributes,
u_long *	thread_time_slice);
```
**Description (extract)**
- This pthreadsmore service returns the current thread time-slice stored in the thread attributes structure. By default, this value is 0, which means time- slicing is disabled. The time-slice value for thread creation can be changed via the mpx_pthread_attr_settimeslice service.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_attr_setaffinity
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_attr_setaffinity(pthread_attr_t * attributes,
size_t cpusetsize, cpu_set_t * core_affinity);
```
**Description (extract)**
- When the MPX RTOS is configured for SMP (MPX_MAXIMUM_CORES greater than one), this pthreadsmore service sets the core affinity in the supplied attribute structure. When the attribute structure is initialized by default, the thread core affinity is set to the constant MPX_DEFAULT_CORE_AFFINITY. If MPX_MAXIMUM_CORES equals one, this service is irrelevant and not defined.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_attr_setautostart
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_attr_setautostart(pthread_attr_t *attributes,
int automatic_start);
```
**Description (extract)**
- This pthreadsmore service sets the automatic start option in the supplied attribute structure. By default, the thread automatic start option is set to MPX_AUTO_START, which means the thread will start automatically after it is created. By supplying MPX_DONT_START to this API, threads subsequently created with this attribute structure will be created in a suspended state and not execute until mpx_pthread_resume is called.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_attr_setcontroladdr
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_attr_setcontroladdr(pthread_attr_t *attributes,
void *	thread_control_address, size_t	thread_control_size);
```
**Description (extract)**
- This pthreadsmore service enables the developer to provide the memory for the internal MPX RTOS thread control structure, as specified by the address in the thread_control_address parameter. This memory will subsequently be used for the next thread created with this attribute structure. The memory size required for the internal thread control structure can be found via a call to the mpx_pthread_attr_getcontrolsize service.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_attr_setname
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_attr_setname(pthread_attr_t *attributes,
char *	name);
```
**Description (extract)**
- This pthreadsmore service stores the specified thread name (ASCII string) in the thread attributes structure.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_attr_setpriority
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_attr_setpriority(pthread_attr_t *attributes,
int	priority);
```
**Description (extract)**
- This pthreadsmore service stores the specified priority in the thread attributes structure. The thread priority must be between 0 and (MPX_MAXIMUM_PRIORITIES – 1), where larger numbers represent higher priority.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_attr_settimeslice
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_attr_settimeslice(pthread_attr_t *attributes,
u_long	time_slice);
```
**Description (extract)**
- This pthreadsmore service stores the specified time-slice in the thread attributes structure. A value of 0 turns off time-slicing (default), while positive values represent the number of timer ticks the thread can execute before giving other threads of the same priority a chance to execute.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_condattr_getcontroladdr
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_condattr_getcontroladdr(pthread_condattr_t * condition_var_attributes,
void ** condition_var_control_address);
```
**Description (extract)**
- This pthreadsmore service returns the previously supplied condition variable control structure address.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_condattr_getcontrolsize
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_condattr_getcontrolsize(pthread_condattr_t
* condition_var_attributes,
size_t * condition_var_control_size);
```
**Description (extract)**
- This pthreadsmore service returns the size of the internal condition variable control structure. The primary purpose of this API is to inform the application how much memory is required for the mpx_pthread_condattr_setcontroladdr API.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_condattr_getname
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_condattr_getname(pthread_condattr_t
* condition_var_attributes, char ** condition_var_name);
```
**Description (extract)**
- This pthreadsmore service returns the previously supplied condition variable name.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_condattr_setcontroladdr
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_condattr_setcontroladdr(pthread_condattr_t
* condition_var_attributes,
void * condition_var_control_address, size_t condition_var_control_size);
```
**Description (extract)**
- This pthreadsmore service enables the developer to provide the memory for the internal MPX RTOS condition variable structure as specified by the address in the condition_var_control_address parameter. This memory will subsequently be used for the next condition variable created with this attribute structure.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_condattr_setname
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_condattr_setname(pthread_condattr_t
* condition_var_attributes, char * cond_var_name);
```
**Description (extract)**
- This pthreadsmore service sets the condition variable name in the specified attribute structure.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_event_flags_clear
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_event_flags_clear(pthread_event_flags_t *
event_flags_handle);
```
**Description (extract)**
- This pthreadsmore service clears all event flags in the specified event flags group.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. No preemption is possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_event_flags_create
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_event_flags_create(pthread_event_flags_t * event_flags_handle,
pthread_event_flagsattr_t * event_flags_attributes);
```
**Description (extract)**
- This pthreadsmore service initializes (creates) an event flags group with the optional event flags attributes. If successful, the event flags handle is set up for further use by the application.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (120 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_event_flags_destroy
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_event_flags_destroy(pthread_event_flags_t *
event_flags_handle);
```
**Description (extract)**
- This pthreadsmore service destroys the previously created event flags group specified by event_flags_handle. An error is returned if the event flags group has any threads waiting for events.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (56 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_event_flags_set
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_event_flags_set(pthread_event_flags_t *
event_flags_handle, u_long events_to_set);
```
**Description (extract)**
- This pthreadsmore service sets all the event flags specified in events_to_set in the event flags group identified by event_flags_handle. All threads suspended on this event flags group that have their event flags request satisfied are resumed.
**Callable from (extract)**
- This service is callable from the thread context and interrupt handlers (ISRs).
**Real-time scenario (extract)**
- NO PREEMPTION. If no other threads are waiting for event flags, no preemption occurs.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (144 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_event_flags_timedwait
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_event_flags_timedwait(pthread_event_flags_t *
event_flags_handle, u_long requested_events, int all_or_any, u_long * received_events,
ticks_t timeout_ticks);
```
**Description (extract)**
- This pthreadsmore service retrieves the event flags specified by the requested_events parameter and in the manner specified by the all_or_any parameter from the specified event flags group. If the requested events are unavailable, this service suspends the calling thread until the specified timeout is reached.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. If the event flags are available, no preemption takes place.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (116 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_event_flags_trywait
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_event_flags_trywait(pthread_event_flags_t *
event_flags_handle, u_long requested_events, int all_or_any, u_long * received_events);
```
**Description (extract)**
- This pthreadsmore service attempts to retrieve the event flags specified by the requested_events parameter as specified by the all_or_any parameter from the specified event flags group. If the requested events are not available, this service returns an error.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. No preemption is possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (56 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_event_flags_wait
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_event_flags_wait(pthread_event_flags_t *
event_flags_handle, u_long requested_events, int all_or_any, u_long * received_events);
```
**Description (extract)**
- This pthreadsmore service retrieves the event flags specified by the requested_events parameter as specified by the all_or_any parameter from the specified event flags group. If the requested events are not available, this service suspends the calling thread.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. If the event flags are available, no preemption takes place.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (108 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_event_flagsattr_destroy
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_event_flagsattr_destroy(pthread_event_flagsattr_t *
event_flags_attributes);
```
**Description (extract)**
- This pthreadsmore service destroys the previously created event flags attributes structure pointed to by event_flags_attributes. Once destroyed, the event flags attributes structure cannot be used again unless it is recreated.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (8 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_event_flagsattr_getcontroladdr
**Prototype**
```c
#include <pthread.h>
int
mpx_pthread_event_flagsattr_getcontroladdr(pthread_event_flagsattr_t
* event_flags_attributes, void ** event_flags_control_address);
```
**Description (extract)**
- This pthreadsmore service returns the previously supplied event flags control structure memory address.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_event_flagsattr_getcontrolsize
**Prototype**
```c
#include <pthread.h>
int
mpx_pthread_event_flagsattr_getcontrolsize(pthread_event_flagsattr_t
* event_flags_attributes, size_t * event_flags_control_size);
```
**Description (extract)**
- This pthreadsmore service returns the size of the internal event flags control structure. The primary purpose of this API is to inform the application how much memory is required for the mpx_pthread_event_flagsattr_setcontroladdr API.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_event_flagsattr_getname
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_event_flagsattr_getname(pthread_event_flagsattr_t
* event_flags_attributes, char ** event_flags_name);
```
**Description (extract)**
- This pthreadsmore service returns the previously supplied event flags name.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_event_flagsattr_init
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_event_flagsattr_init(pthread_event_flagsattr_t *
event_flags_attributes);
```
**Description (extract)**
- This pthreadsmore service initializes the event flags attributes structure with default event flags creation values.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_event_flagsattr_setcontroladdr
**Prototype**
```c
#include <pthread.h>
int
mpx_pthread_event_flagsattr_setcontroladdr(pthread_event_flagsattr_t
* event_flags_attributes, void * event_flags_control_address,
size_t event_flags_control_size);
```
**Description (extract)**
- This pthreadsmore service enables the developer to provide the memory for the internal MPX RTOS event flags structure, as specified by the address in the event_flags_control_address parameter. This memory will subsequently be used for the next event flags created with this attribute structure. The memory size required for the internal event flags control structure can be found via a call to the mpx_pthread_event_flagsattr_getcontrolsize service.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_event_flagsattr_setname
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_event_flagsattr_setname(pthread_event_flagsattr_t
* event_flags_attributes, char * event_flags_name);
```
**Description (extract)**
- This pthreadsmore service sets the event flags name in the specified attribute structure.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_fastqueue_create
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_fastqueue_create(pthread_fastqueue_t *fastqueue_handle, pthread_fastqueueattr_t * fast_queue_attributes,
size_t message_size, int max_messages);
```
**Description (extract)**
- This pthreadsmore service initializes (creates) a fastqueue with the optional fast queue attributes. If successful, the fastqueue handle is set up for further use by the application.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (160 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_fastqueue_destroy
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_fastqueue_destroy(pthread_fastqueue_t *
fastqueue_handle);
```
**Description (extract)**
- This pthreadsmore service destroys the previously created fastqueue specified by fastqueue_handle. An error is returned if the fastqueue has any threads waiting for a message.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (64 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_fastqueue_receive
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_fastqueue_receive(pthread_fastqueue_t * fastqueue_handle, u_long * message_destination, size_t message_size);
```
**Description (extract)**
- This pthreadsmore service receives a message from the specified fastqueue. If the fastqueue is empty, this thread suspends until a message is sent to the fastqueue. If a thread is waiting to send to the fastqueue, the thread’s message is placed in the fastqueue and is resumed.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. If there are one or more messages in the fastqueue, no preemption occurs.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (128 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_fastqueue_send
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_fastqueue_send(pthread_fastqueue_t * fastqueue_handle, u_long * message_source, size_t message_size);
```
**Description (extract)**
- This pthreadsmore service sends the specified message to the specified fastqueue. If there is a thread waiting on the fastqueue, this message is delivered to the thread and it is resumed. If the fastqueue is full, this thread suspends until there is room in the fastqueue.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. If no other threads are waiting for a message on the fastqueue, no preemption occurs.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (128 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_fastqueue_timedreceive
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_fastqueue_timedeceive(pthread_fastqueue_t * fastqueue_handle, u_long * message_destination, size_t message_size, tick_t timeout_ticks);
```
**Description (extract)**
- This pthreadsmore service attempts to receive a message from the specified fastqueue. If the fastqueue is empty, this service suspends waiting for a message from the queue. An error is returned if no message is received before the specified timeout.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. If there are one or more messages in the fastqueue, no preemption occurs.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (144 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_fastqueue_timedsend
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_fastqueue_timedsend(pthread_fastqueue_t *
fastqueue_handle, u_long * message_source, size_t message_size, ticks_t timeout_ticks);
```
**Description (extract)**
- This pthreadsmore service tries to send the specified message to the specified fastqueue. If there is a thread waiting on the fastqueue, this message is delivered to the thread and it is resumed. If the fastqueue is full, this service suspends waiting for room in the queue. An error is returned if there is no room in the queue before the specified timeout.
**Callable from (extract)**
- This service is callable from the thread context and interrupt handlers (ISRs).
**Real-time scenario (extract)**
- NO PREEMPTION. If no other threads are waiting for a message on the fastqueue, no preemption occurs.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (144 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_fastqueue_tryreceive
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_fastqueue_tryreceive(pthread_fastqueue_t * fastqueue_handle, u_long * message_destination, size_t message_size);
```
**Description (extract)**
- This pthreadsmore service attempts to receive a message from the specified fastqueue. If the fastqueue is empty, this service returns an error.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. If there are one or more messages in the fastqueue, no preemption occurs.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (128 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_fastqueue_trysend
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_fastqueue_trysend(pthread_fastqueue_t *
fastqueue_handle, u_long * message_source, size_t message_size);
```
**Description (extract)**
- This pthreadsmore service tries to send the specified message to the specified fastqueue. If there is a thread waiting on the fastqueue, this message is delivered to the thread and it is resumed. If the fastqueue is full, an error is returned.
**Callable from (extract)**
- This service is callable from the thread context and interrupt handlers (ISRs).
**Real-time scenario (extract)**
- NO PREEMPTION. If no other threads are waiting for a message on the fastqueue, no preemption occurs.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (128 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_fastqueueattr_destroy
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_fastqueueattr_destroy(pthread_fastqueueattr_t *
fastqueue_attributes);
```
**Description (extract)**
- This pthreadsmore service destroys the previously created fastqueue attributes structure pointed to by fastqueue_attributes. Once destroyed, the fastqueue attributes structure cannot be used again unless it is recreated.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_fastqueueattr_getcontroladdr
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_fastqueueattr_getcontroladdr(pthread_fastqueueattr_t
* fastqueue_attributes, void ** fastqueue_control_address);
```
**Description (extract)**
- This pthreadsmore service returns the previously supplied fastqueue control structure memory address.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_fastqueueattr_getcontrolsize
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_fastqueueattr_getcontrolsize(pthread_fastqueueattr_t
* fastqueue_attributes, size_t * fastqueue_control_size);
```
**Description (extract)**
- This pthreadsmore service returns the size of the internal fastqueue control structure. The primary purpose of this API is to inform the application how much memory is required for the mpx_pthread_fastqueueattr_setcontroladdr API.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_fastqueueattr_getname
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_fastqueueattr_getname(pthread_fastqueueattr_t
* fastqueue_attributes, char ** fastqueue_name);
```
**Description (extract)**
- This pthreadsmore service returns the previously supplied fastqueue name.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_fastqueueattr_getqueueaddr
**Prototype**
```c
#include <pthead.h>
int mpx_pthread_fastqueueattr_getqueueaddr(pthread_fastqueueattr_t* fastqueue_attributes,
void ** fastqueue_memory_address);
```
**Description (extract)**
- This pthreadsmore service returns the previously supplied fastqueue memory area address.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_fastqueueattr_getqueuesize
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_fastqueueattr_getqueuesize(pthread_fastqueueattr_t* fastqeueu_attributes, size_t * fastqueue_memory_size);
```
**Description (extract)**
- This pthreadsmore service returns the size of the previously supplied fastqueue memory area.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_fastqueueattr_init
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_fastqueueattr_init(pthread_fastqueueattr_t *
fastqueue_attributes);
```
**Description (extract)**
- This pthreadsmore service initializes the fastqueue attributes structure with default fastqueue creation values.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_fastqueueattr_setcontroladdr
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_fastqueueattr_setcontroladdr(pthread_fastqueueattr_t
* fastqueue_attributes, void * fastqueue_control_address,
size_t fastqueue_control_size);
```
**Description (extract)**
- This pthreadsmore service enables the developer to provide the memory for the internal MPX RTOS fastqueue structure as specified by the address in the fastqueue_control_address parameter. This memory will subsequently be used for the fastqueue created with this attribute structure. The memory size required for the internal fastqueue control structure can be found via a call to the mpx_pthread_fastqueueattr_getcontrolsize service.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_fastqueueattr_setname
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_fastqueueattr_setname(pthread_fastqueueattr_t
* fastqueue_attributes, char * fastqueue_name);
```
**Description (extract)**
- This pthreadsmore service sets the fastqueue name in the specified attribute structure.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_fastqueueattr_setqueueaddr
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_fastqueueattr_setqueueaddr(pthread_fastqueueattr_t*
fastqueue_attributes,
void * fastqueue_memory_address, size_t fastqueue_memory_size);
```
**Description (extract)**
- This pthreadsmore service sets the internal fastqueue message memory address to the address specified by fastqueue_memory_address. This address will subsequently be used to supply the memory for the message area on the next fastqueue created with this attribute structure.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_information_get
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_information_get(pthread_t thread_handle, char **name, int * state, int * priority, void ** stack_limit, void ** stack_pointer,
u_long * minimum_stack, pthread_t * next_thread);
```
**Description (extract)**
- This pthreadsmore service retrieves the specified information from the specified thread.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (78 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_memory_manager_enable
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_memory_manager_enable(void);
```
**Description (extract)**
- This pthreadsmore service enables full management of the remaining memory supplied by the application when the MPX RTOS is started via mpx_pthread_start. The memory allocated with all subsequent system object creation and destruction will be fully managed.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. This service does not result in preemption.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (242 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_memory_manager_get
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_memory_manager_get(
void *(** memory_allocate)(u_int type, u_long size),
void (** memory_release)(u_int type, void *memory_to_release));
```
**Description (extract)**
- This pthreadsmore service retrieves the internal memory manager allocate and release function pointers. These function pointers can be used to restore the previous memory manager allocation and deallocation selection.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. This service does not result in preemption.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_memory_manager_set
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_memory_manager_set(
void *(* memory_allocate)(u_int type, u_long size),
void (* memory_release)(u_int type, void *memory_to_release));
```
**Description (extract)**
- This pthreadsmore service installs the specified memory manager allocate and release function pointers.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. This service does not result in preemption.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_memorypool_allocate
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_memorypool_allocate(pthread_memorypool_t *
memorypool_handle, void ** allocated_memory, size_t request_size);
```
**Description (extract)**
- This pthreadsmore service attempts to allocate memory from the specified memory pool. If there is insufficient memory in the pool, the calling thread is suspended until the request can be satisfied.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. If the requested memory is available, no preemption takes place.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (264 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the context of the application.

### mpx_pthread_memorypool_create
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_memorypool_create(pthread_memorypool_t * memorypool_handle,
pthread_memorypoolattr_t * memorypool_attributes, void *pool_start, size_t pool_size);
```
**Description (extract)**
- This pthreadsmore service creates a variable-length memory pool with the optional memory pool attributes. If successful, the memory pool handle is set up for further use by the application.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (240 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the context of the application.

### mpx_pthread_memorypool_destroy
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_memorypool_destroy(pthread_memorypool_t *
memorypool_handle);
```
**Description (extract)**
- This pthreadsmore service destroys the previously created memory pool specified by memorypool_handle. An error is returned if the memory pool has suspended threads waiting for memory.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, there should be at least (120 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the context of the application.

### mpx_pthread_memorypool_free
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_memorypool_free(void * memory_to_release);
```
**Description (extract)**
- This pthreadsmore service releases the previously allocated memory back to the memory pool it was allocated from. Any threads that are suspended on the memory pool that are waiting for this memory are resumed.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. No preemption occurs if no other threads are waiting for memory from the associated memory pool.
**Stack usage (extract)**
- From the location where this API is called, at least (232 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_memorypool_timedallocate
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_memorypool_timedallocate(pthread_memorypool_t *
memorypool_handle, void ** allocated_memory, size_t request_size, ticks_t timeout_ticks);
```
**Description (extract)**
- This pthreadsmore service attempts to allocate memory from the specified memory pool. If there is insufficient memory in the pool, the calling thread is suspended until the request can be satisfied or the specified timeout expires.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. If the requested memory is available, no preemption takes place.
**Stack usage (extract)**
- From the location where this API is called, at least (280 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_memorypool_tryallocate
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_memorypool_tryallocate(pthread_memorypool_t *
memorypool_handle, void ** allocated_memory, size_t request_size);
```
**Description (extract)**
- This pthreadsmore service attempts to allocate memory from the specified memory pool. An error is returned if there is not enough memory in the pool.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. No preemption takes place with this API.
**Stack usage (extract)**
- From the location where this API is called, at least (256 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_memorypoolattr_destroy
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_memorypoolattr_destroy(pthread_memorypoolattr_t *
memorypool_attributes);
```
**Description (extract)**
- This pthreadsmore service destroys the previously created memory pool attributes structure pointed to by memorypool_attributes. Once destroyed, the memory pool attributes structure cannot be used again unless it is recreated.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_memorypoolattr_getcontroladdr
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_memorypoolattr_getcontroladdr(pthread_memorypoolattr_t
* memorypool_attributes, void ** memorypool_control_address);
```
**Description (extract)**
- This pthreadsmore service returns the previously supplied memory pool control structure memory address.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_memorypoolattr_getcontrolsize
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_memorypoolattr_getcontrolsize(pthread_memorypoolattr_t
* memorypool_attributes, size_t * memorypool_control_size);
```
**Description (extract)**
- This pthreadsmore service returns the size of the internal memory pool control structure. The primary purpose of this API is to inform the application how much memory is required for the mpx_pthread_memorypoolattr_setcontroladdr API.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_memorypoolattr_getname
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_memorypoolattr_getname(pthread_memorypoolattr_t
* memorypool_attributes, char ** memorypool_name);
```
**Description (extract)**
- This pthreadsmore service returns the previously supplied memory pool name.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_memorypoolattr_init
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_memorypoolattr_init(pthread_memorypoolattr_t *
memorypool_attributes);
```
**Description (extract)**
- This pthreadsmore service initializes the memory pool attributes structure with default memory pool creation values.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_memorypoolattr_setcontroladdr
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_memorypoolattr_setcontroladdr(pthread_memorypoolattr_t
* memorypool_attributes, void * memorypool_control_address,
size_t memorypool_control_size);
```
**Description (extract)**
- This pthreadsmore service enables the developer to provide the memory for the internal MPX RTOS memory pool structure as specified by the address in the memorypool_control_address parameter. This memory will subsequently be used for the next memory pool created with this attribute structure. The memory size required for the internal memory pool control structure can be found via a call to the mpx_pthread_memorypoolattr_getcontrolsize service.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_memorypoolattr_setname
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_memorypoolattr_setname(pthread_memorypoolattr_t
* memorypool_attributes, char * memorypool_name);
```
**Description (extract)**
- This pthreadsmore service sets the memory pool name in the specified attribute structure.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_mutexattr_getcontroladdr
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_mutexattr_getcontroladdr(pthread_mutexattr_t
*mutex_attributes, void ** mutex_control_address);
```
**Description (extract)**
- This pthreadsmore service returns the previously supplied mutex control structure address.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_mutexattr_getcontrolsize
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_mutexattr_getcontrolsize(pthread_mutexattr_t
*mutex_attributes, size_t * mutex_control_size);
```
**Description (extract)**
- This pthreadsmore service returns the size of the internal mutex control structure. The primary purpose of this API is to inform the application how much memory is required for the mpx_pthread_mutexattr_setcontroladdr API.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_mutexattr_getname
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_mutexattr_getname(pthread_mutexattr_t
*mutex_attributes, char ** mutex_name);
```
**Description (extract)**
- This pthreadsmore service returns the previously supplied mutex name.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_mutexattr_setcontroladdr
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_mutexattr_setcontroladdr(pthread_mutexattr_t
*mutex_attributes, void * mutex_control_address, size_t mutex_control_size);
```
**Description (extract)**
- This pthreadsmore service enables the developer to provide the memory for the internal MPX RTOS mutex structure, as specified by the address in the mutex_control_address parameter. This memory will subsequently be used for the next mutex created with this attribute structure. The memory size required for the internal mutex control structure can be found via a call to the mpx_pthread_mutexattr_getcontrolsize service.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_mutexattr_setname
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_mutexattr_setname(pthread_mutexattr_t
*mutex_attributes, char * mutex_name);
```
**Description (extract)**
- This pthreadsmore service sets the mutex name in the specified attribute structure.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_partitionpool_allocate
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_partitionpool_allocate(pthread_partitionpool_t *
partitionpool_handle, void ** allocated_memory, size_t request_size);
```
**Description (extract)**
- This pthreadsmore service attempts to allocate a memory partition from the specified partition memory pool. If there is no partition memory in the pool, the calling thread is suspended until the request can be satisfied.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. If the requested partition memory is available, no preemption takes place.
**Stack usage (extract)**
- From the location where this API is called, at least (100 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_partitionpool_create
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_partitionpool_create(pthread_partitionpool_t * partitionpool_handle,
pthread_partitionpoolattr_t * partitionpool_attributes, void *pool_start, size_t pool_size, size_t partition_size);
```
**Description (extract)**
- This pthreadsmore service creates a fixed-length partition memory pool with the specified partition size and optional partition memory pool attributes. If successful, the partition memory pool handle is set up for further use by the application.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (160 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_partitionpool_destroy
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_partitionpool_destroy(pthread_partitionpool_t *
partitionpool_handle);
```
**Description (extract)**
- This pthreadsmore service destroys the previously created partition memory pool specified by partitionpool_handle. An error is returned if the partition memory pool has any suspended threads waiting for memory.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (56 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_partitionpool_free
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_partitionpool_free(void * memory_to_release);
```
**Description (extract)**
- This pthreadsmore service releases the previously allocated partition memory back to the partition memory pool it was allocated from. If a thread is suspended on this partition memory pool, the memory partition is given to the suspended thread, and it is resumed.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. No preemption occurs if no other threads are waiting for partition memory from the associated partition memory pool.
**Stack usage (extract)**
- From the location where this API is called, at least (112 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_partitionpool_timedallocate
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_partitionpool_timedallocate(pthread_partitionpool_t * partitionpool_handle, void ** allocated_memory, size_t request_size, ticks_t timeout_ticks);
```
**Description (extract)**
- This pthreadsmore service attempts to allocate a memory partition from the specified partition memory pool. If there are no memory partitions in the pool, the calling thread is suspended until the request can be satisfied or the specified timeout expires.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. If the requested memory partition is available, no preemption takes place.
**Stack usage (extract)**
- From the location where this API is called, at least (116 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_partitionpool_tryallocate
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_partitionpool_tryallocate(pthread_partitionpool_t * partitionpool_handle, void ** allocated_memory, size_t request_size);
```
**Description (extract)**
- This pthreadsmore service attempts to allocate a memory partition from the specified partition memory pool. An error is returned if there are no memory partitions in the pool.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. No preemption takes place with this API.
**Stack usage (extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_partitionpoolattr_destroy
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_partitionpoolattr_destroy(pthread_partitionpoolattr_t *
partitionpool_attributes);
```
**Description (extract)**
- This pthreadsmore service destroys the previously created partition memory pool attributes structure pointed to by partitionpool_attributes. Once destroyed, the partition memory pool attributes structure cannot be used again unless it is recreated.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_partitionpoolattr_getcontroladdr
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_partitoinpoolattr_getcontroladdr( pthread_partitionpoolattr_t	* memorypool_attributes, void ** partitionpool_control_address);
```
**Description (extract)**
- This pthreadsmore service returns the previously supplied partition memory pool control structure memory address.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_partitionpoolattr_getcontrolsize
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_partitionpoolattr_getcontrolsize( pthread_partitionpoolattr_t	* memorypool_attributes, size_t * memorypool_control_size);
```
**Description (extract)**
- This pthreadsmore service returns the size of the internal partition memory pool control structure. The primary purpose of this API is to inform the application how much memory is required for the mpx_pthread_partitionpoolattr_setcontroladdr API.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_partitionpoolattr_getname
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_partitionpoolattr_getname(pthread_partitionpoolattr_t
* partitionpool_attributes, char ** partitionpool_name);
```
**Description (extract)**
- This pthreadsmore service returns the previously supplied partition memory pool name.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_partitionpoolattr_init
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_partitionpoolattr_init(pthread_partitionpoolattr_t *
partitionpool_attributes);
```
**Description (extract)**
- This pthreadsmore service initializes the partition memory pool attributes structure with default partition memory pool creation values.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_partitionpoolattr_setcontroladdr
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_partitionpoolattr_setcontroladdr( pthread_partitionpoolattr_t * partitionpool_attributes, void * partitionpool_control_address,
size_t partitionpool_control_size);
```
**Description (extract)**
- This pthreadsmore service enables the developer to provide the memory for the internal MPX RTOS partition memory pool structure as specified by the address in the partitionpool_control_address parameter. This memory will subsequently be used for the next partition memory pool created with this attribute structure. The memory size required for the internal memory pool control structure can be found via a call to the mpx_pthread_partitionpoolattr_getcontrolsize service.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_partitionpoolattr_setname
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_memorypoolattr_setname(pthread_memorypoolattr_t
* memorypool_attributes, char * memorypool_name);
```
**Description (extract)**
- This pthreadsmore service sets the partition memory pool name in the specified attribute structure.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_priority_change
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_priority_change(pthread_t thread_handle,
int new_priority, int * old_priority);
```
**Description (extract)**
- This pthread+ service changes the priority of the specified thread. If the old_priority parameter is non-NULL, the previous priority is placed in the specified destination.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. If the new priority is not higher than the calling thread, there is no preemption.
**Stack usage (extract)**
- From the location where this API is called, at least (120 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_resume
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_resume(pthread_t thread_handle);
```
**Description (extract)**
- This pthread+ service resumes a previously suspended thread. If the specified thread is not suspended, an error is returned.
**Callable from (extract)**
- This service is callable from the thread context and interrupt handlers (ISRs).
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption if the thread resumed is not a higher priority.
**Stack usage (extract)**
- From the location where this API is called, at least (80 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_stack_check
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_stack_check(pthread_t thread_handle,
u_long * minimum_available_stack);
```
**Description (extract)**
- This pthread+ service calculates the minimum available stack of the specified thread. If the size is less than the constant MPX_BINDING_STACK_FRAME_SIZE, the central error handler is called by this service.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (56 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_start
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_start(u_long run_time_id, void * memory_start,
u_long memory_size);
```
**Description (extract)**
- This pthreadsmore service starts the MPX RTOS. It should be called early in C main. Once invoked, all internal data structures are initialized and prepared for operation. The initialization processing also includes verification of the binding layer – the processor/compiler-specific layer of MPX. If the start process is successful, the C main function is upscaled into the first thread in the system.
**Callable from (extract)**
- This service is callable only once from the C main entry function.
**Real-time scenario (extract)**
- NO PREEMPTION. Even though C main is upscaled into the first thread, there is no actual preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (64 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_suspend
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_suspend(pthread_t thread_handle);
```
**Description (extract)**
- This pthread+ service suspends the specified thread. If the specified thread is already suspended, an error is returned.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. If the thread suspended is not the executing thread, there is no preemption.
**Stack usage (extract)**
- From the location where this API is called, at least (60 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_tick_sleep
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_tick_sleep(tick_t ticks_to_sleep);
```
**Description (extract)**
- This pthreadsmore service suspends the calling thread for the number of timer ticks specified by ticks_to_sleep. If a value of 0 ticks is supplied, this service returns immediately, i.e., the calling thread is not suspended.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. If the number of ticks to sleep is zero, no preemption occurs.
**Stack usage (extract)**
- From the location where this API is called, at least (60 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_ticks_get
**Prototype**
```c
#include <pthread.h>
tick_t mpx_pthread_ticks_get(void);
```
**Description (extract)**
- This pthreadsmore service returns the internal tick count, representing the number of timer interrupts.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. No preemption takes place as a result of this service.
**Stack usage (extract)**
- From the location where this API is called, at least (8 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_ticktimer_create
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_ticktimer_create(pthread_ticktimer_t *ticktimer_handle, pthread_ticktimerattr_t * attributes,
void (*expiration_routine)(pthread_ticktimer_t *, void *), void *argument, tick_t initial_ticks, tick_t reload_ticks);
```
**Description (extract)**
- This pthreadsmore service creates a ticktimer that calls the specified expiration routine after the specified number of initial ticks. If a non-zero value is supplied for reload, this ticktimer will operate periodically.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (152 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_ticktimer_destroy
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_ticktimer_destroy(pthread_ticktimer_t
*ticktimer_handle);
```
**Description (extract)**
- This pthreadsmore service destroys a previously created but stopped ticktimer.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (56 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_ticktimer_start
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_ticktimer_start(pthread_ticktimer_t *ticktimer_handle);
```
**Description (extract)**
- This pthreadsmore service starts a previously created ticktimer.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (48 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_ticktimer_stop
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_ticktimer_stop(pthread_ticktimer_t *ticktimer_handle);
```
**Description (extract)**
- This pthreadsmore service stops a previously created ticktimer. When stopped, the remaining number of ticks before expiration is saved. If the ticktimer is restarted, it is restarted with the previous remaining number of ticks.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (48 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_ticktimer_update
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_ticktimer_update(pthread_ticktimer_t *ticktimer_handle,
tick_t initial_ticks, tick_t reload_ticks);
```
**Description (extract)**
- This pthreadsmore service updates the initial ticks and reload ticks of a previously created but stopped ticktimer.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_ticktimerattr_destroy
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_ticktimerattr_destroy(pthread_ticktimerattr_t *
ticktimer_attributes);
```
**Description (extract)**
- This pthreadsmore service destroys the previously created ticktimer attributes structure pointed to by ticktimer_attributes. Once destroyed, the ticktimer attributes structure cannot be used again unless it is recreated.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_ticktimerattr_getcontroladdr
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_ticktimerattr_getcontroladdr(pthread_ticktimerattr_t
* ticktimer_attributes, void ** ticktimer_control_address);
```
**Description (extract)**
- This pthreadsmore service returns the previously supplied ticktimer control structure memory address.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_ticktimerattr_getcontrolsize
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_ticktimerattr_getcontrolsize(pthread_ticktimerattr_t
*ticktimer_attributes, size_t * ticktimer_control_size);
```
**Description (extract)**
- This pthreadsmore service returns the size of the internal ticktimer control structure. The primary purpose of this API is to inform the application how much memory is required for the mpx_pthread_ticktimerattr_setcontroladdr API.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_ticktimerattr_getname
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_ticktimerattr_getname(pthread_ticktimerattr_t
*ticktimer_attributes, char ** ticktimer_name);
```
**Description (extract)**
- This pthreadsmore service returns the previously supplied ticktimer name.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_ticktimerattr_init
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_ticktimerattr_init(pthread_ticktimerattr_t *
ticktimer_attributes);
```
**Description (extract)**
- This pthreadsmore service initializes the ticktimer attributes structure with default ticktimer creation values.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_ticktimerattr_setcontroladdr
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_ticktimerattr_setcontroladdr(pthread_ticktimerattr_t
* ticktimer_attributes, void * ticktimer_control_address,
size_t ticktimer_control_size);
```
**Description (extract)**
- This pthreadsmore service enables the developer to provide the memory for the internal MPX RTOS ticktimer structure as specified by the address in the ticktimer_control_address parameter. This memory will subsequently be used for the next ticktimer created with this attribute structure. The memory size required for the internal ticktimer control structure can be found via a call to the mpx_pthread_ticktimerattr_getcontrolsize service.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_pthread_ticktimerattr_setname
**Prototype**
```c
#include <pthread.h>
int mpx_pthread_ticktimerattr_setname(pthread_ticktimerattr_t
* ticktimer_attributes, char * ticktimer_name);
```
**Description (extract)**
- This pthreadsmore service sets the ticktimer name in the specified attribute structure.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_sem_extend_init
**Prototype**
```c
#include <semaphore.h>
int mpx_sem_extend_init(sem_t * semaphore_handle, int pshared, unsigned int value, semattr_t * semaphore_attributes);
```
**Description (extract)**
- This pthreadsmore service extension initializes (creates) a semaphore with the specified initial value and with optional MPX semaphore attributes. If successful, the semaphore handle is available for use by the application. This service is an alternative to the sem_init API, i.e., all semaphore APIs can be used on the semaphore created with this extended API.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (144 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_sem_tickwait
**Prototype**
```c
#include <semaphore.h>
int mpx_sem_tickwait(sem_t * semaphore_handle, tick_t timeout_ticks);
```
**Description (extract)**
- If the semaphore is available (count greater than zero), this service decrements the semaphore count by one and returns success to the caller. Otherwise, if the semaphore is zero, the calling thread suspends until the semaphore is available or until the timeout expires.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. If the semaphore is available, no preemption takes place.
**Stack usage (extract)**
- From the location where this API is called, at least (100 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_semattr_destroy
**Prototype**
```c
#include <semaphore.h>
int mpx_semattr_destroy(semttr_t * semaphore_attributes);
```
**Description (extract)**
- This pthreadsmore service destroys the previously created semaphore attributes structure pointed to by semaphore_attributes. Once destroyed, the semaphore attributes structure cannot be used again unless recreated.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_semattr_getcontroladdr
**Prototype**
```c
#include <semaphore.h>
int mpx_semattr_getcontroladdr(semattr_t * semaphore_attributes, void ** semaphore_control_address);
```
**Description (extract)**
- This pthreadsmore service returns the previously supplied semaphore control structure address.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_semattr_getcontrolsize
**Prototype**
```c
#include <semaphore.h>
int mpx_semattr_getcontrolsize(semattr_t * semaphore_attributes,
size_t * semaphore_control_size);
```
**Description (extract)**
- This pthreadsmore service returns the size of the internal semaphore control structure. The primary purpose of this API is to inform the application how much memory is required for the mpx_semattr_setcontroladdr API.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_semattr_getname
**Prototype**
```c
#include <semaphore.h>
int mpx_semattr_getname(semattr_t * semaphore_attributes,
char ** semaphore_name);
```
**Description (extract)**
- This pthreadsmore service returns the previously supplied semaphore name.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_semattr_init
**Prototype**
```c
#include <semaphore.h>
int mpx_semattr_init(semattr_t * semaphore_attributes);
```
**Description (extract)**
- This pthreadsmore service initializes the semaphore attributes structure with default semaphore variable creation values. Note that semaphore attributes are used only by the mpx_sem_extend_init API.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_semattr_setcontroladdr
**Prototype**
```c
#include <semaphore.h>
int mpx_semattr_setcontroladdr(semattr_t * semaphore_attributes,
void * semaphore_control_address, size_t semaphore_control_size);
```
**Description (extract)**
- This pthreadsmore service enables the developer to provide the memory for the internal MPX RTOS semaphore structure, as specified by the address in the semaphore_control_address parameter. This memory will subsequently be used for the next semaphore created with this attribute structure. The memory size required for the internal semaphore control structure can be found via a call to the mpx_semattr_getcontrolsize service.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### mpx_semattr_setname
**Prototype**
```c
#include <semaphore.h>
int mpx_semattr_setname(semattr_t * semaphore_attributes,
char * semaphore_name);
```
**Description (extract)**
- This pthreadsmore service sets the semaphore name in the specified attribute structure.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### sched_yield
**Prototype**
```c
#include <sched.h> int sched_yield(void);
```
**Description (extract)**
- This service relinquishes control to the next thread of the same priority currently ready for execution. If there is no other thread of the same priority ready for execution, this service simply returns a successful status.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. If no other threads of the same priority are ready for execution, this service returns without preemption.
**Stack usage (extract)**
- From the location where this API is called, at least (8 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### sem_destroy
**Prototype**
```c
#include <semaphore.h>
int sem_destroy(sem_t * semaphore_handle);
```
**Description (extract)**
- This service destroys the previously created semaphore specified by semaphore_handle. An error is returned if one or more threads are suspended on this semaphore.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (64 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### sem_init
**Prototype**
```c
#include <semaphore.h>
int sem_init(sem_t * semaphore_handle, int pshared,
unsigned int value);
```
**Description (extract)**
- This service initializes (creates) a semaphore with the specified initial value. If successful, the semaphore handle is available for use by the application.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. There is no preemption possible with this service.
**Stack usage (extract)**
- From the location where this API is called, at least (128 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### sem_post
**Prototype**
```c
#include <semaphore.h>
int sem_post(sem_t * semaphore_handle);
```
**Description (extract)**
- This service posts to the specified semaphore. If one or more threads are waiting, the highest priority thread waiting is resumed. Otherwise, if no threads are waiting, the internal semaphore count is incremented by one.
**Callable from (extract)**
- This service is callable from the thread context and interrupt handlers (ISRs).
**Real-time scenario (extract)**
- NO PREEMPTION. If no other threads are waiting for the semaphore, no preemption occurs.
**Stack usage (extract)**
- From the location where this API is called, at least (120 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### sem_timedwait
**Prototype**
```c
#include <semaphore.h>
int sem_timedwait(sem_t * semaphore_handle,
const struct timespec *absolute_time);
```
**Description (extract)**
- If the semaphore is available (count greater than zero), this service decrements the semaphore count by one and returns success to the caller. Otherwise, if the semaphore is zero, the calling thread suspends until the semaphore is available or until the absolute time is reached.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. If the semaphore is available, no preemption takes place.
**Stack usage (extract)**
- From the location where this API is called, at least (116 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### sem_trywait
**Prototype**
```c
#include <semaphore.h>
int sem_trywait(sem_t * semaphore_handle);
```
**Description (extract)**
- If the semaphore is available (count greater than zero), this service decrements the count and returns success. Otherwise, an error is returned.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. No preemption occurs if the semaphore is available.
**Stack usage (extract)**
- From the location where this API is called, at least (40 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### sem_wait
**Prototype**
```c
#include <semaphore.h>
int sem_wait(sem_t * semaphore_handle);
```
**Description (extract)**
- If the semaphore is available (count greater than zero), this service decrements the semaphore count by one and returns success to the caller. Otherwise, if the semaphore is zero, the calling thread suspends until the semaphore is available.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. If the semaphore is available, no preemption takes place.
**Stack usage (extract)**
- From the location where this API is called, at least (92 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### sigaction
**Prototype**
```c
#include <signal.h>
int sigaction(int signal_number, struct sigaction * new_handler,
struct sigaction * previous_handler);
```
**Description (extract)**
- This service sets up the signal handler for the specified signal number. If the previous handler pointer is non-NULL, the information for the previous signal handler is also returned.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. This service only sets up the signal handler, so no preemption is possible.
**Stack usage (extract)**
- From the location where this API is called, at least (48 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### sigaddset
**Prototype**
```c
#include <signal.h>
int sigaddset(sigset_t * signal_set, int signal_number);
```
**Description (extract)**
- This service adds the specified signal_number to the set of signals.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. This service only adds the signal number in the signal set, so no preemption is possible.
**Stack usage (extract)**
- From the location where this API is called, at least (48 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### sigdelset
**Prototype**
```c
#include <signal.h>
int sigdelset(sigset_t * signal_set, int signal_number);
```
**Description (extract)**
- This service deletes the specified signal_number from the set of signals.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. This service only deletes the signal number in the signal set, so no preemption is possible.
**Stack usage (extract)**
- From the location where this API is called, at least (48 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### sigemptyset
**Prototype**
```c
#include <signal.h>
int sigemptyset(sigset_t * signal_set);
```
**Description (extract)**
- This service removes all signals from the specified set of signals.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. This service removes all signals from the signal set, making no preemption possible.
**Stack usage (extract)**
- From the location where this API is called, at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### sigfillset
**Prototype**
```c
#include <signal.h>
int sigfillset(sigset_t * signal_set);
```
**Description (extract)**
- This service sets all signals in the specified set of signals.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. This service only sets signals in the signal set, so no preemption is possible.
**Stack usage (extract)**
- From the location where this API is called, at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### sigismember
**Prototype**
```c
#include <signal.h>
int sigismember(sigset_t * signal_set, int signal_number);
```
**Description (extract)**
- This service determines if signal_number is part of the specified signal set.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. This service only checks for a signal in the signal set, so no preemption is possible.
**Stack usage (extract)**
- From the location where this API is called, at least (48 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### sigpending
**Prototype**
```c
#include <signal.h>
int sigpending(sigset_t * pending_signals);
```
**Description (extract)**
- This service retrieves the pending signals for the calling thread.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. This service only retrieves the pending signals of the calling thread, so no preemption is possible.
**Stack usage (extract)**
- From the location where this API is called, at least (32 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### sigtimedwait
**Prototype**
```c
#include <signal.h>
int sigtimedwait(const sigset_t * signals, siginfo_t * signal_info,
const struct timespec * timeout);
```
**Description (extract)**
- This service suspends the calling thread until a signal in the specified signal set is raised. If the signal is already pending, this service returns immediately with the corresponding signal number. If none of the signals in the set are pending, this service suspends the calling thread until a signal in the set is raised or until the specified timeout occurs.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. A signal is already pending in the specified signal set, and this service returns immediately. No preemption takes place.
**Stack usage (extract)**
- From the location where this API is called, at least (132 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### sigwait
**Prototype**
```c
#include <signal.h>
int sigwait(const sigset_t * signals, int * signal_number);
```
**Description (extract)**
- This service suspends the calling thread until a signal in the specified signal set is raised. If the signal is already pending, this service returns immediately with the corresponding signal number. If none of the signals in the specified set are pending, this service suspends the calling thread until a signal in the set is raised.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. A signal is already pending in the specified signal set, and this service returns immediately. No preemption takes place.
**Stack usage (extract)**
- From the location where this API is called, at least (92 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### sigwaitinfo
**Prototype**
```c
#include <semaphore.h>
int sigwaitinfo(const sigset_t * signals, siginfo_t * signal_info);
```
**Description (extract)**
- This service suspends the calling thread until a signal in the specified signal set is raised. If the signal is already pending, this service returns immediately with the corresponding signal number (and additional signal information in signal_info). If none of the signals in the specified set are pending, this service suspends the calling thread until a signal in the set is raised.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Real-time scenario (extract)**
- NO PREEMPTION. A signal is already pending in the specified signal set, and this service returns immediately. No preemption takes place.
**Stack usage (extract)**
- From the location where this API is called, at least (108 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### sleep
**Prototype**
```c
#include <unistd.h>
unsigned int sleep(unsigned int seconds);
```
**Description (extract)**
- This service causes the calling thread to suspend for the number of seconds specified in seconds. If an unmasked signal is sent to the thread while sleeping, the thread is resumed, and the remaining seconds are returned.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Stack usage (extract)**
- From the location where this API is called, at least (132 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

### time
**Prototype**
```c
#include <pthread.h>
time_t time(time_t * return_seconds);
```
**Description (extract)**
- This service returns the current number of seconds. If a non-null value for return_seconds is provided, the current number of seconds is also placed in the destination pointed to by return_seconds.

### usleep
**Prototype**
```c
#include <unistd.h>
int usleep(useconds_t microseconds);
```
**Description (extract)**
- This service causes the calling thread to suspend for the time specified in microseconds. If an unmasked signal is sent to the thread while sleeping, the thread is resumed, and an error is returned.
**Callable from (extract)**
- This service is callable only from the thread context, i.e., it may not be called from an interrupt handler.
**Stack usage (extract)**
- From the location where this API is called, at least (76 + MPX_BINDING_STACK_FRAME_SIZE) bytes of stack should be available. This estimate is based on a typical 32-bit architecture. Stack usage should be verified in the application context.

## Reference Card API Surface (Updated)
The following prototypes are listed in the updated Reference Card.

- `int clock_getres(clockid_t clock_id, struct mpx_timespec *resolution);`
- `int clock_gettime(clockid_t clock_id, struct mpx_timespec *current_time);`
- `int clock_settime(clockid_t clock_id, struct mpx_timespec *new_time);`
- `int mpx _pthread_event_flagsattr_getcontrolsize(pthread_event_flagsattr_t *event_flags_attributes, size_t *event_flags_control_size);`
- `int mpx _pthread_event_flagsattr_setcontroladdr(pthread_event_flagsattr_t *event_flags_attributes, void *event_flags_control_address, size_t event_flags_control_size);`
- `int mpx _pthread_fastqueue_trysend(pthread_fastqueue_t *fastqueue_handle, u_long *message_source, size_t message_size);`
- `int mpx _pthread_partitionpoolattr_getcontroladdr(pthread_partitionpoolattr_t *partitionpool_attributes, void **partitionpool_control_address);`
- `int mpx _pthread_partitionpoolattr_getcontrolsize(pthread_partitionpoolattr_t *partitionpool_attributes, size_t *partitionpool_control_size);`
- `int mpx _pthread_partitionpoolattr_setcontroladdr(pthread_partitionpoolattr_t *partitionpool_attributes, void *partitionpool_control_address, size_t partitionpool_control_size);`
- `int mpx _pthread_priority_change(pthread_t thread_handle, int new_priority, int *old_priority);`
- `int mpx _pthread_ticktimer_create(pthread_ticktimer_t *ticktimer_handle, pthread_ticktimerattr_t *attributes, void (*expiration_routine)(pthread_ticktimer_t *, void *), void *argument, tick_t initial_ticks, tick_t reload_ticks);`
- `int mpx _pthread_ticktimer_update(pthread_ticktimer_t *ticktimer_handle, tick_t initial_ticks, tick_t reload_ticks);`
- `int mpx _pthread_ticktimerattr_destroy(pthread_ticktimerattr_t *ticktimer_attributes);`
- `int mpx _pthread_ticktimerattr_getcontroladdr(pthread_ticktimerattr_t * ticktimer_attributes,void **ticktimer_control_address);`
- `int mpx _pthread_ticktimerattr_init(pthread_ticktimerattr_t *ticktimer_attributes);`
- `int mpx _semattr_init(semattr_t *semaphore_attributes);`
- `int mpx _semattr_setcontroladdr(semattr_t *semaphore_attributes, void *s emaphore_control_address, size_t semaphore_control_size);`
- `int mpx_mq_extendattr_destroy(mq_extendattr_t *queue_attributes);`
- `int mpx_mq_extendattr_getcontroladdr(mq_extendattr_t *queue_attributes, void **queue_control_address);`
- `int mpx_mq_extendattr_getcontrolsize(mq_extendattr_t *queue_attributes, size_t *queue_control_size);`
- `int mpx_mq_extendattr_getqueueaddr(mq_extendattr_t *queue_attributes, void **queue_memory_address);`
- `int mpx_mq_extendattr_getqueuesize(mq_extendattr_t *queue_attributes, size_t *queue_memory_size);`
- `int mpx_mq_extendattr_init(mq_extendattr_t *queue_attributes);`
- `int mpx_mq_extendattr_setcontroladdr(mq_extendattr_t *queue_attributes, void *queue_control_address, size_t queue_control_size);`
- `int mpx_mq_extendattr_setqueueaddr(mq_extendattr_t *queue_attributes, void *queue_memory_address, size_t queue_memory_size);`
- `int mpx_pthread_attr_getcontroladdr(pthread_attr_t * thread_attributes, void **thread_control_address);`
- `int mpx_pthread_attr_getcontrolsize(pthread_attr_t * thread_attributes, size_t *thread_control_size);`
- `int mpx_pthread_attr_getname(pthread_attr_t *thread_attributes, char ** name);`
- `int mpx_pthread_attr_getpriority(pthread_attr_t *thread_attributes, int * priority);`
- `int mpx_pthread_attr_gettimeslice(pthread_attr_t * thread_attributes, u_long *thread_time_slice);`
- `int mpx_pthread_attr_setcontroladdr(pthread_attr_t * thread_attributes, void *thread_control_address, size_t thread_control_size);`
- `int mpx_pthread_attr_setname(pthread_attr_t *thread_attributes, char * name);`
- `int mpx_pthread_attr_setpriority(pthread_attr_t * thread_attributes, int priority);`
- `int mpx_pthread_attr_settimeslice(pthread_attr_t * thread_attributes, u_long thread_time_slice);`
- `int mpx_pthread_condattr_getcontroladdr(pthread_condattr_t * condition_var_attributes, void **condition_var_control_address);`
- `int mpx_pthread_condattr_getcontrolsize(pthread_condattr_t * condition_var_attributes, size_t *condition_var_control_size);`
- `int mpx_pthread_condattr_getname(pthread_condattr_t * condition_var_attributes, char **name);`
- `int mpx_pthread_condattr_setcontroladdr(pthread_condattr_t * condition_var_attributes, void *condition_var_control_address, size_t condition_var_control_size);`
- `int mpx_pthread_condattr_setname(pthread_condattr_t * condition_var_attributes, char *name);`
- `int mpx_pthread_event_flags_clear(pthread_event_flags_t *event_flags_handle);`
- `int mpx_pthread_event_flags_create(pthread_event_flags_t * event_flags_handle, pthread_event_flagsattr_t *event_flags_attributes);`
- `int mpx_pthread_event_flags_destroy(pthread_event_flags_t * event_flags_handle);`
- `int mpx_pthread_event_flags_set(pthread_event_flags_t * event_flags_handle, u_long events_to_set);`
- `int mpx_pthread_event_flags_timedwait(pthread_event_flags_t * event_flags_handle, u_long requested_events, int all_or_any, u_long * received_events, tick_t timeout_ticks);`
- `int mpx_pthread_event_flags_trywait(pthread_event_flags_t * event_flags_handle, u_long requested_events, int all_or_any, u_long *received_events);`
- `int mpx_pthread_event_flags_wait(pthread_event_flags_t * event_flags_handle, u_long requested_events, int all_or_any, u_long *received_events);`
- `int mpx_pthread_event_flagsattr_destroy(pthread_event_flagsattr_t * event_flags_attributes);`
- `int mpx_pthread_event_flagsattr_getcontroladdr(pthread_event_flagsattr_t *event_flags_attributes, void **event_flags_control_address);`
- `int mpx_pthread_event_flagsattr_getname(pthread_event_flagsattr_t * event_flags_attributes, char **name);`
- `int mpx_pthread_event_flagsattr_init(pthread_event_flagsattr_t * event_flags_attributes);`
- `int mpx_pthread_event_flagsattr_setname(pthread_event_flagsattr_t * event_flags_attributes, char *name);`
- `int mpx_pthread_fastqueue_create(pthread_fastqueue_t *fastqueue_handle, pthread_fastqueueattr_t *fastqueue_attributes, size_t message_size, int max_messages);`
- `int mpx_pthread_fastqueue_destroy(pthread_fastqueue_t *fastqueue_handle);`
- `int mpx_pthread_fastqueue_receive(pthread_fastqueue_t * fastqueue_handle, u_long *message_destination, size_t message_size);`
- `int mpx_pthread_fastqueue_send(pthread_fastqueue_t * fastqueue_handle, u_long *message_source, size_t message_size);`
- `int mpx_pthread_fastqueue_timedreceive(pthread_fastqueue_t * fastqueue_handle, u_long *message_destination, size_t message_size, tick_t timeout_ticks);`
- `int mpx_pthread_fastqueue_timedsend(pthread_fastqueue_t * fastqueue_handle, u_long *message_source, size_t message_size, tick_t timeout_ticks);`
- `int mpx_pthread_fastqueue_tryreceive(pthread_fastqueue_t * fastqueue_handle, u_long *message_destination, size_t message_size);`
- `int mpx_pthread_fastqueueattr_destroy(pthread_fastqueueattr_t * fastqueue_attributes);`
- `int mpx_pthread_fastqueueattr_getcontroladdr(pthread_fastqueueattr_t * fastqueue_attributes, void **fastqueue_control_address);`
- `int mpx_pthread_fastqueueattr_getcontrolsize(pthread_fastqueueattr_t * fastqueue_attributes, size_t *fastqueue_control_size);`
- `int mpx_pthread_fastqueueattr_getname(pthread_fastqueueattr_t * fastqueue_attributes, char **fastqueue_name);`
- `int mpx_pthread_fastqueueattr_getqueueaddr(pthread_fastqueueattr_t *fastqueue_attributes, void **fastqueue_memory_address);`
- `int mpx_pthread_fastqueueattr_getqueuesize(pthread_fastqueueattr_t *fastqueue_attributes, size_t *fastqueue_memory_size);`
- `int mpx_pthread_fastqueueattr_init(pthread_fastqueueattr_t * fastqueue_attributes);`
- `int mpx_pthread_fastqueueattr_setcontroladdr(pthread_fastqueueattr_t * fastqueue_attributes, void *fastqueue_control_address, size_t fastqueue_control_size);`
- `int mpx_pthread_fastqueueattr_setname(pthread_fastqueueattr_t * fastqueue_attributes, char *fastqueue_name);`
- `int mpx_pthread_fastqueueattr_setqueueaddr(pthread_fastqueueattr_t *fastqueue_attributes, void *fastqueue_memory_address, size_t fastqueue_memory_size);`
- `int mpx_pthread_information_get(pthread_t thread_handle, char ** name, int *state, int *priority, void **stack_limit, void ** stack_pointer, u_long *minimum_stack, pthread_t *next_thread);`
- `int mpx_pthread_memory_manager_enable(void);`
- `int mpx_pthread_memory_manager_get(void *(** memory_allocate_pointer)(u_int type, u_long size), void (**memory_release_pointer)(u_int type, void *memory_to_release));`
- `int mpx_pthread_memory_manager_set(void *(* memory_allocate_pointer)(u_int type, u_long size), void (*memory_release_pointer)(u_int type, void *memory_to_release));`
- `int mpx_pthread_memorypool_allocate(pthread_memorypool_t * memorypool_handle, void **allocated_memory, size_t request_size);`
- `int mpx_pthread_memorypool_create(pthread_memorypool_t * memorypool_handle, pthread_memorypoolattr_t *memorypool_attributes, void *pool_start, size_t pool_size);`
- `int mpx_pthread_memorypool_destroy(pthread_memorypool_t * memorypool_handle);`
- `int mpx_pthread_memorypool_free(void *allocated_memory);`
- `int mpx_pthread_memorypool_timedallocate(pthread_memorypool_t * memorypool_handle, void **allocated_memory, size_t request_size, tick_t timeout_ticks);`
- `int mpx_pthread_memorypool_tryallocate(pthread_memorypool_t * memorypool_handle, void **allocated_memory, size_t request_size);`
- `int mpx_pthread_memorypoolattr_destroy(pthread_memorypoolattr_t * memorypool_attributes);`
- `int mpx_pthread_memorypoolattr_getcontroladdr(pthread_memorypoolattr_t *memorypool_attributes, void **memorypool_control_address);`
- `int mpx_pthread_memorypoolattr_getcontrolsize(pthread_memorypoolattr_t * memorypool_attributes, size_t *memorypool_control_size);`
- `int mpx_pthread_memorypoolattr_getname(pthread_memorypoolattr_t * memorypool_attributes, char **name);`
- `int mpx_pthread_memorypoolattr_init(pthread_memorypoolattr_t * memorypool_attributes);`
- `int mpx_pthread_memorypoolattr_setcontroladdr(pthread_memorypoolattr_t * memorypool_attributes, void *memorypool_control_address, size_t memorypool_control_size);`
- `int mpx_pthread_memorypoolattr_setname(pthread_memorypoolattr_t * memorypool_attributes, char *name);`
- `int mpx_pthread_mutexattr_getcontroladdr(pthread_mutexattr_t * mutex_attributes, void **mutex_control_address);`
- `int mpx_pthread_mutexattr_getcontrolsize(pthread_mutexattr_t * mutex_attributes, size_t *mutex_control_size);`
- `int mpx_pthread_mutexattr_getname(pthread_mutexattr_t * mutex_attributes, char **name);`
- `int mpx_pthread_mutexattr_setcontroladdr(pthread_mutexattr_t * mutex_attributes, void *mutex_control_address, size_t mutex_control_size);`
- `int mpx_pthread_mutexattr_setname(pthread_mutexattr_t * mutex_attributes, char *name);`
- `int mpx_pthread_partitionpool_allocate(pthread_partitionpool_t *partitionpool_handle, void **allocated_memory, size_t request_size);`
- `int mpx_pthread_partitionpool_create(pthread_partitionpool_t * partitionpool_handle, pthread_partitionpoolattr_t *partitionpool_attributes, void * pool_start, size_t pool_size, size_t partition_size);`
- `int mpx_pthread_partitionpool_destroy(pthread_partitionpool_t * partitionpool_handle);`
- `int mpx_pthread_partitionpool_free(void *allocated_memory);`
- `int mpx_pthread_partitionpool_timedallocate(pthread_partitionpool_t * partitionpool_handle, void **allocated_memory, size_t request_size, tick_t timeout_ticks);`
- `int mpx_pthread_partitionpool_tryallocate(pthread_partitionpool_t * partitionpool_handle, void **allocated_memory, size_t request_size);`
- `int mpx_pthread_partitionpoolattr_destroy(pthread_partitionpoolattr_t * partitionpool_attributes);`
- `int mpx_pthread_partitionpoolattr_getname(pthread_partitionpoolattr_t *partitionpool_attributes, char **name);`
- `int mpx_pthread_partitionpoolattr_init(pthread_partitionpoolattr_t * partitionpool_attributes);`
- `int mpx_pthread_partitionpoolattr_setname(pthread_partitionpoolattr_t * partitionpool_attributes, char *name);`
- `int mpx_pthread_resume(pthread_t thread_handle);`
- `int mpx_pthread_stack_check(pthread_t thread_handle, u_long * minimum_available_stack);`
- `int mpx_pthread_start(u_long run_time_id, void * memory_start, u_long memory_size);`
- `int mpx_pthread_suspend(pthread_t thread_handle);`
- `int mpx_pthread_tick_sleep(tick_t ticks_to_sleep);`
- `int mpx_pthread_ticktimer_destroy(pthread_ticktimer_t *ticktimer_handle);`
- `int mpx_pthread_ticktimer_start(pthread_ticktimer_t *ticktimer_handle);`
- `int mpx_pthread_ticktimer_stop(pthread_ticktimer_t *ticktimer_handle);`
- `int mpx_pthread_ticktimerattr_getcontrolsize(pthread_ticktimerattr_t * ticktimer_attributes, size_t *ticktimer_control_size);`
- `int mpx_pthread_ticktimerattr_getname(pthread_ticktimerattr_t * ticktimer_attributes, char **name);`
- `int mpx_pthread_ticktimerattr_setcontroladdr(pthread_ticktimerattr_t * ticktimer_attributes, void *ticktimer_control_address, size_t ticktimer_control_size);`
- `int mpx_pthread_ticktimerattr_setname(pthread_ticktimerattr_t * ticktimer_attributes, char *name);`
- `int mpx_sem_extend_init(sem_t * semaphore_handle, int pshared, unsigned int value,semattr_t *s emaphore_attributes);`
- `int mpx_sem_timedwait(sem_t *semaphore_handle, tick_t timeout_ticks);`
- `int mpx_semattr_destroy(semattr_t *semaphore_attributes);`
- `int mpx_semattr_getcontroladdr(semattr_t *semaphore_attributes, void ** semaphore_control_address);`
- `int mpx_semattr_getcontrolsize(semattr_t *semaphore_attributes, size_t *semaphore_control_size);`
- `int mpx_semattr_getname(semattr_t *semaphore_attributes, char ** semaphore_name);`
- `int mpx_semattr_setname(semattr_t *semaphore_attributes, char * semaphore_name);`
- `int mq_close(mqd_t message_queue);`
- `int mq_getattr(mqd_t message_queue, struct mq_attr *queue_attributes);`
- `int mq_send(mqd_t message_queue, const char *message, size_t message_size, unsigned int message_priority);`
- `int mq_setattr(mqd_t message_queue, const struct mq_attr *queue_attributes, struct mq_attr *previous_attributes);`
- `int mq_timedsend(mqd_t message_queue, const char *message, size_t message_size, unsigned int message_priority, const struct mpx _timespec *absolute_timeout);`
- `int nanosleep(const struct mpx_timespec *request_time, struct mpx_timespec *remaining_time);`
- `int pthread_attr_getdetachstate(pthread_attr_t *thread_attributes, int *detach_state);`
- `int pthread_attr_getstackaddr(pthread_attr_t *thread_attributes, void **stack_address);`
- `int pthread_attr_getstacksize(pthread_attr_t *thread_attributes, size_t *stack_size);`
- `int pthread_attr_init(pthread_attr_t *thread_attributes);`
- `int pthread_attr_setdetachstate(pthread_attr_t *thread_attributes, int detach_state);`
- `int pthread_attr_setstackaddr(pthread_attr_t *thread_attributes, void *stack_address);`
- `int pthread_attr_setstacksize(pthread_attr_t *thread_attributes, size_t stack_size);`
- `int pthread_cancel(pthread_t thread_handle);`
- `int pthread_cond_broadcast(pthread_cond_t *condition_var_handle);`
- `int pthread_cond_destroy(pthread_cond_t *condition_var_handle);`
- `int pthread_cond_init(pthread_cond_t *condition_var_handle, pthread_condattr_t *condition_var_attributes);`
- `int pthread_cond_signal(pthread_cond_t *condition_var_handle);`
- `int pthread_cond_timedwait(pthread_cond_t *condition_var_handle, pthread_mutex_t *mutex_handle,const struct mpx _timespec *absolute_time);`
- `int pthread_cond_wait(pthread_cond_t *condition_var_handle, pthread_mutex_t *mutex_handle);`
- `int pthread_condattr_destroy(pthread_condattr_t *condition_var_attributes);`
- `int pthread_condattr_getpshared(pthread_condattr_t *condition_var_attributes, int *process_sharing_designation);`
- `int pthread_condattr_init(pthread_condattr_t *condition_var_attributes);`
- `int pthread_condattr_setpshared(pthread_condattr_t *condition_var_attributes, int process_sharing_designation);`
- `int pthread_create(pthread_t *thread_handle, pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);`
- `int pthread_detach(pthread_t thread_handle);`
- `int pthread_equal(pthread_t first_thread, pthread_t second_thread);`
- `int pthread_join(pthread_t thread_handle, void **value_destination);`
- `int pthread_mutex_destroy(pthread_mutex_t *mutex_handle);`
- `int pthread_mutex_init(pthread_mutex_t *mutex_handle, pthread_mutexattr_t *mutex_attributes);`
- `int pthread_mutex_lock(pthread_mutex_t *mutex_handle);`
- `int pthread_mutex_trylock(pthread_mutex_t *mutex_handle);`
- `int pthread_mutex_unlock(pthread_mutex_t *mutex_handle);`
- `int pthread_mutexattr_destroy(pthread_mutexattr_t *mutex_attributes);`
- `int pthread_mutexattr_getprotocol(pthread_mutexattr_t *mutex_attributes, int *protocol);`
- `int pthread_mutexattr_getpshared(pthread_mutexattr_t *mutex_attributes, int *process_sharing_designation);`
- `int pthread_mutexattr_gettype(pthread_mutexattr_t *mutex_attributes, int *type);`
- `int pthread_mutexattr_init(pthread_mutexattr_t *mutex_attributes);`
- `int pthread_mutexattr_setprotocol(pthread_mutexattr_t *mutex_attributes, int protocol);`
- `int pthread_mutexattr_setpshared(pthread_mutexattr_t *mutex_attributes, int process_sharing_designation);`
- `int pthread_mutexattr_settype(pthread_mutexattr_t *mutex_attributes, int type);`
- `int pthread_setcancelstate(int new_state, int *old_state);`
- `int pthread_setcanceltype(int new_type, int *old_type);`
- `int sched_yield(void);`
- `int sem_destroy(sem_t *semaphore_handle);`
- `int sem_init(sem_t *semaphore_handle, int pshared, unsigned int value);`
- `int sem_post(sem_t *semaphore_handle);`
- `int sem_trywait(sem_t *semaphore_handle);`
- `int sem_wait(sem_t *semaphore_handle);`
- `int usleep(useconds_t microseconds);`
- `mqd_t mpx_mq_extend_open(const char * queue_name, int operation, mode_t mode, struct mq_attr *queue_attributes, mq_extendattr_t *extend_attributes);`
- `mqd_t mpx_mq_extend_open_check_params(const char *queue_name, int operation, mode_t mode, struct mq_attr *queue_attributes, mq_extendattr_t *extend_attributes);`
- `mqd_t mq_open(const char *queue_name, int operation, mode_t mode, struct mq_attr *queue_attributes);`
- `pthread_t pthread_self(void);`
- `ssize_t mq_receive(mqd_t message_queue, char *message, size_t message_size, unsigned int *message_priority);`
- `ssize_t mq_timedreceive(mqd_t message_queue, char *message, size_t message_size, unsigned int *message_priority, const struct mpx_timespec *absolute_timeout);`
- `tick_t mpx_pthread_ticks_get(void);`
- `time_t time(mpx_time_t *return_seconds);`
- `u_int sleep(unsigned int seconds);`
- `void pthread_cleanup_pop(int execute);`
- `void pthread_cleanup_push(void (*cleanup_handler)(void *), void *argument);`
- `void pthread_exit(void *exit_value);`
- `void pthread_testcancel(void);`

### APIs only in Reference Card (no User Manual definition)
- `_pthread_event_flagsattr_getcontrolsize`
- `_pthread_event_flagsattr_setcontroladdr`
- `_pthread_fastqueue_trysend`
- `_pthread_partitionpoolattr_getcontroladdr`
- `_pthread_partitionpoolattr_getcontrolsize`
- `_pthread_partitionpoolattr_setcontroladdr`
- `_pthread_priority_change`
- `_pthread_ticktimer_create`
- `_pthread_ticktimer_update`
- `_pthread_ticktimerattr_destroy`
- `_pthread_ticktimerattr_getcontroladdr`
- `_pthread_ticktimerattr_init`
- `_semattr_init`
- `_semattr_setcontroladdr`
- `mpx_mq_extend_open_check_params`
- `mpx_sem_timedwait`
