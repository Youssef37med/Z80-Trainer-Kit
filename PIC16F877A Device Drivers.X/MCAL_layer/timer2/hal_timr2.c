/* 
 * File:   hal_timr2.c
 * Author: Youssef Ahmed Tawfik Ali
 * https://www.linkedin.com/in/youssefahmed2001/
 * Created on May 13, 2021, 11:30 PM
 */

/* Includes -----------------------------------------------------------------------------*/
#include "hal_timr2.h"

/* Data Type Definition -----------------------------------------------------------------*/
#if TIMER2_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
    static void (*TMR2_InterruptHandler)(void) = NULL;
#endif
static uint8 timer2_preload = 0;

/* Macros -------------------------------------------------------------------------------*/

/* Macro Functions ----------------------------------------------------------------------*/

/* Functions Definition -----------------------------------------------------------------*/
void HAL_TIMER2_Init(uint16 preload,uint8 pr2,uint8 prescaler,uint8 postscaler,void (*InterruptHandler)(void)){
    
    TIMER2_MODULE_DISABLE();
    TIMER2_PRESCALER_SELECT(prescaler);
    TIMER2_POSTSCALER_SELECT(postscaler);
    TMR2 = preload;
    timer2_preload = preload;
    PR2 = pr2;
    TIMER2_MODULE_ENABLE();
/* Interrupt Configurations */        
#if TIMER2_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
        TIMER2_InterruptEnable();
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
        TIMER2_InterruptFlagClear();
        TMR2_InterruptHandler = InterruptHandler;
/* Interrupt Priority Configurations */
#endif        
    
}

void HAL_TIMER2_DeInit(){
    
    TIMER2_MODULE_DISABLE();
    #if TIMER2_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
            TIMER2_InterruptDisable();
    #endif
      
}

std_ReturnType HAL_TIMER2_Write_Value(uint8 _value){
    std_ReturnType ret = E_NOT_OK;
    if(_value < 0){
        ret = E_NOT_OK;
    }
    else{
        TMR2 = _value;
        ret = E_OK;
    }
    return ret;
}

uint8 HAL_TIMER2_Read_Value(){
    
    uint8 _value = TMR2;
    
    return _value;
}

void HAL_TIMER2_start()
{
    TIMER2_MODULE_ENABLE();
}

void HAL_TIMER2_stop()
{
    TIMER2_MODULE_DISABLE();
}

void TMR2_ISR(void){
    TIMER2_InterruptFlagClear();
    TMR2 = timer2_preload;
    if(TMR2_InterruptHandler){
        TMR2_InterruptHandler();
    }
}



