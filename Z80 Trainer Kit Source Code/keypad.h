/*
 * File:   keypad.h
 * Author: Youssef Ahmed Tawfik Ali
 *
 */

#ifndef KEYPAD_H
#define	KEYPAD_H


/*Section : Includes */
#include "system_def.h"
#include "mcal_std_types.h"


/*Section : Macro Function Declarations */


/*Section : Data Type Declaration*/


/*Section : Macro Declarations */


/*Section : Function Declarations */
void key_address();
void key_data();
void key_plus();
void key_minus();
void key_PC();
void hex_address();
void data_hex();
void key_reg();

void key_step();
void key_go();
void key_exe();
char key_code(char n);
char scan();
void scan1();


#endif  /*KEYPAD_H*/


