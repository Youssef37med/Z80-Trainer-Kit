/* 
 * File:   ecu_chr_lcd.c
 * Author: Youssef Ahmed Tawfik Ali
 * https://www.linkedin.com/in/youssefahmed2001/
 * Created on May 21, 2021, 9:53 PM
 */

/* Includes -----------------------------------------------------------------------------*/
#include "ecu_chr_lcd.h"

/* Data Type Definition -----------------------------------------------------------------*/

/* Macros -------------------------------------------------------------------------------*/

/* Macro Functions ----------------------------------------------------------------------*/

/* Functions Definition -----------------------------------------------------------------*/
static std_ReturnType lcd_send_4bits(const lcd_t *lcd, uint8 _data_command);
static std_ReturnType lcd_send_8bits(const lcd_8_t *lcd, uint8 _data_command);
static std_ReturnType lcd_4bit_send_enable_signal(const lcd_t *lcd);
static std_ReturnType lcd_4bit_set_cursor(const lcd_t *lcd, uint8 row, uint8 coulmn);
static std_ReturnType lcd_8bit_send_enable_signal(const lcd_8_t *lcd);
static std_ReturnType lcd_8bit_set_cursor(const lcd_8_t *lcd, uint8 row, uint8 coulmn);

/**
 * 
 * @param lcd
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType lcd_4bit_intialize(lcd_t *lcd){
    std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{    
        pinMode(lcd->rs.port,lcd->rs.pin,OUTPUT);
        pinMode(lcd->en.port,lcd->en.pin,OUTPUT);
        pinMode(lcd->d4.port,lcd->d4.pin,OUTPUT);
        pinMode(lcd->d5.port,lcd->d5.pin,OUTPUT);
        pinMode(lcd->d6.port,lcd->d6.pin,OUTPUT);
        pinMode(lcd->d7.port,lcd->d7.pin,OUTPUT);
        
        __delay_ms(20);
        ret = lcd_4bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        __delay_ms(5);
        ret = lcd_4bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        __delay_us(150);
        ret = lcd_4bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        
        ret = lcd_4bit_send_command(lcd, _LCD_CLEAR);
        ret = lcd_4bit_send_command(lcd, _LCD_RETURN_HOME);
        ret = lcd_4bit_send_command(lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
        ret = lcd_4bit_send_command(lcd, _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
        ret = lcd_4bit_send_command(lcd, _LCD_4BIT_MODE_2_LINE);
        ret = lcd_4bit_send_command(lcd, 0x80);
        
        
        lcd->clear = lcd_4bit_clear;
        lcd->home = lcd_4bit_home;
        lcd->cursor = lcd_4bit_cursor;
        lcd->noCursor = lcd_4bit_no_cursor;
        lcd->blink = lcd_4bit_blink;
        lcd->noBlink = lcd_4bit_no_blink;
        lcd->display = lcd_4bit_display;
        lcd->noDisplay = lcd_4bit_no_display;
        lcd->autoscroll = lcd_4bit_autoscroll;
        lcd->noAutoscroll = lcd_4bit_noAutoscroll;
        lcd->scrollDisplayLeft = lcd_4bit_scrollDisplayLeft;
        lcd->scrollDisplayRight = lcd_4bit_scrollDisplayRight;
        lcd->leftToRight = lcd_4bit_leftToRight;
        lcd->rightToLeft = lcd_4bit_rightToLeft;
        lcd->createChar = lcd_4bit_save_custom_char;
        lcd->print = lcd_4bit_send_string;
        lcd->write = lcd_4bit_send_char_data;
        lcd->setCursor = lcd_4bit_set_cursor;
        
        lcd->lcd_state.var = 0xC6;
        
        ret = lcd_4bit_send_command(lcd, _LCD_RETURN_HOME);
        ret = lcd_4bit_send_command(lcd, _LCD_CURSOR_MOVE_SHIFT_LEFT);
        ret = lcd_4bit_set_cursor(lcd,1,1);
    }
    return ret;
}

/**
 * 
 * @param lcd
 * @param command
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType lcd_4bit_send_command(const lcd_t *lcd, uint8 command){
    std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        /* R/W Pin connected to the GND -> Logic (0) "Hard Wired" */
        /* Write Logic (0) to the "Register Select" Pin to select the "Instruction Register"  */
        digitalWrite(lcd->rs.port,lcd->rs.pin,LOW);
        /* Send the Command through the (4-Pins" Data lines */
        ret = lcd_send_4bits(lcd, command >> 4);
        /* Send the Enable Signal on the "E" Pin */
        ret = lcd_4bit_send_enable_signal(lcd);
        /* Send the Command through the (4-Pins" Data lines */
        ret = lcd_send_4bits(lcd, command);
        /* Send the Enable Signal on the "E" Pin */
        ret = lcd_4bit_send_enable_signal(lcd);
    }
    return ret;
}

/**
 * 
 * @param lcd Pointer to the LCD configurations
 * @param data The data that we need to send to the LCD
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType lcd_4bit_send_char_data(const lcd_t *lcd, uint8 data){
    std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{    
        /* R/W Pin connected to the GND -> Logic (0) "Hard Wired" */
        /* Write Logic (1) to the "Register Select" Pin to select the "Data Register"  */
        digitalWrite(lcd->rs.port,lcd->rs.pin,HIGH);
        /* Send the Data through the (4-Pins" Data lines */
        ret = lcd_send_4bits(lcd, data >> 4);
        /* Send the Enable Signal on the "E" Pin */
        ret = lcd_4bit_send_enable_signal(lcd);
        /* Send the Data through the (4-Pins" Data lines */
        ret = lcd_send_4bits(lcd, data);
        /* Send the Enable Signal on the "E" Pin */
        ret = lcd_4bit_send_enable_signal(lcd);
    }
    return ret;
}

/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param data
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType lcd_4bit_send_char_data_pos(const lcd_t *lcd,uint8 row, uint8 column, uint8 data){
    std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{    
        ret = lcd_4bit_set_cursor(lcd, row, column);
        ret = lcd_4bit_send_char_data(lcd, data);
    }
    return ret;
}

/**
 * 
 * @param lcd
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType lcd_4bit_send_string(const lcd_t *lcd, uint8 *str){
    std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{    
        while(*str){
            ret = lcd_4bit_send_char_data(lcd, *str++);
        }
    }
    return ret;
}

/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType lcd_4bit_send_string_pos(const lcd_t *lcd, uint8 row, uint8 column, uint8 *str){
    std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{ 
        ret = lcd_4bit_set_cursor(lcd, row, column);
        while(*str){
            ret = lcd_4bit_send_char_data(lcd, *str++);
        }
    }
    return ret;
}

/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param _chr
 * @param mem_pos
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType lcd_4bit_save_custom_char(const lcd_t *lcd, const uint8 _chr[], uint8 mem_pos){
    std_ReturnType ret = E_OK;
    uint8 lcd_counter = 0;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{    
        ret = lcd_4bit_send_command(lcd, (_LCD_CGRAM_START+(mem_pos*8)));
        for(lcd_counter=0; lcd_counter<=7; ++lcd_counter){
            ret = lcd_4bit_send_char_data(lcd, _chr[lcd_counter]);
        }
        //ret = lcd_4bit_send_char_data_pos(lcd, row, column, mem_pos);
    }
    return ret;
}

/**
 * 
 * @param lcd
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType lcd_8bit_intialize(const lcd_8_t *lcd){
    std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        pinMode(lcd->rs.port,lcd->rs.pin,OUTPUT);
        pinMode(lcd->en.port,lcd->en.pin,OUTPUT);
        pinMode(lcd->d0.port,lcd->d0.pin,OUTPUT);
        pinMode(lcd->d1.port,lcd->d1.pin,OUTPUT);
        pinMode(lcd->d2.port,lcd->d2.pin,OUTPUT);
        pinMode(lcd->d3.port,lcd->d3.pin,OUTPUT);
        pinMode(lcd->d4.port,lcd->d4.pin,OUTPUT);
        pinMode(lcd->d5.port,lcd->d5.pin,OUTPUT);
        pinMode(lcd->d6.port,lcd->d6.pin,OUTPUT);
        pinMode(lcd->d7.port,lcd->d7.pin,OUTPUT);
        __delay_ms(20);
        ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        __delay_ms(5);
        ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        __delay_us(150);
        ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        
        ret = lcd_8bit_send_command(lcd, _LCD_CLEAR);
        ret = lcd_8bit_send_command(lcd, _LCD_RETURN_HOME);
        ret = lcd_8bit_send_command(lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
        ret = lcd_8bit_send_command(lcd, _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
        ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        ret = lcd_8bit_send_command(lcd, 0x80);
    }
    return ret;
}

/**
 * 
 * @param lcd
 * @param command
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType lcd_8bit_send_command(const lcd_8_t *lcd, uint8 command){
    std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        /* R/W Pin connected to the GND -> Logic (0) "Hard Wired" */
        /* Write Logic (0) to the "Register Select" Pin to select the "Instruction Register"  */
        digitalWrite(lcd->rs.port,lcd->rs.pin,LOW);
        /* Send the Command through the (8-Pins" Data lines */
        lcd_send_8bits(lcd,command);
        /* Send the Enable Signal on the "E" Pin */
        ret = lcd_8bit_send_enable_signal(lcd);
    }
    return ret;
}

/**
 * 
 * @param lcd
 * @param data
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType lcd_8bit_send_char_data(const lcd_8_t *lcd, uint8 data){
    std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        /* R/W Pin connected to the GND -> Logic (0) "Hard Wired" */
        /* Write Logic (1) to the "Register Select" Pin to select the "Data Register"  */
        digitalWrite(lcd->rs.port,lcd->rs.pin,HIGH);
        /* Send the Data through the (8-Pins" Data lines */
        lcd_send_8bits(lcd,data);
        /* Send the Enable Signal on the "E" Pin */
        ret = lcd_8bit_send_enable_signal(lcd);
    }
    return ret;
}

/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param data
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType lcd_8bit_send_char_data_pos(const lcd_8_t *lcd,uint8 row, uint8 column, uint8 data){
    std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{    
        ret = lcd_8bit_set_cursor(lcd, row, column);
        ret = lcd_8bit_send_char_data(lcd, data);
    }
    return ret;
}

/**
 * 
 * @param lcd
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType lcd_8bit_send_string(const lcd_8_t *lcd, uint8 *str){
    std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{    
        while(*str){
            ret = lcd_8bit_send_char_data(lcd, *str++);
        }
    }
    return ret;
}

/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType lcd_8bit_send_string_pos(const lcd_8_t *lcd, uint8 row, uint8 column, uint8 *str){
    std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{    
        ret = lcd_8bit_set_cursor(lcd, row, column);
        ret = lcd_8bit_send_string(lcd, str);
    }
    return ret;
}

/**
 * 
 * @param lcd
 * @param row
 * @param column
 * @param _chr
 * @param mem_pos
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType lcd_8bit_send_custom_char(const lcd_8_t *lcd, uint8 row, uint8 column, 
                                         const uint8 _chr[], uint8 mem_pos){
    std_ReturnType ret = E_OK;
    uint8 lcd_counter = 0;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{    
        ret = lcd_8bit_send_command(lcd, (_LCD_CGRAM_START+(mem_pos*8)));
        for(lcd_counter=0; lcd_counter<=7; ++lcd_counter){
            ret = lcd_8bit_send_char_data(lcd, _chr[lcd_counter]);
        }
        ret = lcd_8bit_send_char_data_pos(lcd, row, column, mem_pos);
    }
    return ret;
}

/**
 * 
 * @param value
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType convert_uint8_to_string(uint8 value, uint8 *str){
    std_ReturnType ret = E_OK;
    if(NULL == str){
        ret = E_NOT_OK;
    }
    else{    
        //memset((char *)str, '\0', 4);
        //sprintf(str, "%i", value);
    }
    return ret;
}

/**
 * 
 * @param value
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType convert_uint16_to_string(uint16 value, uint8 *str){
    std_ReturnType ret = E_OK;
    uint8 Temp_String[6] = {0};
    uint8 DataCounter = 0;
    if(NULL == str){
        ret = E_NOT_OK;
    }
    else{   
        /*
        memset(str, ' ', 5);
        str[5] = '\0';
        sprintf((char *)Temp_String, "%i", value);
        while(Temp_String[DataCounter] != '\0'){
            str[DataCounter] = Temp_String[DataCounter]; 
            DataCounter++;
        }
        */
    }
    return ret;
}

/**
 * 
 * @param value
 * @param str
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType convert_uint32_to_string(uint32 value, uint8 *str){
    std_ReturnType ret = E_OK;
    if(NULL == str){
        ret = E_NOT_OK;
    }
    else{    
        //memset((char *)str, '\0', 11);
        //sprintf(str, "%i", value);
    }
    return ret;
}

/**
 * 
 * @param lcd
 * @param _data_command
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static std_ReturnType lcd_send_4bits(const lcd_t *lcd, uint8 _data_command){
    std_ReturnType ret = E_OK;
    digitalWrite(lcd->d4.port,lcd->d4.pin, (_data_command >> 0) & (uint8)0x01);
    digitalWrite(lcd->d5.port,lcd->d5.pin, (_data_command >> 1) & (uint8)0x01);
    digitalWrite(lcd->d6.port,lcd->d6.pin, (_data_command >> 2) & (uint8)0x01);
    digitalWrite(lcd->d7.port,lcd->d7.pin, (_data_command >> 3) & (uint8)0x01);
   
    return ret;
}

/**
 * 
 * @param lcd
 * @param _data_command
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static std_ReturnType lcd_send_8bits(const lcd_8_t *lcd, uint8 _data_command){
    std_ReturnType ret = E_OK;
    digitalWrite(lcd->d0.port,lcd->d0.pin, (_data_command >> 0) & (uint8)0x01);
    digitalWrite(lcd->d1.port,lcd->d1.pin, (_data_command >> 1) & (uint8)0x01);
    digitalWrite(lcd->d2.port,lcd->d2.pin, (_data_command >> 2) & (uint8)0x01);
    digitalWrite(lcd->d3.port,lcd->d3.pin, (_data_command >> 3) & (uint8)0x01);
    digitalWrite(lcd->d4.port,lcd->d4.pin, (_data_command >> 4) & (uint8)0x01);
    digitalWrite(lcd->d5.port,lcd->d5.pin, (_data_command >> 5) & (uint8)0x01);
    digitalWrite(lcd->d6.port,lcd->d6.pin, (_data_command >> 6) & (uint8)0x01);
    digitalWrite(lcd->d7.port,lcd->d7.pin, (_data_command >> 7) & (uint8)0x01);
   
    return ret;
}

/**
 * 
 * @param lcd
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static std_ReturnType lcd_4bit_send_enable_signal(const lcd_t *lcd){
    std_ReturnType ret = E_OK;
    digitalWrite(lcd->en.port,lcd->en.pin,HIGH);
    __delay_us(5);
    digitalWrite(lcd->en.port,lcd->en.pin,LOW);
    return ret;
}

/**
 * 
 * @param lcd
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static std_ReturnType lcd_8bit_send_enable_signal(const lcd_8_t *lcd){
    std_ReturnType ret = E_OK;
    digitalWrite(lcd->en.port,lcd->en.pin,HIGH);
    __delay_us(5);
    digitalWrite(lcd->en.port,lcd->en.pin,LOW);
    return ret;
}

/**
 * 
 * @param lcd Pointer to the LCD configuration parameters defined by the user
 * @param row Which row you need to print your character
 * @param coulmn Which column you need to print your character
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static std_ReturnType lcd_8bit_set_cursor(const lcd_8_t *lcd, uint8 row, uint8 coulmn){
    std_ReturnType ret = E_OK;
    coulmn--;
    switch(row){
        case ROW1 : ret = lcd_8bit_send_command(lcd, (0x80 + coulmn)); break; /* 0x00 -> Decimal : 0  */
        case ROW2 : ret = lcd_8bit_send_command(lcd, (0xc0 + coulmn)); break; /* 0x40 -> Decimal : 64 */
        case ROW3 : ret = lcd_8bit_send_command(lcd, (0x94 + coulmn)); break; /* 0x14 -> Decimal : 20 */
        case ROW4 : ret = lcd_8bit_send_command(lcd, (0xd4 + coulmn)); break; /* 0x54 -> Decimal : 84 */
        default : ;
    }
    return ret;
}

/**
 * 
 * @param lcd
 * @param row
 * @param coulmn
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static std_ReturnType lcd_4bit_set_cursor(const lcd_t *lcd, uint8 row, uint8 coulmn){
    std_ReturnType ret = E_OK;
    coulmn--;
    switch(row){
        case ROW1 : ret = lcd_4bit_send_command(lcd, (0x80 + coulmn)); break;
        case ROW2 : ret = lcd_4bit_send_command(lcd, (0xc0 + coulmn)); break;
        case ROW3 : ret = lcd_4bit_send_command(lcd, (0x94 + coulmn)); break;
        case ROW4 : ret = lcd_4bit_send_command(lcd, (0xd4 + coulmn)); break;
        default : ;
    }
    return ret;
}

std_ReturnType lcd_4bit_clear(const lcd_t *lcd){
    std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{    
        ret = lcd_4bit_send_command(lcd, _LCD_CLEAR);
    }
    return ret;
}
std_ReturnType lcd_4bit_home(const lcd_t *lcd){
    std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{    
        ret = lcd_4bit_send_command(lcd, _LCD_RETURN_HOME);
        ret = lcd_4bit_send_command(lcd, _LCD_CURSOR_MOVE_SHIFT_LEFT);
        ret = lcd_4bit_set_cursor(lcd,1,1);
    }
    return ret;
}
std_ReturnType lcd_4bit_cursor(lcd_t *lcd){
    std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        lcd->lcd_state.bits.C = 1;
        ret = lcd_4bit_send_command(lcd, (lcd->lcd_state.var)>>4);
    }
    return ret;
}
std_ReturnType lcd_4bit_no_cursor(lcd_t *lcd){
    std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        lcd->lcd_state.bits.C = 0;
        ret = lcd_4bit_send_command(lcd, (lcd->lcd_state.var)>>4);
    }
    return ret;
}
std_ReturnType lcd_4bit_blink(lcd_t *lcd){
    std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        lcd->lcd_state.bits.B = 1;
        ret = lcd_4bit_send_command(lcd, (lcd->lcd_state.var)>>4);
    }
    return ret;
}
std_ReturnType lcd_4bit_no_blink(lcd_t *lcd){
    std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        lcd->lcd_state.bits.B = 0;
        ret = lcd_4bit_send_command(lcd, (lcd->lcd_state.var)>>4);
    }
    return ret;
}
std_ReturnType lcd_4bit_display(lcd_t *lcd){
    std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        lcd->lcd_state.bits.D = 1;
        ret = lcd_4bit_send_command(lcd, (lcd->lcd_state.var)>>4);
    }
    return ret;
}
std_ReturnType lcd_4bit_no_display(lcd_t *lcd){
    std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        lcd->lcd_state.bits.D = 0;
        ret = lcd_4bit_send_command(lcd, (lcd->lcd_state.var)>>4);
    }
    return ret;
}
std_ReturnType lcd_4bit_autoscroll(lcd_t *lcd){
    std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        lcd->lcd_state.bits.S = 1;
        lcd->lcd_state.bits.I_D = 1;
        ret = lcd_4bit_send_command(lcd, _LCD_ENTRY_MODE_INC_SHIFT_ON);
    }
    return ret;
}
std_ReturnType lcd_4bit_noAutoscroll(lcd_t *lcd){
    std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        lcd->lcd_state.bits.S = 0;
        lcd->lcd_state.bits.I_D = 1;
        ret = lcd_4bit_send_command(lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
    }
    return ret;
}
std_ReturnType lcd_4bit_scrollDisplayLeft(lcd_t *lcd){
    std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        ret = lcd_4bit_send_command(lcd, _LCD_DISPLAY_SHIFT_LEFT);
    }
    return ret;
}
std_ReturnType lcd_4bit_scrollDisplayRight(lcd_t *lcd){
    std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        ret = lcd_4bit_send_command(lcd, _LCD_DISPLAY_SHIFT_RIGHT);
    }
    return ret;
}
std_ReturnType lcd_4bit_leftToRight(lcd_t *lcd){
    std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        lcd->lcd_state.bits.S = 0;
        lcd->lcd_state.bits.I_D = 1;
        ret = lcd_4bit_send_command(lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
    }
    return ret;
}
std_ReturnType lcd_4bit_rightToLeft(lcd_t *lcd){
    std_ReturnType ret = E_OK;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        lcd->lcd_state.bits.S = 0;
        lcd->lcd_state.bits.I_D = 0;
        ret = lcd_4bit_send_command(lcd, _LCD_ENTRY_MODE_DEC_SHIFT_OFF);
    }
    return ret;
}

lcd_t LCD_Get_Instance(port_t rs_port,pin_t rs_pin,port_t en_port,pin_t en_pin,
                       port_t d4_port,pin_t d4_pin,port_t d5_port,pin_t d5_pin,
                       port_t d6_port,pin_t d6_pin,port_t d7_port,pin_t d7_pin)
{
    lcd_t lcd_inst;
    lcd_inst.rs.port = rs_port;
    lcd_inst.rs.pin = rs_pin;
    lcd_inst.en.port = en_port;
    lcd_inst.en.pin = en_pin;
    lcd_inst.d4.port = d4_port;
    lcd_inst.d4.pin = d4_pin;
    lcd_inst.d5.port = d5_port;
    lcd_inst.d5.pin = d5_pin;
    lcd_inst.d6.port = d6_port;
    lcd_inst.d6.pin = d6_pin;
    lcd_inst.d7.port = d7_port;
    lcd_inst.d7.pin = d7_pin;
    
    lcd_4bit_intialize(&lcd_inst);
    
    return lcd_inst;
}



