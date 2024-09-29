/*
 * File:   mcal_std_types.h
 * Author: Youssef Ahmed Tawfik Ali
 *
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H


/*Section : Includes */
#include "std_libraries.h"


/*Section : Macro Function Declarations */


/*Section : Data Type Declaration*/
typedef uint8_t std_ReturnType;


/*Section : Macro Declarations */
#define E_OK (std_ReturnType)     0x01
#define E_NOT_OK (std_ReturnType) 0x00
#define std_ON                    0x01
#define std_OFF                   0x00
#define std_HIGH                  0x01
#define std_LOW                   0x00
#define std_ACTIVE                0x01
#define std_IDLE                  0x00


/*Section : Function Declarations */


#endif	/* MCAL_STD_TYPES_H */

