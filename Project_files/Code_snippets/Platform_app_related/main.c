/*! @file Main.c
    @brief The C application entry

    C entry module
 */

#include "Mcu.h"
#include "Gpio.h"
#include "HalGpio.h"

/***************************************************************************//**
 * @addtogroup Bsw
 * @{
 ******************************************************************************/

/***************************************************************************//**
 * @addtogroup Main
 * @brief C Main Module
 * @{
 */

void _exit(int code);


 /***************************************************************************//**
 * \fn HardwareSetup
 * \brief   The C entry function called by the start-up code.
 * \details Call the EcuM_Init function to initialize the ECU.
 * \return  This function never returns.
 * \callgraph
 * \callergraph
 ******************************************************************************/
void HardwareSetup(void)
{
    ;
}


 /***************************************************************************//**
 * \fn int main(void)
 * \brief   The C entry function called by the start-up code.
 * \details Call the EcuM_Init function to initialize the ECU.
 * \return  This function never returns.
 * \callgraph
 * \callergraph
 ******************************************************************************/
int main(void)
{
    BOOL lb_Status = FALSE;
    
    /*  */
    Mcu_Init( NULL_PTR );
    Gpio_Init( NULL_PTR );
    
    HalGpio_Read_SWITCH_UP( &lb_Status );
    HalGpio_Write_REL_UP( lb_Status );
    
    HalGpio_Read_SWITCH_DOWN( &lb_Status );
    HalGpio_Write_REL_DOWN( lb_Status );
    
#if 0
  LED01_PIN = 0; // Make Pin as O/P
  LED01 = 0; // Turn LED ON
  while(1)
  {
     LED01 = ~LED01; // toggle LED
     delay();
  }
  _exit( 0 );
#endif

  return 0;
}


/***************************************************************************//**
 * \fn void _exit(int code)
 * \brief 
 * \details
 * \param[in] code - The exit code identifier.
 * \return  This function never returns.
 * \callgraph
 * \callergraph
 ******************************************************************************/
void _exit(int code)
{
    while ( 1 ) {
        ;
    }
}

/** @} (end addtogroup Main) */
/** @} (end addtogroup Bsw) */
