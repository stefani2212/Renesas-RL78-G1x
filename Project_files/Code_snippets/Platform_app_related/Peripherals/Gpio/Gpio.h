/*! @file Mcu.h
    @brief The GPIO driver module
 */

#ifndef _GPIO_H
#define _GPIO_H

/***************************************************************************//**
 * @addtogroup Peripherals
 * @{
 ******************************************************************************/

/***************************************************************************//**
 * @addtogroup Gpio
 * @brief The GPIO driver module
 * @{
 */

#include "Std_Types.h"

/***
 * necessary for using within a C++ module
 */
#ifdef __cplusplus
extern "C" {
#endif

void Gpio_Init(void* ConfigPtr);

/***
 * necessary for using within a C++ module
 */
#ifdef __cplusplus
    }
#endif

/** @} (end addtogroup Mcu) */
/** @} (end addtogroup Peripherals) */
#endif  /* End include guard */
