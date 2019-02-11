/*! @file Mcu.h
    @brief The Microcontroller driver module
 */

#ifndef _MCU_H
#define _MCU_H

/***************************************************************************//**
 * @addtogroup Peripherals
 * @{
 ******************************************************************************/

/***************************************************************************//**
 * @addtogroup Mcu
 * @brief The Microcontroller driver module
 * @{
 */

#include "Std_Types.h"

/***
 * necessary for using within a C++ module
 */
#ifdef __cplusplus
extern "C" {
#endif

/*! \def        Mcu_DisableAllInterrupts()
    \brief      Globally disable interrupts
    \return     Opaque key for use by Mcu_RestoreAllInterrupts()
    \details    Mcu_DisableAllInterrupts globally disables hardware interrupts and returns an opaque key indicating whether interrupts 
                were globally enabled or disabled on entry to Mcu_DisableAllInterrupts(). The actual value of the key is target/device
                specific and is meant to be passed to Mcu_RestoreAllInterrupts(). Call Mcu_DisableAllInterrupts before a portion of a
                function that needs to run without interruption. When critical processing is complete, call Mcu_RestoreAllInterrupts or
                Mcu_EnableAllInterrupts to reenable hardware interrupts. Servicing of interrupts that occur while interrupts are disabled
                is postponed until interrupts are reenabled. However, if the same type of interrupt occurs several times while interrupts
                are disabled, the interrupt's function is executed only once when interrupts are reenabled.
 */
#define Mcu_DisableAllInterrupts()          asm("di")

/*! \def        Mcu_EnableAllInterrupts()
    \brief      Globally enable interrupts
    \return     Opaque key for use by Mcu_RestoreAllInterrupts()
    \details    Mcu_EnableAllInterrupts globally enables hardware interrupts and returns an opaque key indicating whether interrupts were
                globally enabled or disabled on entry to Mcu_EnableAllInterrupts(). The actual value of the key is target/device specific
                and is meant to be passed to Mcu_RestoreAllInterrupts(). This function is called as part of SchM startup phase. Hardware
                interrupts are enabled unless a call to Mcu_DisableAllInterrupts disables them. Servicing of interrupts that occur while 
                interrupts are disabled is postponed until interrupts are reenabled. However, if the same type of interrupt occurs several 
                times while interrupts are disabled, the interrupt's function is executed only once when interrupts are reenabled.
 */
#define Mcu_EnableAllInterrupts()           asm("ei") 

/*! \def        Mcu_RestoreAllInterrupts()
    \brief      Globally restore interrupts
    \param[in]  arg1    Enable/disable state to restore
    \details    Mcu_RestoreAllInterrupts globally restores interrupts to the state determined by the key argument provided by a previous 
                invocation of Mcu_DisableAllInterrupts.
 */
#define Mcu_RestoreAllInterrupts( arg1 )    if ( arg1 ) { asm("ei"); } else { asm("di"); }


/*! \enum Mcu_ResetType
    \brief The Microcontroller reset reason enumeration data type definition.
 */
typedef enum 
{
/*  1 */    MCU_RESET_REASON_INVALID = 1,                   /**< Reset reason identifier */
/*  2 */    MCU_RESET_REASON_TRAP,                           /**< Reset reason identifier */
/*  3 */    MCU_RESET_REASON_WDT,                           /**< Reset reason identifier */
/*  4 */    MCU_RESET_REASON_RPE,                           /**< Reset reason identifier */
/*  5 */    MCU_RESET_REASON_IAW,                          /**< Reset reason identifier */
/*  6 */    MCU_RESET_REASON_LVI,                          /**< Reset reason identifier */
/*  2 */    MCU_RESET_REASON_POR_OR_EXT,                           /**< Reset reason identifier */    

/*  9 */    MCU_RESET_REASON_SWR_UNDEFINED,                 /**< Reset reason identifier */

/* 10 */    MCU_RESET_REASON_SWR_CPU_REGISTER_TEST_FAILED,  /**< Reset reason identifier */
/* 11 */    MCU_RESET_REASON_SWR_RAM_CHECK_FAILED,          /**< Reset reason identifier */
/* 12 */    MCU_RESET_REASON_SWR_STACK_OVERFLOW,            /**< Reset reason identifier */

/* 13 */    MCU_RESET_REASON_SWR_ENTER_BOOT,                /**< Reset reason identifier */
} Mcu_ResetType;

/*! \enum Mcu_ModeType
    \brief The microcontroller available operating modes.
 */
typedef enum {
    MCU_MODE_UNDEFINED, /**< Mode identifier */
    MCU_MODE_SLEEP,     /**< Mode identifier */
    MCU_MODE_IDLE,      /**< Mode identifier */
    MCU_MODE_FRC,       /**< Mode identifier */
    MCU_MODE_HSPLL      /**< Mode identifier */
} Mcu_ModeType;

/*  */
void                Mcu_Init(void* ConfigPtr);
Std_ReturnType      Mcu_InitClock(void* ConfigPtr);
Mcu_ResetType       Mcu_GetResetReason(void);
void                Mcu_SetMode(Mcu_ModeType eMode);

/***
 * necessary for using within a C++ module
 */
#ifdef __cplusplus
    }
#endif

/** @} (end addtogroup Mcu) */
/** @} (end addtogroup Peripherals) */
#endif  /* End include guard */
