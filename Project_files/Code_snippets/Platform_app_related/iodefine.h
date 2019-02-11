/***************************************************************/
/*                                                             */
/*      PROJECT NAME :  RL78G13_LED_SAMPLE                     */
/*      FILE         :  iodefine.h                             */
/*      DESCRIPTION  :  Definition of I/O Registers            */
/*      CPU SERIES   :  RL78 - G13                             */
/*      CPU TYPE     :  R5F100LE                               */
/*                                                             */
/***************************************************************/                            

#ifndef __INTRINSIC_FUNCTIONS
#define __INTRINSIC_FUNCTIONS

#define DI() asm("di")
#define EI() asm("ei")
#define HALT() asm("halt")
#define NOP() asm("nop")
#define STOP() asm("stop")

#endif

#ifndef __IOREG_BIT_STRUCTURES
#define __IOREG_BIT_STRUCTURES
typedef struct {
	unsigned char no0 :1;
	unsigned char no1 :1;
	unsigned char no2 :1;
	unsigned char no3 :1;
	unsigned char no4 :1;
	unsigned char no5 :1;
	unsigned char no6 :1;
	unsigned char no7 :1;
} __BITS8;

typedef struct {
	unsigned short no0 :1;
	unsigned short no1 :1;
	unsigned short no2 :1;
	unsigned short no3 :1;
	unsigned short no4 :1;
	unsigned short no5 :1;
	unsigned short no6 :1;
	unsigned short no7 :1;
	unsigned short no8 :1;
	unsigned short no9 :1;
	unsigned short no10 :1;
	unsigned short no11 :1;
	unsigned short no12 :1;
	unsigned short no13 :1;
	unsigned short no14 :1;
	unsigned short no15 :1;
} __BITS16;

#endif

#ifndef IODEFINE_H
#define IODEFINE_H

/*! \union DT_RESFbits
    \brief RESF register data type definition.
 */
typedef union {
    struct {
        unsigned char LVIRF : 1;
        unsigned char IAWRF : 1;
        unsigned char RPERF : 1;
        unsigned char       : 1;
        unsigned char WDTRF : 1;
        unsigned char       : 1;
        unsigned char       : 1;
        unsigned char TRAP  : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_RESFbits;
#define _SFR_RESF (*(volatile DT_RESFbits *)0xFFFA8u)


#define PM_OUTPUT  0
#define PM_INPUT   1

/*! \union DT_PM0bits
    \brief PM0 register data type definition.
 */
typedef union {
    struct {
        unsigned char PM00 : 1;
        unsigned char PM01 : 1;
        unsigned char PM02 : 1;
        unsigned char PM03 : 1;
        unsigned char PM04 : 1;
        unsigned char PM05 : 1;
        unsigned char PM06 : 1;
        unsigned char : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_PM0bits;
#define _SFR_PM0 (*(volatile DT_PM0bits *)0xFFF20u)

/*! \union DT_PM1bits
    \brief PM1 register data type definition.
 */
typedef union {
    struct {
        unsigned char PM10 : 1;
        unsigned char PM11 : 1;
        unsigned char PM12 : 1;
        unsigned char PM13 : 1;
        unsigned char PM14 : 1;
        unsigned char PM15 : 1;
        unsigned char PM16 : 1;
        unsigned char PM17 : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_PM1bits;
#define _SFR_PM1 (*(volatile DT_PM1bits *)0xFFF21u)

/*! \union DT_PM2bits
    \brief PM2 register data type definition.
 */
typedef union {
    struct {
        unsigned char PM20 : 1;
        unsigned char PM21 : 1;
        unsigned char PM22 : 1;
        unsigned char PM23 : 1;
        unsigned char PM24 : 1;
        unsigned char PM25 : 1;
        unsigned char PM26 : 1;
        unsigned char PM27 : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_PM2bits;
#define _SFR_PM2 (*(volatile DT_PM2bits *)0xFFF22u)

/*! \union DT_PM3bits
    \brief PM3 register data type definition.
 */
typedef union {
    struct {
        unsigned char PM30 : 1;
        unsigned char PM31 : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_PM3bits;
#define _SFR_PM3 (*(volatile DT_PM3bits *)0xFFF23u)

/*! \union DT_PM4bits
    \brief PM4 register data type definition.
 */
typedef union {
    struct {
        unsigned char PM40 : 1;
        unsigned char PM41 : 1;
        unsigned char PM42 : 1;
        unsigned char PM43 : 1;
        unsigned char PM44 : 1;
        unsigned char PM45 : 1;
        unsigned char PM46 : 1;
        unsigned char PM47 : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_PM4bits;
#define _SFR_PM4 (*(volatile DT_PM4bits *)0xFFF24u)

/*! \union DT_PM5bits
    \brief PM5 register data type definition.
 */
typedef union {
    struct {
        unsigned char PM50 : 1;
        unsigned char PM51 : 1;
        unsigned char PM52 : 1;
        unsigned char PM53 : 1;
        unsigned char PM54 : 1;
        unsigned char PM55 : 1;
        unsigned char PM56 : 1;
        unsigned char PM57 : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_PM5bits;
#define _SFR_PM5 (*(volatile DT_PM5bits *)0xFFF25u)

/*! \union DT_PM6bits
    \brief PM6 register data type definition.
 */
typedef union {
    struct {
        unsigned char PM60 : 1;
        unsigned char PM61 : 1;
        unsigned char PM62 : 1;
        unsigned char PM63 : 1;
        unsigned char PM64 : 1;
        unsigned char PM65 : 1;
        unsigned char PM66 : 1;
        unsigned char PM67 : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_PM6bits;
#define _SFR_PM6 (*(volatile DT_PM6bits *)0xFFF26u)

/*! \union DT_PM7bits
    \brief PM7 register data type definition.
 */
typedef union {
    struct {
        unsigned char PM70 : 1;
        unsigned char PM71 : 1;
        unsigned char PM72 : 1;
        unsigned char PM73 : 1;
        unsigned char PM74 : 1;
        unsigned char PM75 : 1;
        unsigned char PM76 : 1;
        unsigned char PM77 : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_PM7bits;
#define _SFR_PM7 (*(volatile DT_PM7bits *)0xFFF27u)

/*! \union DT_PM8bits
    \brief PM8 register data type definition.
 */
typedef union {
    struct {
        unsigned char PM80 : 1;
        unsigned char PM81 : 1;
        unsigned char PM82 : 1;
        unsigned char PM83 : 1;
        unsigned char PM84 : 1;
        unsigned char PM85 : 1;
        unsigned char PM86 : 1;
        unsigned char PM87 : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_PM8bits;
#define _SFR_PM8 (*(volatile DT_PM8bits *)0xFFF28u)

/*! \union DT_PM10bits
    \brief PM10 register data type definition.
 */
typedef union {
    struct {
        unsigned char PM100 : 1;
        unsigned char PM101 : 1;
        unsigned char PM102 : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_PM10bits;
#define _SFR_PM10 (*(volatile DT_PM10bits *)0xFFF2Au)

/*! \union DT_PM11bits
    \brief PM11 register data type definition.
 */
typedef union {
    struct {
        unsigned char PM110 : 1;
        unsigned char PM111 : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_PM11bits;
#define _SFR_PM11 (*(volatile DT_PM11bits *)0xFFF2Bu)

/*! \union DT_PM12bits
    \brief PM12 register data type definition.
 */
typedef union {
    struct {
        unsigned char PM120 : 1;
        unsigned char PM121 : 1;
        unsigned char PM122 : 1;
        unsigned char PM123 : 1;
        unsigned char PM124 : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_PM12bits;
#define _SFR_PM12 (*(volatile DT_PM12bits *)0xFFF2Cu)

/*! \union DT_PM12bits
    \brief PM12 register data type definition.
 */
typedef union {
    struct {
        unsigned char PM130 : 1;
        unsigned char PM131 : 1;
        unsigned char PM132 : 1;
        unsigned char PM133 : 1;
        unsigned char PM134 : 1;
        unsigned char PM135 : 1;
        unsigned char PM136 : 1;
        unsigned char PM137 : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_PM13bits;
#define _SFR_PM13 (*(volatile DT_PM13bits *)0xFFF2Du)

/*! \union DT_PM14bits
    \brief PM14 register data type definition.
 */
typedef union {
    struct {
        unsigned char PM140 : 1;
        unsigned char PM141 : 1;
        unsigned char PM142 : 1;
        unsigned char PM143 : 1;
        unsigned char PM144 : 1;
        unsigned char PM145 : 1;
        unsigned char PM146 : 1;
        unsigned char PM147 : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_PM14bits;
#define _SFR_PM14 (*(volatile DT_PM14bits *)0xFFF2Eu)

/*! \union DT_PM15bits
    \brief PM15 register data type definition.
 */
typedef union {
    struct {
        unsigned char PM150 : 1;
        unsigned char PM151 : 1;
        unsigned char PM152 : 1;
        unsigned char PM153 : 1;
        unsigned char PM154 : 1;
        unsigned char PM155 : 1;
        unsigned char PM156 : 1;
        unsigned char : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_PM15bits;
#define _SFR_PM15 (*(volatile DT_PM15bits *)0xFFF2Fu)

/*! \union DT_P0bits
    \brief P0 register data type definition.
 */
typedef union {
    struct {
        unsigned char P00 : 1;
        unsigned char P01 : 1;
        unsigned char P02 : 1;
        unsigned char P03 : 1;
        unsigned char P04 : 1;
        unsigned char P05 : 1;
        unsigned char P06 : 1;
        unsigned char : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_P0bits;
#define _SFR_P0 (*(volatile DT_P0bits *)0xFFF00u)

/*! \union DT_P1bits
    \brief P1 register data type definition.
 */
typedef union {
    struct {
        unsigned char P10 : 1;
        unsigned char P11 : 1;
        unsigned char P12 : 1;
        unsigned char P13 : 1;
        unsigned char P14 : 1;
        unsigned char P15 : 1;
        unsigned char P16 : 1;
        unsigned char P17 : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_P1bits;
#define _SFR_P1 (*(volatile DT_P1bits *)0xFFF01u)

/*! \union DT_P2bits
    \brief P2 register data type definition.
 */
typedef union {
    struct {
        unsigned char P20 : 1;
        unsigned char P21 : 1;
        unsigned char P22 : 1;
        unsigned char P23 : 1;
        unsigned char P24 : 1;
        unsigned char P25 : 1;
        unsigned char P26 : 1;
        unsigned char P27 : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_P2bits;
#define _SFR_P2 (*(volatile DT_P2bits *)0xFFF02u)

/*! \union DT_P3bits
    \brief P3 register data type definition.
 */
typedef union {
    struct {
        unsigned char P30 : 1;
        unsigned char P31 : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_P3bits;
#define _SFR_P3 (*(volatile DT_P3bits *)0xFFF03u)

/*! \union DT_P4bits
    \brief P4 register data type definition.
 */
typedef union {
    struct {
        unsigned char P40 : 1;
        unsigned char P41 : 1;
        unsigned char P42 : 1;
        unsigned char P43 : 1;
        unsigned char P44 : 1;
        unsigned char P45 : 1;
        unsigned char P46 : 1;
        unsigned char P47 : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_P4bits;
#define _SFR_P4 (*(volatile DT_P4bits *)0xFFF04u)

/*! \union DT_P5bits
    \brief P5 register data type definition.
 */
typedef union {
    struct {
        unsigned char P50 : 1;
        unsigned char P51 : 1;
        unsigned char P52 : 1;
        unsigned char P53 : 1;
        unsigned char P54 : 1;
        unsigned char P55 : 1;
        unsigned char P56 : 1;
        unsigned char P57 : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_P5bits;
#define _SFR_P5 (*(volatile DT_P5bits *)0xFFF05u)

/*! \union DT_P6bits
    \brief P6 register data type definition.
 */
typedef union {
    struct {
        unsigned char P60 : 1;
        unsigned char P61 : 1;
        unsigned char P62 : 1;
        unsigned char P63 : 1;
        unsigned char P64 : 1;
        unsigned char P65 : 1;
        unsigned char P66 : 1;
        unsigned char P67 : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_P6bits;
#define _SFR_P6 (*(volatile DT_P6bits *)0xFFF06u)

/*! \union DT_P7bits
    \brief P7 register data type definition.
 */
typedef union {
    struct {
        unsigned char P70 : 1;
        unsigned char P71 : 1;
        unsigned char P72 : 1;
        unsigned char P73 : 1;
        unsigned char P74 : 1;
        unsigned char P75 : 1;
        unsigned char P76 : 1;
        unsigned char P77 : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_P7bits;
#define _SFR_P7 (*(volatile DT_P7bits *)0xFFF07u)

/*! \union DT_P8bits
    \brief P8 register data type definition.
 */
typedef union {
    struct {
        unsigned char P80 : 1;
        unsigned char P81 : 1;
        unsigned char P82 : 1;
        unsigned char P83 : 1;
        unsigned char P84 : 1;
        unsigned char P85 : 1;
        unsigned char P86 : 1;
        unsigned char P87 : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_P8bits;
#define _SFR_P8 (*(volatile DT_P8bits *)0xFFF08u)

/*! \union DT_P10bits
    \brief P10 register data type definition.
 */
typedef union {
    struct {
        unsigned char P100 : 1;
        unsigned char P101 : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_P10bits;
#define _SFR_P10 (*(volatile DT_P10bits *)0xFFF0Au)

/*! \union DT_P11bits
    \brief P11 register data type definition.
 */
typedef union {
    struct {
        unsigned char P110 : 1;
        unsigned char P111 : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_P11bits;
#define _SFR_P11 (*(volatile DT_P11bits *)0xFFF0Bu)

/*! \union DT_P12bits
    \brief P12 register data type definition.
 */
typedef union {
    struct {
        unsigned char P120 : 1;
        unsigned char P121 : 1;
        unsigned char P122 : 1;
        unsigned char P123 : 1;
        unsigned char P124 : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_P12bits;
#define _SFR_P12 (*(volatile DT_P12bits *)0xFFF0Cu)

/*! \union DT_P13bits
    \brief P13 register data type definition.
 */
typedef union {
    struct {
        unsigned char P130 : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char P137 : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_P13bits;
#define _SFR_P13 (*(volatile DT_P13bits *)0xFFF0Du)

/*! \union DT_P14bits
    \brief P14 register data type definition.
 */
typedef union {
    struct {
        unsigned char P140 : 1;
        unsigned char P141 : 1;
        unsigned char P142 : 1;
        unsigned char P143 : 1;
        unsigned char P144 : 1;
        unsigned char P145 : 1;
        unsigned char P146 : 1;
        unsigned char P147 : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_P14bits;
#define _SFR_P14 (*(volatile DT_P14bits *)0xFFF0Eu)

/*! \union DT_P15bits
    \brief P15 register data type definition.
 */
typedef union {
    struct {
        unsigned char P150 : 1;
        unsigned char P151 : 1;
        unsigned char P152 : 1;
        unsigned char P153 : 1;
        unsigned char P154 : 1;
        unsigned char P155 : 1;
        unsigned char P156 : 1;
        unsigned char : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_P15bits;
#define _SFR_P15 (*(volatile DT_P15bits *)0xFFF0Fu)

/*! \union DT_PMC0bits
    \brief PMC0 register data type definition.
 */
typedef union {
    struct {
        unsigned char PMC00 : 1;
        unsigned char PMC01 : 1;
        unsigned char PMC02 : 1;
        unsigned char PMC03 : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_PMC0bits;
#define _SFR_PMC0 (*(volatile DT_PMC0bits *)0xF0060u)

/*! \union DT_PMC1bits
    \brief PMC1 register data type definition.
 */
typedef union {
    struct {
        unsigned char : 0;
        unsigned char : 0;
        unsigned char PMC12 : 1;
        unsigned char PMC13 : 1;
        unsigned char : 0;
        unsigned char : 0;
        unsigned char PMC16 : 1;
        unsigned char PMC17 : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_PMC1bits;
#define _SFR_PMC1 (*(volatile DT_PMC1bits *)0xF0061u)

/*! \union DT_PMC10bits
    \brief PMC10 register data type definition.
 */
typedef union {
    struct {
        unsigned char PMC100 : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_PMC10bits;
#define _SFR_PMC10 (*(volatile DT_PMC10bits *)0xF006Au)

/*! \union DT_PMC12bits
    \brief PMC12 register data type definition.
 */
typedef union {
    struct {
        unsigned char PMC120 : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_PMC12bits;
#define _SFR_PMC12 (*(volatile DT_PMC12bits *)0xF006Cu)

/*! \union DT_PMC14bits
    \brief PMC14 register data type definition.
 */
typedef union {
    struct {
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char : 1;
        unsigned char PMC147 : 1;
    } __attribute__ ((packed));
    unsigned char : 8;
} __attribute__ ((packed)) DT_PMC14bits;
#define _SFR_PMC14 (*(volatile DT_PMC14bits *)0xF006Eu)

/*
 IO Registers
 */
union un_p0 {
	unsigned char p0;
	__BITS8 BIT;
};
union un_p1 {
	unsigned char p1;
	__BITS8 BIT;
};
union un_p2 {
	unsigned char p2;
	__BITS8 BIT;
};
union un_p3 {
	unsigned char p3;
	__BITS8 BIT;
};
union un_p4 {
	unsigned char p4;
	__BITS8 BIT;
};
union un_p5 {
	unsigned char p5;
	__BITS8 BIT;
};
union un_p6 {
	unsigned char p6;
	__BITS8 BIT;
};
union un_p7 {
	unsigned char p7;
	__BITS8 BIT;
};
union un_p12 {
	unsigned char p12;
	__BITS8 BIT;
};
union un_p13 {
	unsigned char p13;
	__BITS8 BIT;
};
union un_p14 {
	unsigned char p14;
	__BITS8 BIT;
};
union un_pm0 {
	unsigned char pm0;
	__BITS8 BIT;
};
union un_pm1 {
	unsigned char pm1;
	__BITS8 BIT;
};
union un_pm2 {
	unsigned char pm2;
	__BITS8 BIT;
};
union un_pm3 {
	unsigned char pm3;
	__BITS8 BIT;
};
union un_pm4 {
	unsigned char pm4;
	__BITS8 BIT;
};
union un_pm5 {
	unsigned char pm5;
	__BITS8 BIT;
};
union un_pm6 {
	unsigned char pm6;
	__BITS8 BIT;
};
union un_pm7 {
	unsigned char pm7;
	__BITS8 BIT;
};
union un_pm12 {
	unsigned char pm12;
	__BITS8 BIT;
};
union un_pm14 {
	unsigned char pm14;
	__BITS8 BIT;
};
union un_adm0 {
	unsigned char adm0;
	__BITS8 BIT;
};
union un_ads {
	unsigned char ads;
	__BITS8 BIT;
};
union un_adm1 {
	unsigned char adm1;
	__BITS8 BIT;
};
union un_krm {
	unsigned char krm;
	__BITS8 BIT;
};
union un_egp0 {
	unsigned char egp0;
	__BITS8 BIT;
};
union un_egn0 {
	unsigned char egn0;
	__BITS8 BIT;
};
union un_egp1 {
	unsigned char egp1;
	__BITS8 BIT;
};
union un_egn1 {
	unsigned char egn1;
	__BITS8 BIT;
};
union un_iics0 {
	unsigned char iics0;
	__BITS8 BIT;
};
union un_iicf0 {
	unsigned char iicf0;
	__BITS8 BIT;
};
union un_rtcc0 {
	unsigned char rtcc0;
	__BITS8 BIT;
};
union un_rtcc1 {
	unsigned char rtcc1;
	__BITS8 BIT;
};
union un_csc {
	unsigned char csc;
	__BITS8 BIT;
};
union un_ostc {
	unsigned char ostc;
	__BITS8 BIT;
};
union un_ckc {
	unsigned char ckc;
	__BITS8 BIT;
};
union un_cks0 {
	unsigned char cks0;
	__BITS8 BIT;
};
union un_cks1 {
	unsigned char cks1;
	__BITS8 BIT;
};
union un_lvim {
	unsigned char lvim;
	__BITS8 BIT;
};
union un_lvis {
	unsigned char lvis;
	__BITS8 BIT;
};
union un_dmc0 {
	unsigned char dmc0;
	__BITS8 BIT;
};
union un_dmc1 {
	unsigned char dmc1;
	__BITS8 BIT;
};
union un_drc0 {
	unsigned char drc0;
	__BITS8 BIT;
};
union un_drc1 {
	unsigned char drc1;
	__BITS8 BIT;
};
union un_if2 {
	unsigned short if2;
	__BITS16 BIT;
};
union un_if2l {
	unsigned char if2l;
	__BITS8 BIT;
};
union un_if2h {
	unsigned char if2h;
	__BITS8 BIT;
};
union un_mk2 {
	unsigned short mk2;
	__BITS16 BIT;
};
union un_mk2l {
	unsigned char mk2l;
	__BITS8 BIT;
};
union un_mk2h {
	unsigned char mk2h;
	__BITS8 BIT;
};
union un_pr02 {
	unsigned short pr02;
	__BITS16 BIT;
};
union un_pr02l {
	unsigned char pr02l;
	__BITS8 BIT;
};
union un_pr02h {
	unsigned char pr02h;
	__BITS8 BIT;
};
union un_pr12 {
	unsigned short pr12;
	__BITS16 BIT;
};
union un_pr12l {
	unsigned char pr12l;
	__BITS8 BIT;
};
union un_pr12h {
	unsigned char pr12h;
	__BITS8 BIT;
};
union un_if0 {
	unsigned short if0;
	__BITS16 BIT;
};
union un_if0l {
	unsigned char if0l;
	__BITS8 BIT;
};
union un_if0h {
	unsigned char if0h;
	__BITS8 BIT;
};
union un_if1 {
	unsigned short if1;
	__BITS16 BIT;
};
union un_if1l {
	unsigned char if1l;
	__BITS8 BIT;
};
union un_if1h {
	unsigned char if1h;
	__BITS8 BIT;
};
union un_mk0 {
	unsigned short mk0;
	__BITS16 BIT;
};
union un_mk0l {
	unsigned char mk0l;
	__BITS8 BIT;
};
union un_mk0h {
	unsigned char mk0h;
	__BITS8 BIT;
};
union un_mk1 {
	unsigned short mk1;
	__BITS16 BIT;
};
union un_mk1l {
	unsigned char mk1l;
	__BITS8 BIT;
};
union un_mk1h {
	unsigned char mk1h;
	__BITS8 BIT;
};
union un_pr00 {
	unsigned short pr00;
	__BITS16 BIT;
};
union un_pr00l {
	unsigned char pr00l;
	__BITS8 BIT;
};
union un_pr00h {
	unsigned char pr00h;
	__BITS8 BIT;
};
union un_pr01 {
	unsigned short pr01;
	__BITS16 BIT;
};
union un_pr01l {
	unsigned char pr01l;
	__BITS8 BIT;
};
union un_pr01h {
	unsigned char pr01h;
	__BITS8 BIT;
};
union un_pr10 {
	unsigned short pr10;
	__BITS16 BIT;
};
union un_pr10l {
	unsigned char pr10l;
	__BITS8 BIT;
};
union un_pr10h {
	unsigned char pr10h;
	__BITS8 BIT;
};
union un_pr11 {
	unsigned short pr11;
	__BITS16 BIT;
};
union un_pr11l {
	unsigned char pr11l;
	__BITS8 BIT;
};
union un_pr11h {
	unsigned char pr11h;
	__BITS8 BIT;
};
union un_pmc {
	unsigned char pmc;
	__BITS8 BIT;
};

#define P0 (*(volatile union un_p0 *)0xFFF00).p0
#define P0_bit (*(volatile union un_p0 *)0xFFF00).BIT
#define P1 (*(volatile union un_p1 *)0xFFF01).p1
#define P1_bit (*(volatile union un_p1 *)0xFFF01).BIT
#define P2 (*(volatile union un_p2 *)0xFFF02).p2
#define P2_bit (*(volatile union un_p2 *)0xFFF02).BIT
#define P3 (*(volatile union un_p3 *)0xFFF03).p3
#define P3_bit (*(volatile union un_p3 *)0xFFF03).BIT
#define P4 (*(volatile union un_p4 *)0xFFF04).p4
#define P4_bit (*(volatile union un_p4 *)0xFFF04).BIT
#define P5 (*(volatile union un_p5 *)0xFFF05).p5
#define P5_bit (*(volatile union un_p5 *)0xFFF05).BIT
#define P6 (*(volatile union un_p6 *)0xFFF06).p6
#define P6_bit (*(volatile union un_p6 *)0xFFF06).BIT
#define P7 (*(volatile union un_p7 *)0xFFF07).p7
#define P7_bit (*(volatile union un_p7 *)0xFFF07).BIT
#define P12 (*(volatile union un_p12 *)0xFFF0C).p12
#define P12_bit (*(volatile union un_p12 *)0xFFF0C).BIT
#define P13 (*(volatile union un_p13 *)0xFFF0D).p13
#define P13_bit (*(volatile union un_p13 *)0xFFF0D).BIT
#define P14 (*(volatile union un_p14 *)0xFFF0E).p14
#define P14_bit (*(volatile union un_p14 *)0xFFF0E).BIT
#define SDR00 (*(volatile unsigned short *)0xFFF10)
#define SIO00 (*(volatile unsigned char *)0xFFF10)
#define TXD0 (*(volatile unsigned char *)0xFFF10)
#define SDR01 (*(volatile unsigned short *)0xFFF12)
#define RXD0 (*(volatile unsigned char *)0xFFF12)
#define SIO01 (*(volatile unsigned char *)0xFFF12)
#define TDR00 (*(volatile unsigned short *)0xFFF18)
#define TDR01 (*(volatile unsigned short *)0xFFF1A)
#define TDR01L (*(volatile unsigned char *)0xFFF1A)
#define TDR01H (*(volatile unsigned char *)0xFFF1B)
#define ADCR (*(volatile unsigned short *)0xFFF1E)
#define ADCRH (*(volatile unsigned char *)0xFFF1F)
#define PM0 (*(volatile union un_pm0 *)0xFFF20).pm0
#define PM0_bit (*(volatile union un_pm0 *)0xFFF20).BIT
#define PM1 (*(volatile union un_pm1 *)0xFFF21).pm1
#define PM1_bit (*(volatile union un_pm1 *)0xFFF21).BIT
#define PM2 (*(volatile union un_pm2 *)0xFFF22).pm2
#define PM2_bit (*(volatile union un_pm2 *)0xFFF22).BIT
#define PM3 (*(volatile union un_pm3 *)0xFFF23).pm3
#define PM3_bit (*(volatile union un_pm3 *)0xFFF23).BIT
#define PM4 (*(volatile union un_pm4 *)0xFFF24).pm4
#define PM4_bit (*(volatile union un_pm4 *)0xFFF24).BIT
#define PM5 (*(volatile union un_pm5 *)0xFFF25).pm5
#define PM5_bit (*(volatile union un_pm5 *)0xFFF25).BIT
#define PM6 (*(volatile union un_pm6 *)0xFFF26).pm6
#define PM6_bit (*(volatile union un_pm6 *)0xFFF26).BIT
#define PM7 (*(volatile union un_pm7 *)0xFFF27).pm7
#define PM7_bit (*(volatile union un_pm7 *)0xFFF27).BIT
//#define PM12 (*(volatile union un_pm12 *)0xFFF2C).pm12
//#define PM12_bit (*(volatile union un_pm12 *)0xFFF2C).BIT
//#define PM14 (*(volatile union un_pm14 *)0xFFF2E).pm14
//#define PM14_bit (*(volatile union un_pm14 *)0xFFF2E).BIT
#define ADM0 (*(volatile union un_adm0 *)0xFFF30).adm0
#define ADM0_bit (*(volatile union un_adm0 *)0xFFF30).BIT
#define ADS (*(volatile union un_ads *)0xFFF31).ads
#define ADS_bit (*(volatile union un_ads *)0xFFF31).BIT
#define ADM1 (*(volatile union un_adm1 *)0xFFF32).adm1
#define ADM1_bit (*(volatile union un_adm1 *)0xFFF32).BIT
#define KRM (*(volatile union un_krm *)0xFFF37).krm
#define KRM_bit (*(volatile union un_krm *)0xFFF37).BIT
#define EGP0 (*(volatile union un_egp0 *)0xFFF38).egp0
#define EGP0_bit (*(volatile union un_egp0 *)0xFFF38).BIT
#define EGN0 (*(volatile union un_egn0 *)0xFFF39).egn0
#define EGN0_bit (*(volatile union un_egn0 *)0xFFF39).BIT
#define EGP1 (*(volatile union un_egp1 *)0xFFF3A).egp1
#define EGP1_bit (*(volatile union un_egp1 *)0xFFF3A).BIT
#define EGN1 (*(volatile union un_egn1 *)0xFFF3B).egn1
#define EGN1_bit (*(volatile union un_egn1 *)0xFFF3B).BIT
#define SDR02 (*(volatile unsigned short *)0xFFF44)
#define SIO10 (*(volatile unsigned char *)0xFFF44)
#define TXD1 (*(volatile unsigned char *)0xFFF44)
#define SDR03 (*(volatile unsigned short *)0xFFF46)
#define RXD1 (*(volatile unsigned char *)0xFFF46)
#define SIO11 (*(volatile unsigned char *)0xFFF46)
#define SDR10 (*(volatile unsigned short *)0xFFF48)
#define SIO20 (*(volatile unsigned char *)0xFFF48)
#define TXD2 (*(volatile unsigned char *)0xFFF48)
#define SDR11 (*(volatile unsigned short *)0xFFF4A)
#define RXD2 (*(volatile unsigned char *)0xFFF4A)
#define SIO21 (*(volatile unsigned char *)0xFFF4A)
#define IICA0 (*(volatile unsigned char *)0xFFF50)
#define IICS0 (*(volatile union un_iics0 *)0xFFF51).iics0
#define IICS0_bit (*(volatile union un_iics0 *)0xFFF51).BIT
#define IICF0 (*(volatile union un_iicf0 *)0xFFF52).iicf0
#define IICF0_bit (*(volatile union un_iicf0 *)0xFFF52).BIT
#define TDR02 (*(volatile unsigned short *)0xFFF64)
#define TDR03 (*(volatile unsigned short *)0xFFF66)
#define TDR03L (*(volatile unsigned char *)0xFFF66)
#define TDR03H (*(volatile unsigned char *)0xFFF67)
#define TDR04 (*(volatile unsigned short *)0xFFF68)
#define TDR05 (*(volatile unsigned short *)0xFFF6A)
#define TDR06 (*(volatile unsigned short *)0xFFF6C)
#define TDR07 (*(volatile unsigned short *)0xFFF6E)
#define ITMC (*(volatile unsigned short *)0xFFF90)
#define SEC (*(volatile unsigned char *)0xFFF92)
#define MIN (*(volatile unsigned char *)0xFFF93)
#define HOUR (*(volatile unsigned char *)0xFFF94)
#define WEEK (*(volatile unsigned char *)0xFFF95)
#define DAY (*(volatile unsigned char *)0xFFF96)
#define MONTH (*(volatile unsigned char *)0xFFF97)
#define YEAR (*(volatile unsigned char *)0xFFF98)
#define SUBCUD (*(volatile unsigned char *)0xFFF99)
#define ALARMWM (*(volatile unsigned char *)0xFFF9A)
#define ALARMWH (*(volatile unsigned char *)0xFFF9B)
#define ALARMWW (*(volatile unsigned char *)0xFFF9C)
#define RTCC0 (*(volatile union un_rtcc0 *)0xFFF9D).rtcc0
#define RTCC0_bit (*(volatile union un_rtcc0 *)0xFFF9D).BIT
#define RTCC1 (*(volatile union un_rtcc1 *)0xFFF9E).rtcc1
#define RTCC1_bit (*(volatile union un_rtcc1 *)0xFFF9E).BIT
#define CMC (*(volatile unsigned char *)0xFFFA0)
#define CSC (*(volatile union un_csc *)0xFFFA1).csc
#define CSC_bit (*(volatile union un_csc *)0xFFFA1).BIT
#define OSTC (*(volatile union un_ostc *)0xFFFA2).ostc
#define OSTC_bit (*(volatile union un_ostc *)0xFFFA2).BIT
#define OSTS (*(volatile unsigned char *)0xFFFA3)
#define CKC (*(volatile union un_ckc *)0xFFFA4).ckc
#define CKC_bit (*(volatile union un_ckc *)0xFFFA4).BIT
#define CKS0 (*(volatile union un_cks0 *)0xFFFA5).cks0
#define CKS0_bit (*(volatile union un_cks0 *)0xFFFA5).BIT
#define CKS1 (*(volatile union un_cks1 *)0xFFFA6).cks1
#define CKS1_bit (*(volatile union un_cks1 *)0xFFFA6).BIT
#define RESF (*(volatile unsigned char *)0xFFFA8)
#define LVIM (*(volatile union un_lvim *)0xFFFA9).lvim
#define LVIM_bit (*(volatile union un_lvim *)0xFFFA9).BIT
#define LVIS (*(volatile union un_lvis *)0xFFFAA).lvis
#define LVIS_bit (*(volatile union un_lvis *)0xFFFAA).BIT
#define WDTE (*(volatile unsigned char *)0xFFFAB)
#define CRCIN (*(volatile unsigned char *)0xFFFAC)
#define DSA0 (*(volatile unsigned char *)0xFFFB0)
#define DSA1 (*(volatile unsigned char *)0xFFFB1)
#define DRA0 (*(volatile unsigned short *)0xFFFB2)
#define DRA0L (*(volatile unsigned char *)0xFFFB2)
#define DRA0H (*(volatile unsigned char *)0xFFFB3)
#define DRA1 (*(volatile unsigned short *)0xFFFB4)
#define DRA1L (*(volatile unsigned char *)0xFFFB4)
#define DRA1H (*(volatile unsigned char *)0xFFFB5)
#define DBC0 (*(volatile unsigned short *)0xFFFB6)
#define DBC0L (*(volatile unsigned char *)0xFFFB6)
#define DBC0H (*(volatile unsigned char *)0xFFFB7)
#define DBC1 (*(volatile unsigned short *)0xFFFB8)
#define DBC1L (*(volatile unsigned char *)0xFFFB8)
#define DBC1H (*(volatile unsigned char *)0xFFFB9)
#define DMC0 (*(volatile union un_dmc0 *)0xFFFBA).dmc0
#define DMC0_bit (*(volatile union un_dmc0 *)0xFFFBA).BIT
#define DMC1 (*(volatile union un_dmc1 *)0xFFFBB).dmc1
#define DMC1_bit (*(volatile union un_dmc1 *)0xFFFBB).BIT
#define DRC0 (*(volatile union un_drc0 *)0xFFFBC).drc0
#define DRC0_bit (*(volatile union un_drc0 *)0xFFFBC).BIT
#define DRC1 (*(volatile union un_drc1 *)0xFFFBD).drc1
#define DRC1_bit (*(volatile union un_drc1 *)0xFFFBD).BIT
#define IF2 (*(volatile union un_if2 *)0xFFFD0).if2
#define IF2_bit (*(volatile union un_if2 *)0xFFFD0).BIT
#define IF2L (*(volatile union un_if2l *)0xFFFD0).if2l
#define IF2L_bit (*(volatile union un_if2l *)0xFFFD0).BIT
#define IF2H (*(volatile union un_if2h *)0xFFFD1).if2h
#define IF2H_bit (*(volatile union un_if2h *)0xFFFD1).BIT
#define MK2 (*(volatile union un_mk2 *)0xFFFD4).mk2
#define MK2_bit (*(volatile union un_mk2 *)0xFFFD4).BIT
#define MK2L (*(volatile union un_mk2l *)0xFFFD4).mk2l
#define MK2L_bit (*(volatile union un_mk2l *)0xFFFD4).BIT
#define MK2H (*(volatile union un_mk2h *)0xFFFD5).mk2h
#define MK2H_bit (*(volatile union un_mk2h *)0xFFFD5).BIT
#define PR02 (*(volatile union un_pr02 *)0xFFFD8).pr02
#define PR02_bit (*(volatile union un_pr02 *)0xFFFD8).BIT
#define PR02L (*(volatile union un_pr02l *)0xFFFD8).pr02l
#define PR02L_bit (*(volatile union un_pr02l *)0xFFFD8).BIT
#define PR02H (*(volatile union un_pr02h *)0xFFFD9).pr02h
#define PR02H_bit (*(volatile union un_pr02h *)0xFFFD9).BIT
#define PR12 (*(volatile union un_pr12 *)0xFFFDC).pr12
#define PR12_bit (*(volatile union un_pr12 *)0xFFFDC).BIT
#define PR12L (*(volatile union un_pr12l *)0xFFFDC).pr12l
#define PR12L_bit (*(volatile union un_pr12l *)0xFFFDC).BIT
#define PR12H (*(volatile union un_pr12h *)0xFFFDD).pr12h
#define PR12H_bit (*(volatile union un_pr12h *)0xFFFDD).BIT
#define IF0 (*(volatile union un_if0 *)0xFFFE0).if0
#define IF0_bit (*(volatile union un_if0 *)0xFFFE0).BIT
#define IF0L (*(volatile union un_if0l *)0xFFFE0).if0l
#define IF0L_bit (*(volatile union un_if0l *)0xFFFE0).BIT
#define IF0H (*(volatile union un_if0h *)0xFFFE1).if0h
#define IF0H_bit (*(volatile union un_if0h *)0xFFFE1).BIT
#define IF1 (*(volatile union un_if1 *)0xFFFE2).if1
#define IF1_bit (*(volatile union un_if1 *)0xFFFE2).BIT
#define IF1L (*(volatile union un_if1l *)0xFFFE2).if1l
#define IF1L_bit (*(volatile union un_if1l *)0xFFFE2).BIT
#define IF1H (*(volatile union un_if1h *)0xFFFE3).if1h
#define IF1H_bit (*(volatile union un_if1h *)0xFFFE3).BIT
#define MK0 (*(volatile union un_mk0 *)0xFFFE4).mk0
#define MK0_bit (*(volatile union un_mk0 *)0xFFFE4).BIT
#define MK0L (*(volatile union un_mk0l *)0xFFFE4).mk0l
#define MK0L_bit (*(volatile union un_mk0l *)0xFFFE4).BIT
#define MK0H (*(volatile union un_mk0h *)0xFFFE5).mk0h
#define MK0H_bit (*(volatile union un_mk0h *)0xFFFE5).BIT
#define MK1 (*(volatile union un_mk1 *)0xFFFE6).mk1
#define MK1_bit (*(volatile union un_mk1 *)0xFFFE6).BIT
#define MK1L (*(volatile union un_mk1l *)0xFFFE6).mk1l
#define MK1L_bit (*(volatile union un_mk1l *)0xFFFE6).BIT
#define MK1H (*(volatile union un_mk1h *)0xFFFE7).mk1h
#define MK1H_bit (*(volatile union un_mk1h *)0xFFFE7).BIT
#define PR00 (*(volatile union un_pr00 *)0xFFFE8).pr00
#define PR00_bit (*(volatile union un_pr00 *)0xFFFE8).BIT
#define PR00L (*(volatile union un_pr00l *)0xFFFE8).pr00l
#define PR00L_bit (*(volatile union un_pr00l *)0xFFFE8).BIT
#define PR00H (*(volatile union un_pr00h *)0xFFFE9).pr00h
#define PR00H_bit (*(volatile union un_pr00h *)0xFFFE9).BIT
#define PR01 (*(volatile union un_pr01 *)0xFFFEA).pr01
#define PR01_bit (*(volatile union un_pr01 *)0xFFFEA).BIT
#define PR01L (*(volatile union un_pr01l *)0xFFFEA).pr01l
#define PR01L_bit (*(volatile union un_pr01l *)0xFFFEA).BIT
#define PR01H (*(volatile union un_pr01h *)0xFFFEB).pr01h
#define PR01H_bit (*(volatile union un_pr01h *)0xFFFEB).BIT
#define PR10 (*(volatile union un_pr10 *)0xFFFEC).pr10
#define PR10_bit (*(volatile union un_pr10 *)0xFFFEC).BIT
#define PR10L (*(volatile union un_pr10l *)0xFFFEC).pr10l
#define PR10L_bit (*(volatile union un_pr10l *)0xFFFEC).BIT
#define PR10H (*(volatile union un_pr10h *)0xFFFED).pr10h
#define PR10H_bit (*(volatile union un_pr10h *)0xFFFED).BIT
#define PR11 (*(volatile union un_pr11 *)0xFFFEE).pr11
#define PR11_bit (*(volatile union un_pr11 *)0xFFFEE).BIT
#define PR11L (*(volatile union un_pr11l *)0xFFFEE).pr11l
#define PR11L_bit (*(volatile union un_pr11l *)0xFFFEE).BIT
#define PR11H (*(volatile union un_pr11h *)0xFFFEF).pr11h
#define PR11H_bit (*(volatile union un_pr11h *)0xFFFEF).BIT
#define MDAL (*(volatile unsigned short *)0xFFFF0)
#define MULA (*(volatile unsigned short *)0xFFFF0)
#define MDAH (*(volatile unsigned short *)0xFFFF2)
#define MULB (*(volatile unsigned short *)0xFFFF2)
#define MDBH (*(volatile unsigned short *)0xFFFF4)
#define MULOH (*(volatile unsigned short *)0xFFFF4)
#define MDBL (*(volatile unsigned short *)0xFFFF6)
#define MULOL (*(volatile unsigned short *)0xFFFF6)
#define PMC (*(volatile union un_pmc *)0xFFFFE).pmc
#define PMC_bit (*(volatile union un_pmc *)0xFFFFE).BIT

/*
 Sfr bits
 */
#define ADCE ADM0_bit.no0
#define ADCS ADM0_bit.no7
#define SPD0 IICS0_bit.no0
#define STD0 IICS0_bit.no1
#define ACKD0 IICS0_bit.no2
#define TRC0 IICS0_bit.no3
#define COI0 IICS0_bit.no4
#define EXC0 IICS0_bit.no5
#define ALD0 IICS0_bit.no6
#define MSTS0 IICS0_bit.no7
#define IICRSV0 IICF0_bit.no0
#define STCEN0 IICF0_bit.no1
#define IICBSY0 IICF0_bit.no6
#define STCF0 IICF0_bit.no7
#define RCLOE1 RTCC0_bit.no5
#define RTCE RTCC0_bit.no7
#define RWAIT RTCC1_bit.no0
#define RWST RTCC1_bit.no1
#define RIFG RTCC1_bit.no3
#define WAFG RTCC1_bit.no4
#define WALIE RTCC1_bit.no6
#define WALE RTCC1_bit.no7
#define HIOSTOP CSC_bit.no0
#define XTSTOP CSC_bit.no6
#define MSTOP CSC_bit.no7
#define SDIV CKC_bit.no3
#define MCM0 CKC_bit.no4
#define MCS CKC_bit.no5
#define CSS CKC_bit.no6
#define CLS CKC_bit.no7
#define PCLOE0 CKS0_bit.no7
#define PCLOE1 CKS1_bit.no7
#define LVIF LVIM_bit.no0
#define LVIOMSK LVIM_bit.no1
#define LVISEN LVIM_bit.no7
#define LVILV LVIS_bit.no0
#define LVIMD LVIS_bit.no7
#define DWAIT0 DMC0_bit.no4
#define DS0 DMC0_bit.no5
#define DRS0 DMC0_bit.no6
#define STG0 DMC0_bit.no7
#define DWAIT1 DMC1_bit.no4
#define DS1 DMC1_bit.no5
#define DRS1 DMC1_bit.no6
#define STG1 DMC1_bit.no7
#define DST0 DRC0_bit.no0
#define DEN0 DRC0_bit.no7
#define DST1 DRC1_bit.no0
#define DEN1 DRC1_bit.no7
#define TMIF05 IF2_bit.no0
#define TMIF06 IF2_bit.no1
#define TMIF07 IF2_bit.no2
#define PIF6 IF2_bit.no3
#define PIF7 IF2_bit.no4
#define PIF8 IF2_bit.no5
#define PIF9 IF2_bit.no6
#define PIF10 IF2_bit.no7
#define PIF11 IF2H_bit.no0
#define MDIF IF2H_bit.no5
#define FLIF IF2H_bit.no7
#define TMMK05 MK2_bit.no0
#define TMMK06 MK2_bit.no1
#define TMMK07 MK2_bit.no2
#define PMK6 MK2_bit.no3
#define PMK7 MK2_bit.no4
#define PMK8 MK2_bit.no5
#define PMK9 MK2_bit.no6
#define PMK10 MK2_bit.no7
#define PMK11 MK2H_bit.no0
#define MDMK MK2H_bit.no5
#define FLMK MK2H_bit.no7
#define TMPR005 PR02_bit.no0
#define TMPR006 PR02_bit.no1
#define TMPR007 PR02_bit.no2
#define PPR06 PR02_bit.no3
#define PPR07 PR02_bit.no4
#define PPR08 PR02_bit.no5
#define PPR09 PR02_bit.no6
#define PPR010 PR02_bit.no7
#define PPR011 PR02H_bit.no0
#define MDPR0 PR02H_bit.no5
#define FLPR0 PR02H_bit.no7
#define TMPR105 PR12_bit.no0
#define TMPR106 PR12_bit.no1
#define TMPR107 PR12_bit.no2
#define PPR16 PR12_bit.no3
#define PPR17 PR12_bit.no4
#define PPR18 PR12_bit.no5
#define PPR19 PR12_bit.no6
#define PPR110 PR12_bit.no7
#define PPR111 PR12H_bit.no0
#define MDPR1 PR12H_bit.no5
#define FLPR1 PR12H_bit.no7
#define WDTIIF IF0_bit.no0
#define LVIIF IF0_bit.no1
#define PIF0 IF0_bit.no2
#define PIF1 IF0_bit.no3
#define PIF2 IF0_bit.no4
#define PIF3 IF0_bit.no5
#define PIF4 IF0_bit.no6
#define PIF5 IF0_bit.no7
#define CSIIF20 IF0H_bit.no0
#define IICIF20 IF0H_bit.no0
#define STIF2 IF0H_bit.no0
#define CSIIF21 IF0H_bit.no1
#define IICIF21 IF0H_bit.no1
#define SRIF2 IF0H_bit.no1
#define SREIF2 IF0H_bit.no2
#define DMAIF0 IF0H_bit.no3
#define DMAIF1 IF0H_bit.no4
#define CSIIF00 IF0H_bit.no5
#define IICIF00 IF0H_bit.no5
#define STIF0 IF0H_bit.no5
#define CSIIF01 IF0H_bit.no6
#define IICIF01 IF0H_bit.no6
#define SRIF0 IF0H_bit.no6
#define SREIF0 IF0H_bit.no7
#define TMIF01H IF0H_bit.no7
#define CSIIF10 IF1_bit.no0
#define IICIF10 IF1_bit.no0
#define STIF1 IF1_bit.no0
#define CSIIF11 IF1_bit.no1
#define IICIF11 IF1_bit.no1
#define SRIF1 IF1_bit.no1
#define SREIF1 IF1_bit.no2
#define TMIF03H IF1_bit.no2
#define IICAIF0 IF1_bit.no3
#define TMIF00 IF1_bit.no4
#define TMIF01 IF1_bit.no5
#define TMIF02 IF1_bit.no6
#define TMIF03 IF1_bit.no7
#define ADIF IF1H_bit.no0
#define RTCIF IF1H_bit.no1
#define ITIF IF1H_bit.no2
#define KRIF IF1H_bit.no3
#define TMIF04 IF1H_bit.no7
#define WDTIMK MK0_bit.no0
#define LVIMK MK0_bit.no1
#define PMK0 MK0_bit.no2
#define PMK1 MK0_bit.no3
#define PMK2 MK0_bit.no4
#define PMK3 MK0_bit.no5
#define PMK4 MK0_bit.no6
#define PMK5 MK0_bit.no7
#define CSIMK20 MK0H_bit.no0
#define IICMK20 MK0H_bit.no0
#define STMK2 MK0H_bit.no0
#define CSIMK21 MK0H_bit.no1
#define IICMK21 MK0H_bit.no1
#define SRMK2 MK0H_bit.no1
#define SREMK2 MK0H_bit.no2
#define DMAMK0 MK0H_bit.no3
#define DMAMK1 MK0H_bit.no4
#define CSIMK00 MK0H_bit.no5
#define IICMK00 MK0H_bit.no5
#define STMK0 MK0H_bit.no5
#define CSIMK01 MK0H_bit.no6
#define IICMK01 MK0H_bit.no6
#define SRMK0 MK0H_bit.no6
#define SREMK0 MK0H_bit.no7
#define TMMK01H MK0H_bit.no7
#define CSIMK10 MK1_bit.no0
#define IICMK10 MK1_bit.no0
#define STMK1 MK1_bit.no0
#define CSIMK11 MK1_bit.no1
#define IICMK11 MK1_bit.no1
#define SRMK1 MK1_bit.no1
#define SREMK1 MK1_bit.no2
#define TMMK03H MK1_bit.no2
#define IICAMK0 MK1_bit.no3
#define TMMK00 MK1_bit.no4
#define TMMK01 MK1_bit.no5
#define TMMK02 MK1_bit.no6
#define TMMK03 MK1_bit.no7
#define ADMK MK1H_bit.no0
#define RTCMK MK1H_bit.no1
#define ITMK MK1H_bit.no2
#define KRMK MK1H_bit.no3
#define TMMK04 MK1H_bit.no7
#define WDTIPR0 PR00_bit.no0
#define LVIPR0 PR00_bit.no1
#define PPR00 PR00_bit.no2
#define PPR01 PR00_bit.no3
#define PPR02 PR00_bit.no4
#define PPR03 PR00_bit.no5
#define PPR04 PR00_bit.no6
#define PPR05 PR00_bit.no7
#define CSIPR020 PR00H_bit.no0
#define IICPR020 PR00H_bit.no0
#define STPR02 PR00H_bit.no0
#define CSIPR021 PR00H_bit.no1
#define IICPR021 PR00H_bit.no1
#define SRPR02 PR00H_bit.no1
#define SREPR02 PR00H_bit.no2
#define DMAPR00 PR00H_bit.no3
#define DMAPR01 PR00H_bit.no4
#define CSIPR000 PR00H_bit.no5
#define IICPR000 PR00H_bit.no5
#define STPR00 PR00H_bit.no5
#define CSIPR001 PR00H_bit.no6
#define IICPR001 PR00H_bit.no6
#define SRPR00 PR00H_bit.no6
#define SREPR00 PR00H_bit.no7
#define TMPR001H PR00H_bit.no7
#define CSIPR010 PR01_bit.no0
#define IICPR010 PR01_bit.no0
#define STPR01 PR01_bit.no0
#define CSIPR011 PR01_bit.no1
#define IICPR011 PR01_bit.no1
#define SRPR01 PR01_bit.no1
#define SREPR01 PR01_bit.no2
#define TMPR003H PR01_bit.no2
#define IICAPR00 PR01_bit.no3
#define TMPR000 PR01_bit.no4
#define TMPR001 PR01_bit.no5
#define TMPR002 PR01_bit.no6
#define TMPR003 PR01_bit.no7
#define ADPR0 PR01H_bit.no0
#define RTCPR0 PR01H_bit.no1
#define ITPR0 PR01H_bit.no2
#define KRPR0 PR01H_bit.no3
#define TMPR004 PR01H_bit.no7
#define WDTIPR1 PR10_bit.no0
#define LVIPR1 PR10_bit.no1
#define PPR10 PR10_bit.no2
#define PPR11 PR10_bit.no3
#define PPR12 PR10_bit.no4
#define PPR13 PR10_bit.no5
#define PPR14 PR10_bit.no6
#define PPR15 PR10_bit.no7
#define CSIPR120 PR10H_bit.no0
#define IICPR120 PR10H_bit.no0
#define STPR12 PR10H_bit.no0
#define CSIPR121 PR10H_bit.no1
#define IICPR121 PR10H_bit.no1
#define SRPR12 PR10H_bit.no1
#define SREPR12 PR10H_bit.no2
#define DMAPR10 PR10H_bit.no3
#define DMAPR11 PR10H_bit.no4
#define CSIPR100 PR10H_bit.no5
#define IICPR100 PR10H_bit.no5
#define STPR10 PR10H_bit.no5
#define CSIPR101 PR10H_bit.no6
#define IICPR101 PR10H_bit.no6
#define SRPR10 PR10H_bit.no6
#define SREPR10 PR10H_bit.no7
#define TMPR101H PR10H_bit.no7
#define CSIPR110 PR11_bit.no0
#define IICPR110 PR11_bit.no0
#define STPR11 PR11_bit.no0
#define CSIPR111 PR11_bit.no1
#define IICPR111 PR11_bit.no1
#define SRPR11 PR11_bit.no1
#define SREPR11 PR11_bit.no2
#define TMPR103H PR11_bit.no2
#define IICAPR10 PR11_bit.no3
#define TMPR100 PR11_bit.no4
#define TMPR101 PR11_bit.no5
#define TMPR102 PR11_bit.no6
#define TMPR103 PR11_bit.no7
#define ADPR1 PR11H_bit.no0
#define RTCPR1 PR11H_bit.no1
#define ITPR1 PR11H_bit.no2
#define KRPR1 PR11H_bit.no3
#define TMPR104 PR11H_bit.no7
#define MAA PMC_bit.no0

/*
 Interrupt vector addresses
 */
#define RST_vect (0x0)
#define INTDBG_vect (0x2)
#define INTWDTI_vect (0x4)
#define INTLVI_vect (0x6)
#define INTP0_vect (0x8)
#define INTP1_vect (0xA)
#define INTP2_vect (0xC)
#define INTP3_vect (0xE)
#define INTP4_vect (0x10)
#define INTP5_vect (0x12)
#define INTCSI20_vect (0x14)
#define INTIIC20_vect (0x14)
#define INTST2_vect (0x14)
#define INTCSI21_vect (0x16)
#define INTIIC21_vect (0x16)
#define INTSR2_vect (0x16)
#define INTSRE2_vect (0x18)
#define INTDMA0_vect (0x1A)
#define INTDMA1_vect (0x1C)
#define INTCSI00_vect (0x1E)
#define INTIIC00_vect (0x1E)
#define INTST0_vect (0x1E)
#define INTCSI01_vect (0x20)
#define INTIIC01_vect (0x20)
#define INTSR0_vect (0x20)
#define INTSRE0_vect (0x22)
#define INTTM01H_vect (0x22)
#define INTCSI10_vect (0x24)
#define INTIIC10_vect (0x24)
#define INTST1_vect (0x24)
#define INTCSI11_vect (0x26)
#define INTIIC11_vect (0x26)
#define INTSR1_vect (0x26)
#define INTSRE1_vect (0x28)
#define INTTM03H_vect (0x28)
#define INTIICA0_vect (0x2A)
#define INTTM00_vect (0x2C)
#define INTTM01_vect (0x2E)
#define INTTM02_vect (0x30)
#define INTTM03_vect (0x32)
#define INTAD_vect (0x34)
#define INTRTC_vect (0x36)
#define INTIT_vect (0x38)
#define INTKR_vect (0x3A)
#define INTTM04_vect (0x42)
#define INTTM05_vect (0x44)
#define INTTM06_vect (0x46)
#define INTTM07_vect (0x48)
#define INTP6_vect (0x4A)
#define INTP7_vect (0x4C)
#define INTP8_vect (0x4E)
#define INTP9_vect (0x50)
#define INTP10_vect (0x52)
#define INTP11_vect (0x54)
#define INTMD_vect (0x5E)
#define INTFL_vect (0x62)
#define BRK_I_vect (0x7E)
#endif
