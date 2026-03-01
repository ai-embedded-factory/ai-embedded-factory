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
#ifndef MPX_EXTERN_C
#define MPX_EXTERN_C
#define MPX_ERRNO_EXTERN_C
extern "C" {
#endif /* MPX_EXTERN_C  */
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
#define EADDRINUSE                                          1
#define EAGAIN                                              2
#define EAFNOSUPPORT                                        3
#define EALREADY                                            4
#define EBADF                                               5
#define EBUSY                                               6
#define ECONNABORTED                                        7
#define ECONNRESET                                          8
#define EDEADLK                                             9
#define EFAULT                                              10
#define EHOSTUNREACH                                        11
#define EINPROGRESS                                         12
#define EINTR                                               13
#define EINVAL                                              14
#define EIO                                                 15
#define EISCONN                                             16
#define EMSGSIZE                                            17
#define EMVSERR                                             18
#define ENFILE                                              19
#define ENOBUFS                                             20
#define ENODEV                                              21
#define ENOMEM                                              22
#define ENOPROTOOPT                                         23
#define ENOSPC                                              24
#define ENOSYS                                              25
#define ENOTCONN                                            26
#define EOPNOTSUPP                                          27
#define ERANGE                                              28         
#define ESRCH                                               29
#define EPERM                                               30
#define ETIMEDOUT                                           31
#define EWOULDBLOCK                                         (EAGAIN)


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
#ifdef MPX_ERRNO_EXTERN_C
}  /* Closing bracket for extern "C" at the top of file.  */
#endif /* MPX_ERRNO_EXTERN_C  */
#endif /* __cplusplus  */


#endif  /* MPX_ERRNO_HEADER */
