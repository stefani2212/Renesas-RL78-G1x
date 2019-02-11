/*! @file Gpio.c
    @brief Definition of GPIO unit.
 */

#include "Gpio.h"
#include "iodefine.h"

/***************************************************************************//**
 * @addtogroup Peripherals
 * @{
 ******************************************************************************/

/***************************************************************************//**
 * @addtogroup Gpio
 * @brief The GPIO driver module
 * @{
 */


 /***************************************************************************//**
 * \fn Gpio_Init
 * \brief   
 * \details 
 * \param[in] ConfigPtr - The pointer to the initialization structure.
 * \return  This function never returns.
 * \callgraph
 * \callergraph
 ******************************************************************************/
void Gpio_Init(void* ConfigPtr)
{
    (void)ConfigPtr;
    
    /*  */
    _SFR_PM4.PM40   = PM_INPUT;   /* Pin  1: TOOL0 */
    _SFR_PM13.PM137 = PM_INPUT;
    _SFR_PM12.PM122 = PM_OUTPUT; /* Not used */
    _SFR_PM12.PM121 = PM_OUTPUT; /* Not used */

    _SFR_PM6.PM60 = PM_INPUT;   /* Pin  9: SWITCH_DOWN manual switch dig. Input */
    _SFR_PM6.PM61 = PM_OUTPUT;  /* Pin 10: DISABLE_DOWN */
    _SFR_PM6.PM62 = PM_OUTPUT;  /* Pin 11: REL_DOWN     */
    _SFR_PM3.PM31 = PM_OUTPUT;  /* Pin 12: DISABLE_UP   */
    _SFR_PM7.PM70 = PM_INPUT;   /* Pin 13: SWITCH_UP manual switch dig. Input */
    _SFR_PM3.PM30 = PM_INPUT;   /* Pin 14: */
    _SFR_PM5.PM50 = PM_INPUT;   /* Pin 15: */
    _SFR_PM5.PM51 = PM_OUTPUT;  /* Pin 16: */
    
    _SFR_PM1.PM17 = PM_OUTPUT;  /* Pin 17: Not used */
    _SFR_PM1.PM16 = PM_INPUT;   /* Pin 18: HALL */
    _SFR_PM1.PM15 = PM_OUTPUT;  /* Pin 19: Not used */
    _SFR_PM1.PM14 = PM_OUTPUT;  /* Pin 20: Not used */
    _SFR_PM1.PM13 = PM_OUTPUT;  /* Pin 21: Not used */
    _SFR_PM1.PM12 = PM_OUTPUT;  /* Pin 22: Vcc WDG  */
    _SFR_PM1.PM11 = PM_OUTPUT;  /* Pin 23: Not used */
    _SFR_PM1.PM10 = PM_OUTPUT;  /* Pin 24: Not used */
    
    _SFR_PM14.PM147 = PM_INPUT;     /* Pin 25:  */
    _SFR_PM2.PM23   = PM_INPUT;     /* Pin 26: HALL */
    _SFR_PM2.PM22   = PM_OUTPUT;    /* Pin 27: Not used */
    _SFR_PM2.PM21   = PM_INPUT;     /* Pin 28: Not used */
    _SFR_PM2.PM20   = PM_INPUT;     /* Pin 29:        [P20/ANI0/AVREFP]                     */
    _SFR_PM0.PM01   = PM_INPUT;     /* Pin 30:        [P01/ANI16/TO00/RxD1/TRGCLKB/TRJIO0]  */
    _SFR_PM0.PM00   = PM_OUTPUT;    /* Pin 31:        [P00/ANI17/TI00/TxD1/TRGCLKA/(TRJO0)] */
    _SFR_PM12.PM120 = PM_OUTPUT;    /* Pin 32: REL_UP [P120/ANI19/VCOUT0]                   */
}

/** @} (end addtogroup Gpio) */
/** @} (end addtogroup Peripherals) */
