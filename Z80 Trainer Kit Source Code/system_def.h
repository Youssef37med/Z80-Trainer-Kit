/*
 * File:   system_def.h
 * Author: Youssef Ahmed Tawfik Ali
 *
 */

#ifndef SYSTEM_DEF_H
#define	SYSTEM_DEF_H


/*Section : Includes */


/*Section : Macro Function Declarations */


/*Section : Data Type Declaration*/
__sfr __at 0x69 p8255; // 8255a control reg
__sfr __at 0x09 portA; // user porta -> input
__sfr __at 0x29 portB; // user portb -> output
__sfr __at 0x49 portC; // user portc -> output
__sfr __at 0x05 portD; // user portd -> output
__sfr __at 0x0D portE; // digit
__sfr __at 0x11 portF; // segment
__sfr __at 0x15 portG; // key input
__sfr __at 0x19 portH; // lcd data bus

__sfr __at 0x01 LCD_command_write; // lcd cmd write
__sfr __at 0x21 LCD_data_write;    // lcd data write
__sfr __at 0x41 LCD_command_read;  // lcd cmd read
__sfr __at 0x61 LCD_data_read;     // lcd data read

__sfr __at 0x1D USART_READ;

/*Section : Macro Declarations */


/*Section : Function Declarations */


#endif	/* SYSTEM_DEF_H */