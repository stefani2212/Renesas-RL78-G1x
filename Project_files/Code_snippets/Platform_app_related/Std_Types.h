/*! @file Std_Types.h
	@brief The data types definition.
 */

#ifndef _STD_TYPES_H
#define _STD_TYPES_H

/***************************************************************************//**
 * @addtogroup Std_Types
 * @brief The data type definition.
 * @{
 */

/*! \def NULL_PTR
	\brief Null pointer definition.
 */
#define NULL_PTR        ((void*)0)

/*! \def E_OK
	\brief The operation succeeded code.
	\def E_NOT_OK
	\brief The operation failed code.
	\def E_PENDING
	\brief The operation ongoing code.
	\def E_CANCELED
	\brief The operation cancel code.
 */
#define E_OK			((Std_ReturnType)0)
#define E_NOT_OK		((Std_ReturnType)1)
#define E_PENDING		((Std_ReturnType)2)
#define E_CANCELED		((Std_ReturnType)3)

/*! \typedef signed char Int8
	\brief Signed 8-bit width data type definition.
 */
typedef signed char		Int8;

/*! \typedef unsigned char UInt8
	\brief Unsigned 8-bit width data type definition.
 */
typedef unsigned char	UInt8;

/*! \typedef signed short Int16
	\brief Signed 16-bit width data type definition.
 */
typedef signed short	Int16;

/*! \typedef unsigned short UInt16
	\brief Unsigned 16-bit width data type definition.
 */
typedef unsigned short	UInt16;

/*! \typedef signed long Int32
	\brief Signed 32-bit width data type definition.
 */
typedef signed long		Int32;

/*! \typedef unsigned long UInt32
	\brief Unsigned 32-bit width data type definition.
 */
typedef unsigned long	UInt32;

/*! \typedef signed long long Int64
	\brief Signed 64-bit width data type definition.
 */
typedef signed long	long Int64;

/*! \typedef unsigned long long UInt64
	\brief Unsigned 64-bit width data type definition.
 */
typedef unsigned long long UInt64;

/*! \typedef Int32 Std_SignedType
	\brief Signed standard data type definition.
 */
typedef Int32			Std_SignedType;

/*! \typedef UInt32 Std_UnsignedType
	\brief Unsigned standard data type definition.
 */
typedef UInt32			Std_UnsignedType;

/*! \typedef Int32 Std_ReturnType
	\brief Standard return data type definition.
 */
typedef Int32			Std_ReturnType;

/*! \enum BOOL
	\brief BOOL data type definition.
 */
typedef enum {
    FALSE = 0,      /**< Value identifier */
    TRUE,           /**< Value identifier */
} BOOL;

typedef unsigned char       bool;         /* unsigned byte       (1 byte ) */
typedef unsigned char       u08;          /* unsigned byte       (1 byte ) */
typedef signed   char       s08;          /* signed byte         (1 byte ) */
typedef unsigned int        u16;          /* short unsigned word (2 bytes) */
typedef signed   int        s16;          /* short signed word   (2 bytes) */
typedef unsigned long  int  u32;          /* long unsigned word  (4 bytes) */
typedef signed   long  int  s32;          /* long signed word    (4 bytes) */

typedef unsigned char       bool_t;       /* unsigned byte       (1 byte ) */
typedef unsigned char       uint8_t;      /* unsigned byte       (1 byte ) */
typedef signed char         int8_t;       /* signed byte         (1 byte ) */
typedef unsigned int        uint16_t;     /* short unsigned word (2 bytes) */
typedef signed int          int16_t;      /* short signed word   (2 bytes) */
typedef unsigned long  int  uint32_t;     /* long unsigned word  (4 bytes) */
typedef signed   long  int  int32_t;      /* long signed word    (4 bytes) */

/** @} (end addtogroup Std_Types) */
#endif	/* End include guard */