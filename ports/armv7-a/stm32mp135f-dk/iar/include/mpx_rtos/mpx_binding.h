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

/****************************************************************************
 *                                                                          *
 *         MPX Binding for Cortex-A7 (STM32MP1) & IAR Development Tools                *
 *                                                                          *
 ***************************************************************************/


/******************************************************************************
 ******************************** Manifest ************************************
 ******************************************************************************
   
   Section I:   Include Files
   Section II:  Binding-specific Constants and Enumerations
   Section III: Binding-specific Overrides
   Section IV:  Binding Macros

   Note: The mpx_binding.h file is only included by the mpx.h file, i.e., it 
         is not meant to be included directly by the application software.

******************************************************************************/

#ifndef MPX_BINDING_HEADER
#define MPX_BINDING_HEADER


/******************************************************************************
 ************************* Section I: Include Files ***************************
 *****************************************************************************/

#include "intrinsics.h"
#include "string.h"


/******************************************************************************
 ********** Section II: Binding-specific Constants and Enumerations ***********
 *****************************************************************************/

/* Define the constant string that identifies this binding.  */

#define MPX_BINDING_IDENTIFIER                              "Cortex-A9/IAR"


/* Define this version of the MPX binding.  */

#define MPX_BINDING_MAJOR_VERSION                           1U
#define MPX_BINDING_MINOR_VERSION                           0U
#define MPX_BINDING_UPDATE_VERSION                          0U
#define MPX_BINDING_PATCH_VERSION                           0U


/* Define the minimal remaining stack size for this port. This is generally a function
   of the size of the context save stack frame.  */

#define MPX_BINDING_MINIMUM_STACK_SIZE                      256UL


/* Define the stack frame size for this binding.  */

#define MPX_BINDING_STACK_FRAME_SIZE                        88UL


/* Define stack alignment required for this binding.  */

#define MPX_BINDING_STACK_ALIGNMENT                         8UL           /* Cortex-A requires 8-byte stack alignment  */


/* Define APIs for enabling/disabling floating point on a per-thread basis. These APIs are defined in the binding assembly file mpx_binding.s.  */

void  mpx_pthread_vfp_enable(void);
void  mpx_pthread_vfp_disable(void);


/******************************************************************************
 ***************** Section III: Binding-specific Overrides *********************
 *****************************************************************************/

/* Define protection storage and get/restore protection macros, which for this
   binding map to interrupt lockout.  */

#define MPX_PROTECTION_SAVE                                 __istate_t local_interrupt_save_area;
#define MPX_PROTECTION_START                                local_interrupt_save_area =  __get_CPSR();  __disable_irq();
#define MPX_PROTECTION_END                                  __set_CPSR(local_interrupt_save_area);
#define MPX_HIGHEST_BIT_SET_GET(b,w)                        (b) =  (int) (((unsigned int) MPX_MAXIMUM_BITS - 1UL) - __CLZ((w)));
#define MEMSET(ptr, v, n)                                   memset((ptr), (v), (n));
#define MPX_STACK_VERIFY_ID                                 __get_return_address()
#define MPX_INTERRUPT_ENABLE                                __enable_irq();


/* Define the thread VFP enable flag extension for the thread control structure.  */

#define MPX_THREAD_CONTROL_BINDING_EXTENSION                u_long   vfp_enabled;


/* Define the binding verification extension so we can verify the offset of the vfp_enabled flag in the thread control structure.  */

#define MPX_BINDING_VERIFICATION_EXTENSION                  mpx_globals.main_thread.vfp_enabled =  3UL;


/******************************************************************************
 ************************ Section IV: Binding Macros **************************
 *****************************************************************************/

void  mpx_binding_thread_return(void);


#define MPX_BINDING_THREAD_PREEMPT                          if (mpx_globals.interrupt_nesting_level[MPX_EXECUTING_CORE] == 0UL) \
                                                            { \
                                                               mpx_binding_thread_return(); \
                                                            }

#endif  /* MPX_BINDING_HEADER */
