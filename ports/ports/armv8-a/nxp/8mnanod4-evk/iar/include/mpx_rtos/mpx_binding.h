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
 *      MPX RTOS SMP Binding for Cortex-Axx & IAR Development Tools         *
 *                                                                          *
 ***************************************************************************/


/******************************************************************************
 ******************************** Manifest ************************************
 ******************************************************************************
   
   Section I:   Include Files
   Section II:  Binding-specific Constants and Enumerations
   Section III: Binding-specific Overrides
   Section IV:  Binding Macros
   Section V:   Binding-specific function prototypes

   Note: The mpx_binding.h file is only included by the mpx.h file, i.e., it 
         is not meant to be included directly by the application software.

******************************************************************************/

#ifndef MPX_BINDING_HEADER
#define MPX_BINDING_HEADER


/******************************************************************************
 ************************* Section I: Include Files ***************************
 *****************************************************************************/

#include <intrinsics.h>
#include "string.h"


/******************************************************************************
 ********** Section II: Binding-specific Constants and Enumerations ***********
 *****************************************************************************/

/* Define the constant string that identifies this binding.  */

#define MPX_BINDING_IDENTIFIER                              "Cortex-Axx/IAR"


/* Define this version of the MPX binding.  */

#define MPX_BINDING_MAJOR_VERSION                           1U
#define MPX_BINDING_MINOR_VERSION                           0U
#define MPX_BINDING_UPDATE_VERSION                          0U
#define MPX_BINDING_PATCH_VERSION                           0U


/* Define the minimal remaining stack size for this port. This is generally a function
   of the size of the context save stack frame.  */

#ifdef __ARMVFP__
#define MPX_BINDING_MINIMUM_STACK_SIZE                      1024UL
#else
#define MPX_BINDING_MINIMUM_STACK_SIZE                      512UL
#endif


/* Define the stack frame size for this binding.  */

#ifdef __ARMVFP__
#define MPX_BINDING_STACK_FRAME_SIZE                        800UL
#else
#define MPX_BINDING_STACK_FRAME_SIZE                        272UL
#endif


/* Define the default stack size for this binding.  */

#ifndef MPX_DEFAULT_STACK_SIZE
#define MPX_DEFAULT_STACK_SIZE                              (MPX_BINDING_MINIMUM_STACK_SIZE*3UL)
#endif  /* MPX_DEFAULT_STACK_SIZE */


/* Define the long word stack fill pattern.  */

#define MPX_STACK_FILL_LWORD                                0xEFEFEFEFEFEFEFEFUL


/* Define stack alignment required for this binding.  */

#define MPX_BINDING_STACK_ALIGNMENT                         16UL           /* Cortex-Axx requires 16-byte stack alignment  */


/******************************************************************************
 ***************** Section III: Binding-specific Overrides *********************
 *****************************************************************************/

/* Define the maximum number of cores for this SMP implementation.  Maximum of 64.  */

#ifndef MPX_MAXIMUM_CORES
#define MPX_MAXIMUM_CORES                                   4
#endif


/* Define the per-thread core bit map mask.  Each bit represents a core. There must be the same number of bits set as the MPX_MAXIMUM_CORES value previously.  */


#ifndef MPX_CORE_BIT_MAP_MASK
#define MPX_CORE_BIT_MAP_MASK                               0xFUL
#endif


/* Define the default per-thread affinity that is setup when each thread is created, excluding the main thread. This bit map must be the same or a sub-set of MPX_CORE_BIT_MAP_MASK.  */

#ifndef MPX_DEFAULT_CORE_AFFINITY
#define MPX_DEFAULT_CORE_AFFINITY                           0xFUL
#endif


/* Define the default main thread affinity. This bit map must be the same or a sub-set of MPX_CORE_BIT_MAP_MASK and must have core 0 selected.  */

#ifndef MPX_DEFAULT_MAIN_CORE_AFFINITY
#define MPX_DEFAULT_MAIN_CORE_AFFINITY                      0xFUL
#endif


/* Define the executing core retrieval.  */

#ifndef MPX_EXECUTING_CORE
#define MPX_EXECUTING_CORE                                  mpx_binding_utility_get_core_id()
#endif


/* Define protection storage and get/restore protection macros, which for this
   binding map to interrupt lockout.  */

#define MPX_PROTECTION_SAVE                                 unsigned int   local_interrupt_save_area;
#define MPX_PROTECTION_START                                local_interrupt_save_area =  mpx_binding_protection_start();
#define MPX_PROTECTION_END                                  mpx_binding_protection_end(local_interrupt_save_area);
#define MEMSET(ptr, v, n)                                   memset((ptr), (v), (n));
#define MPX_STACK_VERIFY_ID                                 __get_return_address()
#define MPX_INTERRUPT_ENABLE                                __enable_irq();
#define MPX_HIGHEST_BIT_SET_GET(b,w)                        (b) =  (int) (((unsigned int) MPX_MAXIMUM_BITS - 1UL) - mpx_binding_utility_clz((w)));


/* Define the global data extensions for this SMP binding.  */

#define MPX_GLOBAL_DATA_BINDING_EXTENSION                   u_long                smp_lock;                                         \
                                                            u_long                smp_lock_count;                                   \
                                                            u_long                smp_lock_core;                                    \
                                                            u_long                smp_release_cores;                                


/* Define the thread VFP enable flag extension for the thread control structure.  */

#define MPX_THREAD_CONTROL_BINDING_EXTENSION                u_long   vfp_enabled;    \
                                                            u_long   schedule_lock;  

                                                            
/* Define the binding verification extension so we can verify the offset of the vfp_enabled flag in the thread control structure.  */

#define MPX_BINDING_VERIFICATION_EXTENSION                  mpx_globals.main_thread.vfp_enabled =    3UL;  \
                                                            mpx_globals.main_thread.schedule_lock =  1UL;  
                                                            


/******************************************************************************
 ************************ Section IV: Binding Macros **************************
 *****************************************************************************/

void  mpx_binding_thread_return(void);


/* Define the memory barrier macro.   */

#define MPX_BINDING_MEMORY_BARRIER                          asm("DSB  SY");


/* Define the inter-core interrupt used to preempt thread execution on a different core.  */
void interrupt_core(int i);
#define MPX_BINDING_OTHER_CORE_PREEMPT(i)                   interrupt_core(i);


/* Define the thread preemption macro.  Since the mpx_binding_thread_return function releases the global SMP protection, we have to restore it when the 
   thread executes again.  */

#define MPX_BINDING_THREAD_PREEMPT                          if (mpx_globals.interrupt_nesting_level[mpx_binding_core_id_get()] == 0UL) \
                                                            {                                                                          \
                                                            u_long   saved_lock_count;                                                 \
                                                               saved_lock_count =  mpx_globals.smp_lock_count;                         \
                                                               mpx_binding_thread_return();                                            \
                                                               mpx_binding_protection_start();                                         \
                                                               mpx_globals.smp_lock_count =  saved_lock_count;                         \
                                                            }

#define MPX_PTHREAD_START_PRE_EXTENSION                     mpx_globals.smp_lock_core =  0xFFFFFFFF;


/* Define the pthread_create extension so we can setup the default core affinity.  */

#define MPX_PTHREAD_CREATE_EXTENSION                        thread_pointer -> core_affinity =  MPX_DEFAULT_CORE_AFFINITY;


/* Define the mpx_pthread_start extension, which will set the default core affinity of the main thread.  */

#define MPX_PTHREAD_START_POST_EXTENSION                    mpx_globals.main_thread.core_affinity =  MPX_DEFAULT_MAIN_CORE_AFFINITY; 


/* Define the C level extensions.  */

#define MPX_BINDING_C_EXTENSION_UTILITIES                  int  mpx_binding_utility_get_core_id(void)                               \
                                                           {                                                                        \
                                                            unsigned long core_id;                                                  \
                                                            asm("mrs %0, MPIDR_EL1\n"                                               \
                                                                "and %0, %0, #0xFF\n"                                               \
                                                                : "=r" (core_id)                                                    \
                                                                :                                                                   \
                                                                );                                                                  \
                                                            return((int) core_id);                                                  \
                                                           }                                                                        \
                                                           unsigned int  mpx_binding_utility_clz(unsigned long bit_map)             \
                                                           {                                                                        \
                                                            unsigned int leading_zeros;                                             \
                                                            asm("clz %w0, %w1\n"                                                    \
                                                                : "=r" (leading_zeros)                                              \
                                                                : "r"  ((unsigned int) bit_map)                                     \
                                                              );                                                                    \
                                                              return(leading_zeros);                                                \
                                                          } 



/******************************************************************************
 **************** Section V: Binding-Specific Function Prototypes *************
 *****************************************************************************/

/* Define the function to retrieve the current core ID.  */
                                                            
int             mpx_binding_core_id_get(void);
int             mpx_binding_utility_get_core_id(void);


/* Define the function to retrieve the leading zeros.  */

unsigned int    mpx_binding_utility_clz(unsigned long  bit_map);


/* Define the multicore protection start/end functions.  */

unsigned int    mpx_binding_protection_start(void);
void            mpx_binding_protection_end(unsigned int interrupt_posture);


/* Define the additional core start entry function.  */

void            mpx_binding_additional_core_start(void);

                                                            
/* Define APIs for enabling/disabling floating point on a per-thread basis. These APIs are defined in the binding assembly file mpx_binding.s.  */

void            mpx_pthread_vfp_enable(void);
void            mpx_pthread_vfp_disable(void);

                                                            
                                                            
#endif  /* MPX_BINDING_HEADER */
