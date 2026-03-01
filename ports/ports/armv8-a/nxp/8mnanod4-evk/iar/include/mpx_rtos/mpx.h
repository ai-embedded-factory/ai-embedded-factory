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

#ifndef MPX_HEADER 
#define MPX_HEADER


/******************************************************************************
 ******************************** Manifest ************************************
 ******************************************************************************
   
   Section I:   Include Files
   Section II:  Constants, Enumerations, and Macros
   Section III: Typedefs
   Section IV:  Internal Core Prototypes
   Section V:   Internal Utility Prototypes
   Section VI:  Internal Error Handling Prototypes
   Section VII: Binding Function Prototypes


   Note: The mpx.h file is only included by the mpx.c file, i.e., it is not 
         meant to be included directly by the application software.

******************************************************************************/


/******************************************************************************
 ************************* Section I: Include Files ***************************
 *****************************************************************************/

#include "mpx_user_config.h"
#include "mpx_binding.h"
#include "mpx_time.h"
#include "pthread.h"
#include "sched.h"
#include "mqueue.h"
#include "semaphore.h"
#include "signal.h"
#include "unistd.h"
#include "mpx_errno.h"


/******************************************************************************
 ************** Section II: Constants, Enumerations, and Macros ***************
 *****************************************************************************/
 
/* Define this version of MPX.  */

#define MPX_MAJOR_VERSION                                   1U
#define MPX_MINOR_VERSION                                   0U
#define MPX_UPDATE_VERSION                                  0U
#define MPX_PATCH_VERSION                                   0U


/* Define the default maximum number of processors. Since most implementations 
   are for single processors, the default value is 1.  */

#ifndef MPX_MAXIMUM_CORES
#define MPX_MAXIMUM_CORES                                   1
#endif  /* MPX_MAXIMUM_CORES */


/* Define the currently executing core. For all non-SMP versions this is simply 
   mapped to 0.  */

#ifndef MPX_EXECUTING_CORE
#define MPX_EXECUTING_CORE                                  0
#endif  /* MPX_EXECUTING_CORE */


/* Define the natural word size to be 32-bits, e.g., C "int" and "long" types are 
   32-bits. This may be overridden in the mpx_binding.h file.  */

#ifndef MPX_NATURAL_WORD_SIZE
#define MPX_NATURAL_WORD_SIZE                               32
#endif  /* MPX_NATURAL_WORD_SIZE */


/* Define the highest active priority when there are ready threads to an invalid priority.  */

#define MPX_NO_READY_THREADS                                (-1)


/* Define default stack size based on minimum binding stack size.  */

#ifndef MPX_DEFAULT_STACK_SIZE
#define MPX_DEFAULT_STACK_SIZE                              (MPX_BINDING_MINIMUM_STACK_SIZE*10UL)
#endif  /* MPX_DEFAULT_STACK_SIZE */


/* Define the stack fill pattern (for byte and for 32-bit word).  */

#ifndef MPX_STACK_FILL
#define MPX_STACK_FILL                                      0xEF
#endif  /* MPX_STACK_FILL */


#ifndef MPX_STACK_FILL_LWORD                    
#define MPX_STACK_FILL_LWORD                                0xEFEFEFEFUL
#endif  /* MPX_STACK_FILL_LWORD */


/* Define the active timer list size.  This can be redefined by the application, but must always be a power of 2.  */

#ifndef MPX_ACTIVE_TIMER_LIST_SIZE
#define MPX_ACTIVE_TIMER_LIST_SIZE                          32UL
#endif  /* MPX_ACTIVE_TIMER_LIST_SIZE */


/* Define the maximum number of cleanup handlers for each thread.  */

#ifndef MPX_MAXIMUM_CLEANUP_HANDLERS
#define MPX_MAXIMUM_CLEANUP_HANDLERS                        3
#endif  /* MPX_MAXIMUM_CLEANUP_HANDLERS */


/* Define NULL pointer constant.  */

#define MPX_NULL                                            ((void *) 0)


/* Define empty list constant.  */

#define MPX_LIST_EMPTY                                      0UL


/* Define preempt/no-preempt constants.  */

#define MPX_PREEMPT                                         1L
#define MPX_NO_PREEMPT                                      0L


/* Define true/false constants.  */

#define MPX_TRUE                                            1L
#define MPX_FALSE                                           0L


/* Define system structure IDs.  */

#define MPX_GLOBALS_ID                                      0x50583520UL
#define MPX_THREAD_ID                                       0x50583554UL  
#define MPX_ATTRIBUTES_ID                                   0x41545452UL
#define MPX_CONDITION_VAR_ID                                0x434F4E56UL
#define MPX_CONDITION_VAR_ATTR_ID                           0x434F4E41UL
#define MPX_EVENT_FLAGS_ID                                  0x4556454EUL
#define MPX_EVENT_FLAGSATTR_ID                              0x45564541UL
#define MPX_FASTQUEUE_ID                                    0x46515545UL
#define MPX_FASTQUEUEATTR_ID                                0x46515541UL
#define MPX_MEMORYPOOL_ID                                   0x4D454D50UL
#define MPX_MEMORYPOOLATTR_ID                               0x4D454D41UL
#define MPX_MUTEX_ID                                        0x4D555458UL
#define MPX_MUTEXATTR_ID                                    0x4D555441UL
#define MPX_PARTITIONPOOL_ID                                0x50415250UL
#define MPX_PARTITIONPOOLATTR_ID                            0x50415241UL
#define MPX_QUEUE_ID                                        0x4D515545UL
#define MPX_DELETED_ID                                      0x44454C20UL
#define MPX_SEMAPHORE_ID                                    0x53454D20UL
#define MPX_TICKTIMER_ID                                    0x54494320UL
#define MPX_TICKTIMER_ATTR_ID                               0x54494345UL


/* Define thread states of execution.  */

#define MPX_THREAD_READY                                    0L
#define MPX_THREAD_RETURNED                                 1L
#define MPX_THREAD_EXITED                                   2L
#define MPX_THREAD_TERMINATED                               3L
#define MPX_THREAD_CANCELED                                 4L 
#define MPX_THREAD_DEFERRED_CLEANUP                         5L
#define MPX_THREAD_DEFERRED_RESUME                          6L
#define MPX_THREAD_SUSPENDED                                7L
#define MPX_THREAD_JOIN_SUSPENDED                           8L
#define MPX_THREAD_CONDITION_VAR_SUSPENDED                  9L
#define MPX_THREAD_MEMORYPOOL_SUSPENDED                     10L
#define MPX_THREAD_MUTEX_SUSPENDED                          11L
#define MPX_THREAD_PARTITIONPOOL_SUSPENDED                  12L
#define MPX_THREAD_QUEUE_SUSPENDED                          13L
#define MPX_THREAD_SEMAPHORE_SUSPENDED                      14L
#define MPX_THREAD_SIGNAL_SUSPENDED                         15L
#define MPX_THREAD_SLEEP_SUSPENDED                          16L
#define MPX_THREAD_TICKSLEEP_SUSPENDED                      17L
#define MPX_THREAD_EVENT_FLAGS_SUSPENDED                    18L
#define MPX_THREAD_FASTQUEUE_SUSPENDED                      19L
#define MPX_THREAD_TCPIP_SUSPENDED                          20L


/* Define internal memory usage types.  */

#define MPX_THREAD_CONTROL_MEMORY                           1UL
#define MPX_THREAD_STACK_MEMORY                             2UL
#define MPX_CONDITION_VAR_CONTROL_MEMORY                    3UL
#define MPX_EVENT_FLAGS_CONTROL_MEMORY                      4UL
#define MPX_FASTQUEUE_CONTROL_MEMORY                        5UL
#define MPX_FASTQUEUE_AREA_MEMORY                           6UL
#define MPX_MEMORYPOOL_CONTROL_MEMORY                       7UL
#define MPX_PARTITIONPOOL_CONTROL_MEMORY                    8UL
#define MPX_MUTEX_CONTROL_MEMORY                            9UL
#define MPX_QUEUE_CONTROL_MEMORY                            10UL
#define MPX_QUEUE_AREA_MEMORY                               11UL
#define MPX_SEMAPHORE_CONTROL_MEMORY                        12UL
#define MPX_TIMER_CONTROL_MEMORY                            13UL
#define MPX_TICKTIMER_CONTROL_MEMORY                        14UL


/* Define the allocated and free memory block constants.  */

#define MPX_BLOCK_ALLOCATED                                 0xAAAAAAAAUL
#define MPX_BLOCK_FREE                                      0xFFFFFFFFUL


/* Define internal system error types.  */

#define MPX_LEVEL_3_ERROR                                   3UL
#define MPX_LEVEL_2_ERROR                                   2UL
#define MPX_LEVEL_1_ERROR                                   1UL


/* Define internal system error sub-types.  */

#define MPX_MEMORY_CORRUPTION                               1UL
#define MPX_INVALID_EXECUTION                               2UL
#define MPX_MISSING_SIGNAL_HANDLER                          3UL
#define MPX_INVALID_API_REQUEST                             4UL
#define MPX_STACK_SIZE_TOO_SMALL                            5UL
#define MPX_STACK_OVERFLOW                                  6UL


/* Define function IDs for tracing and error checking.  */

#define MPX_CLOCK_GETRES_CHECK_PARAMS_ID                    1UL
#define MPX_CLOCK_GETTIME_CHECK_PARAMS_ID                   2UL
#define MPX_CLOCK_SETTIME_CHECK_PARAMS_ID                   3UL
#define MPX_MQ_CLOSE_CHECK_PARAMS_ID                        6UL
#define MPX_MQ_EXTEND_OPEN_CHECK_PARAMS_ID                  7UL
#define MPX_MQ_GETATTR_CHECK_PARAMS_ID                      16UL
#define MPX_MQ_OPEN_CHECK_PARAMS_ID                         20UL
#define MPX_MQ_RECEIVE_CHECK_PARAMS_ID                      21UL
#define MPX_MQ_SEND_CHECK_PARAMS_ID                         22UL
#define MPX_MQ_SETATTR_CHECK_PARAMS_ID                      23UL
#define MPX_MQ_TIMEDRECEIVE_CHECK_PARAMS_ID                 24UL
#define MPX_MQ_TIMEDSEND_CHECK_PARAMS_ID                    25UL
#define MPX_NANOSLEEP_CHECK_PARAMS_ID                       26UL
#define MPX_PTHREAD_COND_BROADCAST_CHECK_PARAMS_ID          56UL
#define MPX_PTHREAD_COND_DESTROY_CHECK_PARAMS_ID            57UL
#define MPX_PTHREAD_COND_INIT_CHECK_PARAMS_ID               59UL
#define MPX_PTHREAD_COND_SIGNAL_CHECK_PARAMS_ID             62UL
#define MPX_PTHREAD_COND_TIMEDWAIT_CHECK_PARAMS_ID          63UL
#define MPX_PTHREAD_COND_WAIT_CHECK_PARAMS_ID               64UL
#define MPX_PTHREAD_CREATE_CHECK_PARAMS_ID                  76UL
#define MPX_PTHREAD_EVENT_FLAGS_CLEAR_CHECK_PARAMS_ID       79UL
#define MPX_PTHREAD_EVENT_FLAGS_CREATE_CHECK_PARAMS_ID      80UL
#define MPX_PTHREAD_EVENT_FLAGS_DESTROY_CHECK_PARAMS_ID     81UL
#define MPX_PTHREAD_EVENT_FLAGS_SET_CHECK_PARAMS_ID         85UL 
#define MPX_PTHREAD_EVENT_FLAGS_TIMEDWAIT_CHECK_PARAMS_ID   86UL
#define MPX_PTHREAD_EVENT_FLAGS_TRYWAIT_CHECK_PARAMS_ID     87UL
#define MPX_PTHREAD_EVENT_FLAGS_WAIT_CHECK_PARAMS_ID        88UL
#define MPX_PTHREAD_FASTQUEUE_CREATE_CHECK_PARAMS_ID        97UL
#define MPX_PTHREAD_FASTQUEUE_DESTROY_CHECK_PARAMS_ID       98UL
#define MPX_PTHREAD_FASTQUEUE_RECEIVE_CHECK_PARAMS_ID       102UL
#define MPX_PTHREAD_FASTQUEUE_SEND_CHECK_PARAMS_ID          103UL
#define MPX_PTHREAD_FASTQUEUE_TIMEDRECEIVE_CHECK_PARAMS_ID  104UL
#define MPX_PTHREAD_FASTQUEUE_TIMEDSEND_CHECK_PARAMS_ID     105UL
#define MPX_PTHREAD_FASTQUEUE_TRYRECEIVE_CHECK_PARAMS_ID    106UL
#define MPX_PTHREAD_FASTQUEUE_TRYSEND_CHECK_PARAMS_ID       107UL
#define MPX_PTHREAD_JOIN_CHECK_PARAMS_ID                    121UL
#define MPX_PTHREAD_KILL_CHECK_PARAMS_ID                    124UL
#define MPX_PTHREAD_MEMORYPOOL_ALLOCATE_CHECK_PARAMS_ID     128UL
#define MPX_PTHREAD_MEMORYPOOL_CREATE_CHECK_PARAMS_ID       129UL
#define MPX_PTHREAD_MEMORYPOOL_DESTROY_CHECK_PARAMS_ID      130UL
#define MPX_PTHREAD_MEMORYPOOL_FREE_CHECK_PARAMS_ID         131UL
#define MPX_PTHREAD_MEMORYPOOL_TIMEDALLOCATE_CHECK_PARAMS_ID 135UL
#define MPX_PTHREAD_MEMORYPOOL_TRYALLOCATE_CHECK_PARAMS_ID  136UL
#define MPX_PTHREAD_MUTEX_DESTROY_CHECK_PARAMS_ID           144UL
#define MPX_PTHREAD_MUTEX_INIT_CHECK_PARAMS_ID              148UL
#define MPX_PTHREAD_MUTEX_LOCK_CHECK_PARAMS_ID              149UL
#define MPX_PTHREAD_MUTEX_TRYLOCK_CHECK_PARAMS_ID           150UL
#define MPX_PTHREAD_MUTEX_UNLOCK_CHECK_PARAMS_ID            151UL
#define MPX_PTHREAD_PARTITIONPOOL_ALLOCATE_CHECK_PARAMS_ID  167UL
#define MPX_PTHREAD_PARTITIONPOOL_CREATE_CHECK_PARAMS_ID    168UL
#define MPX_PTHREAD_PARTITIONPOOL_DESTROY_CHECK_PARAMS_ID   169UL
#define MPX_PTHREAD_PARTITIONPOOL_FREE_CHECK_PARAMS_ID      170UL
#define MPX_PTHREAD_PARTITIONPOOL_TIMEDALLOCATE_CHECK_PARAMS_ID 174UL
#define MPX_PTHREAD_PARTITIONPOOL_TRYALLOCATE_CHECK_PARAMS_ID   175UL
#define MPX_PTHREAD_SIGMASK_CHECK_PARAMS_ID                 190UL
#define MPX_PTHREAD_TICKTIMER_CREATE_CHECK_PARAMS_ID        196UL
#define MPX_PTHREAD_TICKTIMER_DESTROY_CHECK_PARAMS_ID       197UL
#define MPX_PTHREAD_TICKTIMER_START_CHECK_PARAMS_ID         201UL
#define MPX_PTHREAD_TICKTIMER_STOP_CHECK_PARAMS_ID          202UL
#define MPX_PTHREAD_TICKTIMER_UPDATE_CHECK_PARAMS_ID        203UL
#define MPX_SEM_DESTROY_CHECK_PARAMS_ID                     214UL
#define MPX_SEM_EXTEND_INIT_CHECK_PARAMS_ID                 215UL
#define MPX_SEM_INIT_CHECK_PARAMS_ID                        219UL
#define MPX_SEM_POST_CHECK_PARAMS_ID                        220UL
#define MPX_SEM_TICKWAIT_CHECK_PARAMS_ID                    2211UL
#define MPX_SEM_TIMEDWAIT_CHECK_PARAMS_ID                   221UL
#define MPX_SEM_TRYWAIT_CHECK_PARAMS_ID                     222UL
#define MPX_SEM_WAIT_CHECK_PARAMS_ID                        223UL
#define MPX_SIGTIMEDWAIT_CHECK_PARAMS_ID                    238UL
#define MPX_SIGWAIT_CHECK_PARAMS_ID                         239UL
#define MPX_SIGWAITINFO_CHECK_PARAMS_ID                     240UL

#define MPX_CLOCK_GETRES_ID                                 1001UL
#define MPX_CLOCK_GETTIME_ID                                1002UL
#define MPX_CLOCK_SETTIME_ID                                1003UL
#define MPX_ERRNO_GET_ID                                    1004UL
#define MPX_ERRNO_SET_ID                                    1005UL
#define MPX_MQ_CLOSE_ID                                     1006UL
#define MPX_MQ_EXTEND_OPEN_ID                               1007UL
#define MPX_MQ_EXTENDATTR_DESTROY_ID                        1008UL
#define MPX_MQ_EXTENDATTR_GETCONTROLADDR_ID                 1009UL
#define MPX_MQ_EXTENDATTR_GETCONTROLSIZE_ID                 1010UL
#define MPX_MQ_EXTENDATTR_GETQUEUEADDR_ID                   1011UL
#define MPX_MQ_EXTENDATTR_GETQUEUESIZE_ID                   1012UL
#define MPX_MQ_EXTENDATTR_INIT_ID                           1013UL
#define MPX_MQ_EXTENDATTR_SETCONTROLADDR_ID                 1014UL
#define MPX_MQ_EXTENDATTR_SETQUEUEADDR_ID                   1015UL
#define MPX_MQ_GETATTR_ID                                   1016UL
#define MPX_MQ_OPEN_ID                                      1020UL
#define MPX_MQ_RECEIVE_ID                                   1021UL
#define MPX_MQ_SEND_ID                                      1022UL
#define MPX_MQ_SETATTR_ID                                   1023UL
#define MPX_MQ_TIMEDRECEIVE_ID                              1024UL
#define MPX_MQ_TIMEDSEND_ID                                 1025UL
#define MPX_NANOSLEEP_ID                                    1026UL
#define MPX_PTHREAD_ATTR_GETCONTROLADDR_ID                  1028UL
#define MPX_PTHREAD_ATTR_GETCONTROLSIZE_ID                  1029UL
#define MPX_PTHREAD_ATTR_DESTROY_ID                         1030UL
#define MPX_PTHREAD_ATTR_GETDETACHSTATE_ID                  1031UL
#define MPX_PTHREAD_ATTR_GETNAME_ID                         1032UL
#define MPX_PTHREAD_ATTR_GETPRIORITY_ID                     1033UL
#define MPX_PTHREAD_ATTR_GETSTACKADDR_ID                    1036UL
#define MPX_PTHREAD_ATTR_GETSTACKSIZE_ID                    1037UL 
#define MPX_PTHREAD_ATTR_GETTIMESLICE_ID                    1040UL
#define MPX_PTHREAD_ATTR_INIT_ID                            1041UL
#define MPX_PTHREAD_ATTR_SETCONTROLADDR_ID                  1042UL
#define MPX_PTHREAD_ATTR_SETDETACHSTATE_ID                  1043UL
#define MPX_PTHREAD_ATTR_SETNAME_ID                         1045UL
#define MPX_PTHREAD_ATTR_SETPRIORITY_ID                     1046UL
#define MPX_PTHREAD_ATTR_SETSTACKADDR_ID                    1050UL
#define MPX_PTHREAD_ATTR_SETSTACKSIZE_ID                    1051UL
#define MPX_PTHREAD_ATTR_SETTIMESLICE_ID                    1052UL
#define MPX_PTHREAD_CANCEL_ID                               1053UL
#define MPX_PTHREAD_CLEANUP_POP_ID                          1054UL
#define MPX_PTHREAD_CLEANUP_PUSH_ID                         1055UL 
#define MPX_PTHREAD_COND_BROADCAST_ID                       1056UL 
#define MPX_PTHREAD_COND_DESTROY_ID                         1057UL
#define MPX_PTHREAD_COND_INIT_ID                            1059UL
#define MPX_PTHREAD_COND_SIGNAL_ID                          1062UL
#define MPX_PTHREAD_COND_TIMEDWAIT_ID                       1063UL
#define MPX_PTHREAD_COND_WAIT_ID                            1064UL
#define MPX_PTHREAD_CONDATTR_DESTROY_ID                     1065UL
#define MPX_PTHREAD_CONDATTR_GETCONTROLADDR_ID              1066UL
#define MPX_PTHREAD_CONDATTR_GETCONTROLSIZE_ID              1067UL
#define MPX_PTHREAD_CONDATTR_GETNAME_ID                     1068UL
#define MPX_PTHREAD_CONDATTR_GETPSHARED_ID                  1069UL
#define MPX_PTHREAD_CONDATTR_INIT_ID                        1070UL
#define MPX_PTHREAD_CONDATTR_SETCONTROLADDR_ID              1071UL
#define MPX_PTHREAD_CONDATTR_SETNAME_ID                     1072UL
#define MPX_PTHREAD_CONDATTR_SETPSHARED_ID                  1073UL
#define MPX_PTHREAD_CREATE_ID                               1076UL
#define MPX_PTHREAD_DETACH_ID                               1077UL
#define MPX_PTHREAD_EQUAL_ID                                1078UL
#define MPX_PTHREAD_EVENT_FLAGS_CLEAR_ID                    1079UL
#define MPX_PTHREAD_EVENT_FLAGS_CREATE_ID                   1080UL
#define MPX_PTHREAD_EVENT_FLAGS_DESTROY_ID                  1081UL
#define MPX_PTHREAD_EVENT_FLAGS_SET_ID                      1085UL
#define MPX_PTHREAD_EVENT_FLAGS_TIMEDWAIT_ID                1086UL
#define MPX_PTHREAD_EVENT_FLAGS_TRYWAIT_ID                  1087UL
#define MPX_PTHREAD_EVENT_FLAGS_WAIT_ID                     1088UL
#define MPX_PTHREAD_EVENT_FLAGSATTR_DESTROY_ID              1089UL
#define MPX_PTHREAD_EVENT_FLAGSATTR_GETCONTROLADDR_ID       1090UL
#define MPX_PTHREAD_EVENT_FLAGSATTR_GETCONTROLSIZE_ID       1091UL
#define MPX_PTHREAD_EVENT_FLAGSATTR_GETNAME_ID              1092UL
#define MPX_PTHREAD_EVENT_FLAGSATTR_INIT_ID                 1093UL
#define MPX_PTHREAD_EVENT_FLAGSATTR_SETCONTROLADDR_ID       1094UL
#define MPX_PTHREAD_EVENT_FLAGSATTR_SETNAME_ID              1095UL
#define MPX_PTHREAD_EXIT_ID                                 1096UL
#define MPX_PTHREAD_FASTQUEUE_CREATE_ID                     1097UL
#define MPX_PTHREAD_FASTQUEUE_DESTROY_ID                    1098UL
#define MPX_PTHREAD_FASTQUEUE_RECEIVE_ID                    1102UL
#define MPX_PTHREAD_FASTQUEUE_SEND_ID                       1103UL
#define MPX_PTHREAD_FASTQUEUE_TIMEDRECEIVE_ID               1104UL
#define MPX_PTHREAD_FASTQUEUE_TIMEDSEND_ID                  1105UL
#define MPX_PTHREAD_FASTQUEUE_TRYRECEIVE_ID                 1106UL
#define MPX_PTHREAD_FASTQUEUE_TRYSEND_ID                    1107UL
#define MPX_PTHREAD_FASTQUEUEATTR_DESTROY_ID                1108UL
#define MPX_PTHREAD_FASTQUEUEATTR_GETCONTROLADDR_ID         1109UL
#define MPX_PTHREAD_FASTQUEUEATTR_GETCONTROLSIZE_ID         1110UL
#define MPX_PTHREAD_FASTQUEUEATTR_GETNAME_ID                1111UL
#define MPX_PTHREAD_FASTQUEUEATTR_GETQUEUEADDR_ID           1112UL
#define MPX_PTHREAD_FASTQUEUEATTR_GETQUEUESIZE_ID           1113UL
#define MPX_PTHREAD_FASTQUEUEATTR_INIT_ID                   1114UL
#define MPX_PTHREAD_FASTQUEUEATTR_SETCONTROLADDR_ID         1115UL
#define MPX_PTHREAD_FASTQUEUEATTR_SETNAME_ID                1116UL
#define MPX_PTHREAD_FASTQUEUEATTR_SETQUEUEADDR_ID           1117UL
#if MPX_MAXIMUM_CORES>1
#define MPX_PTHREAD_GETAFFINITY_NP_ID                       11171UL
#endif /* MPX_MAXIMUM_CORES>1  */
#define MPX_PTHREAD_INFORMATION_GET_ID                      1120UL
#define MPX_PTHREAD_JOIN_ID                                 1121UL
#define MPX_PTHREAD_KILL_ID                                 1124UL
#define MPX_PTHREAD_MEMORY_MANAGER_ENABLE_ID                1125UL
#define MPX_PTHREAD_MEMORY_MANAGER_GET_ID                   1126UL
#define MPX_PTHREAD_MEMORY_MANAGER_SET_ID                   1127UL
#define MPX_PTHREAD_MEMORYPOOL_ALLOCATE_ID                  1128UL
#define MPX_PTHREAD_MEMORYPOOL_CREATE_ID                    1129UL
#define MPX_PTHREAD_MEMORYPOOL_DESTROY_ID                   1130UL
#define MPX_PTHREAD_MEMORYPOOL_FREE_ID                      1131UL
#define MPX_PTHREAD_MEMORYPOOL_TIMEDALLOCATE_ID             1135UL
#define MPX_PTHREAD_MEMORYPOOL_TRYALLOCATE_ID               1136UL
#define MPX_PTHREAD_MEMORYPOOLATTR_DESTROY_ID               1137UL
#define MPX_PTHREAD_MEMORYPOOLATTR_GETCONTROLADDR_ID        1138UL
#define MPX_PTHREAD_MEMORYPOOLATTR_GETCONTROLSIZE_ID        1139UL
#define MPX_PTHREAD_MEMORYPOOLATTR_GETNAME_ID               1140UL
#define MPX_PTHREAD_MEMORYPOOLATTR_INIT_ID                  1141UL
#define MPX_PTHREAD_MEMORYPOOLATTR_SETCONTROLADDR_ID        1142UL
#define MPX_PTHREAD_MEMORYPOOLATTR_SETNAME_ID               1143UL
#define MPX_PTHREAD_MUTEX_DESTROY_ID                        1144UL
#define MPX_PTHREAD_MUTEX_INIT_ID                           1148UL
#define MPX_PTHREAD_MUTEX_LOCK_ID                           1149UL
#define MPX_PTHREAD_MUTEX_TRYLOCK_ID                        1150UL
#define MPX_PTHREAD_MUTEX_UNLOCK_ID                         1151UL
#define MPX_PTHREAD_MUTEXATTR_DESTROY_ID                    1152UL
#define MPX_PTHREAD_MUTEXATTR_GETCONTROLADDR_ID             1153UL
#define MPX_PTHREAD_MUTEXATTR_GETCONTROLSIZE_ID             1154UL
#define MPX_PTHREAD_MUTEXATTR_GETNAME_ID                    1155UL
#define MPX_PTHREAD_MUTEXATTR_GETPROTOCOL_ID                1156UL
#define MPX_PTHREAD_MUTEXATTR_GETPSHARED_ID                 1157UL
#define MPX_PTHREAD_MUTEXATTR_GETTYPE_ID                    1158UL
#define MPX_PTHREAD_MUTEXATTR_INIT_ID                       1159UL
#define MPX_PTHREAD_MUTEXATTR_SETCONTROLADDR_ID             1160UL
#define MPX_PTHREAD_MUTEXATTR_SETNAME_ID                    1161UL
#define MPX_PTHREAD_MUTEXATTR_SETPROTOCOL_ID                1162UL
#define MPX_PTHREAD_MUTEXATTR_SETPSHARED_ID                 1163UL
#define MPX_PTHREAD_MUTEXATTR_SETTYPE_ID                    1164UL
#define MPX_PTHREAD_PARTITIONPOOL_ALLOCATE_ID               1167UL
#define MPX_PTHREAD_PARTITIONPOOL_CREATE_ID                 1168UL
#define MPX_PTHREAD_PARTITIONPOOL_DESTROY_ID                1169UL
#define MPX_PTHREAD_PARTITIONPOOL_FREE_ID                   1170UL
#define MPX_PTHREAD_PARTITIONPOOL_TIMEDALLOCATE_ID          1174UL
#define MPX_PTHREAD_PARTITIONPOOL_TRYALLOCATE_ID            1175UL
#define MPX_PTHREAD_PARTITIONPOOLATTR_DESTROY_ID            1176UL
#define MPX_PTHREAD_PARTITIONPOOLATTR_GETCONTROLADDR_ID     1177UL
#define MPX_PTHREAD_PARTITIONPOOLATTR_GETCONTROLSIZE_ID     1178UL
#define MPX_PTHREAD_PARTITIONPOOLATTR_GETNAME_ID            1179UL
#define MPX_PTHREAD_PARTITIONPOOLATTR_INIT_ID               1180UL
#define MPX_PTHREAD_PARTITIONPOOLATTR_SETCONTROLADDR_ID     1181UL
#define MPX_PTHREAD_PARTITIONPOOLATTR_SETNAME_ID            1182UL
#define MPX_PTHREAD_PRIORITY_CHANGE_ID                      1183UL
#define MPX_PTHREAD_RESUME_ID                               1184UL
#define MPX_PTHREAD_SELF_ID                                 1185UL
#if MPX_MAXIMUM_CORES>1
#define MPX_PTHREAD_SETAFFINITY_NP_ID                       11851UL
#endif /* MPX_MAXIMUM_CORES>1  */
#define MPX_PTHREAD_SETCANCELSTATE_ID                       1186UL
#define MPX_PTHREAD_SETCANCELTYPE_ID                        1187UL
#define MPX_PTHREAD_SIGMASK_ID                              1190UL
#define MPX_PTHREAD_STACK_CHECK_ID                          1191UL
#define MPX_PTHREAD_START_ID                                1192UL
#define MPX_PTHREAD_SUSPEND_ID                              1193UL
#define MPX_PTHREAD_TESTCANCEL_ID                           1194UL
#define MPX_PTHREAD_TICK_SLEEP_ID                           1195UL
#define MPX_PTHREAD_TICKS_GET_ID                            1196UL
#define MPX_PTHREAD_TICKTIMER_CREATE_ID                     1197UL
#define MPX_PTHREAD_TICKTIMER_DESTROY_ID                    1198UL
#define MPX_PTHREAD_TICKTIMER_START_ID                      1202UL
#define MPX_PTHREAD_TICKTIMER_STOP_ID                       1203UL
#define MPX_PTHREAD_TICKTIMER_UPDATE_ID                     1204UL
#define MPX_PTHREAD_TICKTIMERATTR_DESTROY_ID                1205UL
#define MPX_PTHREAD_TICKTIMERATTR_GETCONTROLADDR_ID         1206UL
#define MPX_PTHREAD_TICKTIMERATTR_GETCONTROLSIZE_ID         1207UL
#define MPX_PTHREAD_TICKTIMERATTR_GETNAME_ID                1208UL
#define MPX_PTHREAD_TICKTIMERATTR_INIT_ID                   1209UL
#define MPX_PTHREAD_TICKTIMERATTR_SETCONTROLADDR_ID         1210UL
#define MPX_PTHREAD_TICKTIMERATTR_SETNAME_ID                1211UL
#define MPX_SCHED_YIELD_ID                                  1214UL
#define MPX_SEM_DESTROY_ID                                  1215UL
#define MPX_SEM_EXTEND_INIT_ID                              1216UL
#define MPX_SEM_INIT_ID                                     1220UL
#define MPX_SEM_POST_ID                                     1221UL
#define MPX_SEM_TICKWAIT_ID                                 1222UL
#define MPX_SEM_TIMEDWAIT_ID                                1223UL
#define MPX_SEM_TRYWAIT_ID                                  1224UL
#define MPX_SEM_WAIT_ID                                     1225UL
#define MPX_SEMATTR_DESTROY_ID                              1226UL
#define MPX_SEMATTR_GETCONTROLADDR_ID                       1227UL  
#define MPX_SEMATTR_GETCONTROLSIZE_ID                       1228UL
#define MPX_SEMATTR_GETNAME_ID                              1229UL
#define MPX_SEMATTR_INIT_ID                                 1230UL  
#define MPX_SEMATTR_SETCONTROLADDR_ID                       1231UL
#define MPX_SEMATTR_SETNAME_ID                              1232UL
#define MPX_SIGACTION_ID                                    1233UL 
#define MPX_SIGADDSET_ID                                    1234UL
#define MPX_SIGDELSET_ID                                    1235UL
#define MPX_SIGEMPTYSET_ID                                  1236UL
#define MPX_SIGFILLSET_ID                                   1237UL
#define MPX_SIGISMEMBER_ID                                  1238UL  
#define MPX_SIGPENDING_ID                                   1239UL
#define MPX_SIGTIMEDWAIT_ID                                 1240UL
#define MPX_SIGWAIT_ID                                      1241UL
#define MPX_SIGWAITINFO_ID                                  1242UL
#define MPX_SLEEP_ID                                        1243UL    
#define MPX_TIME_ID                                         1244UL
#define MPX_TIMER_INTERRUPT_PROCESS_ID                      1245UL
#define MPX_USLEEP_ID                                       1246UL

#define MPX_INTERNAL_CENTRAL_ERROR_ID                       2000UL
#define MPX_INTERNAL_HIGHEST_SET_BIT_GET_ID                 2001UL
#define MPX_INTERNAL_ISR_ENTER_ID                           2002UL
#define MPX_INTERNAL_ISR_EXIT_ID                            2003UL
#define MPX_INTERNAL_MEMORY_ALLOCATE_ID                     2004UL
#define MPX_INTERNAL_MEMORY_MANAGER_ALLOCATE_ID             2005UL
#define MPX_INTERNAL_MEMORY_MANAGER_RELEASE_ID              2006UL
#define MPX_INTERNAL_THREAD_ENTER_ID                        2007UL
#define MPX_INTERNAL_THREAD_EXIT_ID                         2008UL
#define MPX_INTERNAL_THREAD_PRIORITY_CHANGE_ID              2009UL
#define MPX_INTERNAL_THREAD_READY_ID                        2010UL
#define MPX_INTERNAL_THREAD_SUSPEND_ID                      2011UL
#define MPX_INTERNAL_THREAD_SWITCH_TO                       2012UL
#define MPX_INTERNAL_THREAD_SWITCH_FROM                     2013UL
#define MPX_INTERNAL_THREAD_TIMER_PROCESS_ID                2014UL 
#define MPX_INTERNAL_THREAD_WRAPPER_ID                      2015UL
#define MPX_INTERNAL_TICKTIMER_EXPIRE_ID                    2016UL
#define MPX_INTERNAL_TIME_SLICE_PROCESS_ID                  2017UL
#define MPX_INTERNAL_TIMER_ACTIVATE_ID                      2018UL
#define MPX_INTERNAL_TIMER_DEACTIVATE_ID                    2019UL
#define MPX_INTERNAL_TIMER_LIST_PROCESS_ID                  2020UL
#define MPX_INTERNAL_CLEANUP_HANDLERS_EXECUTE_ID            2021UL
#define MPX_INTERNAL_THREAD_DEFERRED_MEMORY_RELEASE_ID      2022UL


/* Define internal system error identification codes that indicate where the error occurred.  */

#define MPX_CONDITION_VAR_OBJECT_CORRUPTION_ERROR           3001UL
#define MPX_EVENT_FLAGS_OBJECT_CORRUPTION_ERROR             3002UL
#define MPX_GLOBAL_OBJECT_CORRUPTION_ERROR                  3003UL
#define MPX_INTERNAL_THREAD_INVALID_RETURN_ERROR            3004UL
#define MPX_INTERNAL_THREAD_DEFERRED_MEM_RELEASE_ERROR      3005UL
#define MPX_INTERNAL_THREAD_DEFERRED_MEM_RELEASE_ERROR1     3006UL
#define MPX_INTERNAL_THREAD_WRAPPER_ERROR                   3007UL
#define MPX_INTERNAL_THREAD_WRAPPER_ERROR1                  3008UL
#define MPX_INTERNAL_TICKTIMER_EXPIRE_ERROR                 3009UL
#define MPX_INTERNAL_TIMER_LIST_PROCESS_ERROR               3010UL
#define MPX_MEMORYPOOL_FRAGMENT_CORRUPTION_ERROR            3011UL
#define MPX_MUTEX_OBJECT_CORRUPTION_ERROR                   3012UL
#define MPX_PARTITIONPOOL_OBJECT_CORRUPTION_ERROR           3013UL
#define MPX_PARTITIONPOOL_CORRUPTION_ERROR                  3014UL
#define MPX_QUEUE_CLOSE_ERROR                               3015UL
#define MPX_QUEUE_CLOSE_ERROR1                              3016UL
#define MPX_QUEUE_OBJECT_CORRUPTION_ERROR                   3017UL
#define MPX_QUEUE_OPEN_ERROR                                3018UL
#define MPX_QUEUE_OPEN_ERROR1                               3019UL
#define MPX_PTHREAD_CANCEL_ERROR                            3020UL
#define MPX_PTHREAD_CANCEL_ERROR1                           3021UL
#define MPX_PTHREAD_CLEANUP_POP_ERROR                       3022UL
#define MPX_PTHREAD_COND_DESTROY_ERROR                      3023UL
#define MPX_PTHREAD_COND_INIT_ERROR                         3024UL
#define MPX_PTHREAD_COND_INIT_ERROR1                        3025UL
#define MPX_PTHREAD_CREATE_ERROR                            3026UL
#define MPX_PTHREAD_CREATE_ERROR1                           3027UL
#define MPX_PTHREAD_EVENT_FLAGS_CREATE_ERROR                3028UL
#define MPX_PTHREAD_EVENT_FLAGS_CREATE_ERROR1               3029UL
#define MPX_PTHREAD_EVENT_FLAGS_DESTROY_ERROR               3030UL
#define MPX_PTHREAD_EXIT_ERROR                              3031UL
#define MPX_PTHREAD_FASTQUEUE_CREATE_ERROR                  3032UL
#define MPX_PTHREAD_FASTQUEUE_CREATE_ERROR1                 3033UL
#define MPX_PTHREAD_FASTQUEUE_DESTROY_ERROR                 3034UL
#define MPX_PTHREAD_FASTQUEUE_DESTROY_ERROR1                3035UL
#define MPX_FASTQUEUE_OBJECT_CORRUPTION_ERROR               3036UL
#define MPX_PTHREAD_JOIN_ERROR                              3037UL
#define MPX_PTHREAD_JOIN_ERROR1                             3038UL
#define MPX_PTHREAD_KILL_ERROR                              3039UL
#define MPX_PTHREAD_KILL_ERROR1                             3040UL
#define MPX_PTHREAD_MEMORY_MANAGER_GET_ERROR                3041UL
#define MPX_PTHREAD_MEMORY_MANAGER_GET_ERROR1               3042UL
#define MPX_PTHREAD_MEMORYPOOL_CREATE_ERROR                 3043UL
#define MPX_PTHREAD_MEMORYPOOL_CREATE_ERROR1                3044UL
#define MPX_PTHREAD_MEMORYPOOL_DESTROY_ERROR                3045UL
#define MPX_PTHREAD_MUTEX_DESTROY_ERROR                     3046UL
#define MPX_PTHREAD_MUTEX_INIT_ERROR                        3047UL
#define MPX_PTHREAD_MUTEX_INIT_ERROR1                       3048UL
#define MPX_PTHREAD_PARTITIONPOOL_CREATE_ERROR              3049UL
#define MPX_PTHREAD_PARTITIONPOOL_CREATE_ERROR1             3050UL
#define MPX_PTHREAD_PARTITIONPOOL_DESTROY_ERROR             3051UL
#define MPX_PTHREAD_SIGMASK_ERROR                           3052UL
#define MPX_PTHREAD_SIGMASK_ERROR1                          3053UL
#define MPX_PTHREAD_TICKTIMER_CREATE_ERROR                  3054UL
#define MPX_PTHREAD_TICKTIMER_CREATE_ERROR1                 3055UL
#define MPX_PTHREAD_TICKTIMER_DESTROY_ERROR                 3056UL
#define MPX_SEM_DESTROY_ERROR                               3057UL
#define MPX_SEM_EXTEND_INIT_ERROR                           3058UL
#define MPX_SEM_EXTEND_INIT_ERROR1                          3059UL
#define MPX_SEM_INIT_ERROR                                  3060UL
#define MPX_SEM_INIT_ERROR1                                 3061UL
#define MPX_MEMORYPOOL_OBJECT_CORRUPTION_ERROR              3062UL
#define MPX_SEMAPHORE_OBJECT_CORRUPTION_ERROR               3063UL
#define MPX_THREAD_OBJECT_CORRUPTION_ERROR                  3064UL
#define MPX_TICKTIMER_OBJECT_CORRUPTION_ERROR               3065UL


/* Default internal system error processing to whitespace.  */

#ifndef MPX_LEVEL_3_ERROR_PROCESSING
#define MPX_LEVEL_3_ERROR_PROCESSING
#endif  /* MPX_LEVEL_3_ERROR_PROCESSING */

#ifndef MPX_LEVEL_2_ERROR_PROCESSING
#define MPX_LEVEL_2_ERROR_PROCESSING
#endif  /* MPX_LEVEL_2_ERROR_PROCESSING */

#ifndef MPX_LEVEL_1_ERROR_PROCESSING
#define MPX_LEVEL_1_ERROR_PROCESSING
#endif  /* MPX_LEVEL_1_ERROR_PROCESSING */


/* Default memory set routine to internal utility.  */

#ifndef MEMSET
#define MEMSET(pointer, value, length)                      mpx_internal_memset(pointer, value, length);
#endif  /* MEMSET */


/* Define bit map manipulation macros.  */  

#ifndef MPX_MAXIMUM_BITS
#define MPX_MAXIMUM_BITS                                    32UL
#endif

#ifndef MPX_BIT_SET
#define MPX_BIT_SET(w,b)                                    (w) =  (w) | (((u_long) 1UL) << (b))
#endif  /* MPX_BIT_SET */

#ifndef MPX_BIT_CLEAR
#define MPX_BIT_CLEAR(w,b)                                  (w) =  (w) & ~(((u_long) 1UL) << (b))
#endif  /* MPX_BIT_CLEAR */

#ifndef MPX_ANY_BIT_SET 
#define MPX_ANY_BIT_SET(w)                                  (w)
#endif  /* MPX_ANY_BIT_SET */

#ifndef MPX_HIGHEST_BIT_SET_GET
#define MPX_HIGHEST_BIT_SET_GET(b,w)                        (b) = mpx_internal_highest_set_bit_get((w));
#endif  /* MPX_HIGHEST_BIT_SET_GET */            


/* Define interrupt nesting level macro that is used to determine if processing is in an interrupt context.   */

#ifndef MPX_INTERRUPT_LEVEL_GET
#define MPX_INTERRUPT_LEVEL_GET(l)                          l =  mpx_globals.interrupt_nesting_level[MPX_EXECUTING_CORE];
#endif


/* Define Pointer\Data Verification Code computation, which can be overridden by the application.  */

#ifndef MPX_POINTER_DATA_VERIFY_CODE_COMPUTE
#define MPX_POINTER_DATA_VERIFY_CODE_COMPUTE(a, b)          (((a) + (b)) ^ mpx_globals.run_time_id)
#endif  /* MPX_POINTER_DATA_VERIFY_CODE_COMPUTE */


/* Default function pointer verification macros to white-space, unless enabled by the application.  */

#ifndef MPX_FUNCTION_POINTER_VERIFY_ENABLE
#define MPX_FUNCTION_POINTER_CODE_VERIFY(a, b, i)
#else
#ifndef MPX_FUNCTION_POINTER_CODE_ENABLE
#define MPX_FUNCTION_POINTER_CODE_ENABLE
#endif  /* MPX_FUNCTION_POINTER_CODE_ENABLE */
#define MPX_FUNCTION_POINTER_CODE_VERIFY(a, b, i)           mpx_internal_pointer_verification_code_verify((a), (b), (i));
#endif  /* MPX_FUNCION_POINTER_VERIFY_ENABLE */

#ifndef MPX_FUNCTION_POINTER_CODE_ENABLE
#define MPX_FUNCTION_POINTER_CODE_CREATE(a, b)
#else
#define MPX_FUNCTION_POINTER_CODE_CREATE(a, b)              mpx_internal_pointer_verification_code_create((a), (b));
#endif  /* MPX_FUNCTION_POINTER_CODE_ENABLE */


/* Default memory pool verification macros to white-space, unless enabled by the application.  */

#ifndef MPX_MEMORYPOOL_VERIFY_ENABLE
#define MPX_MEMORYPOOL_CODE_VERIFY(a, b, i)
#else
#ifndef MPX_MEMORYPOOL_CODE_ENABLE
#define MPX_MEMORYPOOL_CODE_ENABLE
#endif  /* MPX_MEMORYPOOL_CODE_ENABLE */
#define MPX_MEMORYPOOL_CODE_VERIFY(a, b, i)                 mpx_internal_pointer_verification_code_verify((a), (b), (i));
#endif  /* MPX_MEMORYPOOL_VERIFY_ENABLE */

#ifndef MPX_MEMORYPOOL_CODE_ENABLE
#define MPX_MEMORYPOOL_CODE_CREATE(a, b)
#else
#define MPX_MEMORYPOOL_CODE_CREATE(a, b)                    mpx_internal_pointer_verification_code_create((a), (b));
#endif  /* MPX_MEMORYPOOL_CODE_ENABLE */


/* Default object pointer verification macros to white-space, unless enabled by the application.  */

#ifndef MPX_OBJECT_VERIFY_ENABLE
#define MPX_OBJECT_CODE_VERIFY(a, b, i)
#else
#ifndef MPX_OBJECT_CODE_ENABLE
#define MPX_OBJECT_CODE_ENABLE
#endif  /* MPX_OBJECT_CODE_ENABLE */
#define MPX_OBJECT_CODE_VERIFY(a, b, i)                     mpx_internal_data_verification_code_verify((a), (b), (i));
#endif  /* MPX_OBJECT_VERIFY_ENABLE */

#ifndef MPX_OBJECT_CODE_ENABLE
#define MPX_OBJECT_CODE_CREATE(a, b)
#else
#define MPX_OBJECT_CODE_CREATE(a, b)                        mpx_internal_data_verification_code_create((a), (b));
#endif  /* MPX_OBJECT_CODE_ENABLE */


/* Default partition memory pool verification macros to white-space, unless enabled by the application.  */

#ifndef MPX_PARTITIONPOOL_VERIFY_ENABLE
#define MPX_PARTITIONPOOL_CODE_VERIFY(a, b, i)
#else
#ifndef MPX_PARTITIONPOOL_CODE_ENABLE
#define MPX_PARTITIONPOOL_CODE_ENABLE
#endif  /* MPX_PARTITIONPOOL_CODE_ENABLE */
#define MPX_PARTITIONPOOL_CODE_VERIFY(a, b, i)              mpx_internal_pointer_verification_code_verify((a), (b), (i));
#endif  /* MPX_PARTITIONPOOL_VERIFY_ENABLE */

#ifndef MPX_PARTITIONPOOL_CODE_ENABLE
#define MPX_PARTITIONPOOL_CODE_CREATE(a, b)
#else
#define MPX_PARTITIONPOOL_CODE_CREATE(a, b)                 mpx_internal_pointer_verification_code_create((a), (b));
#endif  /* MPX_PARTITIONPOOL_CODE_ENABLE */


/* Default stack verification macros to white-space, unless enabled by the application.  */

#ifndef MPX_STACK_VERIFY_ID
#define MPX_STACK_VERIFY_ID                                 0x5354434BUL
#endif  /* MPX_STACK_VERIFY_ID */

#ifndef MPX_STACK_VERIFY_ENABLE
#define MPX_STACK_VERIFY_INFO
#define MPX_STACK_VERIFY_SETUP(i)
#define MPX_STACK_VERIFY(i)
#else
#define MPX_STACK_VERIFY_INFO                               mpx_internal_stack_verification     stack_verification;
#define MPX_STACK_VERIFY_SETUP(i)                           stack_verification.stack_verification_id =  MPX_STACK_VERIFY_ID;   \
                                                            mpx_internal_data_verification_code_create(stack_verification.stack_verification_id, &stack_verification.stack_verification_code);
#define MPX_STACK_VERIFY(i)                                 mpx_internal_data_verification_code_verify((stack_verification.stack_verification_id + (stack_verification.stack_verification_id - (MPX_STACK_VERIFY_ID))), &stack_verification.stack_verification_code, (i));
#endif  /* MPX_STACK_VERIFY_ENABLE */


/* Default stack size checking macros to white-space, unless enabled by the application.  */

#ifndef MPX_STACK_CHECK_ENABLE
#define MPX_STACK_SIZE_CHECK(i) 
#else                                                     
#define MPX_STACK_SIZE_CHECK(i)                             mpx_internal_thread_stack_size_check(i);
#endif  /* MPX_STACK_CHECK_ENABLE */


/* Default MPX global data extensions to white-space.  */

#ifndef MPX_GLOBAL_DATA_BINDING_EXTENSION
#define MPX_GLOBAL_DATA_BINDING_EXTENSION
#endif  /* MPX_GLOBAL_DATA_BINDING_EXTENSION */

#ifndef MPX_GLOBAL_DATA_EXTENSION
#define MPX_GLOBAL_DATA_EXTENSION
#endif  /* MPX_GLOBAL_DATA_EXTENSION */


/* Default the binding verification processing extension to white-space.  */

#ifndef MPX_BINDING_VERIFICATION_EXTENSION
#define MPX_BINDING_VERIFICATION_EXTENSION
#endif  /* MPX_BINDING_VERIFICATION_EXTENSION */


/* Default the mpx_pthread_start extensions to white-space.  */

#ifndef MPX_PTHREAD_START_PRE_EXTENSION
#define MPX_PTHREAD_START_PRE_EXTENSION
#endif  /* MPX_PTHREAD_START_PRE_EXTENSION */

#ifndef MPX_PTHREAD_START_POST_EXTENSION
#define MPX_PTHREAD_START_POST_EXTENSION
#endif  /* MPX_PTHREAD_START_POST_EXTENSION */


/* Default the MPX thread entry (pre and post) extension processing to white-space.  */

#ifndef MPX_PTHREAD_ENTRY_PRE_EXTENSION
#define MPX_PTHREAD_ENTRY_PRE_EXTENSION
#endif  /* MPX_PTHREAD_ENTRY_PRE_EXTENSION */

#ifndef MPX_PTHREAD_ENTRY_POST_EXTENSION
#define MPX_PTHREAD_ENTRY_POST_EXTENSION
#endif  /* MPX_PTHREAD_ENTRY_POST_EXTENSION */


/* Default the MPX thread exit (pre and post) extension processing to white-space.  */

#ifndef MPX_PTHREAD_EXIT_PRE_EXTENSION
#define MPX_PTHREAD_EXIT_PRE_EXTENSION
#endif  /* MPX_PTHREAD_EXIT_PRE_EXTENSION */

#ifndef MPX_PTHREAD_EXIT_POST_EXTENSION
#define MPX_PTHREAD_EXIT_POST_EXTENSION
#endif  /* MPX_PTHREAD_EXIT_POST_EXTENSION */


/* Default the MPX create/init/open extensions to white space.  */

#ifndef MPX_MQ_EXTEND_OPEN_EXTENSION
#define MPX_MQ_EXTEND_OPEN_EXTENSION
#endif  /* MPX_MQ_EXTEND_OPEN_EXTENSION */

#ifndef MPX_MQ_OPEN_EXTENSION 
#define MPX_MQ_OPEN_EXTENSION 
#endif  /* MPX_MQ_OPEN_EXTENSION */

#ifndef MPX_PTHREAD_COND_INIT_EXTENSION 
#define MPX_PTHREAD_COND_INIT_EXTENSION 
#endif  /* MPX_PTHREAD_COND_INIT_EXTENSION */

#ifndef MPX_PTHREAD_CREATE_EXTENSION
#define MPX_PTHREAD_CREATE_EXTENSION
#endif  /* MPX_PTHREAD_CREATE_EXTENSION */

#ifndef MPX_PTHREAD_EVENT_FLAGS_CREATE_EXTENSION
#define MPX_PTHREAD_EVENT_FLAGS_CREATE_EXTENSION
#endif  /* MPX_PTHREAD_EVENT_FLAGS_CREATE_EXTENSION */

#ifndef MPX_PTHREAD_FASTQUEUE_CREATE_EXTENSION
#define MPX_PTHREAD_FASTQUEUE_CREATE_EXTENSION
#endif  /* MPX_PTHREAD_FASTQUEUE_CREATE_EXTENSION */

#ifndef MPX_PTHREAD_MEMORYPOOL_CREATE_EXTENSION 
#define MPX_PTHREAD_MEMORYPOOL_CREATE_EXTENSION 
#endif  /* MPX_PTHREAD_MEMORYPOOL_CREATE_EXTENSION */

#ifndef MPX_PTHREAD_MUTEX_INIT_EXTENSION
#define MPX_PTHREAD_MUTEX_INIT_EXTENSION
#endif  /* MPX_PTHREAD_MUTEX_INIT_EXTENSION */

#ifndef MPX_PTHREAD_PARTITIONPOOL_CREATE_EXTENSION 
#define MPX_PTHREAD_PARTITIONPOOL_CREATE_EXTENSION 
#endif  /* MPX_PTHREAD_PARTITIONPOOL_CREATE_EXTENSION */

#ifndef MPX_PTHREAD_TICKTIMER_CREATE_EXTENSION
#define MPX_PTHREAD_TICKTIMER_CREATE_EXTENSION
#endif  /* MPX_PTHREAD_TICKTIMER_CREATE_EXTENSION */

#ifndef MPX_SEM_EXTEND_INIT_EXTENSION
#define MPX_SEM_EXTEND_INIT_EXTENSION
#endif  /* MPX_SEM_EXTEND_INIT_EXTENSION */

#ifndef MPX_SEM_INIT_EXTENSION
#define MPX_SEM_INIT_EXTENSION
#endif  /* MPX_SEM_INIT_EXTENSION */


/* Default the MPX function prologue and epilogue extensions to white-space.  */

#ifndef MPX_FUNCTION_ENTRY_EXTENSION
#define MPX_FUNCTION_ENTRY_EXTENSION(a)
#endif  /* MPX_FUNCTION_ENTRY_EXTENSION */

#ifndef MPX_FUNCTION_EXIT_EXTENSION
#define MPX_FUNCTION_EXIT_EXTENSION(a)
#endif  /* MPX_FUNCTION_EXIT_EXTENSION */


/* Default the MPX system trace extensions to white-space.  */

#ifndef MPX_SYSTEM_TRACE_API_EXTENSION
#define MPX_SYSTEM_TRACE_API_EXTENSION(a, b, c, d)
#endif  /* MPX_SYSTEM_TRACE_API_EXTENSION */

#ifndef MPX_SYSTEM_TRACE_ERROR_EXTENSION
#define MPX_SYSTEM_TRACE_ERROR_EXTENSION(a, b, c, d)
#endif  /* MPX_SYSTEM_TRACE_ERROR_EXTENSION */

#ifndef MPX_SYSTEM_TRACE_THREAD_ENTER_EXTENSION
#define MPX_SYSTEM_TRACE_THREAD_ENTER_EXTENSION(a, b, c, d)
#endif  /* MPX_SYSTEM_TRACE_THREAD_ENTER_EXTENSION */

#ifndef MPX_SYSTEM_TRACE_THREAD_EXIT_EXTENSION
#define MPX_SYSTEM_TRACE_THREAD_EXIT_EXTENSION(a, b, c, d)
#endif  /* MPX_SYSTEM_TRACE_THREAD_EXIT_EXTENSION */

#ifndef MPX_SYSTEM_TRACE_THREAD_PRIORITY_CHANGE_EXTENSION
#define MPX_SYSTEM_TRACE_THREAD_PRIORITY_CHANGE_EXTENSION(a, b, c, d)
#endif  /* MPX_SYSTEM_TRACE_THREAD_PRIORITY_CHANGE_EXTENSION */

#ifndef MPX_SYSTEM_TRACE_THREAD_READY_EXTENSION
#define MPX_SYSTEM_TRACE_THREAD_READY_EXTENSION(a, b, c, d)
#endif  /* MPX_SYSTEM_TRACE_THREAD_READY_EXTENSION */

#ifndef MPX_SYSTEM_TRACE_THREAD_SUSPEND_EXTENSION
#define MPX_SYSTEM_TRACE_THREAD_SUSPEND_EXTENSION(a, b, c, d)
#endif  /* MPX_SYSTEM_TRACE_THREAD_SUSPEND_EXTENSION */

#ifndef MPX_SYSTEM_TRACE_TIMER_INTERRUPT_EXTENSION
#define MPX_SYSTEM_TRACE_TIMER_INTERRUPT_EXTENSION(a, b, c, d)
#endif  /* MPX_SYSTEM_TRACE_TIMER_INTERRUPT_EXTENSION */


/* Define the MPX thread entry/exit extensions to white-space.  */

#ifndef MPX_BINDING_THREAD_ENTRY_EXTENSION
#define MPX_BINDING_THREAD_ENTRY_EXTENSION(a)
#endif  /* MPX_BINDING_THREAD_ENTRY_EXTENSION */

#ifndef MPX_BINDING_THREAD_EXIT_EXTENSION
#define MPX_BINDING_THREAD_EXIT_EXTENSION(a)
#endif  /* MPX_BINDING_THREAD_EXIT_EXTENSION */

#ifndef MPX_USER_THREAD_ENTRY_EXTENSION
#define MPX_USER_THREAD_ENTRY_EXTENSION(a)
#endif  /* MPX_BINDING_THREAD_ENTRY_EXTENSION */

#ifndef MPX_USER_THREAD_EXIT_EXTENSION
#define MPX_USER_THREAD_EXIT_EXTENSION(a)
#endif  /* MPX_USER_THREAD_EXIT_EXTENSION */


/* Default the MPX timer interrupt pre-processing extenstion to white-space.  */

#ifndef MPX_TIMER_INTERRUPT_PRE_PROCESS_EXTENSION
#define MPX_TIMER_INTERRUPT_PRE_PROCESS_EXTENSION
#endif  /* MPX_TIMER_INTERRUPT_PRE_PROCESS_EXTENSION */


/* Default the MPX timer interrupt post-processing extenstion to white-space.  */

#ifndef MPX_TIMER_INTERRUPT_POST_PROCESS_EXTENSION
#define MPX_TIMER_INTERRUPT_POST_PROCESS_EXTENSION
#endif  /* MPX_TIMER_INTERRUPT_POST_PROCESS_EXTENSION */


/* Default the MPX condition variable timed wait processing extension to white-space.  */

#ifndef MPX_PTHREAD_COND_TIMEDWAIT_PROCESSING_EXTENSION
#define MPX_PTHREAD_COND_TIMEDWAIT_PROCESSING_EXTENSION
#endif  /* MPX_PTHREAD_COND_TIMEDWAIT_PROCESSING_EXTENSION */


/* Default the MPX condition variable wait processing extension to white-space.  */

#ifndef MPX_PTHREAD_COND_WAIT_PROCESSING_EXTENSION
#define MPX_PTHREAD_COND_WAIT_PROCESSING_EXTENSION
#endif  /* MPX_PTHREAD_COND_WAIT_PROCESSING_EXTENSION */


/* Default MPX thread control structure extensions to white-space.  */

#ifndef MPX_THREAD_CONTROL_BINDING_EXTENSION
#define MPX_THREAD_CONTROL_BINDING_EXTENSION
#endif  /* MPX_THREAD_CONTROL_BINDING_EXTENSION */

#ifndef MPX_THREAD_CONTROL_EXTENSION
#define MPX_THREAD_CONTROL_EXTENSION
#endif  /* MPX_THREAD_CONTROL_EXTENSION */


/* Default MPX condition variable control structure extension to white-space.  */

#ifndef MPX_CONDITION_VAR_CONTROL_EXTENSION
#define MPX_CONDITION_VAR_CONTROL_EXTENSION
#endif  /* MPX_CONDITION_VAR_CONTROL_EXTENSION */


/* Default MPX event flags control structure extension to white-space.  */

#ifndef MPX_EVENT_FLAGS_CONTROL_EXTENSION
#define MPX_EVENT_FLAGS_CONTROL_EXTENSION
#endif  /* MPX_EVENT_FLAGS_CONTROL_EXTENSION */


/* Default MPX fastqueue control structure extension to white-space.  */

#ifndef MPX_FASTQUEUE_CONTROL_EXTENSION
#define MPX_FASTQUEUE_CONTROL_EXTENSION
#endif  /* MPX_FASTQUEUE_CONTROL_EXTENSION */


/* Default MPX memory pool control structure extension to white-space.  */

#ifndef MPX_MEMORYPOOL_CONTROL_EXTENSION
#define MPX_MEMORYPOOL_CONTROL_EXTENSION
#endif  /* MPX_MEMORYPOOL_CONTROL_EXTENSION */


/* Default MPX memory pool control structure extension to white-space.  */

#ifndef MPX_MEMORYPOOL_BLOCK_INFO_EXTENSION
#define MPX_MEMORYPOOL_BLOCK_INFO_EXTENSION
#endif  /* MPX_MEMORYPOOL_BLOCK_INFO_EXTENSION */


/* Default the MPX memory allocate processing extension to white-space.  */

#ifndef MPX_PTHREAD_MEMORYPOOL_ALLOCATE_PROCESSING_EXTENSION
#define MPX_PTHREAD_MEMORYPOOL_ALLOCATE_PROCESSING_EXTENSION
#endif  /* MPX_PTHREAD_MEMORYPOOL_ALLOCATE_PROCESSING_EXTENSION */


/* Default the MPX memory timed allocate processing extension to white-space.  */

#ifndef MPX_PTHREAD_MEMORYPOOL_TIMEDALLOCATE_PROCESSING_EXTENSION
#define MPX_PTHREAD_MEMORYPOOL_TIMEDALLOCATE_PROCESSING_EXTENSION
#endif  /* MPX_PTHREAD_MEMORYPOOL_TIMEDALLOCATE_PROCESSING_EXTENSION */


/* Default MPX partition memory pool control structure extension to white-space.  */

#ifndef MPX_PARTITIONPOOL_CONTROL_EXTENSION
#define MPX_PARTITIONPOOL_CONTROL_EXTENSION
#endif  /* MPX_PARTITIONPOOL_CONTROL_EXTENSION */


/* Default MPX partition memory pool control structure extension to white-space.  */

#ifndef MPX_PARTITION_INFO_EXTENSION
#define MPX_PARTITION_INFO_EXTENSION
#endif  /* MPX_PARTIT_INFO_EXTENSION */


/* Default MPX message timed receive extension to white-space.  */

#ifndef MPX_MESSAGE_TIMEDRECEIVE_SEARCH_EXTENSION
#define MPX_MESSAGE_TIMEDRECEIVE_SEARCH_EXTENSION
#endif  /* MPX_MESSAGE_RECEIVE_SEARCH_EXTENSION */


/* Default MPX message timed receive extension to white-space.  */

#ifndef MPX_MESSAGE_TIMEDRECEIVE_SEARCH_EXTENSION1
#define MPX_MESSAGE_TIMEDRECEIVE_SEARCH_EXTENSION1
#endif  /* MPX_MESSAGE_RECEIVE_SEARCH_EXTENSION1 */


/* Default MPX message receive extension to white-space.  */

#ifndef MPX_MESSAGE_RECEIVE_SEARCH_EXTENSION
#define MPX_MESSAGE_RECEIVE_SEARCH_EXTENSION
#endif  /* MPX_MESSAGE_RECEIVE_SEARCH_EXTENSION */


/* Default MPX message receive extension to white-space.  */

#ifndef MPX_MESSAGE_RECEIVE_SEARCH_EXTENSION1
#define MPX_MESSAGE_RECEIVE_SEARCH_EXTENSION1
#endif  /* MPX_MESSAGE_RECEIVE_SEARCH_EXTENSION1 */


/* Default MPX message send extension to white-space.  */

#ifndef MPX_MESSAGE_SEND_SEARCH_EXTENSION
#define MPX_MESSAGE_SEND_SEARCH_EXTENSION
#endif  /* MPX_MESSAGE_SEND_SEARCH_EXTENSION */


/* Default MPX message timed send extension to white-space.  */

#ifndef MPX_MESSAGE_TIMEDSEND_SEARCH_EXTENSION
#define MPX_MESSAGE_TIMEDSEND_SEARCH_EXTENSION
#endif  /* MPX_MESSAGE_TIMEDSEND_SEARCH_EXTENSION */


/* Define MPX condition variable signal search extension to white-space.  */

#ifndef MPX_PTHREAD_COND_SIGNAL_SEARCH_EXTENSION
#define MPX_PTHREAD_COND_SIGNAL_SEARCH_EXTENSION
#endif  /* MPX_PTHREAD_COND_SIGNAL_SEARCH_EXTENSION */
                                                    

/* Define MPX event flags set search extension to white-space.  */

#ifndef MPX_PTHREAD_EVENT_FLAGS_SET_SEARCH_EXTENSION
#define MPX_PTHREAD_EVENT_FLAGS_SET_SEARCH_EXTENSION
#endif  /* MPX_PTHREAD_EVENT_FLAGS_SET_SEARCH_EXTENSION */


/* Default MPX mutex control structure extension to white-space.  */

#ifndef MPX_MUTEX_CONTROL_EXTENSION
#define MPX_MUTEX_CONTROL_EXTENSION
#endif  /* MPX_MUTEX_CONTROL_EXTENSION */


/* Define MPX mutex unlock search extension to white-space.  */

#ifndef MPX_PTHREAD_MUTEX_UNLOCK_SEARCH_EXTENSION
#define MPX_PTHREAD_MUTEX_UNLOCK_SEARCH_EXTENSION
#endif  /* MPX_PTHREAD_MUTEX_UNLOCK_SEARCH_EXTENSION */


/* Define MPX semaphore post search extension to white-space.  */
#ifndef MPX_SEMAPHORE_POST_SEARCH_EXTENSION
#define MPX_SEMAPHORE_POST_SEARCH_EXTENSION
#endif


/* Default MPX message queue control structure extension to white-space.  */

#ifndef MPX_QUEUE_CONTROL_EXTENSION
#define MPX_QUEUE_CONTROL_EXTENSION
#endif  /* MPX_QUEUE_CONTROL_EXTENSION */


/* Default MPX semaphore control structure extension to white-space.  */

#ifndef MPX_SEMAPHORE_CONTROL_EXTENSION
#define MPX_SEMAPHORE_CONTROL_EXTENSION
#endif  /* MPX_SEMAPHORE_CONTROL_EXTENSION */


/* Default MPX ticktimer control structure extension to white-space.  */

#ifndef MPX_TICKTIMER_CONTROL_EXTENSION
#define MPX_TICKTIMER_CONTROL_EXTENSION
#endif  /* MPX_TICKTIMER_CONTROL_EXTENSION */


/* Default MPX internal timer control structure extension to white-space.  */

#ifndef MPX_INTERNAL_TIMER_CONTROL_EXTENSION
#define MPX_INTERNAL_TIMER_CONTROL_EXTENSION
#endif  /* MPX_INTERNAL_TIMER_CONTROL_EXTENSION */


/* Default MPX binding C-extension utilities to white-space.  */
#ifndef MPX_BINDING_C_EXTENSION_UTILITIES
#define MPX_BINDING_C_EXTENSION_UTILITIES
#endif /* MPX_BINDING_C_EXTENSION_UTILITIES */


/******************************************************************************
 *************************** Section III: Typedefs ****************************
 *****************************************************************************/


/* Define internal stack verification typedef.  */

typedef struct mpx_internal_stack_verification_struct
{
    
    /* Define stack verification ID and verification code.   */
    u_long                                                  stack_verification_id;
    u_long                                                  stack_verification_code;
} mpx_internal_stack_verification;


/* Define forward reference for internal timer control structure, which
   will be defined in full later.  */

struct mpx_internal_timer_control_struct;


/* Define the base doubly linked, circular list type.  */

typedef struct mpx_internal_timer_links_struct
{
    
    /* Define next and previous links.  */
    struct mpx_internal_timer_control_struct *              next_internal_timer;
    struct mpx_internal_timer_control_struct *              previous_internal_timer;

} mpx_internal_timer_links;


/* Define the internal timer control structure that is for internal use only, i.e., 
   it is not directly exposed to the application code.  */

typedef struct mpx_internal_timer_control_struct
{

    /* Define the amount of remaining amount of ticks.  */
    tick_t                                                  remaining_ticks;

    /* Define the reload number of ticks for periodic internal timers.  */
    tick_t                                                  reload_ticks;

    /* Define the expiration function to call when the internal timer ticks expire.  */
    void                                                    (*expiration_routine)(struct mpx_internal_timer_control_struct *);

    /* Define the expiration function verification code.  */
    u_long                                                  expiration_routine_pointer_verification_code;

    /* Define the auxiliary information pointer.  */
    void *                                                  auxilliary_timer_information;

    /* Define the pointer to the head list, since the timer may be on different lists.  When the list head
       is non-NULL, the internal timer is active.  When NULL, the internal timer in inactive.  */
    struct mpx_internal_timer_control_struct **             list_head;

    /* Define the linked list pointers for the internal timer active list.  */
    mpx_internal_timer_links                                active_list;

    /* Define an area for general extensions to the internal timer control structure. By default, this is defined as 
       white-space above.  */
    MPX_INTERNAL_TIMER_CONTROL_EXTENSION

} mpx_internal_timer_control;


/* Define forward reference for thread control structure, which
   will be defined in full later.  */

struct mpx_thread_control_struct;


/* Define the base doubly linked, circular list type.  */

typedef struct mpx_thread_links_struct
{
    
    /* Define next and previous links.  */
    struct mpx_thread_control_struct *                      next_thread;
    struct mpx_thread_control_struct *                      previous_thread;

} mpx_thread_links;


/* Define the cleanup routine type.  */

typedef struct mpx_thread_cleanup_info_struct
{

    /* Define the cleanup handler function pointer and verification code.  */
    void                                                    (*cleanup_handler)(void *);
    u_long                                                  cleanup_handler_verification_code;
    void *                                                  argument;

} mpx_thread_cleanup_info;


/* Define forward reference for mutex control structure, which
   will be defined in full later.  */

struct mpx_mutex_control_struct;


/* Define the internal thread control structure that is for internal use only, i.e., 
   it is not directly exposed to the application code.  */

typedef struct mpx_thread_control_struct
{

    /* This first section of the MPX thread control structure is accessed by the binding assembly code
       and therefore should not be modified.  */

    /* Define the ID of the MPX thread control structure.  */
    u_long                                                  thread_control_id;

    /* Define the verification ID that is used to create the verification code that this stored at the end of the thread control 
       structure - when enabled.  */
    u_long                                                  thread_verification_id;

    /* Define the stack pointers of the thread.  */
    u_long *                                                stack_limit_address;
    u_long *                                                stack_base_address;
    u_long *                                                current_stack_pointer;
    u_long                                                  total_stack_size_in_bytes;
    u_long                                                  minimum_available_stack_bytes;

    /* Define the number of times this thread has been scheduled.  */
    u_long                                                  scheduled_count;

    /* Define an area accessible to the binding assembly language for extensions to the thread
       control structure. By default, this is defined as white-space above.  */
    MPX_THREAD_CONTROL_BINDING_EXTENSION

#if MPX_MAXIMUM_CORES>1

    int                                                     executing_core; 
    u_long                                                  core_affinity;  
#endif /* MPX_MAXIMUM_CORES>1  */

    /* Define name of the thread.  */
    char *                                                  name;

    /* Define the thread state.  */
    int                                                     state;

    /* Define the thread priority.  */      
    int                                                     priority;
    int                                                     user_priority;
    int                                                     inheritance_priority;

    /* Define the thread detach state.  */
    int                                                     detach_state;

    /* Define the thread's cancel state and type.  */
    int                                                     cancel_state;
    int                                                     cancel_type;
    int                                                     cancel_pending;

    /* Define the thread time-slice information.  */
    tick_t                                                  time_slice_remaining;
    tick_t                                                  time_slice_reload;

    /* Define the signal mask and the pending signals for this thread.  */
    sigset_t                                                pending_signals;
    sigset_t                                                signal_mask;

    /* Define the signal set that the thread is suspended on.  */
    sigset_t                                                suspended_for_signals;
    int                                                     signal_received;

    /* Define the context the signal handler runs in.  */
    struct mpx_thread_control_struct  *                     signal_thread;

    /* Define the thread-specific error variable. */
    int                                                     error;

    /* Define the entry point for the thread.  */
    void *                                                  (*entry_routine)(void *);
    u_long                                                  entry_routine_verification_code;
    void *                                                  argument;
    void *                                                  exit_value;
    
    /* Define the memory release function for the control structure.  */
    void                                                    (*control_memory_release_pointer)(u_int type, void *memory_to_release);
    u_long                                                  control_memory_release_pointer_verification_code;

    /* Define the memory release function for the thread's stack.  */
    void                                                    (*stack_memory_release_pointer)(u_int type, void *memory_to_release);
    u_long                                                  stack_memory_release_pointer_verification_code;

    /* Define the join information for this thread.  */
    struct mpx_thread_control_struct *                      thread_that_joined;
    void **                                                 exit_value_destination;

    /* Define the owned priority inheritance list.  */
    struct mpx_mutex_control_struct *                       owned_prio_inheritance_mutexes;
    u_long                                                  owned_prio_inheritance_count;

    /* Define the linked list pointers for the thread created list.  */
    mpx_thread_links                                        created_list;

    /* Define the linked list pointers for the thread ready list.  */
    mpx_thread_links                                        ready_list;

    /* Define an auxiliary thread pointer for internal object use. */
    struct mpx_thread_control_struct *                      thread_pointer;

    /* Define the linked list pointers for the thread suspension list.  */
    struct mpx_thread_control_struct **                     suspension_list_head;
    u_long *                                                suspended_count;
    mpx_thread_links                                        suspension_list;

    /* Define the suspended internal pointer.  */
    u_long *                                                suspended_pointer;

    /* Define the suspended data.  */
    size_t                                                  suspended_size;
    int                                                     suspended_type;
    u_long                                                  suspended_events;
    unsigned int                                            suspended_priority;

    /* Define the internal timer control block used for sleep requests.  */
    mpx_internal_timer_control                              timer;

    /* Define cleanup handler information.  */
    int                                                     stacked_cleanup_handlers;
    mpx_thread_cleanup_info                                 cleanup_handlers[MPX_MAXIMUM_CLEANUP_HANDLERS];

    /* Define an area for general extensions to the thread control structure. By default, this is defined as 
       white-space above.  */
    MPX_THREAD_CONTROL_EXTENSION

    /* Define the optional verification code for the thread structure.  */
    u_long                                                  thread_verification_code;

} mpx_thread_control;


/* Define the base doubly linked, circular list type.  */

typedef struct mpx_mutex_links_struct
{
    
    /* Define next and previous links.  */
    struct mpx_mutex_control_struct *                       next_mutex;
    struct mpx_mutex_control_struct *                       previous_mutex;

} mpx_mutex_links;


/* Define the internal mutex control structure, which is used for mutual exclusion.  */

typedef struct mpx_mutex_control_struct
{

    /* Define the ID of mutex control structure.  */
    u_long                                                  mutex_id;

    /* Define the verification ID that is used to create the verification code that this stored at the end of the mutex control 
       structure - when enabled.  */
    u_long                                                  mutex_verfication_id;

    /* Define the name of the mutex.  */
    char *                                                  name;

    /* Define the type of the mutex.  */
    int                                                     type;

    /* Define the protocol of the mutex.  */
    int                                                     protocol;

    /* Define the routine to call when the mutex control memory is no longer needed.  */
    void                                                    (*memory_release_pointer)(u_int type, void *memory_to_release);
    u_long                                                  memory_release_pointer_verification_code;

    /* Define the owner of the mutex.  */
    mpx_thread_control *                                    owner;               

    /* Define the nested ownership of the mutex, i.e., how many times the current owner has obtained
       the mutex.  */
    u_long                                                  nested_count;

    /* Define the counter for the number of condition variable waits (and timed waits) active. This is necessary to prevent destruction of 
       the mutex while conditional variable waits are pending.  */
    u_long                                                  condition_var_waits;

    /* Define the maximum nested ownership of the mutex.  Since by default, mutexes are not created recursive, this count is set to 1.  */
    u_long                                                  maximum_nesting;

    /* Define the current access for this mutex.  */
    mpx_thread_control *                                    current_access;

    /* Define the list of threads waiting on the mutex.  */
    mpx_thread_control *                                    suspended_list;

    /* Define the number of threads waiting on the mutex.  */
    u_long                                                  suspended_count;

    /* Define the highest-priority suspended thread.  */
    int                                                     suspended_highest_priority;

    /* Define the mutex priority inheritance list, next and previous pointers.  */
    mpx_mutex_links                                         owned_prio_inheritance_list;

    /* Define the mutex created list, next and previous pointers.  */
    mpx_mutex_links                                         created_list;

    /* Define an area for general extensions to the mutex control structure. By default, this is defined as 
       white-space above.  */
    MPX_MUTEX_CONTROL_EXTENSION

    /* Define the optional verification code for the mutex structure.  */
    u_long                                                  mutex_verification_code;

} mpx_mutex_control;


/* Define forward reference for condition variable control structure, which
   will be defined in full later.  */

struct mpx_condition_var_control_struct;


/* Define the base doubly linked, circular list type.  */

typedef struct mpx_condition_var_links_struct
{
    
    /* Define next and previous links.  */
    struct mpx_condition_var_control_struct *               next_condition_var;
    struct mpx_condition_var_control_struct *               previous_condition_var;

} mpx_condition_var_links;


/* Define the internal condition variable control structure, which is used for thread synchronization.  */

typedef struct mpx_condition_var_control_struct
{

    /* Define the ID of condition variable control structure.  */
    u_long                                                  condition_var_id;

    /* Define the verification ID that is used to create the verification code that this stored at the end of the condition variable control 
       structure - when enabled.  */
    u_long                                                  condition_var_verification_id;

    /* Define the name of the condition variable.  */
    char *                                                  name;

    /* Define the routine to call when the condition_var control memory is no longer needed.  */
    void                                                    (*memory_release_pointer)(u_int type, void *memory_to_release);
    u_long                                                  memory_release_pointer_verification_code;

    /* Define the signal counter that is incremented on every signal for this condition variable.  */
    u_long                                                  signal_count;

    /* Define the mutex associated with waiters on this condition variable.  */
    mpx_mutex_control *                                     associated_mutex;

    /* Define the current access for this condition variable. */
    mpx_thread_control *                                    current_access;

    /* Define the list of threads waiting on the condition_var.  */
    mpx_thread_control *                                    suspended_list;

    /* Define the number of threads waiting on the condition_var.  */
    u_long                                                  suspended_count;

    /* Define the condition_var created list, next and previous pointers.  */
    mpx_condition_var_links                                 created_list;

    /* Define an area for general extensions to the condition variable control structure. By default, this is defined as 
       white-space above.  */
    MPX_CONDITION_VAR_CONTROL_EXTENSION

    /* Define the optional verification code for the condition variable structure.  */
    u_long                                                  condition_var_verification_code;

} mpx_condition_var_control;


/* Define forward reference for event flags control structure, which
   will be defined in full later.  */

struct mpx_event_flags_control_struct;


/* Define the base doubly linked, circular list type.  */

typedef struct mpx_event_flags_links_struct
{
    
    /* Define next and previous links.  */
    struct mpx_event_flags_control_struct *                 next_event_flags;
    struct mpx_event_flags_control_struct *                 previous_event_flags;

} mpx_event_flags_links;


/* Define the internal event flags control structure, which is used for thread synchronization.  */

typedef struct mpx_event_flags_control_struct
{

    /* Define the ID of event flags control structure.  */
    u_long                                                  event_flags_id;

    /* Define the verification ID that is used to create the verification code that this stored at the end of the event flags control 
       structure - when enabled.  */
    u_long                                                  event_flags_verfication_id;

    /* Define the name of the event flags.  */
    char *                                                  name;

    /* Define the current event flags for this set.  */
    u_long                                                  current_events;

    /* Define the routine to call when the event flags control memory is no longer needed.  */
    void                                                    (*memory_release_pointer)(u_int type, void *memory_to_release);
    u_long                                                  memory_release_pointer_verification_code;

    /* Define the current access for this event flags.  */
    mpx_thread_control *                                    current_access;

    /* Define the list of threads waiting on the event flags.  */
    mpx_thread_control *                                    suspended_list;

    /* Define the number of threads waiting on the event flags.  */
    u_long                                                  suspended_count;

    /* Define the event flags created list, next and previous pointers.  */
    mpx_event_flags_links                                   created_list;

    /* Define an area for general extensions to the event flags control structure. By default, this is defined as 
       white-space above.  */
    MPX_EVENT_FLAGS_CONTROL_EXTENSION

    /* Define the optional verification code for the event flags structure.  */
    u_long                                                  event_flags_verification_code;

} mpx_event_flags_control;


/* Define forward reference for fastqueue control structure, which
   will be defined in full later.  */

struct mpx_fastqueue_control_struct;


/* Define the base doubly linked, circular list type.  */

typedef struct mpx_fastqueue_links_struct
{
    
    /* Define next and previous links.  */
    struct mpx_fastqueue_control_struct *                   next_fastqueue;
    struct mpx_fastqueue_control_struct *                   previous_fastqueue;

} mpx_fastqueue_links;


/* Define the internal fastqueue control structure, which is used for message passing between threads.  */

typedef struct mpx_fastqueue_control_struct
{

    /* Define the ID of fastqueue control structure.  */
    u_long                                                  fastqueue_id;

    /* Define the verification ID that is used to create the verification code that this stored at the end of the fastqueue control 
       structure - when enabled.  */
    u_long                                                  fastqueue_verfication_id;

    /* Define the name of the fastqueue.  */
    const char *                                            fastqueue_name;

    /* Define the routine to call when the fastqueue control memory is no longer needed.  */
    void                                                    (*control_memory_release_pointer)(u_int type, void *memory_to_release);
    u_long                                                  control_memory_release_pointer_verification_code;

    /* Define the routine to call when the fastqueue queue memory is no longer needed.  */
    void                                                    (*queue_memory_release_pointer)(u_int type, void *memory_to_release);
    u_long                                                  queue_memory_release_pointer_verification_code;

    /* Define the maximum number of messages in the fastqueue.  */
    u_long                                                  maximum_messages;

    /* Define the message size.  */
    size_t                                                  message_size;

    /* Define the number of words per message.  */
    size_t                                                  message_words;

    /* Define the start of the fastqueue memory.  */
    u_long *                                                fastqueue_memory_start;

    /* Define the end of the fastqueue memory.  */
    u_long *                                                fastqueue_memory_end;

    /* Define the first and last message pointers in the fastqueue memory.  */
    u_long *                                                first_message;
    u_long *                                                last_message;

    /* Define the total number of messages in the fastqueue.  */
    u_long                                                  messages_queued;

    /* Define the list of threads waiting on the fastqueue.  */
    mpx_thread_control *                                    suspended_list;

    /* Define the number of threads waiting on the fastqueue.  */
    u_long                                                  suspended_count;

    /* Define the fastqueue created list, next and previous pointers.  */
    mpx_fastqueue_links                                     created_list;

    /* Define an area for general extensions to the fastqueue control structure. By default, this is defined as 
       white-space above.  */
    MPX_FASTQUEUE_CONTROL_EXTENSION

    /* Define the optional verification code for the fastqueue structure.  */
    u_long                                                  fastqueue_verification_code;

} mpx_fastqueue_control;


/* Define forward reference for memory pool control structure, which
   will be defined in full later.  */

struct mpx_memorypool_control_struct;


/* Define the base doubly linked, circular list type.  */

typedef struct mpx_memorypool_links_struct
{
    
    /* Define next and previous links.  */
    struct mpx_memorypool_control_struct *                 next_memorypool;
    struct mpx_memorypool_control_struct *                 previous_memorypool;

} mpx_memorypool_links;


/* Define the information ahead of each memory block in the pool.  */

typedef struct mpx_memorypool_block_info_struct
{

    /* Define the storage for the verification code if enabled.  */
    u_long                                                  memorypool_pointer_verification_code;

    /* Define memory pool link.  */
    struct mpx_memorypool_control_struct *                  pool_control;

    /* Define the next block pointer.  */
    struct mpx_memorypool_block_info_struct *               next_block;

    /* Define the allocated or free flag.  */
    u_long                                                  allocated_status;

    /* Define an area for general extensions to the block information structure. By default, this is defined as 
       white-space above.  */
    MPX_MEMORYPOOL_BLOCK_INFO_EXTENSION

} mpx_memorypool_block_info;


/* Define the internal memory pool control structure, which is used for memory management.  */

typedef struct mpx_memorypool_control_struct
{

    /* Define the ID of memory pool control structure.  */
    u_long                                                  memorypool_id;

    /* Define the verification ID that is used to create the verification code that this stored at the end of the memory pool control 
       structure - when enabled.  */
    u_long                                                  memorypool_verfication_id;

    /* Define the name of the memory pool.  */
    char *                                                  name;

    /* Define the routine to call when the memory pool control memory is no longer needed.  */
    void                                                    (*memory_release_pointer)(u_int type, void *memory_to_release);
    u_long                                                  memory_release_pointer_verification_code;

    /* Define the mutex for controlling access to the memory pool.  */
    pthread_mutex_t                                         pool_mutex_handle;
    mpx_mutex_control                                       pool_mutex;

    /* Define memory pool memory area starting pointer.  */
    mpx_memorypool_block_info *                             pool_start;

    /* Define memory pool memory area starting pointer.  */
    mpx_memorypool_block_info *                             search_start;

    /* Define memory pool size.  */
    size_t                                                  pool_size;

    /* Define the maximum available size.  */
    size_t                                                  max_available;

    /* Define the number of fragments in the pool.  */
    u_long                                                  fragments;

    /* Define permanently allocated block at the end of the memory pool.  */
    mpx_memorypool_block_info *                             pool_end;

    /* Define the list of threads waiting on the memory pool.  */
    mpx_thread_control *                                    suspended_list;

    /* Define the number of threads waiting on the memory pool.  */
    u_long                                                  suspended_count;

    /* Define the memory pool created list, next and previous pointers.  */
    mpx_memorypool_links                                    created_list;

    /* Define an area for general extensions to the memory pool control structure. By default, this is defined as 
       white-space above.  */
    MPX_MEMORYPOOL_CONTROL_EXTENSION

    /* Define the optional verification code for the memory pool structure.  */
    u_long                                                  memorypool_verification_code;

} mpx_memorypool_control;


/* Define forward reference for partition memory pool control structure, which
   will be defined in full later.  */

struct mpx_partitionpool_control_struct;


/* Define the base doubly linked, circular list type.  */

typedef struct mpx_partitionpool_links_struct
{
    
    /* Define next and previous links.  */
    struct mpx_partitionpool_control_struct *              next_partitionpool;
    struct mpx_partitionpool_control_struct *              previous_partitionpool;

} mpx_partitionpool_links;


/* Define the information ahead of each partition in the partition pool.  */

typedef struct mpx_partition_info_struct
{

    /* Define the storage for the verification code if enabled.  */
    u_long                                                  partition_pointer_verification_code;

    /* Define partition memory pool link.  */
    struct mpx_partitionpool_control_struct *               pool_control;

    /* Define the next partition pointer.  */
    struct mpx_partition_info_struct *                      next_partition;

    /* Define the next created partition.  */
    struct mpx_partition_info_struct *                      next_created;

    /* Define an area for general extensions to the partition information structure. By default, this is defined as 
       white-space above.  */
    MPX_PARTITION_INFO_EXTENSION

} mpx_partition_info;


/* Define the internal partition memory pool control structure, which is used for memory management.  */

typedef struct mpx_partitionpool_control_struct
{

    /* Define the ID of partition memory pool control structure.  */
    u_long                                                  partitionpool_id;

    /* Define the verification ID that is used to create the verification code that this stored at the end of the partition memory pool control 
       structure - when enabled.  */
    u_long                                                  partitionpool_verfication_id;

    /* Define the name of the partition memory pool.  */
    char *                                                  name;

    /* Define the routine to call when the partition memory pool control memory is no longer needed.  */
    void                                                    (*memory_release_pointer)(u_int type, void *memory_to_release);
    u_long                                                  memory_release_pointer_verification_code;

    /* Define partition memory pool memory area starting pointer.  */
    mpx_partition_info *                                    pool_start;

    /* Define partition memory pool memory area starting pointer.  */
    mpx_partition_info *                                    free_partition_list;

    /* Define partition memory pool size.  */
    size_t                                                  pool_size;

    /* Define partition size.  */
    size_t                                                  partition_size;

    /* Define the list of threads waiting on the partition memory pool.  */
    mpx_thread_control *                                    suspended_list;

    /* Define the number of threads waiting on the partition memory pool.  */
    u_long                                                  suspended_count;

    /* Define the partition memory pool created list, next and previous pointers.  */
    mpx_partitionpool_links                                 created_list;

    /* Define an area for general extensions to the partition memory pool control structure. By default, this is defined as 
       white-space above.  */
    MPX_PARTITIONPOOL_CONTROL_EXTENSION

    /* Define the optional verification code for the memory pool structure.  */
    u_long                                                  partitionpool_verification_code;

} mpx_partitionpool_control;


/* Define forward reference for queue control structure, which
   will be defined in full later.  */

struct mpx_queue_control_struct;


/* Define the queue message header. Each message has a header of this type in front of the actual message data.  */

typedef struct mpx_queue_message_header_struct
{

    /* Define the next message pointer.  */
    struct mpx_queue_message_header_struct *                next_message;

    /* Define the message size.  */
    size_t                                                  size;

    /* Define the message priority.  */
    unsigned int                                            priority;

} mpx_queue_message_header;


/* Define the base doubly linked, circular list type.  */

typedef struct mpx_queue_links_struct
{
    
    /* Define next and previous links.  */
    struct mpx_queue_control_struct *                       next_queue;
    struct mpx_queue_control_struct *                       previous_queue;

} mpx_queue_links;


/* Define the internal queue control structure, which is used for message passing between threads.  */

typedef struct mpx_queue_control_struct
{

    /* Define the ID of queue control structure.  */
    u_long                                                  queue_id;

    /* Define the verification ID that is used to create the verification code that this stored at the end of the queue control 
       structure - when enabled.  */
    u_long                                                  queue_verfication_id;

    /* Define the name of the queue.  */
    const char *                                            queue_name;

    /* Define the routines to call when the queue control memory or queue message memory is no longer needed.  */
    void                                                    (*control_memory_release_pointer)(u_int type, void *memory_to_release);
    u_long                                                  control_memory_release_pointer_verification_code;
    void                                                    (*queue_memory_release_pointer)(u_int type, void *memory_to_release);
    u_long                                                  queue_memory_release_pointer_verification_code;

    /* Define the queue operation information.  */
    u_long                                                  operation;

    /* Define the maximum number of messages in the queue.  */
    u_long                                                  maximum_messages;

    /* Define the maximum message size.  */
    size_t                                                  maximum_message_size;

    /* Define the start of the queue memory.  */
    u_long *                                                queue_memory_start;

    /* Define the end of the queue memory.  */
    u_long *                                                queue_memory_end;

    /* Define the head and tail pointer of the queue.  */
    mpx_queue_message_header *                              first_message;
    mpx_queue_message_header *                              last_message;

    /* Define the available messages, i.e., messages not in the queue.  */
    mpx_queue_message_header *                              available_messages;

    /* Define the total number of messages in the queue.  */
    u_long                                                  messages_queued;

    /* Define the current access for this mutex.  */
    mpx_thread_control *                                    current_access;

    /* Define the list of threads waiting on the queue.  */
    mpx_thread_control *                                    suspended_list;

    /* Define the number of threads waiting on the queue.  */
    u_long                                                  suspended_count;

    /* Define the queue created list, next and previous pointers.  */
    mpx_queue_links                                         created_list;

    /* Define an area for general extensions to the queue control structure. By default, this is defined as 
       white-space above.  */
    MPX_QUEUE_CONTROL_EXTENSION

    /* Define the optional verification code for the queue structure.  */
    u_long                                                  queue_verification_code;

} mpx_queue_control;


/* Define forward reference for semaphore control structure, which
   will be defined in full later.  */

struct mpx_semaphore_control_struct;


/* Define the base doubly linked, circular list type.  */

typedef struct mpx_semaphore_links_struct
{
    
    /* Define next and previous links.  */
    struct mpx_semaphore_control_struct *                   next_semaphore;
    struct mpx_semaphore_control_struct *                   previous_semaphore;

} mpx_semaphore_links;


/* Define the internal semaphore control structure, which is used for consumer/producer and mutual exclusion.  */

typedef struct mpx_semaphore_control_struct
{

    /* Define the ID of semaphore control structure.  */
    u_long                                                  semaphore_id;

    /* Define the verification ID that is used to create the verification code that this stored at the end of the semaphore control 
       structure - when enabled.  */
    u_long                                                  semaphore_verfication_id;

    /* Define the name of the semaphore.  */
    char *                                                  name;

    /* Define the routine to call when the semaphore control memory is no longer needed.  */
    void                                                    (*memory_release_pointer)(u_int type, void *memory_to_release);
    u_long                                                  memory_release_pointer_verification_code;

    /* Define the semaphore count.  */
    u_long                                                  count;

    /* Define the current access of this semaphore - could be ISR or thread.  */
    mpx_thread_control *                                    current_access;

    /* Define the list of threads waiting on the semaphore.  */
    mpx_thread_control *                                    suspended_list;

    /* Define the number of threads waiting on the semaphore.  */
    u_long                                                  suspended_count;

    /* Define the semaphore created list, next and previous pointers.  */
    mpx_semaphore_links                                     created_list;

    /* Define an area for general extensions to the semaphore control structure. By default, this is defined as 
       white-space above.  */
    MPX_SEMAPHORE_CONTROL_EXTENSION

    /* Define the optional verification code for the semaphore structure.  */
    u_long                                                  semaphore_verification_code;

} mpx_semaphore_control;


/* Define forward reference for ticktimer control structure, which
   will be defined in full later.  */

struct mpx_ticktimer_control_struct;


/* Define the base doubly linked, circular list type.  */

typedef struct mpx_ticktimer_links_struct
{
    
    /* Define next and previous links.  */
    struct mpx_ticktimer_control_struct *                   next_ticktimer;
    struct mpx_ticktimer_control_struct *                   previous_ticktimer;

} mpx_ticktimer_links;


/* Define the internal ticktimer control structure, which is used for one-shot or periodic execution of an expiration routine.  */

typedef struct mpx_ticktimer_control_struct
{

    /* Define the ID of ticktimer control structure.  */
    u_long                                                  ticktimer_id;

    /* Define the verification ID that is used to create the verification code that this stored at the end of the ticktimer control 
       structure - when enabled.  */
    u_long                                                  ticktimer_verfication_id;

    /* Define the routine to call when the ticktimer control memory is no longer needed.  */
    void                                                    (*memory_release_pointer)(u_int type, void *memory_to_release);
    u_long                                                  memory_release_pointer_verification_code;

    /* Define the ticktimer expiration routine.  */
    void                                                    (*expiration_routine)(pthread_ticktimer_t *, void *);
    u_long                                                  expiration_routine_pointer_verification_code;

    /* Define the user-supplied pointer that will be passed to the expiration routine.  */
    void *                                                  argument;

    /* Define the internal timer control structure.  */
    mpx_internal_timer_control                              internal_timer;

    /* Define the ticktimer created list, next and previous pointers.  */
    mpx_ticktimer_links                                     created_list;

    /* Define an area for general extensions to the ticktimer control structure. By default, this is defined as 
       white-space above.  */
    MPX_TICKTIMER_CONTROL_EXTENSION

    /* Define the optional verification code for the ticktimer structure.  */
    u_long                                                  ticktimer_verification_code;

} mpx_ticktimer_control;


/* Define the global variable typedef for all of the MPX RTOS global variables.  */

typedef struct mpx_global_data_struct
{

    /* This first section of global data for MPX is accessed by the binding assembly code
       and therefore should not be modified.  */

    /* Define the ID of the MPX global data structure.  */
    u_long                                                  global_data_id;

    /* Define the verification ID that is used to create the verification code that this stored at the end of the MPX RTOS global variables.  */
    u_long                                                  global_verfication_id;

    /* Define the executing thread pointer. When this is non-NULL, the thread 
       associated with this thread control structure is running.  */
    mpx_thread_control *                                    executing_thread[MPX_MAXIMUM_CORES];

    /* Define the next highest-priority thread to execute. When this is different 
       than the "executing_thread" a context switch (preemption/suspension) is 
       required.  */
    mpx_thread_control *                                    highest_priority_thread[MPX_MAXIMUM_CORES];

    /* Define the MPX system stack pointer.  This pointer is used when no thread is 
       is running. */
    u_long *                                                system_stack[MPX_MAXIMUM_CORES];

    /* Define the interrupt nesting level used in some binding layers.  */
    u_int                                                   interrupt_nesting_level[MPX_MAXIMUM_CORES];

    /* Define an area accessible to the binding assembly language for extensions to the MPX global data. 
       By default, this is defined as white-space above.  */
    MPX_GLOBAL_DATA_BINDING_EXTENSION

#if MPX_MAXIMUM_CORES>1

    /* Define some of the SMP control structures used internally.  */
    mpx_thread_control *                                  new_highest_priority_threads[MPX_MAXIMUM_CORES];  
    mpx_thread_control *                                  top_priority_threads[MPX_MAXIMUM_CORES];          
    mpx_thread_control *                                  remap_thread_list[MPX_MAXIMUM_CORES];           
#endif /* MPX_MAXIMUM_CORES>1  */

    /* Define the version IDs for MPX, both the C code and the binding code.  */
    u_char                                                  major_version;
    u_char                                                  minor_version;
    u_char                                                  update_version;
    u_char                                                  patch_version;
    u_char                                                  binding_major_version;
    u_char                                                  binding_minor_version;
    u_char                                                  binding_update_version;
    u_char                                                  binding_patch_version;

    /* Define the binding identifier string.  */
    char *                                                  binding_identifier; 

    /* Information after this point is not accessible by the binding assembly code and
       therefore can be modified without disturbing the binding.  */

    /* Define the run-time ID.  */
    u_long                                                  run_time_id;

    /* Define central error counters.  */
    u_long                                                  level_3_system_errors;
    u_long                                                  level_2_system_errors;
    u_long                                                  level_1_system_errors;

    /* Define the most recent error.  */
    u_int                                                   last_error_class;
    u_int                                                   last_error_sub_class;
    u_int                                                   last_error_id;
    mpx_thread_control *                                    last_error_thread;
    u_long                                                  last_error_interrupt_level;

    /* Define the user-supplied memory information. This is used by default for allocating internal control
       blocks, stacks and other memory areas.  */
    void *                                                  memory_start;
    u_long                                                  memory_size;
    u_long *                                                available_memory_pointer;
    u_long                                                  available_size;
    void *                                                  (*memory_allocate_pointer)(u_int type, u_long size);
    u_long                                                  memory_allocate_pointer_verification_code;
    void                                                    (*memory_release_pointer)(u_int type, void *memory_to_release);
    u_long                                                  memory_release_pointer_verification_code;
    pthread_memorypool_t                                    memory_manager_pool;

    /* Define the highest priority ready at any given moment.  */
    int                                                     highest_active_priority;

    /* Defined the bitmap for the number of ready threads. Each bit represents
       a priority where one or more threads are ready for execution. If the bit
       is zero, there are no threads ready at that priority level.  */
    u_long                                                  ready_thread_bit_map[MPX_MAXIMUM_PRIORITIES/32];

    /* Define the list of ready threads. The list is indexed by priority.  */
    mpx_thread_control *                                    ready_thread_list[MPX_MAXIMUM_PRIORITIES];

    /* Define the periodic timer interrupt count. This simply increments on every periodic timer interrupt.  */
    tick_t                                                  timer_interrupts;

    /* Define the mapping of physical time to internal timer ticks.  */
    u_long                                                  ticks_per_second;
    u_long                                                  nanoseconds_per_tick;

    /* Define the epoch.  */
    mpx_time_t                                              epoch_seconds;
    u_long                                                  epoch_nanoseconds;

    /* Define the list of activated timers.  */
    mpx_internal_timer_control *                            active_timer_list[MPX_ACTIVE_TIMER_LIST_SIZE];

    /* Define the current timer list pointer.  */
    mpx_internal_timer_control **                           current_active_timer_list_pointer;

    /* Define the signal handler information.  */
    struct sigaction *                                      signal_handlers[MPX_MAXIMUM_SIGNALS];

    /* Define the created thread list head pointer and created count.  */
    u_long                                                  total_created_threads;
    mpx_thread_control *                                    created_thread_list;

    /* Define the created condition variable list head pointer and created count.  */
    u_long                                                  total_created_condition_vars;
    mpx_condition_var_control *                             created_condition_var_list;

    /* Define the created event flags group list head pointer and created count.  */
    u_long                                                  total_created_event_flags;
    mpx_event_flags_control *                               created_event_flags_list;

    /* Define the created fastqueue list head pointer and created count.  */
    u_long                                                  total_created_fastqueues;
    mpx_fastqueue_control *                                 created_fastqueue_list;

    /* Define the created memory pool list head pointer and created count.  */
    u_long                                                  total_created_memorypools;
    mpx_memorypool_control *                                created_memorypool_list;

    /* Define the created mutex list head pointer and created count.  */
    u_long                                                  total_created_mutexes;
    mpx_mutex_control *                                     created_mutex_list;

    /* Define the created partition memory pool list head pointer and created count.  */
    u_long                                                  total_created_partitionpools;
    mpx_partitionpool_control *                             created_partitionpool_list;

    /* Define the created queue list head pointer and created count.  */
    u_long                                                  total_created_queues;
    mpx_queue_control *                                     created_queue_list;

    /* Define the created semaphore list head pointer and created count.  */
    u_long                                                  total_created_semaphores;
    mpx_semaphore_control *                                 created_semaphore_list;

    /* Define the created ticktimer list head pointer and created count.  */
    u_long                                                  total_created_ticktimers;
    mpx_ticktimer_control *                                 created_ticktimer_list;

    /* Define the "main" thread control structure.  */
    mpx_thread_control                                      main_thread;

    /* Define the deferred thread cleanup pointer.  */
    mpx_thread_control *                                    deferred_memory_release_thread;

    /* Define an area for general extensions to the MPX global data. By default, this is defined as 
       white-space above.  */
    MPX_GLOBAL_DATA_EXTENSION

    /* Define the optional verification code for the MPX RTOS global variables.  */
    u_long                                                  global_verification_code;

} mpx_global_data;


/* Define external reference of the MPX RTOS global data.  */

extern mpx_global_data                              mpx_globals;


/* Define structures to take the structure offset information to the assembly binding
   verification routine.  */

/******************************************************************************
 ******************** Section IV: Internal Core Prototypes ********************
 *****************************************************************************/

void *          mpx_internal_memory_allocate(u_int type, u_long  size);
void *          mpx_internal_memory_manager_allocate(u_int type, u_long size);
void            mpx_internal_memory_marager_release(u_int type, void *  memory_to_release);
#if MPX_MAXIMUM_CORES>1
int             mpx_internal_smp_core_insert(mpx_thread_control *  thread_pointer, u_long  target_cores, mpx_thread_control **  schedule_list);
void            mpx_internal_smp_load_balance(void);
int             mpx_internal_smp_remap_check(mpx_thread_control *   thread_pointer);
#endif /* MPX_MAXIMUM_CORES>1  */
void            mpx_internal_thread_enter_notify(mpx_thread_control *  thread_pointer);
void            mpx_internal_thread_exit_notify(mpx_thread_control *  thread_pointer);
void            mpx_internal_thread_priority_change(mpx_thread_control *  thread_pointer);
void            mpx_internal_thread_ready(mpx_thread_control *  thread_pointer, mpx_thread_control **  suspension_list_head, u_long *  suspended_count);
void            mpx_internal_thread_suspend(mpx_thread_control *  thread_pointer, int  suspended_state, mpx_thread_control **  suspension_list_head, u_long *  suspended_count);
void            mpx_internal_thread_timer_process(mpx_internal_timer_control *  internal_timer);
void            mpx_internal_thread_wrapper(void);
void            mpx_internal_ticktimer_expire(mpx_internal_timer_control *  internal_timer);
void            mpx_internal_time_slice_process(void);
void            mpx_internal_timer_activate(mpx_internal_timer_control *  internal_timer);
void            mpx_internal_timer_deactivate(mpx_internal_timer_control *  internal_timer_pointer);
void            mpx_internal_timer_list_process(void);


/******************************************************************************
 ****************** Section V: Internal Utility Prototypes ********************
 *****************************************************************************/

u_long          mpx_internal_data_verification_code_compute(u_long  data, u_long *  code_destination);
void            mpx_internal_data_verification_code_create(u_long  data, u_long *  code_destination);
void            mpx_internal_data_verification_code_verify(u_long  data, u_long *  code_destination, u_int  error_id);
int             mpx_internal_highest_set_bit_get(u_long word);
u_int           mpx_internal_highest_signal_get(sigset_t  signal_set);
void            mpx_internal_memset(void *  ptr, int v, int n);
u_long          mpx_internal_pointer_verification_code_compute(void *  pointer, u_long *  code_destination);
void            mpx_internal_pointer_verification_code_create(void *  pointer, u_long *  code_destination);
void            mpx_internal_pointer_verification_code_verify(void *  pointer, u_long *  code_destination, u_int  error_id);
void            mpx_internal_thread_cleanup_handlers_execute(mpx_thread_control *  this_thread);
void            mpx_internal_thread_control_created_list_append(mpx_thread_control *  this_thread);
void            mpx_internal_thread_control_created_list_remove(mpx_thread_control *  this_thread);
void            mpx_internal_thread_deferred_memory_release(void);
void            mpx_internal_thread_stack_size_check(u_int id);


/******************************************************************************
 *************** Section VI: Internal Error Handling Prototypes ***************
 *****************************************************************************/

void            mpx_internal_central_error_process(u_int error_class, u_int error_sub_class, u_int  error_id); 
void            mpx_internal_thread_entry_validity_check(mpx_thread_control *  this_thread);
void            mpx_internal_thread_invalid_return_error_handler(void);
void            mpx_internal_thread_validity_check(mpx_thread_control *  this_thread);


/******************************************************************************
 ****************** Section VII: Binding Function Prototypes ******************
 *****************************************************************************/

void            mpx_binding_initialize(void);
u_long *        mpx_binding_main_stack_base_get(void);
u_long *        mpx_binding_main_stack_limit_get(void);
u_long          mpx_binding_main_stack_minimum_stack_size_get(void);
u_long *        mpx_binding_main_stack_pointer_get(void);
u_long          mpx_binding_main_stack_size_get(void);
void            mpx_binding_stack_frame_build(mpx_thread_control *  this_thread, void *  execution_pointer);
u_long *        mpx_binding_system_stack_pointer_get(void);
int             mpx_binding_verify(mpx_thread_control *  this_thread, u_int thread_control_sizeof);


#endif  /* MPX_HEADER */
