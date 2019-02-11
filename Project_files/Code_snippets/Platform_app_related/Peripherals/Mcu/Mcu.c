/*! @file Mcu.c
    @brief Definition of Microcontroller unit.
 */

#include "Mcu.h"
#include "iodefine.h"

/***************************************************************************//**
 * @addtogroup Peripherals
 * @{
 ******************************************************************************/

/***************************************************************************//**
 * @addtogroup Mcu
 * @brief The Microcontroller driver module
 * @{
 */

/*! \var static Mcu_ResetType rt_ResetReason
    \brief Holds the microcontroller reset reason.
 */
static Mcu_ResetType rt_ResetReason;

void Default_IRQHandler(void);

/** @cond DO_NOT_INCLUDE_WITH_DOXYGEN */
extern void PowerON_Reset(void);
/** @endcond */

void __attribute__((weak)) INT_WDTI(void);
void __attribute__((weak)) INT_LVI(void);
void __attribute__((weak)) INT_P0(void);
void __attribute__((weak)) INT_P1(void);
void __attribute__((weak)) INT_P2(void);
void __attribute__((weak)) INT_P3(void);
void __attribute__((weak)) INT_P4(void);
void __attribute__((weak)) INT_P5(void);
void __attribute__((weak)) INT_ST2(void);
void __attribute__((weak)) INT_SR2(void);
void __attribute__((weak)) INT_SRE2(void);
void __attribute__((weak)) INT_ST0(void);
void __attribute__((weak)) INT_SR0(void);
void __attribute__((weak)) INT_SRE0(void);
void __attribute__((weak)) INT_ST1(void);
void __attribute__((weak)) INT_SR1(void);
void __attribute__((weak)) INT_SRE1(void);
void __attribute__((weak)) INT_IICA0(void);
void __attribute__((weak)) INT_TM00(void);
void __attribute__((weak)) INT_TM01(void);
void __attribute__((weak)) INT_TM02(void);
void __attribute__((weak)) INT_TM03(void);
void __attribute__((weak)) INT_AD(void);
void __attribute__((weak)) INT_RTC(void);
void __attribute__((weak)) INT_IT(void);
void __attribute__((weak)) INT_KR(void);
void __attribute__((weak)) INT_ST3(void);
void __attribute__((weak)) INT_SR3(void);
void __attribute__((weak)) INT_TRJ0(void);
void __attribute__((weak)) INT_TM10(void);
void __attribute__((weak)) INT_TM11(void);
void __attribute__((weak)) INT_TM12(void);
void __attribute__((weak)) INT_TM13(void);
void __attribute__((weak)) INT_P6(void);
void __attribute__((weak)) INT_P7(void);
void __attribute__((weak)) INT_P8(void);
void __attribute__((weak)) INT_P9(void);
void __attribute__((weak)) INT_P10(void);
void __attribute__((weak)) INT_P11(void);
void __attribute__((weak)) INT_TRD0(void);
void __attribute__((weak)) INT_TRD1(void);
void __attribute__((weak)) INT_TRG(void);
void __attribute__((weak)) INT_SRE3(void);
void __attribute__((weak)) INT_IICA1(void);
void __attribute__((weak)) INT_FL(void);
void __attribute__((weak)) INT_BRK(void);

/*! \var const unsigned char Option_Bytes[]
    \brief
 */
const unsigned char Option_Bytes[]  __attribute__ ((section (".option_bytes"))) = {
	0xef, 0xff, 0xe8, 0x85
};

/*! \var const unsigned char Security_Id[]
    \brief
 */
const unsigned char Security_Id[]  __attribute__ ((section (".security_id"))) = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

/*! \var const void *HardwareVectors[]
    \brief
 */
const void *Vectors[] __attribute__ ((section (".vects"))) =
{
/* 0x00 */  PowerON_Reset,
/* 0x02 */  (void*)0xFFFF,
/* 0x04 */  INT_WDTI,
/* 0x06 */  INT_LVI,
/* 0x08 */	INT_P0,
/* 0x0A */	INT_P1,
/* 0x0C */	INT_P2,
/* 0x0E */	INT_P3,
/* 0x10 */	INT_P4,
/* 0x12 */	INT_P5,
/* 0x14 */	INT_ST2,
/* 0x16 */	INT_SR2,
/* 0x18 */	INT_SRE2,
/* 0x1A */	(void*)0xFFFF,
/* 0x1C */	(void*)0xFFFF,
/* 0x1E */	INT_ST0,
/* 0x20 */	INT_SR0,
/* 0x22 */	INT_SRE0,
/* 0x24 */	INT_ST1,
/* 0x26 */	INT_SR1,
/* 0x28 */	INT_SRE1,
/* 0x2A */	INT_IICA0,
/* 0x2C */	INT_TM00,
/* 0x2E */	INT_TM01,
/* 0x30 */	INT_TM02,
/* 0x32 */	INT_TM03,
/* 0x34 */	INT_AD,
/* 0x36 */	INT_RTC,
/* 0x38 */	INT_IT,
/* 0x3A */	INT_KR,
/* 0x3C */	INT_ST3,
/* 0x3E */	INT_SR3,
/* 0x40 */	INT_TRJ0,
/* 0x42 */	INT_TM10,
/* 0x44 */	INT_TM11,
/* 0x46 */	INT_TM12,
/* 0x48 */	INT_TM13,
/* 0x4A */	INT_P6,
/* 0x4C */	INT_P7,
/* 0x4E */	INT_P8,
/* 0x50 */	INT_P9,
/* 0x52 */	INT_P10,
/* 0x54 */	INT_P11,
/* 0x56 */	INT_TRD0,
/* 0x58 */	INT_TRD1,
/* 0x5A */	INT_TRG,
/* 0x5C */	INT_SRE3,
/* 0x5E */	(void*)0xFFFF,
/* 0x60 */	INT_IICA1,
/* 0x62 */	INT_FL,
/* 0x64 */	(void*)0xFFFF,
/* 0x66 */	(void*)0xFFFF,
/* 0x68 */	(void*)0xFFFF,
/* 0x6A */	(void*)0xFFFF,
/* 0x6C */	(void*)0xFFFF,
/* 0x6E */	(void*)0xFFFF,
/* 0x70 */	(void*)0xFFFF,
/* 0x72 */	(void*)0xFFFF,
/* 0x74 */	(void*)0xFFFF,
/* 0x76 */	(void*)0xFFFF,
/* 0x78 */	(void*)0xFFFF,
/* 0x7A */	(void*)0xFFFF,
/* 0x7C */	(void*)0xFFFF,
/* 0x7E */	INT_BRK,
};


/***************************************************************************//**
 * \fn void Mcu_Init(void* ConfigPtr)
 * \brief   Initialization routine of the module.
 * \details Upon system start-up, call this function to initialize the module before 
 *          any other module function call.
 * \param[in] ConfigPtr - A pointer to the initialization structure.
 * \return  This function has no return value.
 * \callgraph
 * \callergraph
 ******************************************************************************/
void Mcu_Init(void* ConfigPtr)
{
    DT_RESFbits RESFbits;
    
    /*  */
    (void)ConfigPtr;        /* Reserved */
    
    RESFbits = _SFR_RESF;    /* Read it once */
    if ( 0u != RESFbits.TRAP ) {
        rt_ResetReason = MCU_RESET_REASON_TRAP;
    }
    else if ( 0u != RESFbits.WDTRF ) {
        rt_ResetReason = MCU_RESET_REASON_WDT;
    }
    else if ( 0u != RESFbits.RPERF ) {
        rt_ResetReason = MCU_RESET_REASON_RPE;
    }
    else if ( 0u != RESFbits.IAWRF ) {
        rt_ResetReason = MCU_RESET_REASON_IAW;
    }
    else if ( 0u != RESFbits.LVIRF ) {
        rt_ResetReason = MCU_RESET_REASON_LVI;
    }
    else {
        rt_ResetReason = MCU_RESET_REASON_POR_OR_EXT;
    }
}


/***************************************************************************//**
 * \fn Std_ReturnType Mcu_InitClock(void* ConfigPtr)
 * \brief   Mcu clock initialization routine.
 * \details
 * \param[in] ConfigPtr - A pointer to the initialization structure.
 * \return  E_OK on success, otherwise E_NOT_OK.
 * \callgraph
 * \callergraph
 ******************************************************************************/
Std_ReturnType Mcu_InitClock(void* ConfigPtr)
{
    (void)ConfigPtr;    /* Reserved */
    
    return E_OK;
}


/***************************************************************************//**
 * \fn Mcu_SetMode
 * \brief   Gets the microcontroller reset reason.
 * \details
 * \param[in] eMode - The mode to enter accortingly to @p Mcu_ModeType.
 * \return  The Mcu reset reason accordingly to @p Mcu_ResetType.
 * \callgraph
 * \callergraph
 ******************************************************************************/
void Mcu_SetMode(Mcu_ModeType eMode)
{
#if 0
#define HALT() asm("halt")
#define NOP() asm("nop")
#define STOP() asm("stop")
#endif
}


/***************************************************************************//**
 * \fn Mcu_ResetType Mcu_GetResetReason(void)
 * \brief   Gets the microcontroller reset reason.
 * \details
 * \return  The Mcu reset reason accordingly to @p Mcu_ResetType.
 * \callgraph
 * \callergraph
 ******************************************************************************/
Mcu_ResetType Mcu_GetResetReason(void) {
    return rt_ResetReason;
}


/***************************************************************************//**
 * \fn Default_IRQHandler
 * \brief   
 ******************************************************************************/
void Default_IRQHandler(void)
{
    ;
}

/***************************************************************************//**
 * \fn INT_WDTI
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_WDTI(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_LVI
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_LVI(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_P0
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_P0(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_P1
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_P1(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_P2
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_P2(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_P3
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_P3(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_P4
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_P4(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_P5
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_P5(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_ST2
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_ST2(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_SR2
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_SR2(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_SRE2
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_SRE2(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_ST0
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_ST0(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_SR0
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_SR0(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_SRE0
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_SRE0(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_ST1
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_ST1(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_SR1
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_SR1(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_SRE1
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_SRE1(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_IICA0
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_IICA0(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_TM00
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_TM00(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_TM01
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_TM01(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_TM02
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_TM02(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_TM03
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_TM03(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_AD
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_AD(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_RTC
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_RTC(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_IT
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_IT(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_KR
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_KR(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_ST3
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_ST3(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_SR3
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_SR3(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_TRJ0
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_TRJ0(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_TM10
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_TM10(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_TM11
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_TM11(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_TM12
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_TM12(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_TM13
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_TM13(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_P6
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_P6(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_P7
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_P7(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_P8
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_P8(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_P9
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_P9(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_P10
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_P10(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_P11
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_P11(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_TRD0
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_TRD0(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_TRD1
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_TRD1(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_TRG
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_TRG(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_SRE3
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_SRE3(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_IICA1
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_IICA1(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_FL
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_FL(void) {
    Default_IRQHandler();
}

/***************************************************************************//**
 * \fn INT_BRK
 * \brief   
 ******************************************************************************/
void __attribute__((weak)) INT_BRK(void) {
    Default_IRQHandler();
}

/** @} (end addtogroup Mcu) */
/** @} (end addtogroup Peripherals) */
