/*
/*! @file Adc.h
*/
#ifndef _ADC_H
#define _ADC_H

typedef enum{
    ADCHANNEL0,
	ADCHANNEL1,
	ADCHANNEL2,
	ADCHANNEL3,
	ADCHANNEL16 = 16U,
	ADCHANNEL17,
    ADCHANNEL18,
	ADCHANNEL19,
	ADTEMPERSENSOR0 = 128U,
	ADINTERREFVOLT
} ad_channel_t;

/* Status list definition as in CG_file */
#define MD_STATUSBASE       (0x00U)
#define MD_OK               (MD_STATUSBASE + 0x00U) /* register setting OK */
#define MD_SPT              (MD_STATUSBASE + 0x01U) /* IIC stop */
#define MD_NACK             (MD_STATUSBASE + 0x02U) /* IIC no ACK */
#define MD_BUSY1            (MD_STATUSBASE + 0x03U) /* busy 1 */
#define MD_BUSY2            (MD_STATUSBASE + 0x04U) /* busy 2 */
#define MD_OVERRUN          (MD_STATUSBASE + 0x05U) /* IIC OVERRUN occur */

/* Error list definition */
#define MD_ERRORBASE        (0x80U)
#define MD_ERROR            (MD_ERRORBASE + 0x00U)  /* error */
#define MD_ARGERROR         (MD_ERRORBASE + 0x01U)  /* error agrument input error */
#define MD_ERROR1           (MD_ERRORBASE + 0x02U)  /* error 1 */
#define MD_ERROR2           (MD_ERRORBASE + 0x03U)  /* error 2 */
#define MD_ERROR3           (MD_ERRORBASE + 0x04U)  /* error 3 */
#define MD_ERROR4           (MD_ERRORBASE + 0x05U)  /* error 4 */



void ADC_Init(UInt8 Channel);
void ADC_DeInit(UInt8 Channel);
UInt16 ADC_Read(UInt16 * const buffer);

#endif