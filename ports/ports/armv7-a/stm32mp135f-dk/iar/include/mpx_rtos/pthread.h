/*
MMMMMMMMM                     MMMMMMMMM       PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP               XXXXXXXXX                        XXXXXXXXX    
MMMMMMMMMMMM               MMMMMMMMMMMM       PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP           XXXXXXXXXXX                    XXXXXXXXXXX    
MMMMMMMMMMMMMMM         MMMMMMMMMMMMMMM       PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP         XXXXXXXXXXXXX                XXXXXXXXXXXXX    
MMMMMMMMM MMMMMMMM   MMMMMMMM MMMMMMMMM       PPPPPPPPP                     PPPPPPPPPP             XXXXXXXXX            XXXXXXXXX          
MMMMMMMMM   MMMMMMMMMMMMMMM   MMMMMMMMM       PPPPPPPPP                     PPPPPPPPPP               XXXXXXXXX        XXXXXXXXX            
MMMMMMMMM      MMMMMMMMM      MMMMMMMMM       PPPPPPPPP                     PPPPPPPPPP                 XXXXXXXXX    XXXXXXXXX                                
MMMMMMMMM          M          MMMMMMMMM       PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP                     XXXXXXXXXXXXXXXXXX                
MMMMMMMMM                     MMMMMMMMM       PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP                       XXXXXXXXXXXXXXXXXX                
MMMMMMMMM                     MMMMMMMMM       PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP                         XXXXXXXXX    XXXXXXXXX              
MMMMMMMMM                     MMMMMMMMM       PPPPPPPPP                                              XXXXXXXXX        XXXXXXXXX            
MMMMMMMMM                     MMMMMMMMM       PPPPPPPPP                                            XXXXXXXXX            XXXXXXXXX          
MMMMMMMMM                     MMMMMMMMM       PPPPPPPPP                                      XXXXXXXXXXXXX                XXXXXXXXXXXXX    
MMMMMMMMM                     MMMMMMMMM       PPPPPPPPP                                      XXXXXXXXXXX                    XXXXXXXXXXX    
MMMMMMMMM                     MMMMMMMMM       PPPPPPPPP                                      XXXXXXXXX                        XXXXXXXXX    

                                                                                             RRRRRRRR   TTTTTTTTT   OOOOOOO    SSSSSSSS    
																						                           RRRRRRRRR  TTTTTTTTT  OOOOOOOOO  SSSSSSSSS    
																						                           RRR   RRR     TTT     OOO   OOO  SSS          
                                                                                             RRR   RRR     PTHREADS-MORE      SSS          
												                                                         RRRRRRRRR     TTT     OOO   OOO  SSSSSSSS     
                                                                                             RRRRRRRR      TTT     OOO   OOO   SSSSSSSS    
                                                                                             RRR RRR       TTT     OOO   OOO        SSS    
                                                                                             RRR  RRR      TTT     OOO   OOO        SSS    
                                                                                             RRR   RRR     TTT     OOOOOOOOO  SSSSSSSSS    
                                                                                             RRR   RRR     TTT      OOOOOOO   SSSSSSSS 

                                                                                                        by   Julian  Offredi

************************************************************** CONFIDENTIAL ************************************************************ 

Version 1.0.0.0


Copyright (C) 2025-2026 Julian Offredi - All Rights Reserved.

You may use this software only under the terms specified in your license 
from Julian Offredi. All other use is strictly prohibited. If you do not have a license 
to use this software, please contact julian.offredi@gmail.com to obtain one.

*/

#ifndef MPX_PTHREAD_HEADER
#define MPX_PTHREAD_HEADER


/* Ensure this file can be included and used by C++ programs.  */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus  */


/******************************************************************************
 ******************************** Manifest ************************************
 ******************************************************************************
   
   Section I:   Include Files
   Section II:  Constants
   Section III: MPX API Mapping
   Section IV:  Actual MPX API prototypes

******************************************************************************/


/******************************************************************************
 ************************** Section I: Include Files **************************
 *****************************************************************************/

#include "sys/types.h"
#include "bits/pthreadtypes.h"
#include "mpx_time.h"
#include "mpx_errno.h"


/******************************************************************************
 ************************** Section II:  Constants ****************************
 *****************************************************************************/

#define PTHREAD_CREATE_JOINABLE                             1L
#define PTHREAD_CREATE_DETACHED                             2L
#define PTHREAD_PROCESS_SHARED                              3L
#define PTHREAD_PROCESS_PRIVATE                             4L
#define PTHREAD_CANCEL_DISABLE                              5L
#define PTHREAD_CANCEL_ENABLE                               6L
#define PTHREAD_CANCEL_ASYNCHRONOUS                         7L
#define PTHREAD_CANCEL_DEFERRED                             8L
#define PTHREAD_ALL_EVENTS                                  9L
#define PTHREAD_ANY_EVENT                                   10L
#define PTHREAD_MUTEX_NORMAL                                11L
#define PTHREAD_MUTEX_RECURSIVE                             12L
#define PTHREAD_MUTEX_ERRORCHECK                            13L
#ifndef PTHREAD_MUTEX_DEFAULT 
#define PTHREAD_MUTEX_DEFAULT                               (PTHREAD_MUTEX_ERRORCHECK)
#endif
#define PTHREAD_MUTEX_MAX_NESTING                           0xFFFFFFFFUL
#define PTHREAD_PRIO_NONE                                   14L
#define PTHREAD_PRIO_INHERIT                                15L
#define PTHREAD_PRIO_PROTECT                                16L


/* Define the minimal stack size, as determined by the binding layer.  */

#define PTHREAD_STACK_MIN                                   (MPX_BINDING_MINIMUM_STACK_SIZE)


/* Define the no time-slice constant.  */

#define MPX_NO_TIME_SLICE                                   0UL


/* Define the cancled return type.  */

#define PTHREAD_CANCELED                                    ((void *) -1)


/* Define the default maximum number of 32 priorities (0-31 where 31 is the 
   highest priority. In the future, this may be overridden by the application, but 
   for now only 32 priorities are supported.  */                          

#define MPX_MAXIMUM_PRIORITIES                              32L


/* Define the default priority to the middle of the maximum number of priorities.  */

#ifndef MPX_DEFAULT_PRIORITY
#define MPX_DEFAULT_PRIORITY                                (MPX_MAXIMUM_PRIORITIES/2L)
#endif  /* MPX_DEFAULT_PRIORITY */


/******************************************************************************
 ********************** Section III: MPX API Mapping **************************
 *****************************************************************************/

/* Determine if MPX source is present. If so, skip remapping.  */

#ifndef MPX_SOURCE_CODE


/* Determine if parameter checking is disabled. If so, skip parameter checking veneer.  */

#ifndef MPX_PARAMETER_CHECKING_DISABLE

#define pthread_attr_destroy                                mpx_pthread_attr_destroy
#define pthread_attr_getdetachstate                         mpx_pthread_attr_getdetachstate
#define pthread_attr_getstackaddr                           mpx_pthread_attr_getstackaddr
#define pthread_attr_getstacksize                           mpx_pthread_attr_getstacksize
#define pthread_attr_init                                   mpx_pthread_attr_init
#define pthread_attr_setdetachstate                         mpx_pthread_attr_setdetachstate
#define pthread_attr_setstackaddr                           mpx_pthread_attr_setstackaddr
#define pthread_attr_setstacksize                           mpx_pthread_attr_setstacksize
#define pthread_cancel                                      mpx_pthread_cancel
#define pthread_cleanup_pop                                 mpx_pthread_cleanup_pop
#define pthread_cleanup_push                                mpx_pthread_cleanup_push
#define pthread_cond_broadcast                              mpx_pthread_cond_broadcast_check_params
#define pthread_cond_destroy                                mpx_pthread_cond_destroy_check_params
#define pthread_cond_init                                   mpx_pthread_cond_init_check_params
#define pthread_cond_signal                                 mpx_pthread_cond_signal_check_params
#define pthread_cond_timedwait                              mpx_pthread_cond_timedwait_check_params
#define pthread_cond_wait                                   mpx_pthread_cond_wait_check_params
#define pthread_condattr_destroy                            mpx_pthread_condattr_destroy
#define pthread_condattr_getpshared                         mpx_pthread_condattr_getpshared
#define pthread_condattr_init                               mpx_pthread_condattr_init
#define pthread_condattr_setpshared                         mpx_pthread_condattr_setpshared
#define pthread_create                                      mpx_pthread_create_check_params
#define pthread_detach                                      mpx_pthread_detach
#define pthread_equal                                       mpx_pthread_equal
#define pthread_exit                                        mpx_pthread_exit
#if MPX_MAXIMUM_CORES>1
#define pthread_getaffinity_np                              mpx_pthread_getaffinity_np
#endif /* MPX_MAXIMUM_CORES>1  */
#define pthread_join                                        mpx_pthread_join_check_params
#define pthread_mutex_destroy                               mpx_pthread_mutex_destroy_check_params
#define pthread_mutex_init                                  mpx_pthread_mutex_init_check_params
#define pthread_mutex_lock                                  mpx_pthread_mutex_lock_check_params
#define pthread_mutex_trylock                               mpx_pthread_mutex_trylock_check_params
#define pthread_mutex_unlock                                mpx_pthread_mutex_unlock_check_params
#define pthread_mutexattr_destroy                           mpx_pthread_mutexattr_destroy
#define pthread_mutexattr_getprotocol                       mpx_pthread_mutexattr_getprotocol
#define pthread_mutexattr_getpshared                        mpx_pthread_mutexattr_getpshared
#define pthread_mutexattr_gettype                           mpx_pthread_mutexattr_gettype
#define pthread_mutexattr_init                              mpx_pthread_mutexattr_init
#define pthread_mutexattr_setprotocol                       mpx_pthread_mutexattr_setprotocol
#define pthread_mutexattr_setpshared                        mpx_pthread_mutexattr_setpshared
#define pthread_mutexattr_settype                           mpx_pthread_mutexattr_settype
#define pthread_self                                        mpx_pthread_self
#if MPX_MAXIMUM_CORES>1
#define pthread_setaffinity_np                              mpx_pthread_setaffinity_np
#endif /* MPX_MAXIMUM_CORES>1  */
#define pthread_setcancelstate                              mpx_pthread_setcancelstate
#define pthread_setcanceltype                               mpx_pthread_setcanceltype
#define pthread_testcancel                                  mpx_pthread_testcancel
#define mpx_pthread_event_flags_clear                       mpx_pthread_event_flags_clear_check_params
#define mpx_pthread_event_flags_create                      mpx_pthread_event_flags_create_check_params
#define mpx_pthread_event_flags_destroy                     mpx_pthread_event_flags_destroy_check_params
#define mpx_pthread_event_flags_set                         mpx_pthread_event_flags_set_check_params
#define mpx_pthread_event_flags_timedwait                   mpx_pthread_event_flags_timedwait_check_params
#define mpx_pthread_event_flags_trywait                     mpx_pthread_event_flags_trywait_check_params
#define mpx_pthread_event_flags_wait                        mpx_pthread_event_flags_wait_check_params
#define mpx_pthread_fastqueue_create                        mpx_pthread_fastqueue_create_check_params
#define mpx_pthread_fastqueue_destroy                       mpx_pthread_fastqueue_destroy_check_params
#define mpx_pthread_fastqueue_receive                       mpx_pthread_fastqueue_receive_check_params
#define mpx_pthread_fastqueue_timedreceive                  mpx_pthread_fastqueue_timedreceive_check_params
#define mpx_pthread_fastqueue_timedsend                     mpx_pthread_fastqueue_timedsend_check_params
#define mpx_pthread_fastqueue_send                          mpx_pthread_fastqueue_send_check_params
#define mpx_pthread_fastqueue_tryreceive                    mpx_pthread_fastqueue_tryreceive_check_params
#define mpx_pthread_fastqueue_trysend                       mpx_pthread_fastqueue_trysend_check_params
#define mpx_pthread_memorypool_allocate                     mpx_pthread_memorypool_allocate_check_params
#define mpx_pthread_memorypool_create                       mpx_pthread_memorypool_create_check_params
#define mpx_pthread_memorypool_destroy                      mpx_pthread_memorypool_destroy_check_params
#define mpx_pthread_memorypool_free                         mpx_pthread_memorypool_free_check_params
#define mpx_pthread_memorypool_timedallocate                mpx_pthread_memorypool_timedallocate_check_params
#define mpx_pthread_memorypool_tryallocate                  mpx_pthread_memorypool_tryallocate_check_params
#define mpx_pthread_partitionpool_allocate                  mpx_pthread_partitionpool_allocate_check_params
#define mpx_pthread_partitionpool_create                    mpx_pthread_partitionpool_create_check_params
#define mpx_pthread_partitionpool_destroy                   mpx_pthread_partitionpool_destroy_check_params
#define mpx_pthread_partitionpool_free                      mpx_pthread_partitionpool_free_check_params
#define mpx_pthread_partitionpool_timedallocate             mpx_pthread_partitionpool_timedallocate_check_params
#define mpx_pthread_partitionpool_tryallocate               mpx_pthread_partitionpool_tryallocate_check_params
#define mpx_pthread_ticktimer_create                        mpx_pthread_ticktimer_create_check_params
#define mpx_pthread_ticktimer_destroy                       mpx_pthread_ticktimer_destroy_check_params
#define mpx_pthread_ticktimer_start                         mpx_pthread_ticktimer_start_check_params
#define mpx_pthread_ticktimer_stop                          mpx_pthread_ticktimer_stop_check_params
#define mpx_pthread_ticktimer_update                        mpx_pthread_ticktimer_update_check_params

#else

#define pthread_attr_destroy                                mpx_pthread_attr_destroy
#define pthread_attr_getdetachstate                         mpx_pthread_attr_getdetachstate
#define pthread_attr_getstackaddr                           mpx_pthread_attr_getstackaddr
#define pthread_attr_getstacksize                           mpx_pthread_attr_getstacksize
#define pthread_attr_init                                   mpx_pthread_attr_init
#define pthread_attr_setdetachstate                         mpx_pthread_attr_setdetachstate
#define pthread_attr_setstackaddr                           mpx_pthread_attr_setstackaddr
#define pthread_attr_setstacksize                           mpx_pthread_attr_setstacksize
#define pthread_cancel                                      mpx_pthread_cancel
#define pthread_cleanup_pop                                 mpx_pthread_cleanup_pop
#define pthread_cleanup_push                                mpx_pthread_cleanup_push
#define pthread_cond_broadcast                              mpx_pthread_cond_broadcast
#define pthread_cond_destroy                                mpx_pthread_cond_destroy
#define pthread_cond_init                                   mpx_pthread_cond_init
#define pthread_cond_signal                                 mpx_pthread_cond_signal
#define pthread_cond_timedwait                              mpx_pthread_cond_timedwait
#define pthread_cond_wait                                   mpx_pthread_cond_wait
#define pthread_condattr_destroy                            mpx_pthread_condattr_destroy
#define pthread_condattr_getpshared                         mpx_pthread_condattr_getpshared
#define pthread_condattr_init                               mpx_pthread_condattr_init
#define pthread_condattr_setpshared                         mpx_pthread_condattr_setpshared
#define pthread_create                                      mpx_pthread_create
#define pthread_detach                                      mpx_pthread_detach
#define pthread_equal                                       mpx_pthread_equal
#define pthread_exit                                        mpx_pthread_exit
#if MPX_MAXIMUM_CORES>1
#define pthread_getaffinity_np                              mpx_pthread_getaffinity_np
#endif /* MPX_MAXIMUM_CORES>1  */
#define pthread_join                                        mpx_pthread_join
#define pthread_mutex_destroy                               mpx_pthread_mutex_destroy
#define pthread_mutex_init                                  mpx_pthread_mutex_init
#define pthread_mutex_lock                                  mpx_pthread_mutex_lock
#define pthread_mutex_trylock                               mpx_pthread_mutex_trylock
#define pthread_mutex_unlock                                mpx_pthread_mutex_unlock
#define pthread_mutexattr_destroy                           mpx_pthread_mutexattr_destroy
#define pthread_mutexattr_getprotocol                       mpx_pthread_mutexattr_getprotocol
#define pthread_mutexattr_getpshared                        mpx_pthread_mutexattr_getpshared
#define pthread_mutexattr_gettype                           mpx_pthread_mutexattr_gettype
#define pthread_mutexattr_init                              mpx_pthread_mutexattr_init
#define pthread_mutexattr_setprotocol                       mpx_pthread_mutexattr_setprotocol
#define pthread_mutexattr_setpshared                        mpx_pthread_mutexattr_setpshared
#define pthread_mutexattr_settype                           mpx_pthread_mutexattr_settype
#define pthread_self                                        mpx_pthread_self
#if MPX_MAXIMUM_CORES>1
#define pthread_setaffinity_np                              mpx_pthread_setaffinity_np
#endif /* MPX_MAXIMUM_CORES>1  */
#define pthread_setcancelstate                              mpx_pthread_setcancelstate
#define pthread_setcanceltype                               mpx_pthread_setcanceltype
#define pthread_testcancel                                  mpx_pthread_testcancel


#endif /* MPX_PARAMETER_CHECKING_DISABLE */

#endif /* MPX_SOURCE_CODE */


/******************************************************************************
 ******************** Section IV: Actual MPX API prototypes *******************
 *****************************************************************************/

int             mpx_pthread_attr_destroy(pthread_attr_t *  thread_attributes);
int             mpx_pthread_attr_getcontroladdr(pthread_attr_t *  thread_attributes, void **  thread_control_address);
int             mpx_pthread_attr_getcontrolsize(pthread_attr_t *  thread_attributes, size_t *  thread_control_size);
int             mpx_pthread_attr_getdetachstate(pthread_attr_t *  thread_attributes, int *  detach_state);
int             mpx_pthread_attr_getname(pthread_attr_t *  thread_attributes, char **  name);
int             mpx_pthread_attr_getpriority(pthread_attr_t *  thread_attributes, int *  priority);
int             mpx_pthread_attr_getstackaddr(pthread_attr_t *  thread_attributes, void **  stack_address);
int             mpx_pthread_attr_getstacksize(pthread_attr_t *  thread_attributes, size_t *  stack_size);
int             mpx_pthread_attr_gettimeslice(pthread_attr_t *  thread_attributes, u_long *  thread_time_slice);
int             mpx_pthread_attr_init(pthread_attr_t *  thread_attributes);
int             mpx_pthread_attr_setcontroladdr(pthread_attr_t *  thread_attributes, void *  thread_control_address, size_t thread_control_size);
int             mpx_pthread_attr_setdetachstate(pthread_attr_t *  thread_attributes, int detach_state);
int             mpx_pthread_attr_setname(pthread_attr_t *  thread_attributes, char *  name);
int             mpx_pthread_attr_setpriority(pthread_attr_t *  thread_attributes, int  priority);
int             mpx_pthread_attr_setstackaddr(pthread_attr_t *  thread_attributes, void *  stack_address);
int             mpx_pthread_attr_setstacksize(pthread_attr_t *  thread_attributes, size_t  stack_size);
int             mpx_pthread_attr_settimeslice(pthread_attr_t *  thread_attributes, u_long  thread_time_slice);
int             mpx_pthread_cancel(pthread_t thread_handle);
void            mpx_pthread_cleanup_pop(int execute);
void            mpx_pthread_cleanup_push(void (* cleanup_handler)(void *), void *  argument);
int             mpx_pthread_cond_broadcast(pthread_cond_t *  condition_var_handle);
int             mpx_pthread_cond_broadcast_check_params(pthread_cond_t *  condition_var_handle);
int             mpx_pthread_cond_destroy(pthread_cond_t *  condition_var_handle);
int             mpx_pthread_cond_destroy_check_params(pthread_cond_t *  condition_var_handle);
int             mpx_pthread_cond_init(pthread_cond_t *  condition_var_handle, pthread_condattr_t *  condition_var_attributes);
int             mpx_pthread_cond_init_check_params(pthread_cond_t *  condition_var_handle, pthread_condattr_t *  condition_var_attributes);
int             mpx_pthread_cond_signal(pthread_cond_t *  condition_var_handle);
int             mpx_pthread_cond_signal_check_params(pthread_cond_t *  condition_var_handle);
int             mpx_pthread_cond_timedwait(pthread_cond_t *  condition_var_handle, pthread_mutex_t *  mutex_handle, const struct mpx_timespec *  absolute_time);
int             mpx_pthread_cond_timedwait_check_params(pthread_cond_t *  condition_var_handle, pthread_mutex_t *  mutex_handle, const struct mpx_timespec *  absolute_time);
int             mpx_pthread_cond_wait(pthread_cond_t *  condition_var_handle, pthread_mutex_t *  mutex_handle);
int             mpx_pthread_cond_wait_check_params(pthread_cond_t *  condition_var_handle, pthread_mutex_t *  mutex_handle);
int             mpx_pthread_condattr_destroy(pthread_condattr_t *  condition_var_attributes);
int             mpx_pthread_condattr_getcontroladdr(pthread_condattr_t *  condition_var_attributes, void ** condition_var_control_address);
int             mpx_pthread_condattr_getcontrolsize(pthread_condattr_t *  condition_var_attributes, size_t *  condition_var_control_size);
int             mpx_pthread_condattr_getname(pthread_condattr_t *  condition_var_attributes, char **  name);
int             mpx_pthread_condattr_getpshared(pthread_condattr_t *  condition_var_attributes, int *  process_sharing_designation);
int             mpx_pthread_condattr_init(pthread_condattr_t *  condition_var_attributes);
int             mpx_pthread_condattr_setcontroladdr(pthread_condattr_t *  condition_var_attributes, void *  condition_var_control_address, size_t  condition_var_control_size);
int             mpx_pthread_condattr_setname(pthread_condattr_t *  condition_var_attributes, char *  name);
int             mpx_pthread_condattr_setpshared(pthread_condattr_t *  condition_var_attributes, int   process_sharing_designation);
int             mpx_pthread_create(pthread_t *  thread_handle, pthread_attr_t *  attr,  void *(* start_routine)(void *), void *arg);
int             mpx_pthread_create_check_params(pthread_t *  thread_handle, pthread_attr_t *  attr,  void *(* start_routine)(void *), void *arg);
int             mpx_pthread_detach(pthread_t thread_handle);
int             mpx_pthread_equal(pthread_t first_thread, pthread_t second_thread);
void            mpx_pthread_exit(void *  exit_value);
int             mpx_pthread_event_flags_clear(pthread_event_flags_t *  event_flags_handle);
int             mpx_pthread_event_flags_clear_check_params(pthread_event_flags_t *  event_flags_handle);
int             mpx_pthread_event_flags_create(pthread_event_flags_t *  event_flags_handle, pthread_event_flagsattr_t *  event_flags_attributes);
int             mpx_pthread_event_flags_create_check_params(pthread_event_flags_t *  event_flags_handle, pthread_event_flagsattr_t *  event_flags_attributes);
int             mpx_pthread_event_flags_destroy(pthread_event_flags_t *  event_flags_handle);
int             mpx_pthread_event_flags_destroy_check_params(pthread_event_flags_t *  event_flags_handle);
int             mpx_pthread_event_flags_set(pthread_event_flags_t *  event_flags_handle, u_long events_to_set);
int             mpx_pthread_event_flags_set_check_params(pthread_event_flags_t *  event_flags_handle, u_long events_to_set);
int             mpx_pthread_event_flags_timedwait(pthread_event_flags_t *  event_flags_handle, u_long requested_events, int all_or_any, u_long *  received_events, tick_t  timeout_ticks);
int             mpx_pthread_event_flags_timedwait_check_params(pthread_event_flags_t *  event_flags_handle, u_long requested_events, int all_or_any, u_long *  received_events, tick_t  timeout_ticks);
int             mpx_pthread_event_flags_trywait(pthread_event_flags_t *  event_flags_handle, u_long requested_events, int all_or_any, u_long *  received_events);
int             mpx_pthread_event_flags_trywait_check_params(pthread_event_flags_t *  event_flags_handle, u_long requested_events, int all_or_any, u_long *  received_events);
int             mpx_pthread_event_flags_wait(pthread_event_flags_t *  event_flags_handle, u_long requested_events, int all_or_any, u_long *  received_events);
int             mpx_pthread_event_flags_wait_check_params(pthread_event_flags_t *  event_flags_handle, u_long requested_events, int all_or_any, u_long *  received_events);
int             mpx_pthread_event_flagsattr_destroy(pthread_event_flagsattr_t *  event_flags_attributes);
int             mpx_pthread_event_flagsattr_getcontroladdr(pthread_event_flagsattr_t *  event_flags_attributes, void **  event_flags_control_address);
int             mpx_pthread_event_flagsattr_getcontrolsize(pthread_event_flagsattr_t *  event_flags_attributes, size_t *  event_flags_control_size);
int             mpx_pthread_event_flagsattr_getname(pthread_event_flagsattr_t *  event_flags_attributes, char ** name);
int             mpx_pthread_event_flagsattr_init(pthread_event_flagsattr_t *  event_flags_attributes);
int             mpx_pthread_event_flagsattr_setcontroladdr(pthread_event_flagsattr_t *  event_flags_attributes, void *  event_flags_control_address, size_t  event_flags_control_size);
int             mpx_pthread_event_flagsattr_setname(pthread_event_flagsattr_t *  event_flags_attributes, char *  name);
int             mpx_pthread_fastqueue_create(pthread_fastqueue_t *  fastqueue_handle, pthread_fastqueueattr_t *  fastqueue_attributes, size_t message_size, u_long  max_messages);
int             mpx_pthread_fastqueue_create_check_params(pthread_fastqueue_t *  fastqueue_handle, pthread_fastqueueattr_t *  fastqueue_attributes, size_t message_size, u_long  max_messages);
int             mpx_pthread_fastqueue_destroy(pthread_fastqueue_t *  fastqueue_handle);
int             mpx_pthread_fastqueue_destroy_check_params(pthread_fastqueue_t *  fastqueue_handle);
int             mpx_pthread_fastqueue_receive(pthread_fastqueue_t *  fastqueue_handle, u_long *  message_destination, size_t message_size);
int             mpx_pthread_fastqueue_receive_check_params(pthread_fastqueue_t *  fastqueue_handle, u_long *  message_destination, size_t message_size);
int             mpx_pthread_fastqueue_send(pthread_fastqueue_t *  fastqueue_handle, u_long *  message_source, size_t message_size);
int             mpx_pthread_fastqueue_send_check_params(pthread_fastqueue_t *  fastqueue_handle, u_long *  message_source, size_t message_size);
int             mpx_pthread_fastqueue_timedreceive(pthread_fastqueue_t *  fastqueue_handle, u_long *  message_destination, size_t message_size, tick_t timeout_ticks);
int             mpx_pthread_fastqueue_timedreceive_check_params(pthread_fastqueue_t *  fastqueue_handle, u_long *  message_destination, size_t message_size, tick_t timeout_ticks);
int             mpx_pthread_fastqueue_timedsend(pthread_fastqueue_t *  fastqueue_handle, u_long *  message_source, size_t message_size, tick_t  timeout_ticks);
int             mpx_pthread_fastqueue_timedsend_check_params(pthread_fastqueue_t *  fastqueue_handle, u_long *  message_source, size_t message_size, tick_t  timeout_ticks);
int             mpx_pthread_fastqueue_tryreceive(pthread_fastqueue_t *  fastqueue_handle, u_long *  message_destination, size_t message_size);
int             mpx_pthread_fastqueue_tryreceive_check_params(pthread_fastqueue_t *  fastqueue_handle, u_long *  message_destination, size_t message_size);
int             mpx_pthread_fastqueue_trysend(pthread_fastqueue_t *  fastqueue_handle, u_long *  message_source, size_t message_size);
int             mpx_pthread_fastqueue_trysend_check_params(pthread_fastqueue_t *  fastqueue_handle, u_long *  message_source, size_t message_size);
int             mpx_pthread_fastqueueattr_destroy(pthread_fastqueueattr_t *  fastqueue_attributes);
int             mpx_pthread_fastqueueattr_getcontroladdr(pthread_fastqueueattr_t *  fastqueue_attributes, void ** fastqueue_control_address);
int             mpx_pthread_fastqueueattr_getcontrolsize(pthread_fastqueueattr_t *  fastqueue_attributes, size_t *  fastqueue_control_size);
int             mpx_pthread_fastqueueattr_getname(pthread_fastqueueattr_t *  fastqueue_attributes, char ** fastqueue_name);
int             mpx_pthread_fastqueueattr_getqueueaddr(pthread_fastqueueattr_t *  fastqueue_attributes, void ** fastqueue_memory_address);
int             mpx_pthread_fastqueueattr_getqueuesize(pthread_fastqueueattr_t *  fastqeueu_attributes, size_t *  fastqueue_memory_size);
int             mpx_pthread_fastqueueattr_init(pthread_fastqueueattr_t *  fastqueue_attributes);
int             mpx_pthread_fastqueueattr_setcontroladdr(pthread_fastqueueattr_t *  fastqueue_attributes, void *  fastqueue_control_address, size_t fastqueue_control_size);
int             mpx_pthread_fastqueueattr_setname(pthread_fastqueueattr_t *  fastqueue_attributes, char *  fastqueue_name);
int             mpx_pthread_fastqueueattr_setqueueaddr(pthread_fastqueueattr_t *  fastqueue_attributes, void *  fastqueue_memory_address, size_t fastqueue_memory_size);
#if MPX_MAXIMUM_CORES>1
int             mpx_pthread_getaffinity_np(pthread_t  thread_handle,  size_t  cpusetsize, cpu_set_t  *cpuset);
#endif /* MPX_MAXIMUM_CORES>1  */
int             mpx_pthread_information_get(pthread_t  thread_handle, char **  name,  int *  state, int *  priority, void **  stack_limit, void **  stack_pointer, u_long *  minimum_stack, pthread_t *  next_thread);
int             mpx_pthread_join(pthread_t  thread_handle, void **  value_destination);
int             mpx_pthread_join_check_params(pthread_t  thread_handle, void **  value_destination);
int             mpx_pthread_memory_manager_enable(void);
int             mpx_pthread_memory_manager_get(void * (** memory_allocate_pointer)(u_int type, u_long size), void (** memory_release_pointer)(u_int type, void *  memory_to_release));
int             mpx_pthread_memory_manager_set(void * (* memory_allocate_pointer)(u_int type, u_long size), void (* memory_release_pointer)(u_int type, void *  memory_to_release));
int             mpx_pthread_memorypool_allocate(pthread_memorypool_t *  memorypool_handle, void **  allocated_memory, size_t  request_size);
int             mpx_pthread_memorypool_allocate_check_params(pthread_memorypool_t *  memorypool_handle, void **  allocated_memory, size_t  request_size);
int             mpx_pthread_memorypool_create(pthread_memorypool_t *  memorypool_handle, pthread_memorypoolattr_t *  memorypool_attributes, void *  pool_start, size_t  pool_size);
int             mpx_pthread_memorypool_create_check_params(pthread_memorypool_t *  memorypool_handle, pthread_memorypoolattr_t *  memorypool_attributes, void *  pool_start, size_t  pool_size);
int             mpx_pthread_memorypool_destroy(pthread_memorypool_t *  memorypool_handle);
int             mpx_pthread_memorypool_destroy_check_params(pthread_memorypool_t *  memorypool_handle);
int             mpx_pthread_memorypool_free(void *  allocated_memory);
int             mpx_pthread_memorypool_free_check_params(void *  allocated_memory);
int             mpx_pthread_memorypool_timedallocate(pthread_memorypool_t *  memorypool_handle, void **  allocated_memory, size_t  request_size, tick_t  timeout_ticks);
int             mpx_pthread_memorypool_timedallocate_check_params(pthread_memorypool_t *  memorypool_handle, void **  allocated_memory, size_t  request_size, tick_t  timeout_ticks);
int             mpx_pthread_memorypool_tryallocate(pthread_memorypool_t *  memorypool_handle, void **  allocated_memory, size_t  request_size);
int             mpx_pthread_memorypool_tryallocate_check_params(pthread_memorypool_t *  memorypool_handle, void **  allocated_memory, size_t  request_size);
int             mpx_pthread_memorypoolattr_destroy(pthread_memorypoolattr_t *  memorypool_attributes);
int             mpx_pthread_memorypoolattr_getcontroladdr(pthread_memorypoolattr_t *  memorypool_attributes, void ** memorypool_control_address);
int             mpx_pthread_memorypoolattr_getcontrolsize(pthread_memorypoolattr_t *  memorypool_attributes, size_t *  memorypool_control_size);
int             mpx_pthread_memorypoolattr_getname(pthread_memorypoolattr_t *  memorypool_attributes, char ** name);
int             mpx_pthread_memorypoolattr_init(pthread_memorypoolattr_t *  memorypool_attributes);
int             mpx_pthread_memorypoolattr_setcontroladdr(pthread_memorypoolattr_t *  memorypool_attributes, void *  memorypool_control_address, size_t  memorypool_control_size);
int             mpx_pthread_memorypoolattr_setname(pthread_memorypoolattr_t *  memorypool_attributes, char *  name);
int             mpx_pthread_mutex_destroy(pthread_mutex_t *  mutex_handle);
int             mpx_pthread_mutex_destroy_check_params(pthread_mutex_t *  mutex_handle);
int             mpx_pthread_mutex_init(pthread_mutex_t *  mutex_handle, pthread_mutexattr_t *  mutex_attributes);
int             mpx_pthread_mutex_init_check_params(pthread_mutex_t *  mutex_handle, pthread_mutexattr_t *  mutex_attributes);
int             mpx_pthread_mutex_lock(pthread_mutex_t *  mutex_handle);
int             mpx_pthread_mutex_lock_check_params(pthread_mutex_t *  mutex_handle);
int             mpx_pthread_mutex_trylock(pthread_mutex_t *  mutex_handle);
int             mpx_pthread_mutex_trylock_check_params(pthread_mutex_t *  mutex_handle);
int             mpx_pthread_mutex_unlock(pthread_mutex_t *  mutex_handle);
int             mpx_pthread_mutex_unlock_check_params(pthread_mutex_t *  mutex_handle);
int             mpx_pthread_mutexattr_destroy(pthread_mutexattr_t *  mutex_attributes);
int             mpx_pthread_mutexattr_getcontroladdr(pthread_mutexattr_t *  mutex_attributes, void **  mutex_control_address);
int             mpx_pthread_mutexattr_getcontrolsize(pthread_mutexattr_t *  mutex_attributes, size_t *  mutex_control_size);
int             mpx_pthread_mutexattr_getname(pthread_mutexattr_t *  mutex_attributes, char **  name);
int             mpx_pthread_mutexattr_getprotocol(pthread_mutexattr_t *  mutex_attributes, int *  protocol);
int             mpx_pthread_mutexattr_getpshared(pthread_mutexattr_t *  mutex_attributes, int *  process_sharing_designation);
int             mpx_pthread_mutexattr_gettype(pthread_mutexattr_t *  mutex_attributes, int *  type);
int             mpx_pthread_mutexattr_init(pthread_mutexattr_t *  mutex_attributes);
int             mpx_pthread_mutexattr_setcontroladdr(pthread_mutexattr_t *  mutex_attributes, void *  mutex_control_address, size_t  mutex_control_size);
int             mpx_pthread_mutexattr_setname(pthread_mutexattr_t *  mutex_attributes, char *  name);
int             mpx_pthread_mutexattr_setprotocol(pthread_mutexattr_t *  mutex_attributes, int   protocol);
int             mpx_pthread_mutexattr_setpshared(pthread_mutexattr_t *  mutex_attributes, int   process_sharing_designation);
int             mpx_pthread_mutexattr_settype(pthread_mutexattr_t *  mutex_attributes, int   type);
int             mpx_pthread_partitionpool_allocate(pthread_partitionpool_t *  partitionpool_handle, void **  allocated_memory, size_t  request_size);
int             mpx_pthread_partitionpool_allocate_check_params(pthread_partitionpool_t *  partitionpool_handle, void **  allocated_memory, size_t  request_size);
int             mpx_pthread_partitionpool_create(pthread_partitionpool_t *  partitionpool_handle, pthread_partitionpoolattr_t *  partitionpool_attributes, void *  pool_start, size_t  pool_size, size_t partition_size);
int             mpx_pthread_partitionpool_create_check_params(pthread_partitionpool_t *  partitionpool_handle, pthread_partitionpoolattr_t *  partitionpool_attributes, void *  pool_start, size_t  pool_size, size_t partition_size);
int             mpx_pthread_partitionpool_destroy(pthread_partitionpool_t *  partitionpool_handle);
int             mpx_pthread_partitionpool_destroy_check_params(pthread_partitionpool_t *  partitionpool_handle);
int             mpx_pthread_partitionpool_free(void *  allocated_memory);
int             mpx_pthread_partitionpool_free_check_params(void *  allocated_memory);
int             mpx_pthread_partitionpool_timedallocate(pthread_partitionpool_t *  partitionpool_handle, void **  allocated_memory, size_t  request_size, tick_t  timeout_ticks);
int             mpx_pthread_partitionpool_timedallocate_check_params(pthread_partitionpool_t *  partitionpool_handle, void **  allocated_memory, size_t  request_size, tick_t  timeout_ticks);
int             mpx_pthread_partitionpool_tryallocate(pthread_partitionpool_t *  partitionpool_handle, void **  allocated_memory, size_t  request_size);
int             mpx_pthread_partitionpool_tryallocate_check_params(pthread_partitionpool_t *  partitionpool_handle, void **  allocated_memory, size_t  request_size);
int             mpx_pthread_partitionpoolattr_destroy(pthread_partitionpoolattr_t *  partitionpool_attributes);
int             mpx_pthread_partitionpoolattr_getcontroladdr(pthread_partitionpoolattr_t *  partitionpool_attributes, void ** partitionpool_control_address);
int             mpx_pthread_partitionpoolattr_getcontrolsize(pthread_partitionpoolattr_t *  partitionpool_attributes, size_t *  partitionpool_control_size);
int             mpx_pthread_partitionpoolattr_getname(pthread_partitionpoolattr_t *  partitionpool_attributes, char ** name);
int             mpx_pthread_partitionpoolattr_init(pthread_partitionpoolattr_t *  partitionpool_attributes);
int             mpx_pthread_partitionpoolattr_setcontroladdr(pthread_partitionpoolattr_t *  partitionpool_attributes, void *  partitionpool_control_address, size_t  partitionpool_control_size);
int             mpx_pthread_partitionpoolattr_setname(pthread_partitionpoolattr_t *  partitionpool_attributes, char *  name);
int             mpx_pthread_priority_change(pthread_t thread_handle, int  new_priority, int *  old_priority);
int             mpx_pthread_resume(pthread_t thread_handle);
pthread_t       mpx_pthread_self(void);
#if MPX_MAXIMUM_CORES>1
int             mpx_pthread_setaffinity_np(pthread_t  thread_handle,  size_t  cpusetsize, cpu_set_t  *cpuset);
#endif /* MPX_MAXIMUM_CORES>1  */
int             mpx_pthread_setcancelstate(int  new_state, int *  old_state);
int             mpx_pthread_setcanceltype(int  new_type, int *  old_type);
int             mpx_pthread_start(u_long run_time_id, void *  memory_start, u_long memory_size);
int             mpx_pthread_stack_check(pthread_t thread_handle, u_long *  minimum_available_stack);
int             mpx_pthread_suspend(pthread_t thread_handle);
void            mpx_pthread_testcancel(void);
int             mpx_pthread_tick_sleep(tick_t ticks_to_sleep);
tick_t          mpx_pthread_ticks_get(void);
int             mpx_pthread_ticktimer_create(pthread_ticktimer_t *  ticktimer_handle, pthread_ticktimerattr_t *  attributes, void (* expiration_routine)(pthread_ticktimer_t *, void *), void *  argument, tick_t initial_ticks, tick_t reload_ticks);
int             mpx_pthread_ticktimer_create_check_params(pthread_ticktimer_t *  ticktimer_handle, pthread_ticktimerattr_t *  attributes, void (* expiration_routine)(pthread_ticktimer_t *, void *), void *  argument, tick_t initial_ticks, tick_t reload_ticks);
int             mpx_pthread_ticktimer_destroy(pthread_ticktimer_t *  ticktimer_handle);
int             mpx_pthread_ticktimer_destroy_check_params(pthread_ticktimer_t *  ticktimer_handle);
int             mpx_pthread_ticktimer_start(pthread_ticktimer_t *  ticktimer_handle);
int             mpx_pthread_ticktimer_start_check_params(pthread_ticktimer_t *  ticktimer_handle);
int             mpx_pthread_ticktimer_stop(pthread_ticktimer_t *  ticktimer_handle);
int             mpx_pthread_ticktimer_stop_check_params(pthread_ticktimer_t *  ticktimer_handle);
int             mpx_pthread_ticktimer_update(pthread_ticktimer_t *  ticktimer_handle, tick_t  initial_ticks, tick_t  reload_ticks);
int             mpx_pthread_ticktimer_update_check_params(pthread_ticktimer_t *  ticktimer_handle, tick_t  initial_ticks, tick_t  reload_ticks);
int             mpx_pthread_ticktimerattr_destroy(pthread_ticktimerattr_t *  ticktimer_attributes);
int             mpx_pthread_ticktimerattr_getcontroladdr(pthread_ticktimerattr_t *  ticktimer_attributes, void **  ticktimer_control_address);
int             mpx_pthread_ticktimerattr_getcontrolsize(pthread_ticktimerattr_t *  ticktimer_attributes, size_t *  ticktimer_control_size);
int             mpx_pthread_ticktimerattr_getname(pthread_ticktimerattr_t *  ticktimer_attributes, char **  name);
int             mpx_pthread_ticktimerattr_init(pthread_ticktimerattr_t *  ticktimer_attributes);
int             mpx_pthread_ticktimerattr_setcontroladdr(pthread_ticktimerattr_t *  ticktimer_attributes, void *  ticktimer_control_address, size_t  ticktimer_control_size);
int             mpx_pthread_ticktimerattr_setname(pthread_ticktimerattr_t *  ticktimer_attributes, char *  name);
void            mpx_timer_interrupt_process(void);


#ifdef __cplusplus
}  /* Closing bracket for extern "C" at the top of file.  */
#endif /* __cplusplus  */


#endif  /* MPX_PTHREAD_HEADER */
