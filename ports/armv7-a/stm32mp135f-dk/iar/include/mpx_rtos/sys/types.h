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

#ifndef MPX_TYPES_HEADER
#define MPX_TYPES_HEADER


/******************************************************************************
 ******************************** Manifest ************************************
 ******************************************************************************
   
   Section I:   Include Files
   Section II:  MPX Identification
   Section III: Base types
   Section IV:  Base constants

******************************************************************************/

/******************************************************************************
 ************************** Section I: Include Files **************************
 *****************************************************************************/

#include "mpx_user_config.h"
#include "mpx_binding.h"


/******************************************************************************
 *********************** Section II: MPX Identification ***********************
 *****************************************************************************/

#ifndef MPX
#define MPX
#endif  /* MPX */


/******************************************************************************
 ************************** Section III: Base types ***************************
 *****************************************************************************/

/* Define base types.  */

#ifndef _U_CHAR
#define _U_CHAR
typedef unsigned char                                       u_char;
#endif  /* _U_CHAR */

#ifndef _U_INT
#define _U_INT
typedef unsigned int                                        u_int;
#endif

#ifndef _U_LONG
#define _U_LONG
typedef unsigned long                                       u_long;
#endif  /* _U_LONG */

#ifndef _U_SHORT
#define _U_SHORT
typedef unsigned short                                      u_short;
#endif  /* _U_SHORT */

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned int                                        size_t;
#endif  /* _SIZE_T  */


#ifndef _SSIZE_T
#define _SSIZE_T
typedef int                                                 ssize_t;
#endif  /* _SIZE_T  */

#ifndef _OFF_T
#define _OFF_T
typedef long                                                off_t;
#endif  /* _OFF_T  */

#ifndef _U_UINT4
#define _U_UINT4
typedef unsigned int                                        u_int4;
#endif  /* _U_UINT4 */


/******************************************************************************
 ************************* Section IV: Base constants *************************
 *****************************************************************************/

#ifndef NULL 
#define NULL                                                ((void *) 0)
#endif  /* NULL */

#endif  /* MPX_TYPES_HEADER */
