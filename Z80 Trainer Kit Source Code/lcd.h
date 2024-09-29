/*
 * File:   lcd.h
 * Author: Youssef Ahmed Tawfik Ali
 *
 */

#ifndef LCD_H
#define	LCD_H


/*Section : Includes */
#include "system_def.h"
#include "mcal_std_types.h"


/*Section : Macro Function Declarations */


/*Section : Data Type Declaration*/


/*Section : Macro Declarations */
#define _LCD_CLEAR								 0X01
#define _LCD_RETURN_HOME						 0x02
#define _LCD_ENTRY_MODE_DEC_SHIFT_OFF			 0x04
#define _LCD_ENTRY_MODE_DEC_SHIFT_ON			 0x05
#define _LCD_ENTRY_MODE_INC_SHIFT_OFF			 0x06
#define _LCD_ENTRY_MODE_INC_SHIFT_ON			 0x07
#define _LCD_CURSOR_MOVE_SHIFT_LEFT				 0x10
#define _LCD_CURSOR_MOVE_SHIFT_RIGHT			 0x14
#define _LCD_DISPLAY_SHIFT_LEFT					 0x18
#define _LCD_DISPLAY_SHIFT_RIGHT				 0x1C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF 0x0C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON  0x0D
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF  0x0E
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON   0x0F
#define _LCD_DISPLAY_OFF_CURSOR_OFF              0x08
#define _LCD_8BIT_MODE_2_LINE					 0x38
#define _LCD_4BIT_MODE_2_LINE					 0x28
#define _LCD_CGRAM_START						 0x40
#define _LCD_DDRAM_START						 0x80

#define BUSY_FLAG 0x80
#define CGRAM_ADDRESS 0x7F

#define ROW1 1
#define ROW2 2
#define ROW3 3
#define ROW4 4


/*Section : Function Declarations */
void lcd_8bit_initialize();
void lcd_8bit_send_command(uint8_t command);
void lcd_8bit_send_char_data(uint8_t data);
void lcd_8bit_send_string(char* str);
void lcd_8bit_set_cursor(uint8_t row, uint8_t coulmn);
void lcd_8bit_send_uint8_hex_data(uint8_t data);


#endif  /*LCD_H*/