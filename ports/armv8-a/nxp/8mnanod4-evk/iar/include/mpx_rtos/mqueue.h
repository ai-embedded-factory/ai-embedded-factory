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

#ifndef MPX_MQUEUE_HEADER
#define MPX_MQUEUE_HEADER


/* Ensure this file can be included and used by C++ programs.  */

#ifdef __cplusplus
#ifndef MPX_EXTERN_C
#define MPX_EXTERN_C
#define MPX_MQUEUE_EXTERN_C
extern "C" {
#endif /* MPX_EXTERN_C  */
#endif /* __cplusplus  */


/******************************************************************************
 ******************************** Manifest ************************************
 ******************************************************************************
   
   Section I:   Include Files
   Section II:  Message Queue Constants
   Section III: Message Queue Types
   Section IV:  MPX API Mapping
   Section V:   Actual MPX API prototypes

******************************************************************************/


/******************************************************************************
 ************************** Section I: Include Files **************************
 *****************************************************************************/

#include "sys/types.h"
#include "mpx_time.h"
#include "mpx_errno.h"
#include "fcntl.h"
#include "sys/stat.h"


/******************************************************************************
 ****************** Section II:  Message Queue Constants **********************
 *****************************************************************************/

#define MPX_QUEUE_ATTR_ID                                   0x4D515541UL


/******************************************************************************
 ******************* Section III:  Message Queue Types ************************
 *****************************************************************************/


/* Define the message queue type, which is effectively contains a pointer to the internal message queue control structure.  */

typedef void *                                              mqd_t;


/* Define the message queue attribute structure.  */

struct mq_attr
{

    /* Define flags. Note that these are not used for mq_open call, since they are supplied in the API itself.  */
    u_long                                                  mq_flags;

    /* Define the maximum number of messages.  */
    u_long                                                  mq_maxmsg;

    /* Define the maximum number of bytes per message.  */
    size_t                                                  mq_msgsize;

    /* Define the current number of messages currently in the queue.  Not applicable to mq_open API.  */
    u_long                                                  mq_curmsgs;
};


/* Define the message queue extended attribute structure.  */

typedef struct mq_extendattr_t_struct
{

    /* Define ID of extended message queue attributes structure. */
    u_long                                                  mq_extendattr_id;

    /* Define the user-specified message queue control memory address.  */
    void *                                                  mq_control_address;

    /* Define the user-specified message queue memory area address.  */
    void *                                                  mq_memory_area_address;

    /* Define the user-specified message queue memory area size.  */
    size_t                                                  mq_memory_area_size;

} mq_extendattr_t;



/******************************************************************************
 *********************** Section IV: MPX API Mapping **************************
 *****************************************************************************/

/* Determine if MPX source is present. If so, skip remapping.  */

#ifndef MPX_SOURCE_CODE


/* Determine if parameter checking is disabled. If so, skip parameter checking veener.  */

#ifndef MPX_PARAMETER_CHECKING_DISABLE

#define mq_close                                            mpx_mq_close_check_params
#define mpx_mq_extend_open                                  mpx_mq_extend_open_check_params
#define mq_getattr                                          mpx_mq_getattr_check_params
#define mq_open                                             mpx_mq_open_check_params
#define mq_receive                                          mpx_mq_receive_check_params
#define mq_send                                             mpx_mq_send_check_params
#define mq_setattr                                          mpx_mq_setattr_check_params
#define mq_timedreceive                                     mpx_mq_timedreceive_check_params
#define mq_timedsend                                        mpx_mq_timedsend_check_params

#else

#define mq_close                                            mpx_mq_close
#define mpx_mq_extend_open                                  mpx_mq_extend_open
#define mq_getattr                                          mpx_mq_getattr
#define mq_open                                             mpx_mq_open
#define mq_receive                                          mpx_mq_receive
#define mq_send                                             mpx_mq_send
#define mq_setattr                                          mpx_mq_setattr
#define mq_timedreceive                                     mpx_mq_timedreceive
#define mq_timedsend                                        mpx_mq_timedsend

#endif /* MPX_PARAMETER_CHECKING_DISABLE */

#endif /* MPX_SOURCE_CODE */


/******************************************************************************
 ******************** Section IV: Actual MPX API prototypes *******************
 *****************************************************************************/

int             mpx_mq_close(mqd_t  message_queue);
int             mpx_mq_close_check_params(mqd_t  message_queue);
mqd_t           mpx_mq_extend_open(const char *  queue_name, int operation, mode_t  mode, struct mq_attr *  queue_attributes, mq_extendattr_t *  extend_attributes);
mqd_t           mpx_mq_extend_open_check_params(const char *  queue_name, int operation, mode_t  mode, struct mq_attr *  queue_attributes, mq_extendattr_t *  extend_attributes);
int             mpx_mq_extendattr_destroy(mq_extendattr_t *  queue_attributes);
int             mpx_mq_extendattr_getcontroladdr(mq_extendattr_t *  queue_attributes, void **  queue_control_address);
int             mpx_mq_extendattr_getcontrolsize(mq_extendattr_t *  queue_attributes, size_t *  queue_control_size);
int             mpx_mq_extendattr_getqueueaddr(mq_extendattr_t *  queue_attributes, void **  queue_memory_address);
int             mpx_mq_extendattr_getqueuesize(mq_extendattr_t *  queue_attributes, size_t *  queue_memory_size);
int             mpx_mq_extendattr_init(mq_extendattr_t *  queue_attributes);
int             mpx_mq_extendattr_setcontroladdr(mq_extendattr_t *  queue_attributes, void *  queue_control_address, size_t  queue_contorl_size);
int             mpx_mq_extendattr_setqueueaddr(mq_extendattr_t *  queue_attributes, void *  queue_memory_address, size_t  queue_memory_size);
int             mpx_mq_getattr(mqd_t  message_queue, struct mq_attr *  queue_attributes);
int             mpx_mq_getattr_check_params(mqd_t  message_queue, struct mq_attr *  queue_attributes);
mqd_t           mpx_mq_open(const char *  queue_name, int operation, mode_t  mode, struct mq_attr *  queue_attributes);
mqd_t           mpx_mq_open_check_params(const char *  queue_name, int operation, mode_t  mode, struct mq_attr *  queue_attributes);
ssize_t         mpx_mq_receive(mqd_t  message_queue, char *  message, size_t message_size, unsigned int *  message_priority);
ssize_t         mpx_mq_receive_check_params(mqd_t  message_queue, char *  message, size_t message_size, unsigned int *  message_priority);
int             mpx_mq_send(mqd_t  message_queue, char *  message, size_t  message_size, unsigned int  message_priority);
int             mpx_mq_send_check_params(mqd_t  message_queue, char *  message, size_t  message_size, unsigned int  message_priority);
int             mpx_mq_setattr(mqd_t  message_queue, const struct mq_attr *  queue_attributes, struct mq_attr *  previous_attributes);
int             mpx_mq_setattr_check_params(mqd_t  message_queue, const struct mq_attr *  queue_attributes, struct mq_attr *  previous_attributes);
ssize_t         mpx_mq_timedreceive(mqd_t  message_queue, char *  message, size_t message_size, unsigned int  *  message_priority, const struct mpx_timespec *  absolute_timeout);
ssize_t         mpx_mq_timedreceive_check_params(mqd_t  message_queue, char *  message, size_t message_size, unsigned int  *  message_priority, const struct mpx_timespec *  absolute_timeout);
int             mpx_mq_timedsend(mqd_t  message_queue, char *  message, size_t  message_size, unsigned int  message_priority, const struct mpx_timespec *  absolute_timeout);
int             mpx_mq_timedsend_check_params(mqd_t  message_queue, char *  message, size_t  message_size, unsigned int  message_priority, const struct mpx_timespec *  absolute_timeout);


#ifdef __cplusplus
#ifdef MPX_MQUEUE_EXTERN_C
}  /* Closing bracket for extern "C" at the top of file.  */
#endif /* MPX_MQUEUE_EXTERN_C  */
#endif /* __cplusplus  */


#endif  /* MPX_MQUEUE_HEADER */
