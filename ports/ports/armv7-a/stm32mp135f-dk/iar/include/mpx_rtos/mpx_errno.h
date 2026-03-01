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

#ifndef MPX_ERRNO_HEADER
#define MPX_ERRNO_HEADER


/* Ensure this file can be included and used by C++ programs.  */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus  */


/******************************************************************************
 ******************************** Manifest ************************************
 ******************************************************************************
   
   Section I:   Error constants
   Section II:  Errno mapping

******************************************************************************/


/******************************************************************************
 ************************ Section I: Errno constants **************************
 *****************************************************************************/

#define MPX_SUCCESS                                         0
#define MPX_ERROR                                          -1
#ifndef EACCES
#define EACCES                                              13
#endif  /* EACCES */
#ifndef EADDRINUSE
#define EADDRINUSE                                          98
#endif  /* EADDRINUSE */
#ifndef EADDRNOTAVAIL
#define EADDRNOTAVAIL                                       99
#endif  /* EADDRNOTAVAIL */
#ifndef EAGAIN
#define EAGAIN                                              11
#endif  /* EAGAIN */
#ifndef EAFNOSUPPORT
#define EAFNOSUPPORT                                        97
#endif  /* EAFNOSUPPORT */
#ifndef EALREADY
#define EALREADY                                            114
#endif  /* EALREADY */
#ifndef EBADF
#define EBADF                                               9
#endif  /* EBADF */
#ifndef EBUSY
#define EBUSY                                               16
#endif  /* EBUSY */
#ifndef ECONNABORTED
#define ECONNABORTED                                        103
#endif  /* ECONNABORTED */
#ifndef ECONNRESET
#define ECONNRESET                                          104
#endif  /* ECONNRESET */
#ifndef EDEADLK
#define EDEADLK                                             35
#endif  /* EDEADLK */
#ifndef EDESTADDRREQ 
#define EDESTADDRREQ                                        89
#endif  /* EDESTADDRREQ */
#ifndef EEXIST
#define EEXIST                                              17
#endif  /* EEXIST */
#ifndef EFAULT
#define EFAULT                                              14
#endif  /* EFAULT */
#ifndef EHOSTUNREACH
#define EHOSTUNREACH                                        113
#endif  /* EHOSTUNREACH */
#ifndef EINPROGRESS
#define EINPROGRESS                                         115
#endif  /* EINPROGRESS */
#ifndef EINTR
#define EINTR                                               4
#endif  /* EINTR */
#ifndef EINVAL
#define EINVAL                                              22
#endif  /* EINVAL */
#ifndef EIO
#define EIO                                                 5
#endif  /* EIO */
#ifndef EISCONN
#define EISCONN                                             106
#endif  /* EISCONN */
#ifndef EISDIR   
#define EISDIR                                              21
#endif  /* EISDIR */
#ifndef EMSGSIZE
#define EMSGSIZE                                            90
#endif  /* EMSGSIZE */
#ifndef EMVSERR
#define EMVSERR                                             200
#endif  /* EMVSERR */
#ifndef ENETUNREACH
#define ENETUNREACH                                         101
#endif  /* ENETUNREACH */
#ifndef ENFILE
#define ENFILE                                              23
#endif  /* ENFILE */
#ifndef ENOBUFS
#define ENOBUFS                                             105
#endif  /* ENOBUFS */
#ifndef ENODEV
#define ENODEV                                              19
#endif  /* ENODEV */
#ifndef ENOENT 
#define ENOENT                                              2
#endif  /* ENOENT */
#ifndef ENOMEM
#define ENOMEM                                              12
#endif  /* ENOMEM */
#ifndef ENOPROTOOPT
#define ENOPROTOOPT                                         92
#endif  /* ENOPROTOOPT */
#ifndef ENOSPC
#define ENOSPC                                              28
#endif  /* ENOSPC */
#ifndef ENOSYS
#define ENOSYS                                              38
#endif  /* ENOSYS */
#ifndef ENOTCONN
#define ENOTCONN                                            107
#endif  /* ENOTCONN */
#ifndef ENOTDIR 
#define ENOTDIR                                             20
#endif  /* ENOTDIR */
#ifndef ENOTEMPTY
#define ENOTEMPTY                                           39
#endif  /* ENOTEMPTY */
#ifndef ENOTSOCK
#define ENOTSOCK                                            88
#endif  /* ENOTSOCK */
#ifndef EOPNOTSUPP
#define EOPNOTSUPP                                          95
#endif  /* EOPNOTSUPP */
#ifndef EOVERFLOW
#define EOVERFLOW                                           75
#endif  /* EOVERFLOW */
#ifndef EPERM
#define EPERM                                               1
#endif  /* EPERM */
#ifndef EPIPE
#define EPIPE                                               32
#endif  /* EPIPE */
#ifndef EPROTONOSUPPORT
#define EPROTONOSUPPORT                                     93
#endif  /* EPROTONOSUPPORT */
#ifndef ERANGE
#define ERANGE                                              34         
#endif  /* ERANGE */
#ifndef ESRCH
#define ESRCH                                               3
#endif  /* ESRCH */
#ifndef ETIMEDOUT
#define ETIMEDOUT                                           110
#endif  /* ETIMEDOUT */
#ifndef EWOULDBLOCK
#define EWOULDBLOCK                                         EAGAIN
#endif  /* EWOULDBLOCK */
#ifndef EXDEV
#define EXDEV                                               18
#endif  /* EXDEV */


/* Remap references to "errno" to the function that retrieves the error from thread storage.  */

#ifdef MPX_SPECIFIC_ERRNO
#define mpx_errno                                           mpx_errno_get()
#define mpx_errno_get                                       mpx_errno_get
#define mpx_errno_set(e)                                    mpx_errno_set(e)
#else
#define errno                                               mpx_errno_get()
#define errno_get                                           mpx_errno_get
#define errno_set(e)                                        mpx_errno_set(e)
#endif


/******************************************************************************
 *********************** Section II: Errno constants **************************
 *****************************************************************************/

int             mpx_errno_get(void);
int             mpx_errno_set(int error);


#ifdef __cplusplus
}  /* Closing bracket for extern "C" at the top of file.  */
#endif /* __cplusplus  */


#endif  /* MPX_ERRNO_HEADER */
