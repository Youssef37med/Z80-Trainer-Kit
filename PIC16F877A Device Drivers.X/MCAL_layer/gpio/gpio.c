/* 
 * File:   gpio.c
 * Author: Youssef Ahmed Tawfik Ali
 * https://www.linkedin.com/in/youssefahmed2001/
 * Created on May 21, 2021, 9:53 PM
 */

/* Includes ---------------------------------------------------------------------------*/
#include "gpio.h"

/* Data Type Definition -----------------------------------------------------------------*/

/* Macros -------------------------------------------------------------------------------*/

/* Macro Functions ----------------------------------------------------------------------*/

/* Functions Declarations ---------------------------------------------------------------*/
/**
  * @brief  Reads the specified input port pin.
  * @param  port specifies the port bit to read.
  *         can be PA,PB,PC,PD,PE
  * @param  GPIO_Pin specifies the port bit to read.
  *         This parameter can be GPIO_PIN_x where x can be (0..15).
  * @retval The input port pin value.
  */
void pinMode(port_t Portx, pin_t Pinx, pinmode_t mode) {
    if (mode == OUTPUT) {
        // Set the pin as output
        switch (Portx) {
            case PA:
                CLEAR_BIT(TRISA, Pinx);
                break;
            case PB:
                CLEAR_BIT(TRISB, Pinx);
                break;
            case PC:
                CLEAR_BIT(TRISC, Pinx);
                break;
            case PD:
                CLEAR_BIT(TRISD, Pinx);
                break;
            case PE:
                CLEAR_BIT(TRISE, Pinx);
                break;
            default:
                break;
        }
    } else if (mode == INPUT) {
        // Set the pin as input
        switch (Portx) {
            case PA:
                SET_BIT(TRISA, Pinx);
                break;
            case PB:
                SET_BIT(TRISB, Pinx);
                break;
            case PC:
                SET_BIT(TRISC, Pinx);
                break;
            case PD:
                SET_BIT(TRISD, Pinx);
                break;
            case PE:
                SET_BIT(TRISE, Pinx);
                break;
            default:
                break;
        }
    }
}

/**
  * @brief  Reads the specified input port pin.
  * @param  port specifies the port bit to read.
  *         can be PA,PB,PC,PD,PE
  * @param  GPIO_Pin specifies the port bit to read.
  *         This parameter can be GPIO_PIN_x where x can be (0..15).
  * @retval The input port pin value.
  */
void digitalWrite(port_t Portx, pin_t Pinx, logic_t logic) {
    if (logic == HIGH) {
        // Set the pin HIGH
        switch (Portx) {
            case PA:
                SET_BIT(PORTA, Pinx);
                break;
            case PB:
                SET_BIT(PORTB, Pinx);
                break;
            case PC:
                SET_BIT(PORTC, Pinx);
                break;
            case PD:
                SET_BIT(PORTD, Pinx);
                break;
            case PE:
                SET_BIT(PORTE, Pinx);
                break;
            default:
                break;
        }
    } else if (logic == LOW) {
        // Set the pin LOW
        switch (Portx) {
            case PA:
                CLEAR_BIT(PORTA, Pinx);
                break;
            case PB:
                CLEAR_BIT(PORTB, Pinx);
                break;
            case PC:
                CLEAR_BIT(PORTC, Pinx);
                break;
            case PD:
                CLEAR_BIT(PORTD, Pinx);
                break;
            case PE:
                CLEAR_BIT(PORTE, Pinx);
                break;
            default:
                break;
        }
    }
}

/**
  * @brief  Reads the specified input port pin.
  * @param  port specifies the port bit to read.
  *         can be PA,PB,PC,PD,PE
  * @param  GPIO_Pin specifies the port bit to read.
  *         This parameter can be GPIO_PIN_x where x can be (0..15).
  * @retval The input port pin value.
  */
logic_t digitalRead(port_t Portx, pin_t Pinx) {
    logic_t level = LOW;
    switch (Portx) {
        case PA:
            level = READ_BIT(PORTA, Pinx) ? HIGH : LOW;
            break;
        case PB:
            level = READ_BIT(PORTB, Pinx) ? HIGH : LOW;
            break;
        case PC:
            level = READ_BIT(PORTC, Pinx) ? HIGH : LOW;
            break;
        case PD:
            level = READ_BIT(PORTD, Pinx) ? HIGH : LOW;
            break;
        case PE:
            level = READ_BIT(PORTE, Pinx) ? HIGH : LOW;
            break;
        default:
            break;
    }
    return level;
}

/**
  * @brief  Reads the specified input port pin.
  * @param  port specifies the port bit to read.
  *         can be PA,PB,PC,PD,PE
  * @param  GPIO_Pin specifies the port bit to read.
  *         This parameter can be GPIO_PIN_x where x can be (0..15).
  * @retval The input port pin value.
  */
void togglePin(port_t Portx, pin_t Pinx){
    switch (Portx) {
        case PA:
            TOGGLE_BIT(PORTA, Pinx) ? HIGH : LOW;
            break;
        case PB:
            TOGGLE_BIT(PORTB, Pinx) ? HIGH : LOW;
            break;
        case PC:
            TOGGLE_BIT(PORTC, Pinx) ? HIGH : LOW;
            break;
        case PD:
            TOGGLE_BIT(PORTD, Pinx) ? HIGH : LOW;
            break;
        case PE:
            TOGGLE_BIT(PORTE, Pinx) ? HIGH : LOW;
            break;
        default:
            break;
    }
}
