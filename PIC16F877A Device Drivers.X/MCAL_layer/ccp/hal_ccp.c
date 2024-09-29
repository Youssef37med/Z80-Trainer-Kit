/* 
 * File:   hal_ccp.h
 * Author: Youssef Ahmed Tawfik Ali
 * https://www.linkedin.com/in/youssefahmed2001/
 * Created on April 6, 2021, 8:53 PM
 */

/* Includes -----------------------------------------------------------------------------*/
#include "hal_ccp.h"

/* Data Type Definition -----------------------------------------------------------------*/
#if CCP1_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
    static void (*CCP1_InterruptHandler)(void) = NULL;
#endif
    
#if CCP2_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
    static void (*CCP2_InterruptHandler)(void) = NULL;
#endif

/* Macros -------------------------------------------------------------------------------*/

/* Macro Functions ----------------------------------------------------------------------*/

/* Functions Declarations ---------------------------------------------------------------*/
static void CCP_Interrupt_Config(ccp_pin_t pin,void (* InterruptHandler)(void));
static std_ReturnType CCP_Capture_Mode_Config(ccp_pin_t pin,uint8 mode);
static std_ReturnType CCP_Compare_Mode_Config(ccp_pin_t pin,uint8 mode);
static void CCP_PWM_Mode_Config(ccp_pin_t pin);


std_ReturnType HAL_CCP_Capture_Mode_Init(ccp_pin_t pin,uint8 mode,void (* InterruptHandler)(void)){
    std_ReturnType ret = E_NOT_OK;
    if(NULL == InterruptHandler){
        ret = E_NOT_OK;
    }
    else{
        /* CCP Module Disable */
        if(CCP1_PIN == pin){
            CCP1_SET_MODE(CCP_MODULE_DISABLE);
            pinMode(PC,PIN2,INPUT);
        }
        else if(CCP2_PIN == pin){
            CCP2_SET_MODE(CCP_MODULE_DISABLE);
            pinMode(PC,PIN1,INPUT);
        }
        else { /* Nothing */ }
                
        /* Interrupt Configurations for CCP1 and CCP2 Modules */
        CCP_Interrupt_Config(pin,InterruptHandler);
        
        /* CCP Module Capture Mode Initialization */
        ret = CCP_Capture_Mode_Config(pin,mode);

        ret = E_OK;
    }
    return ret;
}

std_ReturnType HAL_CCP_Compare_Mode_Init(ccp_pin_t pin,uint8 mode,void (* InterruptHandler)(void)){
    std_ReturnType ret = E_NOT_OK;
    
    /* CCP Module Disable */
    if(CCP1_PIN == pin){
        CCP1_SET_MODE(CCP_MODULE_DISABLE);
        pinMode(PC,PIN2,OUTPUT);
    }
    else if(CCP2_PIN == pin){
        CCP2_SET_MODE(CCP_MODULE_DISABLE);
        pinMode(PC,PIN1,OUTPUT);
    }
    else { /* Nothing */ }

    /* Interrupt Configurations for CCP1 and CCP2 Modules */
    CCP_Interrupt_Config(pin,InterruptHandler);
    
    /* CCP Module Compare Mode Initialization */
    ret = CCP_Compare_Mode_Config(pin,mode);
        
    return ret;
}

std_ReturnType HAL_CCP_Pwm_Mode_Init(ccp_pin_t pin,void (* InterruptHandler)(void)){
    std_ReturnType ret = E_NOT_OK;
    if(pin < 0){
        ret = E_NOT_OK;
    }
    else{
        /* CCP Module Disable */
        if(CCP1_PIN == pin){
            CCP1_SET_MODE(CCP_MODULE_DISABLE);
            pinMode(PC,PIN2,OUTPUT);
        }
        else if(CCP2_PIN == pin){
            CCP2_SET_MODE(CCP_MODULE_DISABLE);
            pinMode(PC,PIN1,OUTPUT);
        }
        else { /* Nothing */ }
        
        
        /* CCP Module PWM Mode Initialization */
        CCP_PWM_Mode_Config(pin);
        
        /* Interrupt Configurations for CCP1 and CCP2 Modules */
        CCP_Interrupt_Config(pin,InterruptHandler);

        ret = E_OK;
    }
    return ret;
}

std_ReturnType HAL_CCP_DeInit(ccp_pin_t pin){
    std_ReturnType ret = E_NOT_OK;
    if(CCP1_PIN == pin || CCP2_PIN == pin){
        ret = E_NOT_OK;
    }
    else{
        if(CCP1_PIN == pin){
            CCP1_SET_MODE(CCP_MODULE_DISABLE); /* CCP1 Module Disable */
/* Interrupt Configurations */ 
#if CCP1_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
            CCP1_InterruptDisable();
#endif 
        }
        else if(CCP2_PIN == pin){
            CCP2_SET_MODE(CCP_MODULE_DISABLE); /* CCP2 Module Disable */
#if CCP2_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
            CCP2_InterruptDisable();
#endif  
        }
        else { /* Nothing */ }
 
        ret = E_OK;
    }
    return ret;
}

uint16 HAL_CCP_Capture_Mode_Read_Value(ccp_pin_t pin){
    uint16 capture_value = 0;
    if(CCP1_PIN == pin)
    {capture_value = CCPR1;}
    else if(CCP1_PIN == pin)
    {capture_value = CCPR2;}
    
    return capture_value;
}

std_ReturnType HAL_CCP_Compare_Mode_Set_Value(ccp_pin_t pin ,uint16 compare_value){
    std_ReturnType ret = E_NOT_OK;
    
    if(((CCP1_PIN != pin) && (CCP2_PIN != pin)) || (compare_value < 0) ){
        ret = E_NOT_OK;
    }
    else{
        /* Copy compared value */
        if(CCP1_PIN == pin){
            CCPR1 = compare_value;
        }
        else if(CCP2_PIN == pin){
            CCPR2 = compare_value;
        }
        else{ /* Nothing */ }
        
        ret = E_OK;
    }
    return ret;
}

std_ReturnType HAL_CCP_PWM_Set_Duty(ccp_pin_t pin, uint16 _duty){
    std_ReturnType ret = E_NOT_OK;
    uint16 l_duty_temp = 0;
    
    if((CCP1_PIN != pin) && (CCP2_PIN != pin)){
        ret = E_NOT_OK;
    }
    else{
        l_duty_temp = 4*(PR2 + 1);
        if     (_duty < 0)         {_duty = 0;} 
        else if(_duty >1023)       {_duty = 1023;}
        else if(_duty >l_duty_temp){_duty = l_duty_temp;}
        
        
        
        if(CCP1_PIN == pin){
            CCP1Y = _duty & 1;
            CCP1X = _duty & 2;
            CCPR1L = (uint8)(_duty >> 2);
        }
        else if(CCP2_PIN == pin){
            CCP2Y = _duty & 1;
            CCP2X = _duty & 2;
            CCPR2L = (uint8)(_duty >> 2);
        }
        else{ /* Nothing */ }
        
        ret = E_OK;
    }

    return ret;
}
std_ReturnType HAL_CCP_PWM_Start(ccp_pin_t pin){
    std_ReturnType ret = E_NOT_OK;
    
    if((CCP1_PIN != pin) && (CCP2_PIN != pin)){
        ret = E_NOT_OK;
    }
    else{
        if(CCP1_PIN == pin){
            CCP1CONbits.CCP1M = CCP_PWM_MODE;
        }
        else if(CCP2_PIN == pin){
            CCP2CONbits.CCP2M = CCP_PWM_MODE;
        }
        else{ /* Nothing */ }
        ret = E_OK;
    }
    
    return ret;
}
std_ReturnType HAL_CCP_PWM_Stop(ccp_pin_t pin){
    std_ReturnType ret = E_NOT_OK;
    
    if((CCP1_PIN != pin) && (CCP2_PIN != pin)){
        ret = E_NOT_OK;
    }
    else{
        if(CCP1_PIN == pin){
            CCP1CONbits.CCP1M = CCP_MODULE_DISABLE;
        }
        else if(CCP2_PIN == pin){
            CCP2CONbits.CCP2M = CCP_MODULE_DISABLE;
        }
        else{ /* Nothing */ }
        ret = E_OK;
    }

    return ret;
}

void CCP1_ISR(void){
    CCP1_InterruptFlagClear();
    if(CCP1_InterruptHandler){
        CCP1_InterruptHandler();
    }
    else{ /* Nothing */ }
}

void CCP2_ISR(void){
    CCP2_InterruptFlagClear();
    if(CCP2_InterruptHandler){
        CCP2_InterruptHandler();
    }
    else{ /* Nothing */ }
}

static void CCP_PWM_Mode_Config(ccp_pin_t pin){
    /* PWM Frequency Initialization */
    HAL_TIMER2_Init(0,255,TIMER2_PRESCALER_DIV_BY_4,TIMER2_POSTSCALER_DIV_BY_1,NULL);
    TIMER2_InterruptDisable();
    
    if(CCP1_PIN == pin){
        CCP1_SET_MODE(CCP_PWM_MODE);
    }
    else if(CCP2_PIN == pin){
        CCP2_SET_MODE(CCP_PWM_MODE);
    }
    else{ /* Nothing */ }
}
static void CCP_Interrupt_Config(ccp_pin_t pin,void (* InterruptHandler)(void)){
/* CCP1 Interrupt Configurations */
    if(CCP1_PIN == pin)
    {
        #if CCP1_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
            CCP1_InterruptEnable();
            CCP1_InterruptFlagClear();
            INTERRUPT_GlobalInterruptEnable();
            INTERRUPT_PeripheralInterruptEnable();
            CCP1_InterruptHandler = InterruptHandler;
            /* Interrupt Priority Configurations */
        #endif
    }
    else if(CCP2_PIN == pin)
    {
        #if CCP2_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
            CCP2_InterruptEnable();
            CCP2_InterruptFlagClear();
            INTERRUPT_GlobalInterruptEnable();
            INTERRUPT_PeripheralInterruptEnable();
            CCP2_InterruptHandler = InterruptHandler;
            /* Interrupt Priority Configurations */
        #endif 

    }

        
/* CCP2 Interrupt Configurations */ 
}

static std_ReturnType CCP_Capture_Mode_Config(ccp_pin_t pin,uint8 mode){
    std_ReturnType ret = E_OK;
    
    if(CCP1_PIN == pin){
        /* CCP1 Module Capture variants Mode Initialization */
        switch(mode){
            case CCP_CAPTURE_MODE_1_FALLING_EDGE : CCP1_SET_MODE(CCP_CAPTURE_MODE_1_FALLING_EDGE); break;
            case CCP_CAPTURE_MODE_1_RISING_EDGE  : CCP1_SET_MODE(CCP_CAPTURE_MODE_1_RISING_EDGE);  break;
            case CCP_CAPTURE_MODE_4_RISING_EDGE  : CCP1_SET_MODE(CCP_CAPTURE_MODE_4_RISING_EDGE);  break;
            case CCP_CAPTURE_MODE_16_RISING_EDGE : CCP1_SET_MODE(CCP_CAPTURE_MODE_16_RISING_EDGE); break;
            default : ret = E_NOT_OK; /* Not supported variant */
        }
    }
    else if(CCP2_PIN == pin){
        /* CCP2 Module Capture variants Mode Initialization */
        switch(mode){
            case CCP_CAPTURE_MODE_1_FALLING_EDGE : CCP2_SET_MODE(CCP_CAPTURE_MODE_1_FALLING_EDGE); break;
            case CCP_CAPTURE_MODE_1_RISING_EDGE  : CCP2_SET_MODE(CCP_CAPTURE_MODE_1_RISING_EDGE);  break;
            case CCP_CAPTURE_MODE_4_RISING_EDGE  : CCP2_SET_MODE(CCP_CAPTURE_MODE_4_RISING_EDGE);  break;
            case CCP_CAPTURE_MODE_16_RISING_EDGE : CCP2_SET_MODE(CCP_CAPTURE_MODE_16_RISING_EDGE); break;
            default : ret = E_NOT_OK; /* Not supported variant */
        }
    }
    else{ /* Nothing */ }
        
    return ret;
}

static std_ReturnType CCP_Compare_Mode_Config(ccp_pin_t pin,uint8 mode){
    std_ReturnType ret = E_OK;
    
    if(CCP1_PIN == pin){
        /* CCP1 Module Compare variants Mode Initialization */
        switch(mode){
            case CCP_COMPARE_MODE_SET_PIN_LOW      : CCP1_SET_MODE(CCP_COMPARE_MODE_SET_PIN_LOW);      break;
            case CCP_COMPARE_MODE_SET_PIN_HIGH     : CCP1_SET_MODE(CCP_COMPARE_MODE_SET_PIN_HIGH);     break;
            case CCP_COMPARE_MODE_GEN_SW_INTERRUPT : CCP1_SET_MODE(CCP_COMPARE_MODE_GEN_SW_INTERRUPT); break;
            case CCP_COMPARE_MODE_GEN_EVENT        : CCP1_SET_MODE(CCP_COMPARE_MODE_GEN_EVENT);        break;
            default : ret = E_NOT_OK; /* Not supported variant */
        }
    }
    else if(CCP2_PIN == pin){
        /* CCP1 Module Compare variants Mode Initialization */
        switch(mode){
            case CCP_COMPARE_MODE_SET_PIN_LOW      : CCP2_SET_MODE(CCP_COMPARE_MODE_SET_PIN_LOW);      break;
            case CCP_COMPARE_MODE_SET_PIN_HIGH     : CCP2_SET_MODE(CCP_COMPARE_MODE_SET_PIN_HIGH);     break;
            case CCP_COMPARE_MODE_GEN_SW_INTERRUPT : CCP2_SET_MODE(CCP_COMPARE_MODE_GEN_SW_INTERRUPT); break;
            case CCP_COMPARE_MODE_GEN_EVENT        : CCP2_SET_MODE(CCP_COMPARE_MODE_GEN_EVENT);        break;
            default : ret = E_NOT_OK; /* Not supported variant */
        }
    }
    else{ /* Nothing */ }
        
    return ret;
}