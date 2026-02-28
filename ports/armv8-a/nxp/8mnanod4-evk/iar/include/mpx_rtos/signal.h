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

#ifndef MPX_SIGNAL_HEADER
#define MPX_SIGNAL_HEADER


/* Ensure this file can be included and used by C++ programs.  */

#ifdef __cplusplus
#ifndef MPX_EXTERN_C
#define MPX_EXTERN_C
#define MPX_SIGNAL_EXTERN_C
extern "C" {
#endif /* MPX_EXTERN_C  */
#endif /* __cplusplus  */


/******************************************************************************
 ******************************** Manifest ************************************
 ******************************************************************************
   
   Section I:   Include Files
   Section II:  Signal Constants
   Section III: Signal Types
   Section IV:  MPX API Mapping
   Section V:   Actual MPX API prototypes

******************************************************************************/


/******************************************************************************
 ************************** Section I: Include Files **************************
 *****************************************************************************/

#include "sys/types.h"
#include "mpx_time.h"
#include "mpx_errno.h"


/******************************************************************************
 ********************** Section II:  Signal Constants *************************
 *****************************************************************************/


/* Define maximum number of signals.  */

#define MPX_MAXIMUM_SIGNALS                                 32
#define MPX_SIGNAL_NUMBER_MASK                              0x1FUL


/* Define default signal mask.  */

#ifndef MPX_DEFAULT_SIGNAL_MASK
#define MPX_DEFAULT_SIGNAL_MASK                             0xFFFFFFFFUL
#endif /* MPX_DEFAULT_SIGNAL_MASK  */


/* Define default valid signal waiting mask, which by default excludes signal 0, since
   it is only used for error checking.  */

#ifndef MPX_DEFAULT_VALID_SIGNAL_WAIT
#define MPX_DEFAULT_VALID_SIGNAL_WAIT                       0xFFFFFFFEUL
#endif


/* Define default fill and empty signal masks.  */

#ifndef MPX_DEFAULT_FILL_MASK
#define MPX_DEFAULT_FILL_MASK                               0xFFFFFFFFUL
#endif  /* MPX_DEFAULT_FILL_MASK */

#ifndef MPX_DEFAULT_EMPTY_MASK
#define MPX_DEFAULT_EMPTY_MASK                              0UL
#endif  /* MPX_DEFAULT_EMPTY_MASK */


/* Default signal info extension macro to whitespace.  */

#ifndef MPX_SIGINFO_T_EXTENSTIONS
#define MPX_SIGINFO_T_EXTENSTIONS
#endif  /* MPX_SIGINFO_T_EXTENSTIONS */


/* Define pthread_sigmask constants.  */

#define SIG_BLOCK                                           0
#define SIG_UNBLOCK                                         1
#define SIG_SETMASK                                         2


/* Define signal numbers.  */

#define SIG_ZERO                                            0
#define SIGABRT                                             6
#define SIGALRM                                             14
#define SIGBUS                                              10
#define SIGCHLD                                             20
#define SIGCONT                                             19
#define SIGFPE                                              8
#define SIGHUP                                              1
#define SIGILL                                              4
#define SIGINT                                              2
#define SIGKILL                                             9
#define SIGPIPE                                             13
#define SIGQUIT                                             3
#define SIGSEGV                                             11
#define SIGSTOP                                             17
#define SIGTERM                                             15
#define SIGTSTP                                             18
#define SIGTTIN                                             21
#define SIGTTOU                                             22
#define SIGUSR1                                             30
#define SIGUSR2                                             31
#define SIGPOLL                                             23
#define SIGPROF                                             27
#define SIGSYS                                              12
#define SIGTRAP                                             5
#define SIGURG                                              16
#define SIGVTALRM                                           26
#define SIGXCPU                                             24
#define SIGXFSZ                                             25


/******************************************************************************
 ************************ Section III:  Signal Types **************************
 *****************************************************************************/

/* Remap sigaction early, since structure name is the same as the API name.  */

#define sigaction                                           mpx_sigaction


/* Define the signal information structure that is used by some of the APIs.  */

typedef struct siginfo_t_struct 
{

    /* Define signal information.  */
    int                                                     si_signo;
    int                                                     si_errno;
    int                                                     si_code;
    int                                                     si_trapno;  

    /* Define a macro for application to define additional structure members to the signal
       information type.  By default, the macro is set to whitespace (above).  */
    MPX_SIGINFO_T_EXTENSTIONS

} siginfo_t;


/* Define signal set type.  */

typedef unsigned long                                       sigset_t;


/* Define the signal action structure, which specifies the signal handler.  */

struct sigaction
{

    /* Define the signal handler.  */
    void                                                    (*signal_handler)(int);
    u_long                                                  signal_handler_verification_code;
    siginfo_t                                               signal_info;
};

typedef struct sigaction                                    sigaction_t;


/******************************************************************************
 *********************** Section IV: MPX API Mapping **************************
 *****************************************************************************/

/* Determine if MPX source is present. If so, skip remapping.  */

#ifndef MPX_SOURCE_CODE


/* Determine if parameter checking is disabled. If so, skip parameter checking veener.  */

#ifndef MPX_PARAMETER_CHECKING_DISABLE

#define pthread_kill                                        mpx_pthread_kill_check_params
#define pthread_sigmask                                     mpx_pthread_sigmask_check_params
#define sigaddset                                           mpx_sigaddset
#define sigdelset                                           mpx_sigdelset
#define sigemptyset                                         mpx_sigemptyset
#define sigfillset                                          mpx_sigfillset
#define sigismember                                         mpx_sigismember
#define sigpending                                          mpx_sigpending
#define sigtimedwait                                        mpx_sigtimedwait_check_params
#define sigwait                                             mpx_sigwait_check_params
#define sigwaitinfo                                         mpx_sigwaitinfo_check_params

#else

#define pthread_kill                                        mpx_pthread_kill
#define pthread_sigmask                                     mpx_pthread_sigmask
#define sigaddset                                           mpx_sigaddset
#define sigdelset                                           mpx_sigdelset
#define sigemptyset                                         mpx_sigemptyset
#define sigfillset                                          mpx_sigfillset
#define sigismember                                         mpx_sigismember
#define sigpending                                          mpx_sigpending
#define sigtimedwait                                        mpx_sigtimedwait
#define sigwait                                             mpx_sigwait
#define sigwaitinfo                                         mpx_sigwaitinfo



#endif /* MPX_PARAMETER_CHECKING_DISABLE */

#endif /* MPX_SOURCE_CODE */


/******************************************************************************
 ******************** Section IV: Actual MPX API prototypes *******************
 *****************************************************************************/

int             mpx_pthread_kill(pthread_t  thread_handle, int  signal_number);
int             mpx_pthread_kill_check_params(pthread_t  thread_handle, int  signal_number);
int             mpx_pthread_sigmask(int  operation, const sigset_t *  signal_set,  sigset_t *  previous_mask);
int             mpx_pthread_sigmask_check_params(int  operation, const sigset_t *  signal_set,  sigset_t *  previous_mask);
int             mpx_sigaction(int  signal_number, struct sigaction *  new_handler,  struct sigaction *  previous_handler);
int             mpx_sigaddset(sigset_t *  signal_set, int signal_number);
int             mpx_sigdelset(sigset_t *  signal_set, int signal_number);
int             mpx_sigemptyset(sigset_t *  signal_set);
int             mpx_sigfillset(sigset_t *  signal_set);
int             mpx_sigismember(sigset_t *  signal_set, int signal_number);
int             mpx_sigpending(sigset_t *  pending_signals);
int             mpx_sigtimedwait(const sigset_t *  signals, siginfo_t *  signal_info, const struct mpx_timespec *timeout);
int             mpx_sigtimedwait_check_params(const sigset_t *  signals, siginfo_t *  signal_info, const struct mpx_timespec *timeout);
int             mpx_sigwait(const sigset_t *  signals, int *  return_signal);
int             mpx_sigwait_check_params(const sigset_t *  signals, int *  return_signal);
int             mpx_sigwaitinfo(const sigset_t *  signals, siginfo_t *  signal_info);
int             mpx_sigwaitinfo_check_params(const sigset_t *  signals, siginfo_t *  signal_info);


#ifdef __cplusplus
#ifdef MPX_SIGNAL_EXTERN_C
}  /* Closing bracket for extern "C" at the top of file.  */
#endif /* MPX_PTHREAD_EXTERN_C  */
#endif /* __cplusplus  */


#endif  /* MPX_SIGNAL_HEADER */
