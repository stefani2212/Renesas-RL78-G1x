/*! \file HalGpio.h
    \brief The HAL GPIO header file.
 */

#ifndef _HALGPIO_H
#define _HALGPIO_H

/***************************************************************************//**
 * @addtogroup Hal
 * @{
 ******************************************************************************/

/***************************************************************************//**
 * @addtogroup HalGpio
 * @brief
 * @{
 */

#include "Std_Types.h"
#include "iodefine.h"

/***
 * necessary for using within a C++ module
 */
#ifdef __cplusplus
extern "C" {
#endif

#define HalGpio_Write_REL_UP( arg1 )        _SFR_P12.P120 = (FALSE != (arg1))
#define HalGpio_Write_REL_DOWN( arg1 )      _SFR_P6.P62 = (FALSE != (arg1))

#define HalGpio_Read_SWITCH_UP( arg1 )      *(arg1) = _SFR_P7.P70
#define HalGpio_Read_SWITCH_DOWN( arg1 )    *(arg1) = _SFR_P6.P60

/***
 * necessary for using within a C++ module
 */
#ifdef __cplusplus
    }
#endif

/** @} (end addtogroup HalGpio) */
/** @} (end addtogroup Hal) */
#endif  /* End include guard */
