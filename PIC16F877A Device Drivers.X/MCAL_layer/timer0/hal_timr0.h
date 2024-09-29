/* 
 * File:   hal_timr0.h
 * Author: Youssef Ahmed Tawfik Ali
 * https://www.linkedin.com/in/youssefahmed2001/
 * Created on April 6, 2021, 8:53 PM
 */

#ifndef HAL_TIMR0_H
#define	HAL_TIMR0_H

/* Includes -----------------------------------------------------------------------------*/
#include "pic16f877a.h"
#include "../mcal_std_types.h"
#include "../../MCAL_layer/gpio/gpio.h"
#include "../../MCAL_Layer/Interrupt/mcal_internal_interrupt.h"

/* Data Type Declaration ----------------------------------------------------------------*/
typedef enum{
    TIMER0_PRESCALER_DIV_BY_2 = 0,
    TIMER0_PRESCALER_DIV_BY_4,
    TIMER0_PRESCALER_DIV_BY_8,
    TIMER0_PRESCALER_DIV_BY_16,
    TIMER0_PRESCALER_DIV_BY_32,
    TIMER0_PRESCALER_DIV_BY_64,
    TIMER0_PRESCALER_DIV_BY_128,
    TIMER0_PRESCALER_DIV_BY_256
}timer0_prescaler_select_t;

/* Macros -------------------------------------------------------------------------------*/
#define TIMER0_TIMER_MODE                0
#define TIMER0_COUNTER_MODE_RISING       1
#define TIMER0_COUNTER_MODE_FALLING      2
#define TIMER0_PRESCALER_ENABLE_CFG      1
#define TIMER0_PRESCALER_DISABLE_CFG     0

/* Macro Functions ----------------------------------------------------------------------*/
#define TIMER0_PRESCALER_ENABLE()           (OPTION_REGbits.PSA = 0)
#define TIMER0_PRESCALER_DISABLE()          (OPTION_REGbits.PSA = 1)
#define TIMER0_RISING_EDGE_ENABLE()         (OPTION_REGbits.T0SE = 0)
#define TIMER0_FALLING_EDGE_ENABLE()        (OPTION_REGbits.T0SE = 1)
#define TIMER0_TIMER_MODE_ENABLE()          (OPTION_REGbits.T0CS = 0)
#define TIMER0_COUNTER_MODE_ENABLE()        (OPTION_REGbits.T0CS = 1)

/* Functions Declarations ---------------------------------------------------------------*/
void HAL_TIMER0_Init(uint8 preload,uint8 prescaler,uint8 prescaler_en,uint8 mode,void (*InterruptHandler)(void));
void HAL_TIMER0_DeInit();
std_ReturnType HAL_TIMER0_Write_Value(uint8 _value);
uint8 HAL_TIMER0_Read_Value();

#endif	/* HAL_TIMR0_H */
