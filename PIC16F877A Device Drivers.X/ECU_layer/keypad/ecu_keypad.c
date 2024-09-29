/* 
 * File:   ecu_Keypad.c
 * Author: Youssef Ahmed Tawfik Ali
 * https://www.linkedin.com/in/youssefahmed2001/
 * Created on May 21, 2021, 9:53 PM
 */

/* Includes -----------------------------------------------------------------------------*/
#include "ecu_keypad.h"

/* Data Type Definition -----------------------------------------------------------------*/
static const uint8 btn_values[ECU_KEYPAD_ROWS][ECU_KEYPAD_COLUMNS] = {
                                                                        {'7', '8', '9', '/'},
                                                                        {'4', '5', '6', '*'},
                                                                        {'1', '2', '3', '-'},
                                                                        {'#', '0', '=', '+'}
                                                                     };

/* Macros -------------------------------------------------------------------------------*/

/* Macro Functions ----------------------------------------------------------------------*/

/* Functions Definition -----------------------------------------------------------------*/
/**
 * @brief Initialize the keypad assigned pins
 * @param _keypad_obj pointer to the keypad configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
std_ReturnType keypad_initialize(keypad_t *_keypad_obj){
    std_ReturnType ret = E_OK;
    if(NULL == _keypad_obj){
        ret = E_NOT_OK;
    }
    else{
        _keypad_obj->get_key = keypad_get_value;
        for(uint8 l_counter=0; l_counter<ECU_KEYPAD_ROWS; l_counter++){
                pinMode(_keypad_obj->row[l_counter].port,_keypad_obj->row[l_counter].pin,OUTPUT);
            }
        for(uint8 l_counter=0; l_counter<ECU_KEYPAD_ROWS; l_counter++){
                pinMode(_keypad_obj->col[l_counter].port,_keypad_obj->col[l_counter].pin,INPUT);
            }
        
        for(uint8 l_counter1=0; l_counter1<ECU_KEYPAD_ROWS; l_counter1++){
                for(uint8 l_counter2=0; l_counter2<ECU_KEYPAD_COLUMNS; l_counter2++){
                    _keypad_obj->btn_values[l_counter1][l_counter2] = btn_values[l_counter1][l_counter2];
                }
            }
    }
    return ret;
}

/**
 * @brief Get the value of the button pressed by the user and performing the scanning algorithm
 * @param _keypad_obj pointer to the keypad configurations
 * @param value Value of the button pressed by the user
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action 
 */
uint8 keypad_get_value(const keypad_t *_keypad_obj){
    std_ReturnType ret = E_OK;
    uint8 l_rows_counter = 0, l_columns_counter = 0, l_counter = 0;
    uint8 column_logic = 0;
    if((NULL == _keypad_obj)){
        ret = E_NOT_OK;
    }
    else{    
        for(l_rows_counter=0; l_rows_counter<ECU_KEYPAD_ROWS; l_rows_counter++){
            for(l_counter=0; l_counter<ECU_KEYPAD_ROWS; l_counter++){
                digitalWrite(_keypad_obj->row[l_counter].port,_keypad_obj->row[l_counter].pin,LOW);
            }
            digitalWrite(_keypad_obj->row[l_rows_counter].port,_keypad_obj->row[l_rows_counter].pin,HIGH);
            __delay_ms(10);
            for(l_columns_counter=0; l_columns_counter<ECU_KEYPAD_COLUMNS; l_columns_counter++){
                column_logic = digitalRead(_keypad_obj->col[l_columns_counter].port,_keypad_obj->col[l_columns_counter].pin);
                if(HIGH == column_logic){
                    return _keypad_obj->btn_values[l_rows_counter][l_columns_counter];
                }
            }
        }
    }
    return 0;
}

keypad_t Keypad_Get_Instance(uint8 port_pin_row[ECU_KEYPAD_ROWS][2],uint8 port_pin_col[ECU_KEYPAD_ROWS][2])
{
    keypad_t _keypad_obj;
    
    for(uint8 l_counter1=0; l_counter1<ECU_KEYPAD_ROWS; l_counter1++){
        
        _keypad_obj.row[l_counter1].port = port_pin_row[l_counter1][0];
        _keypad_obj.row[l_counter1].pin = port_pin_row[l_counter1][1];
        
        _keypad_obj.col[l_counter1].port = port_pin_col[l_counter1][0];
        _keypad_obj.col[l_counter1].pin = port_pin_col[l_counter1][1];
    }
    
    /*
    if(btn_values){
        for(uint8 l_counter1=0; l_counter1<ECU_KEYPAD_ROWS; l_counter1++){
        for(uint8 l_counter2=0; l_counter2<ECU_KEYPAD_COLUMNS; l_counter2++){
                _keypad_obj.btn_values[l_counter1][l_counter2] = btn_values[l_counter1][l_counter2];
            }
        }
    }
    else{}
    */
    keypad_initialize(&_keypad_obj);
    return _keypad_obj;
}
