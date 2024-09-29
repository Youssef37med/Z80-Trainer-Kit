/* 
 * File:   mcal_internal_interrupt.c
 * Author: Youssef Ahmed Tawfik Ali
 * https://www.linkedin.com/in/youssefahmed2001/
 * Created on February 14, 2021, 11:52 PM
 */

/* Includes -----------------------------------------------------------------------------*/
#include "mcal_external_interrupt.h"

/* Data Type Definition -----------------------------------------------------------------*/
#if EXTERNAL_INTERRUPT_INTx_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
    /* Pointer to function to hold the callbacks for INTx */
    static InterruptHandler INT0_InterruptHandler = NULL;
#endif

#if EXTERNAL_INTERRUPT_OnChange_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
    /* Pointer to function to hold the callbacks for RBx */
    static InterruptHandler RB4_InterruptHandler_HIGH = NULL;
    static InterruptHandler RB4_InterruptHandler_LOW = NULL;
    static InterruptHandler RB5_InterruptHandler_HIGH = NULL;
    static InterruptHandler RB5_InterruptHandler_LOW = NULL;
    static InterruptHandler RB6_InterruptHandler_HIGH = NULL;
    static InterruptHandler RB6_InterruptHandler_LOW = NULL;
    static InterruptHandler RB7_InterruptHandler_HIGH = NULL;
    static InterruptHandler RB7_InterruptHandler_LOW = NULL;
#endif

/* Macros -------------------------------------------------------------------------------*/

/* Macro Functions ----------------------------------------------------------------------*/

/* Functions Definition -----------------------------------------------------------------*/
static std_ReturnType Interrupt_INT0_Pin_Init();
static void Interrupt_RBx_Pin_Init();

static std_ReturnType RBx_SetInterruptHandler(interrupt_RBX_src pin,void (*InterruptHandler_high)(void),void (*InterruptHandler_low)(void));
static std_ReturnType INT0_SetInterruptHandler(void (*InterruptHandler)(void));



/**
 * External Interrupt 0 MCAL Helper function 
 */
void INT0_ISR(void){
    /* The INT0 external interrupt occurred (must be cleared in software) */
    EXT_INT0_InterruptFlagClear();
    /* Code : To be executed from MCAL Interrupt Context */
    /* Application Callback function gets called every time this ISR executes */
    if(INT0_InterruptHandler){ INT0_InterruptHandler(); }
    else{ /* Nothing */ }
}

/**
 * External Interrupt RB4 MCAL Helper function 
 */
void RB4_ISR(uint8 RB4_Source){
    /* The RB4 external OnChange interrupt occurred (must be cleared in software) */
    EXT_RBx_InterruptFlagClear();
    /* Code : To be executed from MCAL Interrupt Context */
    /* Application Callback function gets called every time this ISR executes */
    if(0 == RB4_Source){
        if(RB4_InterruptHandler_HIGH){ RB4_InterruptHandler_HIGH(); }
        else{ /* Nothing */ }
    }
    else if (1 == RB4_Source){
        if(RB4_InterruptHandler_LOW){ RB4_InterruptHandler_LOW(); }
        else{ /* Nothing */ }
    }
    else { /* Nothing */ }   
}

/**
 * External Interrupt RB4 MCAL Helper function 
 */
void RB5_ISR(uint8 RB5_Source){
    /* The RB4 external OnChange interrupt occurred (must be cleared in software) */
    EXT_RBx_InterruptFlagClear();
    /* Code : To be executed from MCAL Interrupt Context */
    /* Application Callback function gets called every time this ISR executes */
    if(0 == RB5_Source){
        if(RB5_InterruptHandler_HIGH){ RB5_InterruptHandler_HIGH(); }
        else{ /* Nothing */ }
    }
    else if (1 == RB5_Source){
        if(RB5_InterruptHandler_LOW){ RB5_InterruptHandler_LOW(); }
        else{ /* Nothing */ }
    }
    else { /* Nothing */ }
}

/**
 * External Interrupt RB4 MCAL Helper function 
 */
void RB6_ISR(uint8 RB6_Source){
    /* The RB4 external OnChange interrupt occurred (must be cleared in software) */
    EXT_RBx_InterruptFlagClear();
    /* Code : To be executed from MCAL Interrupt Context */
    /* Application Callback function gets called every time this ISR executes */
    if(0 == RB6_Source){
        if(RB6_InterruptHandler_HIGH){ RB6_InterruptHandler_HIGH(); }
        else{ /* Nothing */ }
    }
    else if (1 == RB6_Source){
        if(RB6_InterruptHandler_LOW){ RB6_InterruptHandler_LOW(); }
        else{ /* Nothing */ }
    }
    else { /* Nothing */ }   
}

/**
 * External Interrupt RB4 MCAL Helper function 
 */
void RB7_ISR(uint8 RB7_Source){
    /* The RB4 external OnChange interrupt occurred (must be cleared in software) */
    EXT_RBx_InterruptFlagClear();
    /* Code : To be executed from MCAL Interrupt Context */
    /* Application Callback function gets called every time this ISR executes */
    if(0 == RB7_Source){
        if(RB7_InterruptHandler_HIGH){ RB7_InterruptHandler_HIGH(); }
        else{ /* Nothing */ }
    }
    else if (1 == RB7_Source){
        if(RB7_InterruptHandler_LOW){ RB7_InterruptHandler_LOW(); }
        else{ /* Nothing */ }
    }
    else { /* Nothing */ }   
}



/**
 * @brief  
 * @param InterruptHandler
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
static std_ReturnType INT0_SetInterruptHandler(void (*InterruptHandler)(void)){
    std_ReturnType ret = E_NOT_OK;
    if(NULL == InterruptHandler){
        ret = E_NOT_OK;
    }
    else{
        /* Set Default Interrupt Handler for INT0 External Interrupt : Application ISR */
        INT0_InterruptHandler = InterruptHandler;
        ret = E_OK;
    }
    return ret;
}

static std_ReturnType RBx_SetInterruptHandler(interrupt_RBX_src pin,void (*InterruptHandler_high)(void),void (*InterruptHandler_low)(void)){
    std_ReturnType ret = E_NOT_OK;
    if(NULL == InterruptHandler_high && NULL == InterruptHandler_low){
        ret = E_NOT_OK;
    }
    else{        
        
        
        /* Initialize the call back functions */
        switch(pin){
            case INTERRUPT_EXTERNAL_RB4 :
                /* Initialize the RBx pin to be input */
                pinMode(PB,PIN4,INPUT);
                RB4_InterruptHandler_HIGH = InterruptHandler_high;
                RB4_InterruptHandler_LOW = InterruptHandler_low;
                break;
            case INTERRUPT_EXTERNAL_RB5 :
                /* Initialize the RBx pin to be input */
                pinMode(PB,PIN5,INPUT);
                RB5_InterruptHandler_HIGH = InterruptHandler_high;
                RB5_InterruptHandler_LOW = InterruptHandler_low;
                break;
            case INTERRUPT_EXTERNAL_RB6 :
                /* Initialize the RBx pin to be input */
                pinMode(PB,PIN6,INPUT);
                RB6_InterruptHandler_HIGH = InterruptHandler_high;
                RB6_InterruptHandler_LOW = InterruptHandler_low;
                break;
            case INTERRUPT_EXTERNAL_RB7 :
                /* Initialize the RBx pin to be input */
                pinMode(PB,PIN7,INPUT);
                RB7_InterruptHandler_HIGH = InterruptHandler_high;
                RB7_InterruptHandler_LOW = InterruptHandler_low;
                break;
            default:
                ret = E_NOT_OK;
        }
        
        ret = E_OK;
    }
    return ret;
}

static std_ReturnType Interrupt_INT0_Pin_Init(void (*InterruptHandler)(void),interrupt_INTx_edge edge){
    std_ReturnType ret = E_NOT_OK;
    if(NULL == InterruptHandler){
        ret = E_NOT_OK;
    }
    else{
            EXT_INT0_InterruptDisable();
            EXT_INT0_InterruptFlagClear();
            if(FALLING==edge){EXT_INT0_FallingEdgeSet();}
            else if(RISING==edge){EXT_INT0_RisingEdgeSet();}
            pinMode(PB,PIN0,INPUT);
            INT0_SetInterruptHandler(InterruptHandler);
            EXT_INT0_InterruptEnable();
            INTERRUPT_GlobalInterruptEnable();
            ret = E_OK;
    }
    return ret;
}
static void Interrupt_RBx_Pin_Init(){
    
        /* This routine clears the interrupt disable for the external interrupt, RBx */
        EXT_RBx_InterruptDisable();
        /* This routine clears the interrupt flag for the external interrupt, RBx */
        EXT_RBx_InterruptFlagClear();

        /* This routine sets the interrupt enable for the external interrupt, RBx */
        EXT_RBx_InterruptEnable();
        INTERRUPT_GlobalInterruptEnable();
    
}

/* ----------------- Software Interfaces Declarations -----------------*/
void attachInterrupt_INT0(void (*InterruptHandler)(void),interrupt_INTx_edge edge){
    Interrupt_INT0_Pin_Init(InterruptHandler,edge);
}
void attachInterrupt_RBx(interrupt_RBX_src pin,void (*InterruptHandler_high)(void),void (*InterruptHandler_low)(void)){
    Interrupt_RBx_Pin_Init();
    RBx_SetInterruptHandler(pin,InterruptHandler_high,InterruptHandler_low);
}