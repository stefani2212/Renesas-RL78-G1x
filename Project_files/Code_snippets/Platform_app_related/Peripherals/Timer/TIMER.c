/*! @file TIMER.c
 *	@brief Definition of the TIMER driver module.
*/

#include "TIMER.h"
#include "iodefine.h"
#include "iodefine_ext.h"


/***********************************************************************************************************************
* Function Name: R_TAU0_Create
* Description  : This function initializes the TAU0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void TAU_Init(void)
{
	/*Timer_Array_Unit_Init defined as in the CG */

	_SFR_PER0bits.TAU0EN = 1U;	/* supplies input clock */
	_SFR_TPS0 = 0U; /* 32MHz CLK */
	_SFR_TMR00 = 1U; /* Setup as Interval timer mode */
	_SFR_TT0 = 0xA0Fu;/*Disables TAU channels */
	/* When a bit of this register is set to 1, 
	the corresponding bit of timer channel enable status register m (TEm) is cleared to 0.
	*/	 /*Channel 0 */
	_SFR_MK1Lbits.TMMK00 = 1U;/*disables INTTM00 Interrupt*/
	_SFR_IF1Lbits.TMIF00 = 0U;/*clears INTTM00 Interrupt request flag*/
	/*Channel 1 */
	_SFR_MK1Lbits.TMMK01 = 1U;/*disables INTTM01 Interrupt*/
	_SFR_IF1Lbits.TMIF01 = 0U;/*clears INTTM01 Interrupt request flag*/
	_SFR_MK1Lbits.TMMK01H = 1U;/*disables INTTM01H Interrupt*/
	_SFR_IF1Lbits.TMIF01H = 0U;/*clears INTTM01H Interrupt request flag*/
	/*Channel 2 */
	_SFR_MK1Lbits.TMMK02 = 1U;/*disables INTTM02 Interrupt*/
	_SFR_IF1Lbits.TMIF02 = 0U;/*clears INTTM02 Interrupt request flag*/
	/*Channel 3 */
	_SFR_MK1Lbits.TMMK03 = 1U;/*disables INTTM03 Interrupt*/
	_SFR_IF1Lbits.TMIF03 = 0U;/*clears INTTM03 Interrupt request flag*/
	_SFR_MK1Lbits.TMMK03H = 1U;/*disables INTTM03H Interrupt*/
	_SFR_IF1Lbits.TMIF03H = 0U;/*clears INTTM03H Interrupt request flag*/
	/*Set INTTM00 low priority */
	_SFR_PR11Lbits.TMPR100 = 1U;
	_SFR_PR01Lbits.TMPR000 = 1U;
	/* Set INTTM01 low priority */
	_SFR_PR11Lbits.TMPR101 = 1U;
	_SFR_PR01Lbits.TMPR001 = 1U;
	/* Set up Channel 0 of the TAU0 as Interval Timer */
	_SFR_TMR00 = 0U;/* CLOCK_SELECT_CKM0 CLOCK_MODE_CKS COMBINATION_SLAVE TRIGGER_SOFTWARE
						MODE_INTERVAL_TIMER START_INT_UNUSED */
	_SFR_TDR00 = 0x0C7Fu;
	_SFR_TO0 &= ~(0x1u);
	_SFR_TOE0 &= ~(0x01u);/* Disable Timer Channel 0 Output */
	_SFR_NFEN1 &= (uint8_t)~(0x02) /* disable using noise filter of TI01 pin input signal */
	 /* Set TI01 pin */
    _SFR_PM1 |= 0x40U;
}

/***********************************************************************************************************************
* Function Name: R_TAU0_Channel0_Start
* Description  : This function starts TAU0 channel 0 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_Channel0_Start(void)
{
    _SFR_IF1Lbits.TMIF00 = 0U;    /* clear INTTM00 interrupt flag */
    _SFR_MK1Lbits.TMMK00 = 0U;    /* enable INTTM00 interrupt */
    _SFR_TS0 |= _0001_TAU_CH0_START_TRG_ON;
}

/***********************************************************************************************************************
* Function Name: R_TAU0_Channel0_Stop
* Description  : This function stops TAU0 channel 0 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_Channel0_Stop(void)
{
    _SFR_TT0 |= _0001_TAU_CH0_STOP_TRG_ON;
    /* Mask channel 0 interrupt */
    _SFR_MK1Lbits.TMMK00 = 1U;    /* disable INTTM00 interrupt */
    _SFR_IF1Lbits.TMIF00 = 0U;    /* clear INTTM00 interrupt flag */
}

/***********************************************************************************************************************
* Function Name: R_TAU0_Channel1_Start
* Description  : This function starts TAU0 channel 1 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_Channel1_Start(void)
{
    _SFR_IF1Lbits.TMIF01 = 0U;    /* clear INTTM01 interrupt flag */
    _SFR_MK1Lbits.TMMK01 = 0U;    /* enable INTTM01 interrupt */
    _SFR_TS0 |= _0002_TAU_CH1_START_TRG_ON;
}

/***********************************************************************************************************************
* Function Name: R_TAU0_Channel1_Stop
* Description  : This function stops TAU0 channel 1 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAU0_Channel1_Stop(void)
{
    _SFR_TT0 |= _0002_TAU_CH1_STOP_TRG_ON;
    /* Mask channel 1 interrupt */
    _SFR_MK1Lbits.TMMK01 = 1U;    /* disable INTTM01 interrupt */
    _SFR_IF1Lbits.TMIF01 = 0U;    /* clear INTTM01 interrupt flag */
}

/***********************************************************************************************************************
* Function Name: R_TMR_RJ0_Create
* Description  : This function initializes the TMRJ0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR_RJ0_Create(void)
{
	_SFR_PER1bits.TRJ0EN = 1U;    /* enable input clock supply */
    _SFR_TRJCR0 &= (uint8_t)~_01_TMRJ_COUNT_START;    /* disable TMRJ0 operation */
    _SFR_MK1Hbits.TRJMK0 = 1U;    /* disable INTTRJ0 interrupt */
    _SFR_IF1Hbits.TRJIF0 = 0U;    /* clear INTTRJ0 interrupt flag */
    /* Set INTTRJ0 low priority */
    _SFR_PR11Hbits.TRJPR10 = 1U;
    _SFR_PR11Lbits.TRJPR00 = 1U;
    _SFR_TRJMR0 = _00_TMRJ_MODE_TIMER | _30_TMRJ_COUNT_SOURCE_FCLK2;
    _SFR_TRJIOC0 = _00_TMRJ_TRJIOC_INITIAL_VALUE;
    TRJ0 = _3E7F_TMRJ_TRJ0_VALUE;
}

/***********************************************************************************************************************
* Function Name: R_TMR_RJ0_Start
* Description  : This function starts TMRJ0 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR_RJ0_Start(void)
{
    _SFR_IF1Hbits.TRJIF0 = 0U;    /* clear INTTRJ0 interrupt flag */
    _SFR_MK1Hbits.TRJMK0 = 0U;    /* enable INTTRJ0 interrupt */
    _SFR_TRJCR0 |= _01_TMRJ_COUNT_START;    /* enable TMRJ operation */
}

/***********************************************************************************************************************
* Function Name: R_TMR_RJ0_Stop
* Description  : This function stops TMRJ0 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR_RJ0_Stop(void)
{
    _SFR_TRJCR0 &= (uint8_t)~_01_TMRJ_COUNT_START;    /* disable TMRJ operation */
    _SFR_MK1Hbits.TRJMK0 = 1U;    /* disable INTTRJ0 interrupt */
    _SFR_IF1Hbits.TRJIF0 = 0U;    /* clear INTTRJ0 interrupt flag */
}

