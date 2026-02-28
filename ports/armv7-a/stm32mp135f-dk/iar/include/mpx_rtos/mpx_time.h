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

#ifndef MPX_TIME_HEADER
#define MPX_TIME_HEADER


/******************************************************************************
 ******************************** Manifest ************************************
 ******************************************************************************
   
   Section I:   Include Files
   Section II:  Time Constants
   Section III: Time Types
   Section IV:  MPX API Mapping
   Section V:   Actual MPX API prototypes

******************************************************************************/


/******************************************************************************
 ************************** Section I: Include Files **************************
 *****************************************************************************/

#include "sys/types.h"
#include "mpx_errno.h"

/* Backwards/forwards compatibility alias (ports may use either macro name) */
#if defined(MPX_TIME_REMAPPING_DISABLE) && !defined(MPX_DISABLE_TIME_REMAPPING)
#define MPX_DISABLE_TIME_REMAPPING MPX_TIME_REMAPPING_DISABLE
#endif
#if defined(MPX_DISABLE_TIME_REMAPPING) && !defined(MPX_TIME_REMAPPING_DISABLE)
#define MPX_TIME_REMAPPING_DISABLE MPX_DISABLE_TIME_REMAPPING
#endif



/******************************************************************************
 ************************ Section II:  Time Constants *************************
 *****************************************************************************/

/* Define the default 10ms periodic tick constants. These may be overridden by the
   application and/or the MPX binding layer.  */

#ifndef MPX_TICKS_PER_SECOND            
#define MPX_TICKS_PER_SECOND                                1000UL
#endif  /* MPX_TICKS_PER_SECOND */


/* Define the default clock ID.  */

#define CLOCK_REALTIME                                      1UL
#define CLOCK_MONOTONIC                                     (CLOCK_REALTIME)


/* Define number of nanoseconds in a second.  */

#define MPX_NANOSECONDS_PER_SECOND                          1000000000UL


/* Define number of microseconds in a second.  */

#define MPX_MICROSECONDS_PER_SECOND                         1000000UL


/* Define the number of nanoseconds per tick.  */

#define MPX_NANOSECONDS_PER_TICK                            (MPX_NANOSECONDS_PER_SECOND/MPX_TICKS_PER_SECOND)


/* Define the number of microseconds per tick.  */

#define MPX_MICROSECONDS_PER_TICK                           (MPX_MICROSECONDS_PER_SECOND/MPX_TICKS_PER_SECOND)


/* Define the maximum number of seconds the tick timer can support.  */

#define MPX_MAXIMUM_SECONDS                                 (0xFFFFFFFEUL/MPX_TICKS_PER_SECOND)


/* Define the default epoch value.  */

#ifndef MPX_DEFAULT_EPOCH
#define MPX_DEFAULT_EPOCH                                   1714568400  /* May 1, 2024  01:00:00  */
#endif  /* MPX_DEFAULT_EPOCH */


/******************************************************************************
 ************************* Section III:  Time Types ***************************
 *****************************************************************************/

/* Define the clock ID handle type.  */

typedef unsigned long                                       clockid_t;


/* Define the basic time type, default to 32-bit time and allow for external override.  */

#ifndef _MPX_TIME_T
#define _MPX_TIME_T
#ifdef MPX_64BIT_TIME_T
typedef unsigned long long                                  mpx_time_t;
#else
typedef unsigned long                                       mpx_time_t;
#endif
#endif  /* _MPX_TIME_T */


/* Define the timer specification structure.  */

struct mpx_timespec
{

    /* Number of seconds  */
    mpx_time_t                                              tv_sec;

    /* Number of nanoseconds.  */
    unsigned long                                           tv_nsec;
};


/* Define forward references for internal control structures.  */

struct mpx_time_control_struct; 


/* Define the timer type, which is effectively contains a pointer to the internal timer control structure.  */

typedef struct timer_t_struct
{

    /* Pointer to the internal timer control structure.  */
    struct mpx_timer_control_struct *                       internal_timer_control;
    
} timer_t;


/******************************************************************************
 *********************** Section IV: MPX API Mapping **************************
 *****************************************************************************/

/* Determine if MPX source is present. If so, skip remapping.  */

#ifndef MPX_SOURCE_CODE


/* Determine if parameter checking is disabled. If so, skip parameter checking veneer.  */

#ifndef MPX_PARAMETER_CHECKING_DISABLE

#define clock_getres                                        mpx_clock_getres_check_params
#define clock_gettime                                       mpx_clock_gettime_check_params
#define clock_settime                                       mpx_clock_settime_check_params
#define nanosleep                                           mpx_nanosleep_check_params
#ifndef MPX_TIME_REMAPPING_DISABLE
#define time                                                mpx_time
#endif  /* MPX_TIME_REMAPPING_DISABLE */

#else

#define clock_getres                                        mpx_clock_getres
#define clock_gettime                                       mpx_clock_gettime
#define clock_settime                                       mpx_clock_settime
#define nanosleep                                           mpx_nanosleep
#ifndef MPX_TIME_REMAPPING_DISABLE
#define time                                                mpx_time
#endif  /* MPX_TIME_REMAPPING_DISABLE */

#endif /* MPX_PARAMETER_CHECKING_DISABLE */

#endif /* MPX_SOURCE_CODE */


/* By default, the basic time-types are mapped to MPX internal versions.  */

#ifndef MPX_TIME_REMAPPING_DISABLE
#define timespec                                            mpx_timespec
#define time_t                                              mpx_time_t
#endif  /* MPX_TIME_REMAPPING_DISABLE */


/******************************************************************************
 ******************** Section IV: Actual MPX API prototypes *******************
 *****************************************************************************/

int             mpx_clock_getres(clockid_t  clock_id,  struct mpx_timespec *  resolution);
int             mpx_clock_getres_check_params(clockid_t  clock_id,  struct mpx_timespec *  resolution);
int             mpx_clock_gettime(clockid_t  clock_id,  struct mpx_timespec *  current_time);
int             mpx_clock_gettime_check_params(clockid_t  clock_id,  struct mpx_timespec *  current_time);
int             mpx_clock_settime(clockid_t  clock_id,  struct mpx_timespec *  new_time);
int             mpx_clock_settime_check_params(clockid_t  clock_id,  struct mpx_timespec *  new_time);
int             mpx_nanosleep(const struct mpx_timespec *  request_time, struct mpx_timespec *  remaining_time);
int             mpx_nanosleep_check_params(const struct mpx_timespec *  request_time, struct mpx_timespec *  remaining_time);
mpx_time_t      mpx_time(mpx_time_t *  return_seconds);

#endif  /* MPX_TIME_HEADER */
