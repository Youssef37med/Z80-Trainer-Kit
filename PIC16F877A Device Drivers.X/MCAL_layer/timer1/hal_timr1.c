/* 
 * File:   hal_timr1.c
 * Author: YOussef Ahmed Tawfik Ali
 * https://www.linkedin.com/in/youssefahmed2001/
 * Created on May 12, 2021, 1:05 AM
 */

/* Includes -----------------------------------------------------------------------------*/
#include "hal_timr1.h"


/* Data Type Definition -----------------------------------------------------------------*/
#if TIMER1_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
    static volatile void (*TMR1_InterruptHandler)(void) = NULL;
#endif
static volatile uint16 timer1_preload = 0;

/* Macros -------------------------------------------------------------------------------*/

/* Macro Functions ----------------------------------------------------------------------*/

/* Functions Definition -----------------------------------------------------------------*/
static inline void Timer1_Mode_Select(uint8 mode);

void HAL_TIMER1_Init(uint16 preload,uint8 prescaler,uint8 mode,void (*InterruptHandler)(void)){
    TIMER1_MODULE_DISABLE();
    TIMER1_PRESCALER_SELECT(prescaler);
    Timer1_Mode_Select(mode);
    TMR1H = (preload) >> 8;
    TMR1L = (uint8)(preload);
    timer1_preload = preload;
    /* Interrupt Configurations */        
    #if TIMER1_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
            TIMER1_InterruptEnable();
            TIMER1_InterruptFlagClear();
            INTERRUPT_GlobalInterruptEnable();
            INTERRUPT_PeripheralInterruptEnable();
            TMR1_InterruptHandler = InterruptHandler;
    /* Interrupt Priority Configurations */
    #endif
    //TIMER1_MODULE_ENABLE();
}

void HAL_TIMER1_DeInit(){
    
    TIMER1_MODULE_DISABLE();
    #if TIMER1_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
            TIMER1_InterruptDisable();
    #endif
}
    
std_ReturnType HAL_TIMER1_Write_Value(uint16 _value){
    std_ReturnType ret = E_NOT_OK;
    if(_value < 0){
        ret = E_NOT_OK;
    }
    else{
        TMR1H = (_value) >> 8;
        TMR1L = (uint8)(_value);
        ret = E_OK;
    }
    return ret;
}

uint16 HAL_TIMER1_Read_Value(){
    
    uint8 l_tmr1l = 0, l_tmr1h = 0;
    
    l_tmr1l = TMR1L;
    l_tmr1h = TMR1H;
    uint16 _value = (uint16)((l_tmr1h << 8) + l_tmr1l);
    return _value;
    
}

void HAL_TIMER1_Start(){TIMER1_MODULE_ENABLE();}

void HAL_TIMER1_Stop(){TIMER1_MODULE_DISABLE();}

void TMR1_ISR(void){
    TIMER1_InterruptFlagClear();     /* Clear the interrupt flag */
    TMR1H = (timer1_preload) >> 8;   /* Initialize the pre-loaded value again */
    TMR1L = (uint8)(timer1_preload); /* Initialize the pre-loaded value again */
    if(TMR1_InterruptHandler){
        TMR1_InterruptHandler();     /* Call the callback function */
    }
}

static inline void Timer1_Mode_Select(uint8 mode){
    if(TIMER1_TIMER_MODE == mode){
        TIMER1_TIMER_MODE_ENABLE();
        TIMER1_ASYNC_COUNTER_MODE_ENABLE();
    }
    else if(TIMER1_COUNTER_MODE == mode){
        TIMER1_COUNTER_MODE_ENABLE();
        TIMER1_SYNC_COUNTER_MODE_ENABLE();
        TIMER1_OSC_HW_ENABLE();
        pinMode(PC,PIN0,INPUT);
    }
    else{ /* Nothing */ }
}
