/*! @file Uart.c
 *
    @brief Definition of the Uart driver module.
*/
#include "UART.h"
#include "iodefine.h"
#include "iodefine_ext.h"
#include "Std_Types.h"


#define UART_RX_BUF_SIZE		(128u)
#define UART_TX_BUF_SIZE		(128u)



/*! \def UART_TOTAL_NUMBER_OF_CHANNELS
    \brief Defines the amount of channels the driver handles.
    */
#define UART_TOTAL_NUMBER_OF_CHANNELS (3u) 

#define Un0		( 0u ) 
#define Un1 	( 1u ) 
#define Un2 	( 2u ) 

#define UART_TX_BUF_SIZE_MASK                   (UART_TX_BUF_SIZE - 1u)
#if (UART_TX_BUF_SIZE & UART_TX_BUF_SIZE_MASK)
#error UART_TX_BUF_SIZE is not power of 2
#endif

#define UART_RX_BUF_SIZE_MASK                   (UART_RX_BUF_SIZE - 1u)
#if (UART_RX_BUF_SIZE & UART_RX_BUF_SIZE_MASK)
#error UART_RX_BUF_SIZE is not power of 2
#endif

/* Local Prototypes */
 UInt16 Uart_GetRxQueueLevel(UInt8 Channel);
 UInt16 Uart_GetTxQueueLevel(UInt8 Channel);

/*! \struct Un_DataType
    \brief The Uart data type instance definition.
 */
 typedef struct
{
    UInt16 u16RxBuff[UART_RX_BUF_SIZE];   /**< The RX data buffer */
    UInt16 u16TxBuff[UART_TX_BUF_SIZE];   /**< The TX data buffer */
    UInt16 u16TxHead;   /**< Holds the head within TX buffer */
    UInt16 u16TxTail;   /**< Holds the tail within TX buffer */
    UInt16 u16RxHead;   /**< Holds the head within RX buffer */
    UInt16 u16RxTail;   /**< Holds the tail within RX buffer */
    UInt32 u32PbClk;    /**< Holds the peripheral bus clock */
    UInt32 u32BaudRate; /**< Holds the peripheral baud rate */
    BOOL bRts;          /**< Holds the actual RTS status */
    void (*pfRTSCtl)(BOOL);     /**< A pointer to function that control the RTS status */
    UInt8 u8BootByteLast;   /**< Used for enter boot request bytes sequence identifier. Holds the latest received byte. */
    UInt8 u8BootByteCount;  /**< Used for enter boot request bytes sequence identifier. Holds the number of bytes the sequence is expected. */
} Un_DataType;

/*! \var static Un_DataType Un_Inst[ UART_TOTAL_NUMBER_OF_CHANNELS ]
    \brief The Uart instances declaration.
 */
static Un_DataType Un_Inst[ UART_TOTAL_NUMBER_OF_CHANNELS ];

/***************************************************************************//**
 * \fn static void INT_ST0(void)
 * \brief  Describes UART0 transmission transfer end or buffer empty interrupt
 * \details Transfer end interrupt (in single-transfer mode) or buffer empty interrupt 
 *  (in continuous transfer mode) can be selected.
 * \return  This function has no return value.
 * \callgraph
 * \callergraph
 ******************************************************************************/
void INT_ST0(void) {
	UART0_IRQHandler();
}

/***************************************************************************//**
 * \fn static void INT_SR0(void)
 * \brief  Describes UART0 reception transfer end
 * \details
 * \return  This function has no return value.
 * \callgraph
 * \callergraph
 ******************************************************************************/
void INT_SR0(void) {
	UART0_IRQHandler();
}

/***************************************************************************//**
 * \fn static void INT_SRE0(void)
 * \brief  Describes UART0 reception communication error occurrence
 * \details
 * \return  This function has no return value.
 * \callgraph
 * \callergraph
 ******************************************************************************/
void INT_SRE0(void) {
	UART0_IRQHandler();
}

/***************************************************************************//**
 * \fn static void INT_ST1(void)
 * \brief  Describes UART1 transmission transfer end or buffer empty interrupt
 * \details Transfer end interrupt (in single-transfer mode) or buffer empty interrupt 
 *  (in continuous transfer mode) can be selected.
 * \return  This function has no return value.
 * \callgraph
 * \callergraph
 ******************************************************************************/
void INT_ST1(void) {
	UART1_IRQHandler();
}

/***************************************************************************//**
 * \fn static void INT_SR1(void)
 * \brief  Describes UART1 reception transfer end
 * \details
 * \return  This function has no return value.
 * \callgraph
 * \callergraph
 ******************************************************************************/
void INT_SR1(void) {
	UART1_IRQHandler();
}

/***************************************************************************//**
 * \fn static void INT_SRE1(void)
 * \brief  Describes UART0 reception communication error occurrence
 * \details
 * \return  This function has no return value.
 * \callgraph
 * \callergraph
 ******************************************************************************/
void INT_SRE1(void) {
	UART1_IRQHandler();
}

/***************************************************************************//**
 * \fn static void INT_ST2(void)
 * \brief  Describes UART2 transmission transfer end or buffer empty interrupt
 * \details Transfer end interrupt (in single-transfer mode) or buffer empty interrupt 
 *  (in continuous transfer mode) can be selected.
 * \return  This function has no return value.
 * \callgraph
 * \callergraph
 ******************************************************************************/
void INT_ST2(void) {
	UART2_IRQHandler();
}

/***************************************************************************//**
 * \fn static void INT_SR2(void)
 * \brief  Describes UART2 reception transfer end
 * \details
 * \return  This function has no return value.
 * \callgraph
 * \callergraph
 ******************************************************************************/
void INT_SR2(void) {
	UART2_IRQHandler();
}

/***************************************************************************//**
 * \fn static void INT_SRE2(void)
 * \brief  Describes UART2 reception communication error occurrence
 * \details
 * \return  This function has no return value.
 * \callgraph
 * \callergraph
 ******************************************************************************/
void INT_SRE2(void) {
	UART2_IRQHandler();
}

/***************************************************************************//**
 * \fn static void UART0_IRQHandler(void)
 * \brief   The UART0 ISR.
 * \details
 * \return  This function has no return value.
 * \callgraph
 * \callergraph
 ******************************************************************************/
static void UART0_IRQHandler(void)
{
	UInt16 lu16_SSR = _SFR_SSR00;//status register
	UInt16 lu16_SDR = _SFR_SDR00;//data register
	
	/* UART parity error interrupt occurred ------------------------------------- */
	//Error detection flag : Parity error detection flag (PEFmn)
	if( lu16_SSR & lu16_SDR ){
		_SFR_SIR00bits.PECT = 1;
	}
	/* UART frame error interrupt occurred -------------------------------------- */
	if( lu16_SSR & lu16_SDR ){
	//clear condition• 1 is written to the FECTmn bit of the SIRmn register.
		_SFR_SIR00bits.FECT = 1;
	}
	/* UART noise error interrupt occurred -------------------------------------- */
	if( lu16_SSR & lu16_SDR ){
		_SFR_NFEN0bits.SNFEN00 = 1;
    }
	/* UART Over-Run interrupt occurred ----------------------------------------- */
	if( lu16_SSR & lu16_SDR ){
		_SFR_SIR00bits.OVCT = 1;
	}
	/* UART RX-NotEmpty interrupt occurred -------------------------------------- */
	if( lu16_SSR & lu16_SDR ){
		Un_RxISR( Un0,lu16_SDR );
	}
	/* ########################################################################## */
	/* ################################### */
	// Based on number of bytes in TxFifo, Un_TxISR, shall enable the TXE or TXC interrupt.
	/* UART TX-Empty interrupt occurred ----------------------------------------- */
	if( lu16_SSR & lu16_SDR ){
		//INT_ST0(void);
		Un_TxISR( Un0 );
	}
	/* UART TX-Complete interrupt occurred -------------------------------------- */
	if( lu16_SSR & lu16_SDR ){
		_SFR_MK0Hbits.STMK0 = 0;/*!!! check on debugging clear INTST0 flag*/
	}
}

/***************************************************************************//**
 * \fn static void UART1_IRQHandler(void)
 * \brief   The UART1 ISR.
 * \details
 * \return  This function has no return value.
 * \callgraph
 * \callergraph
 ******************************************************************************/
static void UART1_IRQHandler(void)
{
	UInt16 lu16_SSR = _SFR_SSR01;//status register
	UInt16 lu16_SDR = _SFR_SDR01;//data register

	/* UART parity error interrupt occurred ------------------------------------- */
	//Error detection flag : Parity error detection flag (PEFmn)
	if( lu16_SSR & lu16_SDR ){
		_SFR_SIR01bits.PECT = 1;} 
	/* UART frame error interrupt occurred -------------------------------------- */
	if( lu16_SSR & lu16_SDR ){
		_SFR_SIR01bits.FECT = 1;}
	/* UART noise error interrupt occurred -------------------------------------- */
	if(lu16_SSR & lu16_SDR){
		_SFR_NFEN0bits.SNFEN10 = 1;}
	/* UART Over-Run interrupt occurred ----------------------------------------- */
	if( lu16_SSR & lu16_SDR ){
		_SFR_SIR01bits.OVCT = 1;}
	/* UART RX-NotEmpty interrupt occurred -------------------------------------- */
	if( lu16_SSR & lu16_SDR ){
		Un_RxISR( Un1,lu16_SDR);}
	/* ########################################################################## */
	/* ################################### */
	// Based on number of bytes in TxFifo, Un_TxISR, shall enable the TXE or TXC interrupt.
	/* UART TX-Empty interrupt occurred ----------------------------------------- */
	if( lu16_SSR & lu16_SDR ){
		//INT_ST1(void);
		 Un_TxISR( Un1 );
	}
	/* UART TX-Complete interrupt occurred -------------------------------------- */
	if( lu16_SSR & lu16_SDR ){
		_SFR_MK1Lbits.STMK1 = 0;/*!!! check on debugging clear INTST0 flag*/	
		}
}

/***************************************************************************//**
 * \fn static void UART2_IRQHandler(void)
 * \brief   The UART2 ISR.
 * \details
 * \return  This function has no return value.
 * \callgraph
 * \callergraph
 ******************************************************************************/
static void UART2_IRQHandler(void) {
	
	UInt16 lu16_SSR = _SFR_SSR02;//status register
	UInt16 lu16_SDR = _SFR_SDR02;//data register
	
	/* UART parity error interrupt occurred ------------------------------------- */
	//Error detection flag : Parity error detection flag (PEFmn)
	if( lu16_SSR & lu16_SDR ){
		_SFR_SIR02bits.PECT = 1;} 
	/* UART frame error interrupt occurred -------------------------------------- */
	if( lu16_SSR & lu16_SDR ){
		_SFR_SIR02bits.FECT = 1;}
	/* UART noise error interrupt occurred -------------------------------------- */
	if(lu16_SSR & lu16_SDR){
		_SFR_NFEN0bits.SNFEN20 = 1;}
	/* UART Over-Run interrupt occurred ----------------------------------------- */
	if( lu16_SSR & lu16_SDR ){
		_SFR_SIR02bits.OVCT = 1;}
	/* UART RX-NotEmpty interrupt occurred -------------------------------------- */
	if( lu16_SSR & lu16_SDR ){
		Un_RxISR( Un2,lu16_SDR);}
	/* ########################################################################## */
	/* ################################### */
	// Based on number of bytes in TxFifo, Un_TxISR, shall enable the TXE or TXC interrupt.
	/* UART TX-Empty interrupt occurred ----------------------------------------- */
	if( lu16_SSR & lu16_SDR ){
		//INT_ST2(void);
		 Un_TxISR( Un2 );
	}
	/* UART TX-Complete interrupt occurred -------------------------------------- */
	if( lu16_SSR & lu16_SDR ){
		_SFR_MK0Hbits.STMK2 = 0;/*!!! check on debugging clear INTST2 flag*/
	}
}

 /**************************************************!
 *fn void UART_INIT(void)-Initialization of UART0
 *\brief The UART initialization fct.
 *\details:Datasheet Description:
 *Full-duplex UART communication:00-Tx 01-Rx 
 *Steps:Clock supply to SAU,Serial clock selection(SPS0),
 *		Stop operations of channel 0 and 1,
 *		UART0 interrupt disabled,
 *		Channel 0 operation mode setup,
 *		Channel 1 operation mode setup,
 *		Channel 0 communication operation setup,
 *		Channel 1 communication operation setup,
 *		Transfer rate setup of channel 1 and 0,
 *		Noise filter setup,Set up the output level as non-inverted,
 *		Initialization of channel 0 output (TxD0),
 *		Enable channel 0 output,
 *		Clear of error flag,
 *		Port setup.
 *Preset BR:9600bps(SDRmn reg to config in order to calc the desired baud rate)
 *	    fCLK:20MHz
 *	    (Baud rate) = {Operation clock (fMCK) frequency of target channel} ÷ (SDRmn[15:9] + 1) ÷ 2 [bps]
 *      fCLK/BR=208-2=>206(CE00)      0xAB  
 *		Divisor Value:CE00 <=>206
 *\no return
 ****************************************************
 ****************************************************/
void UART_INIT(UInt8 Channel, UInt32 PbClk, UInt32 BaudRate)
{
 if ( UART_TOTAL_NUMBER_OF_CHANNELS > Channel )
  {
	Un_Inst[Channel].u32PbClk=PbClk;
	Un_Inst[Channel].u32BaudRate=BaudRate;
	Un_Inst[Channel].u8BootByteCount=50u;

/* Clock Enable */
	_SFR_PER0bits.SAU0EN = 1U;/* Serial Array Unit supply SAU0 clock *///check if SAU0 enables all channels 
	_SFR_SPS  = 0x44U; /* SPS:serial_clock_select_register Channel 0 Clock enabled */
	switch ( Channel )
		 {
	case Un0:/* Channel 0,1  of SAU0 */
/* Disable Rx & Tx */
	_SFR_ST0bits.ST00 = 1; /* ST0:serial_channel_stop_register Disable Rx & Tx */
	_SFR_ST0bits.ST01 = 1;
	_SFR_SCR00bits.TXE = 0;//disable tx
	_SFR_SCR01bits.RXE = 0;//disable rx
/* Uart_Settings
	* Implementing:
	*  2-wire connection:FULL_DUPLEX(00-as Tx & 01 as Rx)
	*  1 stop_bit,
	*  lsb,
	*  8bit-data-length,
	*  no parity			  */
   /* Default baud rate:9600 */
/* Transmission only */
	_SFR_SCR00bits.TXE = 1; //•settings for transmission•/
	_SFR_SCR00bits.DLS0 = 1;/* 8-bit data length */
	_SFR_SCR00bits.DLS1 = 1;
	_SFR_SCR00bits.SLC0 = 1;/*Stop bit length = 1 bit*/
	_SFR_SCR00bits.PTC0 = 0;/*no parity bit*/
	_SFR_SCR00bits.PTC1 = 0;
	_SFR_SCR00bits.DIR = 1;/*lsb-start bit*/
	_SFR_SCR00bits.EOC = 1;/*enables generation of error interrupt INTSREx*/
	_SFR_SDR00 =_CE00_UART0_TRANSMIT_DIVISOR;
/*	brVar : variable to store the hexa value of the SDRmn upper byte register
	assign above value to SDRmn[15:9] register.
	Serial_Data_Register [15:9] :BaudRate responsible.
	ADD.COMMENTS:9600 = 20 000 000 : 2
	9600 = 10 000 000 => x = 1041-> 10 000 000 000 ->2^9 =512
					 -> 		 2^10 = 1024	
	PbCLK ->set by SPS & CKS of SMRmn
	Selected clk :32MHz
	Target BR : 300
	CLK_Divisor: 2^9
	High_SDRmn : 103
	[[[[32Mhz/2^9]/300]/2]-1]
	Integrate above formula and assign it to SDRmn[15:9] register as a hexa value;
	[| /////////
	flags to be implemented :	*/
/* Reception only */
	_SFR_SCR01bits.RXE = 1; //•settings for reception•/
	_SFR_SCR01bits.DLS0 = 1;/* 8-bit data length */
	_SFR_SCR01bits.DLS1 = 1;
	_SFR_SCR01bits.SLC0 = 1;/*Stop bit length = 1 bit*/
	_SFR_SCR01bits.PTC0 = 0;/*no parity bit*/
	_SFR_SCR01bits.PTC1 = 0;
	_SFR_SCR01bits.DIR = 1;/*lsb-start bit*/
	_SFR_SCR01bits.EOC = 1;/*enables generation of error interrupt INTSREx*/
	_SFR_SDR01 = _CE00_UART0_RECEIVE_DIVISOR;
/* Baud Rate Settings */
	/*12.6.4 Calculating baud rate of hardware manual.
	(Baud rate) = {Operation clock (fMCK) frequency of target channel} ÷ (SDRmn[15:9] + 1) ÷ 2 [bps]
	for 115200 bps with 24MHz clock :
	115200 = 24*1000*1000 / (x + 1) / 2 -> x + 1 = 24*1000*1000 / 2 / 115200 -> x ~= 103
	so you need to write value 103 to bits 9:15 of SDR register
	SDRxy = 103U <*/
	/* describe baud rate formula in order to input a BR value as fct param.
	BaudRate =(UInt32)()
	##
	SDR02 = 0x88; /*Set baud rate frequency for 115 200bps */
	/*16 000 000Mhz/115 200bps = 138.8 = 138 counts ==> 
	transforming into register number 138-2=136. 
	Shifting LSB to zero = 0x88
	Start configuration of UART RX
	######Baud Rate & CLK (set it up to 1
	## 
	*/
	SDRBaudRate = ((PbClk>>n)/(BaudRate>>1))-1;//n - clk divisor
	/*##SDR register SDRLow : shift register & SDRHigh :BR register 
	_SFR_SDRmn = SDRBaudRate ->converted to hexa
	*/
/*Enable Receiver & Transmitter*/
	SS0  |= _0002_SAU_CH1_START_TRG_ON | _0001_SAU_CH0_START_TRG_ON;    /* enable UART0 receive and transmit */
	/*!!!!*/SO0  |= _0001_SAU_CH0_DATA_OUTPUT_1; /*Enable Rx & Tx Buffer*///Check datasheet SO0->bit0, for enabling rx&tx
	SOE0 |= _0001_SAU_CH0_OUTPUT_ENABLE; /*Enable UART0 output */
	SOL0 |= _0000_SAU_CHANNEL0_NORMAL;   /*Output level normal */
/*Enable Rx & TX Interrupts
	STMK0 = 1U;  disable INTST0 interrupt
	STIF0= 0U;   clear INTST0 interrupt flag
	SRMK0 = 1U;  disable INTSR0 interrupt
	SRIF0 = 0U;  clear INTSR0 interrupt flag 	*/
/* Set RxD0 pin */
   /* PM5 |= 0x01U;
     Set TxD0 pin
    P5 |= 0x02U;
    PM5 &= 0xFDU;*/
break;
	case Un1:/*Channel 2,3 of SAU0*/
/*Disable Rx & Tx*/
	_SFR_ST0bits.ST02 = 1; /*ST0:serial_channel_stop_register Disable Rx & Tx*/
	_SFR_ST0bits.ST03 = 1;
	_SFR_SCR02bits.TXE = 0;//disable tx
	_SFR_SCR03bits.RXE = 0;//disable rx
	/*Uart_Settings
	 * Implementing:2-wire connection:FULL_DUPLEX(02-as Tx & 03 as Rx)
	 * 1 stop_bit,
	 *  lsb,
	 *  8bit-data-length,
	 *   no parity.*/
	/*Default baud rate:9600*/
/* Transmission only */
	_SFR_SCR02bits.TXE = 1; //•settings for transmission•/
	_SFR_SCR02bits.DLS0 = 1;/* 8-bit data length */
	_SFR_SCR02bits.DLS1 = 1;
	_SFR_SCR02bits.SLC0 = 1;/*Stop bit length = 1 bit*/
	_SFR_SCR02bits.PTC0 = 0;/*no parity bit*/
	_SFR_SCR02bits.PTC1 = 0;
	_SFR_SCR02bits.DIR = 1;/*lsb-start bit*/
	_SFR_SCR02bits.EOC = 1;/*enables generation of error interrupt INTSREx*/
	_SFR_SDR02|=_CE00_UART1_TRANSMIT_DIVISOR;
/* Reception only */
	_SFR_SCR03bits.RXE = 1; //•settings for reception•/
	_SFR_SCR03bits.DLS0 = 1;/* 8-bit data length */
	_SFR_SCR03bits.DLS1 = 1;
	_SFR_SCR03bits.SLC0 = 1;/*Stop bit length = 1 bit*/
	_SFR_SCR03bits.PTC0 = 0;/*no parity bit*/
	_SFR_SCR03bits.PTC1 = 0;
	_SFR_SCR03bits.DIR = 1;/*lsb-start bit*/
	_SFR_SCR03bits.EOC = 1;/*enables generation of error interrupt INTSREx*/
	_SFR_SDR03 = _CE00_UART1_RECEIVE_DIVISOR;
	/*Baud Rate Settings*/
	/*12.6.4 Calculating baud rate of hardware manual.
	(Baud rate) = {Operation clock (fMCK) frequency of target channel} ÷ (SDRmn[15:9] + 1) ÷ 2 [bps]
	for 115200 bps with 24MHz clock :
	115200 = 24*1000*1000 / (x + 1) / 2 -> x + 1 = 24*1000*1000 / 2 / 115200 -> x ~= 103
	so you need to write value 103 to bits 9:15 of SDR register
	SDRxy = 103U <*/
					/* describe baud rate formula in order to input a BR value as fct param.
					BaudRate =(UInt32)() ;
	*//*Enable Receiver & Transmitter*/
	SS0  |= _0008_SAU_CH3_START_TRG_ON | _0004_SAU_CH2_START_TRG_ON;    /* enable UART1 receive and transmit */
/*!!!!*/SO0  |= _0004_SAU_CH2_DATA_OUTPUT_1; /*Enable Rx & Tx Buffer*///Check datasheet SO0->bit2,3 for enabling rx&tx
/*!!!!*/SOE0 |=  _0004_SAU_CH2_OUTPUT_ENABLE ; /*Enable UART1 output *///Check datasheet SO0->bit2,3 for enabling rx&tx
	SOL0 |= _0000_SAU_CHANNEL2_NORMAL;   /*Output level normal */
/*Enable Rx & TX Interrupts
	STMK0 = 1U;  disable INTST0 interrupt
	STIF0= 0U;   clear INTST0 interrupt flag
	SRMK0 = 1U;  disable INTSR0 interrupt
	SRIF0 = 0U;  clear INTSR0 interrupt flag 	*/
 /* Set RxD1 pin */
	/*PMC0 &= 0xFDU;
	PM0 |= 0x02U;
	 Set TxD1 pin
	PMC0 &= 0xFEU;
	P0 |= 0x01U;
	PM0 &= 0xFEU;*/
break;
	case Un2:/*Channel 0,1 of SAU1*/
	/*Disable Rx & Tx*/
	_SFR_ST1bits.ST10 = 1;/*ST1:serial_channel_stop_register Disable Rx & Tx*/
	_SFR_ST1bits.ST11 = 1;
	_SFR_SCR10bits.TXE = 0;//disable tx
	_SFR_SCR11bits.RXE = 0;//disable rx
	/*Uart_Settings
	 * Implementing:2-wire connection:FULL_DUPLEX(02-as Tx & 03 as Rx)
	 * 1 stop_bit,
	 *  lsb,
	 *  8bit-data-length,
	 *   no parity.*/
	/*Default baud rate:9600*/
/* Transmission only */
	_SFR_SCR10bits.TXE = 1; //•settings for transmission•/
	_SFR_SCR10bits.DLS0 = 1;/* 8-bit data length */
	_SFR_SCR10bits.DLS1 = 1;
	_SFR_SCR10bits.SLC0 = 1;/*Stop bit length = 1 bit*/
	_SFR_SCR10bits.PTC0 = 0;/*no parity bit*/
	_SFR_SCR10bits.PTC1 = 0;
	_SFR_SCR10bits.DIR = 1;/*lsb-start bit*/
	_SFR_SCR10bits.EOC = 1;/*enables generation of error interrupt INTSREx*/
	_SFR_SDR10|=_CE00_UART2_TRANSMIT_DIVISOR;
/* Reception only */
	_SFR_SCR11bits.RXE = 1; //•settings for reception•/
	_SFR_SCR11bits.DLS0 = 1;/* 8-bit data length */
	_SFR_SCR11bits.DLS1 = 1;
	_SFR_SCR11bits.SLC0 = 1;/*Stop bit length = 1 bit*/
	_SFR_SCR11bits.PTC0 = 0;/*no parity bit*/
	_SFR_SCR11bits.PTC1 = 0;
	_SFR_SCR11bits.DIR = 1;/*lsb-start bit*/
	_SFR_SCR11bits.EOC = 1;/*enables generation of error interrupt INTSREx*/
	_SFR_SDR11 = _CE00_UART2_RECEIVE_DIVISOR;
	/*Baud Rate Settings*/
	/*12.6.4 Calculating baud rate of hardware manual.
	(Baud rate) = {Operation clock (fMCK) frequency of target channel} ÷ (SDRmn[15:9] + 1) ÷ 2 [bps]
	for 115200 bps with 24MHz clock :
	115200 = 24*1000*1000 / (x + 1) / 2 -> x + 1 = 24*1000*1000 / 2 / 115200 -> x ~= 103
	so you need to write value 103 to bits 9:15 of SDR register
	SDRxy = 103U <*/
					/* describe baud rate formula in order to input a BR value as fct param.
					BaudRate =(UInt32)() ;*/
/* Enable Receiver & Transmitter*/ //CHECK THESE REGS!!!!!
	SS1  |= _0002_SAU_CH1_START_TRG_ON | _0001_SAU_CH0_START_TRG_ON;    /* enable UART0 receive and transmit */
	/*!!!!*/SO1  |= _0001_SAU_CH0_DATA_OUTPUT_1; /*Enable Rx & Tx Buffer*///Check datasheet SO1->bit0, for enabling rx&tx
	SOE1 |= _0002_SAU_CH1_OUTPUT_ENABLE; /*Enable UART0 output */
	SOL1 |= _0000_SAU_CHANNEL2_NORMAL;   /*Output level normal */
/* Enable Rx & TX Interrupts
	STMK0 = 1U;  disable INTST0 interrupt
	STIF0= 0U;   clear INTST0 interrupt flag
	SRMK0 = 1U;  disable INTSR0 interrupt
	SRIF0 = 0U;  clear INTSR0 interrupt flag 	*/
/* Set RxD2 pin */
	/*PM1 |= 0x10U;
	 Set TxD2 pin
	P1 |= 0x08U;
	PM1 &= 0xF7U;*/
	break;
default:
break;
		}
  }
}	

/**************************************************!
 *fn void UART_DEINIT(UInt8 Channel)
 *\brief The UART deinitialization fct.
 *\details no return function.Disables the UART0 channel
****************************************************
****************************************************/
void UART_DEINIT(UInt8 Channel)
{
	switch(Channel)
	{
		case Un0:
	//DeInit Channel 0
	_SFR_ST0bits.ST00 = 1U;/*Disable Rx & Tx*/
	_SFR_ST0bits.ST00 = 1U;
	_SFR_MK1Lbits = 1U; /* disable INTST0 interrupt */
	_SFR_IF0Hbits.STIF0 = 0U; /* clear INTST0 interrupt flag */
	_SFR_MK0Hbits.SRMK0 = 1U; /* disable INTSR0 interrupt */
	_SFR_IF0Hbits.SRIF0 = 0U; /* clear INTSR0 interrupt flag */
	break;
		case Un1:
	//DeInit Channel 1
	_SFR_ST0bits.ST02 = 1U;/*Disable Rx & Tx*/
	_SFR_ST0bits.ST03 = 1U;
	_SFR_MK1Lbits.STMK1 = 1U; /* disable INTST1 interrupt */
	_SFR_IF1Lbits.STIF1 = 0U; /* clear INTST1 interrupt flag */
	_SFR_MK1Lbits.SRMK1 = 1U; /* disable INTSR1 interrupt */
	_SFR_IF1Lbits.SRIF1 = 0U; /* clear INTSR1 interrupt flag */
	break;
		case Un2:
	//DeInit Channel 2
	_SFR_ST1bits.ST10 = 1U;/*Disable Rx & Tx*/
	_SFR_ST1bits.ST11 = 1U;
	_SFR_MK0Hbits.STMK2 = 1U; /* disable INTST2 interrupt */
	_SFR_IF0Hbits.STIF2 = 0U; /* clear INTST2 interrupt flag */
	_SFR_MK0Hbits.SRMK2 = 1U; /* disable INTSR2 interrupt */
	_SFR_IF0Hbits.SRIF2 = 0U; /* clear INTSR2 interrupt flag */
	break;
	default:
	break;
	}
}

/***************************************************************************//**
 * \fn void Uart_Read(UInt8 Channel, UInt8* lpBuffer, UInt8 nNumberOfBytesToRead, UInt8* lpNumberOfBytesRead)
 * \brief
 *	 Reading Data
 * \details
 *
 * \param[in] Channel - Identifies the peripheral instance.
 *
 * \param[in] lpBuffer - The buffer where data shall be read.
 *
 * \param[in] nNumberOfBytesToRead - The number of bytes to read.
 *
 * \param[out] lpNumberOfBytesRead - The number of bytes successfully read.
 *
 * \return
 * 	 This function has no return value.
 * \callgraph
 * \callergraph
 ******************************************************************************/
void UART_READ(UInt8 Channel,UInt8* lpBuffer, UInt8 nNumberOfBytesToRead, UInt8* lpNumberOfBytesRead)
{
	UInt8  *pBuff = NULL_PTR;
	UInt16 *pHead = NULL_PTR;
	UInt16 *pTail = NULL_PTR;
	
	/* Check if given channel is correct. Each channel have one structure assigned so pick the correct one  */
	if ( UART_TOTAL_NUMBER_OF_CHANNELS > Channel) {// Check whether invalid data was requested or not
		if ( (NULL_PTR != lpBuffer) && (NULL_PTR != lpNumberOfBytesRead) ){
		   *lpNumberOfBytesRead = 0u;
		   while ( (*pHead != *pTail) && (0u < nNumberOfBytesToRead) )
		   {
			   *pTail = (UInt16)((*pTail + 1u) & UART_RX_BUF_SIZE_MASK);
			   *lpBuffer++ = pBuff[*pTail];
			   nNumberOfBytesToRead--;
			   (*lpNumberOfBytesRead)++;
		   }
	   }
	}
}

 /***************************************************************************//**
 * \fn void Uart_Write(UInt8 Channel, const UInt8* lpBuffer, UInt8 nNumberOfBytesToWrite,
 UInt8* lpNumberOfBytesWritten)
 * \brief
 *	 Writing Data
 * \details
 *
 * \param[in] Channel - Identifies the peripheral instance.
 *
 * \param[in] lpBuffer - The buffer where data shall be written.
 *
 * \param[in] nNumberOfBytesToWrite - The number of bytes to write.
 *
 * \param[out] lpNumberOfBytesWritten - The number of bytes successfully written.
 *
 * \return
 * 	 This function has no return value.
 * \callgraph
 * \callergraph
 ******************************************************************************/
void Uart_Write(UInt8 Channel, const UInt8* lpBuffer,
		UInt8 nNumberOfBytesToWrite, UInt8* lpNumberOfBytesWritten)
{
	UInt8 lb_Cond = 1u;
	UInt16 lu16_Head = 0u;
	UInt8  *pBuff = NULL_PTR;
	UInt16 *pHead = NULL_PTR;
	UInt16 *pTail = NULL_PTR;
	UInt16 *pStatusReg = NULL_PTR;
	UInt16 *pTxDataReg = NULL_PTR;
	UInt32 lu32_Un_STATUS_TXBL_MASK = 0ul;

//Head Ptr updated. Grab the byte & update the buffer
do {
	lu16_Head = (UInt16)((*pHead + 1u) & UART_TX_BUF_SIZE_MASK);
	if ( *pTail != lu16_Head ) {
		*pHead = lu16_Head;/* Update It */
		pBuff[lu16_Head] = *lpBuffer++;
		(*lpNumberOfBytesWritten)++;
		nNumberOfBytesToWrite--;
	}
	else {
		lb_Cond = 0u;
		}
}while ( (0u != lb_Cond) && (0u < nNumberOfBytesToWrite) );
	pStatusReg=(UInt16*)&_SFR_SSR00;
	pTxDataReg=(UInt16*)&_SFR_SDR00;
	/*Once the status & data registers are initialized check if data is ready to be transmitted */
	lu32_Un_STATUS_TXBL_MASK = ;
  while ( (*pHead != *pTail) && (0ul != (*pStatusReg & lu32_Un_STATUS_TXBL_MASK)) ) {
		*pTail = (UInt16)((*pTail + 1u) & UART_TX_BUF_SIZE_MASK);
		*pTxDataReg = pBuff[*pTail];
	}
  if ( *pHead != *pTail ) {
	_SFR_MK0Hbits.SRMK0=0u;/*!!!Check Registers on debugging enable INTSR0 interrupt */
  }else {
	_SFR_MK0Hbits.STMK0=0u;/*!!!Check Registers on debugging enable INTST0 interrupt */}		
}

/***************************************************************************//**
 * \fn void Un_RxISR(UInt8 Channel, UInt8 Data)
 * \brief
 * This function shall be called from interrupt.
 * It reads from serial port 1 byte and then push it back to the buffer within data structure.
 * \details
 *
 * \param[in] Channel - Identifies the peripheral instance.
 *
 * \param[in] Data - Defines the data character passed from interrupt routine.
 *
 * \return
 *   This function has no return value.
 * \callgraph
 * \callergraph
 ******************************************************************************/
static void Un_RxISR(UInt8 Channel, UInt16 Data)
{
	UInt16 *pBuff = NULL_PTR;
	UInt16 *pHead = NULL_PTR;
	UInt16 *pTail = NULL_PTR;
	UInt16 lu16_Head = 0u;
	UInt16 lu16_Un_STATUS_TXBL_MASK = 0ul;
	// Check if given channel is correct. Each channel have one structure assigned so pick the correct one
	if ( UART_TOTAL_NUMBER_OF_CHANNELS > Channel) {
	//Assign initial values
		pHead = &Un_Inst[Channel].u16RxHead;
		pTail = &Un_Inst[Channel].u16RxTail;
		pBuff = Un_Inst[Channel].u16RxBuff;

	//Head Ptr updated. Grab the byte & update the buffer
	lu16_Head = (UInt16) ((*pHead + 1u) & UART_RX_BUF_SIZE_MASK);
	//if Tail != Head ,update head with new value and update value in the Buffer
	if (*pTail != lu16_Head) {
		*pHead = lu16_Head;
		pBuff[lu16_Head] = Data;
	}
 }
}

/***************************************************************************//**
 * \fn void Un_TxISR(UInt8 Channel)
 * \brief
 *	 This is the function used to send data via UART.
 * \details
 *
 * \param[in] Channel - Identifies the peripheral instance.
 *
 * \return
 *   This function has no return value.
 * \callgraph
 * \callergraph
 ******************************************************************************/
static void Un_TxISR(UInt8 Channel)
{
	UInt16 *pBuff = NULL_PTR;
	UInt16 *pHead = NULL_PTR;
	UInt16 *pTail = NULL_PTR;
	UInt16 *pStatusReg = NULL_PTR;
	UInt16 *pTxDataReg = NULL_PTR;
	UInt16 lu16_Un_STATUS_TXBL_MASK = 0ul;

 if ( UART_TOTAL_NUMBER_OF_CHANNELS > Channel) {
	pHead = &Un_Inst[Channel].u16TxHead;
	pTail = &Un_Inst[Channel].u16TxTail;
	pBuff = Un_Inst[Channel].u16TxBuff;
	/* ********************************************** */
	/* Get The Address Of STATUS And TXDATA Registers */
	/* ********************************************** */
	switch (Channel) {
case Un0:
		
	pStatusReg = (UInt16*) &_SFR_SSR00; //used extract TDRE field from status register
	pTxDataReg = (UInt16*) &_SFR_SDR01; //tx data write register
	lu16_Un_STATUS_TXBL_MASK = _SFR_IF0Hbits.STIF0;//!!!check on debugging INTST0 interrupt flag
	break;
case Un1:
		
	pStatusReg = (UInt16*) &_SFR_SSR02; //used extract TDRE field from status register
	pTxDataReg = (UInt16*) &_SFR_SDR03; //tx data write register
	lu16_Un_STATUS_TXBL_MASK = _SFR_IF1Lbits.STIF1;//!!!check on debugging INTST1 interrupt flag
	break;
case Un2:
		
	pStatusReg = (UInt16*) &_SFR_SSR10; //used extract TDRE field from status register
	pTxDataReg = (UInt16*) &_SFR_SDR11; //tx data write register
	lu16_Un_STATUS_TXBL_MASK = _SFR_IF0Hbits.STIF2;//!!!check on debugging INTST2 interrupt flag
	break;
	default:
return;
break;
	}
	/* ***********************************************************************   */
	/* Arm hardware TX Fifo until it is full or no more bytes are to be TXmited */
	/* *********************************************************************** */
	while ((*pHead != *pTail)
			&& (0ul != (*pStatusReg & lu16_Un_STATUS_TXBL_MASK))) // transmit data
	{
		*pTail = (UInt16) ((*pTail + 1u) & UART_TX_BUF_SIZE_MASK);
		*pTxDataReg = pBuff[*pTail];
	}

	/***********************************************************************************/
	/* If there are more bytes to be TXmited - enable TX Empty, otherwise TX Complete */
	/*********************************************************************************/
	  if ( *pHead != *pTail ) {
		  //If there are more bytes to be TXmited - enable TX Empty
			_SFR_MK0Hbits.SRMK0=0u;/* enable INTSR0 interrupt *///!!!check it on debugging
	  }else {
		  //else TX Complete
			_SFR_MK0Hbits.STMK0=0u;/* enable INTST0 interrupt *///!!!check it on debugging		
							  }
	  }
}

/***************************************************************************//**
 * \fn UInt16 Uart_GetRxQueueLevel(UInt8 Channel)
 * \brief
 * \details
 * \param[in] Channel
 * \return  Returns the available RX Buffer space
 * \callgraph
 * \callergraph
 ******************************************************************************/
UInt16 Uart_GetRxQueueLevel(UInt8 Channel) {

	return (Un_Inst[Channel].u16RxHead - Un_Inst[Channel].u16RxTail);

}

/***************************************************************************//**
 * \fn UInt16 Uart_GetTxQueueLevel(UInt8 Channel)
 * \brief
 * \details
 * \param[in] Channel
 * \return  Returns the available TX Buffer space
 * \callgraph
 * \callergraph
 ******************************************************************************/
UInt16 Uart_GetTxQueueLevel(UInt8 Channel) {

	return (Un_Inst[Channel].u16TxHead - Un_Inst[Channel].u16TxTail);

}


