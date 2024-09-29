/*
 * File:   p8255.h
 * Author: Youssef Ahmed Tawfik Ali
 *
 */

#ifndef P8255_H
#define	P8255_H


/*Section : Includes */
#include "system_def.h"
#include "mcal_std_types.h"


/*Section : Macro Function Declarations */


/*Section : Data Type Declaration*/
#define P8255_PORTA		  	      0x00
#define P8255_PORTB		  	      0x01
#define P8255_PORTC_L		  	  0x02
#define P8255_PORTC_H		  	  0x03

#define P8255_DEFAULT_MODE	      0x90 //porta -> input , portb -> output , portc -> output


/*Section : Macro Declarations */


/*Section : Function Declarations */
void p8255_initialize();


#endif  /*P8255_H*/