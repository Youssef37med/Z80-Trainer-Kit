/* 
 * File:   hal_timr0.c
 * Author: Youssef Ahmed Tawfik Ali
 * https://www.linkedin.com/in/youssefahmed2001/
 * Created on April 6, 2021, 8:53 PM
 */

/* Includes -----------------------------------------------------------------------------*/
#include "hal_timr0.h"

/* Data Type Definition -----------------------------------------------------------------*/
#if TIMER0_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
    static void (*TMR0_InterruptHandler)(void) = NULL;
#endif
static uint16 timer0_preload = 0;

/* Macros -------------------------------------------------------------------------------*/

/* Macro Functions ----------------------------------------------------------------------*/

/* Functions Definition -----------------------------------------------------------------*/
static inline void Timer0_Prescaler_Config(uint8 prescaler,uint8 prescaler_en);
static inline void Timer0_Mode_Select(uint8 mode);

void HAL_TIMER0_Init(uint8 preload,uint8 prescaler,uint8 prescaler_en,uint8 mode,void (*InterruptHandler)(void)){

        
    Timer0_Prescaler_Config(prescaler,prescaler_en);
    Timer0_Mode_Select(mode);
    TMR0 = preload;
    timer0_preload = preload;
    /* Interrupt Configurations */        
    #if TIMER0_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
            TIMER0_InterruptEnable();
            INTERRUPT_GlobalInterruptEnable();
            INTERRUPT_PeripheralInterruptEnable();
            TIMER0_InterruptFlagClear();
            TMR0_InterruptHandler = InterruptHandler;

    /* Interrupt Priority Configurations */

    #endif
}

void HAL_TIMER0_DeInit(){

    #if TIMER0_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
            TIMER0_InterruptDisable();
    #endif
}

std_ReturnType HAL_TIMER0_Write_Value(uint8 _value){
    std_ReturnType ret = E_NOT_OK;
    if(_value < 0){
        ret = E_NOT_OK;
    }
    else{
        TMR0 = _value;
        ret = E_OK;
    }
    return ret;
}

uint8 HAL_TIMER0_Read_Value(){
    
    uint8 _value = TMR0;
    return _value;
}

void TMR0_ISR(void){
    TIMER0_InterruptFlagClear();
    TMR0 = timer0_preload;
    if(TMR0_InterruptHandler){
        TMR0_InterruptHandler();
    }
}

static inline void Timer0_Prescaler_Config(uint8 prescaler,uint8 prescaler_en){
    if(TIMER0_PRESCALER_ENABLE_CFG == prescaler_en){
        TIMER0_PRESCALER_ENABLE();
        OPTION_REGbits.PS = prescaler;
    }
    else if(TIMER0_PRESCALER_DISABLE_CFG == prescaler_en){
        TIMER0_PRESCALER_DISABLE();
        OPTION_REGbits.PS = 0;
    }
    else{ /* Nothing */ }
}

static inline void Timer0_Mode_Select(uint8 mode){
    if(TIMER0_TIMER_MODE == mode){
        TIMER0_TIMER_MODE_ENABLE();
    }
    else if(TIMER0_COUNTER_MODE_RISING == mode){
        TIMER0_COUNTER_MODE_ENABLE();
        TIMER0_RISING_EDGE_ENABLE();
    }
    else if(TIMER0_COUNTER_MODE_FALLING == mode){
        TIMER0_COUNTER_MODE_ENABLE();
        TIMER0_FALLING_EDGE_ENABLE();
    }
    else{ /* Nothing */ }
}
