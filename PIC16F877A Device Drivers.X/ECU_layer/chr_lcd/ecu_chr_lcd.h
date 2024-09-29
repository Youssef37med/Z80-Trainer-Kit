/* 
 * File:   ecu_chr_lcd.h
 * Author: Youssef Ahmed Tawfik Ali
 * https://www.linkedin.com/in/youssefahmed2001/
 * Created on May 21, 2021, 9:53 PM
 */

#ifndef ECU_CHR_LCD_H
#define	ECU_CHR_LCD_H

/* Includes -----------------------------------------------------------------------------*/
#include "ecu_chr_lcd_cfg.h"
#include "../../MCAL_Layer/gpio/gpio.h"
#include "../../MCAL_layer/mcal_std_types.h"

/* Data Type Declaration ----------------------------------------------------------------*/
typedef struct{
    uint8 lcd_rs;
    uint8 lcd_en;
    uint8 lcd_data[4];
}chr_lcd_4bit_t;

typedef struct{
    uint8 lcd_rs;
    uint8 lcd_en;
    uint8 lcd_data[8];
}chr_lcd_8bit_t;

typedef struct{
    uint8 port  : 4;
    uint8 pin   : 4;
}lcd_pin_t;
typedef union{
    struct {
        uint8_t S : 1;
        uint8_t I_D : 1;
        uint8_t RES1 : 1;
        uint8_t RES2 : 1;
        uint8_t B : 1;
        uint8_t C : 1;
        uint8_t D : 1;
        uint8_t RES3 : 1;
    } bits;

    uint8_t var;
}lcd_stat;
typedef struct{
    void (*begin)(struct lcd_t *lcd,uint8 row,uint8 col);
    void (*clear)(struct lcd_t *lcd);
    void (*home)(struct lcd_t *lcd);
    void (*setCursor)(struct lcd_t *lcd,uint8 row,uint8 col);
    void (*write)(struct lcd_t *lcd, uint8 data);
    void (*print)(struct lcd_t *lcd, uint8 *str);
    void (*cursor)(struct lcd_t *lcd);
    void (*noCursor)(struct lcd_t *lcd);
    void (*blink)(struct lcd_t *lcd);
    void (*noBlink)(struct lcd_t *lcd);
    void (*display)(struct lcd_t *lcd);
    void (*noDisplay)(struct lcd_t *lcd);
    void (*scrollDisplayLeft)(struct lcd_t *lcd);
    void (*scrollDisplayRight)(struct lcd_t *lcd);
    void (*autoscroll)(struct lcd_t *lcd);
    void (*noAutoscroll)(struct lcd_t *lcd);
    void (*leftToRight)(struct lcd_t *lcd);
    void (*rightToLeft)(struct lcd_t *lcd);
    void (*createChar)(struct lcd_t *lcd, const uint8 _chr[], uint8 mem_pos);
    
    lcd_stat lcd_state;
    
    lcd_pin_t rs;
    lcd_pin_t en;
    lcd_pin_t d4;
    lcd_pin_t d5;
    lcd_pin_t d6;
    lcd_pin_t d7;
}lcd_t;
typedef struct{
    lcd_pin_t rs;
    lcd_pin_t en;
    lcd_pin_t d0;
    lcd_pin_t d1;
    lcd_pin_t d2;
    lcd_pin_t d3;
    lcd_pin_t d4;
    lcd_pin_t d5;
    lcd_pin_t d6;
    lcd_pin_t d7;
}lcd_8_t;

/* Macros -------------------------------------------------------------------------------*/
#define _LCD_CLEAR                      0X01
#define _LCD_RETURN_HOME                0x02
#define _LCD_ENTRY_MODE_DEC_SHIFT_OFF   0x04
#define _LCD_ENTRY_MODE_DEC_SHIFT_ON    0x05
#define _LCD_ENTRY_MODE_INC_SHIFT_OFF   0x06
#define _LCD_ENTRY_MODE_INC_SHIFT_ON    0x07
#define _LCD_CURSOR_MOVE_SHIFT_LEFT     0x10
#define _LCD_CURSOR_MOVE_SHIFT_RIGHT    0x14
#define _LCD_DISPLAY_SHIFT_LEFT         0x18
#define _LCD_DISPLAY_SHIFT_RIGHT        0x1C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF 0x0C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON  0x0D
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF  0x0E
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON   0x0F
#define _LCD_DISPLAY_OFF_CURSOR_OFF              0x08
#define _LCD_8BIT_MODE_2_LINE           0x38
#define _LCD_4BIT_MODE_2_LINE           0x28

#define _LCD_CGRAM_START                0x40
#define _LCD_DDRAM_START                0x80

#define ROW1 1
#define ROW2 2
#define ROW3 3
#define ROW4 4

/* Macro Functions ----------------------------------------------------------------------*/

/* Functions Declarations ---------------------------------------------------------------*/
std_ReturnType lcd_4bit_intialize(lcd_t *lcd);
std_ReturnType lcd_4bit_send_command(const lcd_t *lcd, uint8 command);
std_ReturnType lcd_4bit_send_char_data(const lcd_t *lcd, uint8 data);
std_ReturnType lcd_4bit_send_char_data_pos(const lcd_t *lcd,uint8 row, uint8 column, uint8 data);
std_ReturnType lcd_4bit_send_string(const lcd_t *lcd, uint8 *str);
std_ReturnType lcd_4bit_send_string_pos(const lcd_t *lcd, uint8 row, uint8 column, uint8 *str);
std_ReturnType lcd_4bit_save_custom_char(const lcd_t *lcd, const uint8 _chr[], uint8 mem_pos);

std_ReturnType lcd_4bit_clear(const lcd_t *lcd);
std_ReturnType lcd_4bit_home(const lcd_t *lcd);
std_ReturnType lcd_4bit_cursor(lcd_t *lcd);
std_ReturnType lcd_4bit_no_cursor(lcd_t *lcd);
std_ReturnType lcd_4bit_blink(lcd_t *lcd);
std_ReturnType lcd_4bit_no_blink(lcd_t *lcd);
std_ReturnType lcd_4bit_display(lcd_t *lcd);
std_ReturnType lcd_4bit_no_display(lcd_t *lcd);
std_ReturnType lcd_4bit_autoscroll(lcd_t *lcd);
std_ReturnType lcd_4bit_noAutoscroll(lcd_t *lcd);
std_ReturnType lcd_4bit_scrollDisplayLeft(lcd_t *lcd);
std_ReturnType lcd_4bit_scrollDisplayRight(lcd_t *lcd);
std_ReturnType lcd_4bit_leftToRight(lcd_t *lcd);
std_ReturnType lcd_4bit_rightToLeft(lcd_t *lcd);




std_ReturnType lcd_8bit_intialize(const lcd_8_t *lcd);
std_ReturnType lcd_8bit_send_command(const lcd_8_t *lcd, uint8 command);
std_ReturnType lcd_8bit_send_char_data(const lcd_8_t *lcd, uint8 data);
std_ReturnType lcd_8bit_send_char_data_pos(const lcd_8_t *lcd,uint8 row, uint8 column, uint8 data);
std_ReturnType lcd_8bit_send_string(const lcd_8_t *lcd, uint8 *str);
std_ReturnType lcd_8bit_send_string_pos(const lcd_8_t *lcd, uint8 row, uint8 column, uint8 *str);
std_ReturnType lcd_8bit_send_custom_char(const lcd_8_t *lcd, uint8 row, uint8 column, 
                                         const uint8 _chr[], uint8 mem_pos);



std_ReturnType convert_uint8_to_string(uint8 value, uint8 *str);
std_ReturnType convert_uint16_to_string(uint16 value, uint8 *str);
std_ReturnType convert_uint32_to_string(uint32 value, uint8 *str);




lcd_t LCD_Get_Instance(port_t rs_port,pin_t rs_pin,port_t en_port,pin_t en_pin,
                       port_t d4_port,pin_t d4_pin,port_t d5_port,pin_t d5_pin,
                       port_t d6_port,pin_t d6_pin,port_t d7_port,pin_t d7_pin);
#endif	/* ECU_CHR_LCD_H */
