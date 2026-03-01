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

#ifndef MPX_SEMAPHORE_HEADER
#define MPX_SEMAPHORE_HEADER


/* Ensure this file can be included and used by C++ programs.  */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus  */


/******************************************************************************
 ******************************** Manifest ************************************
 ******************************************************************************
   
   Section I:   Include Files
   Section II:  Semaphore Constants
   Section III: Semaphore Types
   Section IV:  MPX API Mapping
   Section V:   Actual MPX API prototypes

******************************************************************************/


/******************************************************************************
 ************************** Section I: Include Files **************************
 *****************************************************************************/

#include "sys/types.h"
#include "pthread.h"
#include "mpx_errno.h"


/******************************************************************************
 ******************* Section II:  Semaphore Constants *************************
 *****************************************************************************/

#ifndef SEM_VALUE_MAX
#define SEM_VALUE_MAX                                       0xFFFFFFFFUL
#endif  /* SEM_VALUE_MAX */


/* Define semaphore object handle ID.  */

#define MPX_SEMAPHORE_HANDLE_ID                             0x53455448UL
#define MPX_SEMAPHORE_ATTR_ID                               0x53455441UL


/* Default attribute extension to whitespace.  */

#ifndef MPX_SEMATTR_T_EXTENSIONS
#define MPX_SEMATTR_T_EXTENSIONS
#endif  /* MPX_SEMATTR_T_EXTENSIONS */


/******************************************************************************
 ********************* Section III:  Semaphore Types **************************
 *****************************************************************************/


/* Define the semaphore attribute type, which is optionally used to initialize a semaphore.  */

typedef struct semattr_t_struct
{

    /* Define ID of attributes structure. */
    u_long                                                  semaphore_attr_id;

    /* Define name.  */
    char *                                                  name;

    /* Define the user-specified semaphore control memory address.  */
    void *                                                  semaphore_control_address;

    /* Define extensions to the semattr_t structure.  */
    MPX_SEMATTR_T_EXTENSIONS

} semattr_t;



/* Define forward references for internal control structures.  */

struct mpx_semaphore_control_struct; 


/* Define the semaphore type, which is effectively contains a pointer to the internal semaphore control structure.  */

typedef struct sem_t_struct
{

    /* Define the ID of semaphore handle structure.  */
    u_long                                                  semaphore_handle_id;

    /* Pointer to the internal semaphore control structure.  */
    struct mpx_semaphore_control_struct *                   internal_semaphore_control;
    
} sem_t;


/******************************************************************************
 *********************** Section IV: MPX API Mapping **************************
 *****************************************************************************/

/* Determine if MPX source is present. If so, skip remapping.  */

#ifndef MPX_SOURCE_CODE


/* Determine if parameter checking is disabled. If so, skip parameter checking veneer.  */

#ifndef MPX_PARAMETER_CHECKING_DISABLE

#define sem_destroy                                         mpx_sem_destroy_check_params
#define mpx_sem_extend_init                                 mpx_sem_extend_init_check_params
#define sem_init                                            mpx_sem_init_check_params
#define sem_post                                            mpx_sem_post_check_params
#define mpx_sem_tickwait                                    mpx_sem_tickwait_check_params
#define sem_timedwait                                       mpx_sem_timedwait_check_params
#define sem_trywait                                         mpx_sem_trywait_check_params
#define sem_wait                                            mpx_sem_wait_check_params

#else

#define sem_destroy                                         mpx_sem_destroy
#define sem_init                                            mpx_sem_init
#define sem_post                                            mpx_sem_post
#define sem_timedwait                                       mpx_sem_timedwait
#define sem_trywait                                         mpx_sem_trywait
#define sem_wait                                            mpx_sem_wait


#endif /* MPX_PARAMETER_CHECKING_DISABLE */

#endif /* MPX_SOURCE_CODE */


/******************************************************************************
 ******************** Section IV: Actual MPX API prototypes *******************
 *****************************************************************************/

int             mpx_sem_destroy(sem_t *  semaphore_handle);
int             mpx_sem_destroy_check_params(sem_t *  semaphore_handle);
int             mpx_sem_extend_init(sem_t *  semaphore_handle, int pshared, unsigned int value, semattr_t *  semaphore_attributes);
int             mpx_sem_extend_init_check_params(sem_t *  semaphore_handle, int pshared, unsigned int value, semattr_t *  semaphore_attributes);
int             mpx_sem_init(sem_t *  semaphore_handle, int pshared, unsigned int value);
int             mpx_sem_init_check_params(sem_t *  semaphore_handle, int pshared, unsigned int value);
int             mpx_sem_post(sem_t *  semaphore_handle);
int             mpx_sem_post_check_params(sem_t *  semaphore_handle);
int             mpx_sem_tickwait(sem_t *  semaphore_handle, tick_t  timemout_ticks);
int             mpx_sem_tickwait_check_params(sem_t *  semaphore_handle, tick_t  timemout_ticks);
int             mpx_sem_timedwait(sem_t *  semaphore_handle, const struct mpx_timespec *  absolute_time);
int             mpx_sem_timedwait_check_params(sem_t *  semaphore_handle, const struct mpx_timespec *  absolute_time);
int             mpx_sem_trywait(sem_t *  semaphore_handle);
int             mpx_sem_trywait_check_params(sem_t *  semaphore_handle);
int             mpx_sem_wait(sem_t *  semaphore_handle);
int             mpx_sem_wait_check_params(sem_t *  semaphore_handle);
int             mpx_semattr_destroy(semattr_t *  semaphore_attributes);
int             mpx_semattr_getcontroladdr(semattr_t *  semaphore_attributes, void **  semaphore_control_address);
int             mpx_semattr_getcontrolsize(semattr_t *  semaphore_attributes, size_t *  semaphore_control_size);
int             mpx_semattr_getname(semattr_t *  semaphore_attributes, char **  semaphore_name);
int             mpx_semattr_init(semattr_t *  semaphore_attributes);
int             mpx_semattr_setcontroladdr(semattr_t *  semaphore_attributes, void *  semaphore_control_address, size_t  semaphore_control_size);
int             mpx_semattr_setname(semattr_t *  semaphore_attributes, char *  semaphore_name);


#ifdef __cplusplus
}  /* Closing bracket for extern "C" at the top of file.  */
#endif /* __cplusplus  */


#endif  /* MPX_SEMAPHORE_HEADER */
