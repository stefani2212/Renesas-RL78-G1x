/*
 *! @file Adc.c
 *	@brief Definition of the ADC driver module.
 */

#include "ADC.h"
#include "iodefine.h"
#include "iodefine_ext.h"

/***************************************************************************//**
 * \fn static void ADC_INIT(UInt8 Channel)
 * \brief   The ADC Init function.
 * \details
 * \return  This function has no return value.
 * \callgraph
 * \callergraph
 ******************************************************************************/
void ADC_Init(UInt8 Channel)
{
	UInt8 status; /* Defines channel status */
	_SFR_PM2 |=0x07; /* Setup PIN for analog input mode.Pin 20.21.22 setup as input analog mode */
	_SFR_PER0bits.ADCEN = 1U; /* ADC clock enable */
	if (((Channel > ADCHANNEL3) && (Channel < ADCHANNEL16))
	 || ((Channel > ADCHANNEL19) && (Channel < ADTEMPERSENSOR0))
	 || (Channel > ADINTERREFVOLT))
		{
		status = MD_ARGERROR ;
		}
    else
		{
    _SFR_ADS = ( UInt8 )Channel;/* Specify analog input channel */
		}
	/* ADC Settings */
	/* function(INIT_ADC) developed as in ADC_application_note */
	_SFR_ADM1bits.ADSCM = 1;// A/D conversion operation mode is set to one-shot conversion mode.
	_SFR_ADM1bits.ADTMD1 = 0;// A/D conversion is started using the software trigger.
	/* Setup of A/D conversion time and operation mode */
	/* Sets conversion time */
	_SFR_ADM0bits.FR0 = 1 ;
	_SFR_ADM0bits.FR1 = 1 ;
	_SFR_ADM0bits.FR2 = 1 ;
	_SFR_ADM0bits.ADMD = 0;/* A/D conversion channel selection mode is set to select mode. */
	/* Setup of A/D conversion end operation */
	_SFR_IF1Hbits.ADIF = 0;
	_SFR_MK1Hbits.ADMK = 1;
	/* Select trigger mode
	:Software trigger mode */
	_SFR_ADM1bits.ADTMD1 = 0;
	/*  Set up reference voltage source
	 *  10-bit resolution when bit0 is set to 0 or 8-bit resolution when bit0 is set to 1
	 *  Set + side reference voltage source to AVREFP : Supplied from P20/AVREFP/ANI0
	 *  Set - side reference voltage source to AVREFM : Supplied from P21/AVREFM/ANI1
	 *  */
	_SFR_ADM2bits.ADTYP = 0;
	_SFR_ADM2bits.ADREFP0 = 1;
	_SFR_ADM2bits.ADREFP1 = 0;
	_SFR_ADM2bits.ADREFM = 1;
	/*  Set up upper/lower limit of conversion result
	 *  comparison
 	 *  */
	_SFR_ADUL = 0xFF;//Set upper limit comparison to FFH
	_SFR_ADLL = 0x00;//Set lower limit comparison to 00H

	/* additional settings : CompareVoltage */
	/* 
	_SFR_ADM0bits.ADCE = 1;//ADC_CompareVoltageEnable
	_SFR_ADM0bits.ADCE = 0;//ADC_DisableCompareVoltage 
	*/
	/*** A/D Converter registers: PER0, ADM0-2, ADCR(10bit), ADCRH(8bit), ADS, ADUL, ADLL, ADTES, ADPC
	     A/D Interrupt registers: ADIF, ADMK, ADCE-comparator enable */
}

/***************************************************************************//**
 * \fn static void ADC_DeInit(UInt8 Channel)
 * \brief   The ADC DeInit function.
 * \parameters UInt8 Channel - channel number
 * \details
 * \return  This function has no return value.
 * \callgraph
 * \callergraph
 ******************************************************************************/
void ADC_DeInit(UInt8 Channel) {
	_SFR_ADM0bits.ADCS = 0U;  /* disable AD conversion */
	_SFR_MK1Hbits.ADMK = 1U;  /* disable INTAD interrupt */
	_SFR_IF1Hbits.ADIF = 0U;  /* clear INTAD interrupt flag */
}

/***************************************************************************//**
 * \fn static UInt16 ADC_Read(UInt16 *const buffer)
 * \brief   The ADC Read function.
 * \parameters UInt8 * const buffer - where the read data is stored
 * \details
 * \return  This function returns the data read into the ADCR register.
 * \callgraph
 * \callergraph
 ******************************************************************************/
UInt16 ADC_Read(UInt16 * const buffer) {
	return *buffer = (UInt16)(ADCR>>6);
}
