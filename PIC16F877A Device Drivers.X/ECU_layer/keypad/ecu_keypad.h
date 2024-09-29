/* 
 * File:   ecu_Keypad.h
 * Author: Youssef Ahmed Tawfik Ali
 * https://www.linkedin.com/in/youssefahmed2001/
 * Created on May 21, 2021, 9:53 PM
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H

/* Includes -----------------------------------------------------------------------------*/
#include "ecu_keypad_cfg.h"
#include "../../MCAL_Layer/gpio/gpio.h"

/* Macros -------------------------------------------------------------------------------*/
#define ECU_KEYPAD_ROWS    4
#define ECU_KEYPAD_COLUMNS 4

/* Data Type Declaration ----------------------------------------------------------------*/
typedef struct{
    uint8 port  : 4;
    uint8 pin   : 4;
}keypad_pin_t;
typedef struct{
    keypad_pin_t row[ECU_KEYPAD_ROWS];  
    keypad_pin_t col[ECU_KEYPAD_COLUMNS];
    uint8 (*get_key) (const struct keypad_t *_keypad_obj);
    uint8 btn_values[ECU_KEYPAD_ROWS][ECU_KEYPAD_COLUMNS];
    
}keypad_t;

/* Macro Functions ----------------------------------------------------------------------*/

/* Functions Declarations ---------------------------------------------------------------*/
std_ReturnType keypad_initialize(keypad_t *_keypad_obj);
uint8 keypad_get_value(const keypad_t *_keypad_obj);
keypad_t Keypad_Get_Instance(uint8 port_pin_row[ECU_KEYPAD_ROWS][2],uint8 port_pin_col[ECU_KEYPAD_ROWS][2]);

#endif	/* ECU_KEYPAD_H */

