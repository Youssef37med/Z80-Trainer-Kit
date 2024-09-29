/* 
 * File:   mcal_std_types.h
 * Author: Youssef Ahmed Tawfik Ali
 * https://www.linkedin.com/in/youssefahmed2001/
 * Created on July 9, 2023, 12:24 AM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/* Includes -----------------------------------------------------------------------------*/
#include "compiler.h"
#include "std_libraries.h"

/* Data Type Declaration ----------------------------------------------------------------*/
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;
typedef uint8 std_ReturnType;

/* Macros -------------------------------------------------------------------------------*/
#define E_OK (std_ReturnType)     0x01
#define E_NOT_OK (std_ReturnType) 0x00
#define std_ON                    0x01
#define std_OFF                   0x00
#define std_HIGH                  0x01
#define std_LOW                   0x00
#define std_ACTIVE                0x01
#define std_IDLE                  0x00

/* Macro Functions ----------------------------------------------------------------------*/

/* Functions Declarations ---------------------------------------------------------------*/

#endif	/* MCAL_STD_TYPES_H */


