/*! @file Uart.h
 *
*/
#ifndef _UART_H
#define _UART_H

#include "Std_Types.h"




/* UART_FUNCTIONS_PROTOTYPES */
static void UART0_IRQHandler(void);
static void UART1_IRQHandler(void);
static void UART2_IRQHandler(void);
void UART_INIT(UInt8 Channel, UInt32 PbClk, UInt32 BaudRate);
void UART_DEINIT(UInt8 Channel);
void UART_READ(UInt8 Channel,UInt8* lpBuffer, 
UInt8 nNumberOfBytesToRead, UInt8* lpNumberOfBytesRead);
void Uart_Write(UInt8 Channel, const UInt8* lpBuffer,
		UInt8 nNumberOfBytesToWrite, UInt8* lpNumberOfBytesWritten);
static void Un_RxISR(UInt8 Channel, UInt16 Data);
static void Un_TxISR(UInt8 Channel);

#endif