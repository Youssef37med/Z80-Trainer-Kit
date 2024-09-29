/*
 * File:   seven_segment.h
 * Author: Youssef Ahmed Tawfik Ali
 *
 */

#ifndef SEVEN_SEGMENT_H
#define	SEVEN_SEGMENT_H


/*Section : Includes */
#include "system_def.h"
#include "mcal_std_types.h"


/*Section : Macro Function Declarations */


/*Section : Data Type Declaration*/


/*Section : Macro Declarations */


/*Section : Function Declarations */
void dot_address();
void dot_data();
void address_buffer_write(uint16_t value);
void data_buffer_write(uint8_t value);
void address_display();
void data_display();
void read_memory();

void reg_AF();
void reg_BC();
void reg_DE();
void reg_HL();
void reg_IX();
void reg_IY();
void reg_SP();
void reg_display();


#endif  /*SEVEN_SEGMENT_H*/