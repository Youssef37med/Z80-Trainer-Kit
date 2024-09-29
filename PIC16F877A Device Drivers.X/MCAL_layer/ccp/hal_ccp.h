/* 
 * File:   hal_ccp.h
 * Author: Youssef Ahmed Tawfik Ali
 * https://www.linkedin.com/in/youssefahmed2001/
 * Created on April 6, 2021, 8:53 PM
 */

#ifndef HAL_CCP_H
#define	HAL_CCP_H

/* Includes -----------------------------------------------------------------------------*/
#include "pic16f877a.h"
#include "../mcal_std_types.h"
#include "../../MCAL_Layer/gpio/gpio.h"
#include "../../MCAL_Layer/Interrupt/mcal_internal_interrupt.h"
#include "../../MCAL_layer/timer2/hal_timr2.h"
#include "ccp_cfg.h"

/* Data Type Declaration ----------------------------------------------------------------*/
typedef enum{
    CCP1_PIN = 0,
    CCP2_PIN
}ccp_pin_t;

/* Macros -------------------------------------------------------------------------------*/
/* CCP1 Module Mode Select  */
#define CCP_MODULE_DISABLE                 ((uint8)0x00)
#define CCP_CAPTURE_MODE_1_FALLING_EDGE    ((uint8)0x04)
#define CCP_CAPTURE_MODE_1_RISING_EDGE     ((uint8)0x05)
#define CCP_CAPTURE_MODE_4_RISING_EDGE     ((uint8)0x06)
#define CCP_CAPTURE_MODE_16_RISING_EDGE    ((uint8)0x07)
#define CCP_COMPARE_MODE_SET_PIN_LOW       ((uint8)0x09)
#define CCP_COMPARE_MODE_SET_PIN_HIGH      ((uint8)0x08)
#define CCP_COMPARE_MODE_GEN_SW_INTERRUPT  ((uint8)0x0A)
#define CCP_COMPARE_MODE_GEN_EVENT         ((uint8)0x0B)
#define CCP_PWM_MODE                       ((uint8)0x0C)

/* CCP1 Capture Mode State  */
#define CCP1_CAPTURE_NOT_READY              0X00
#define CCP1_CAPTURE_READY                  0X01

/* CCP1 Compare Mode State  */
#define CCP1_COMPARE_NOT_READY              0X00
#define CCP1_COMPARE_READY                  0X01

/* Macro Functions ----------------------------------------------------------------------*/
/* Set the CCP1 Mode Variant */
#define CCP1_SET_MODE(_CONFIG)  (CCP1CONbits.CCP1M = _CONFIG)
#define CCP2_SET_MODE(_CONFIG)  (CCP2CONbits.CCP2M = _CONFIG)

/* Functions Declarations ---------------------------------------------------------------*/
std_ReturnType HAL_CCP_Capture_Mode_Init(ccp_pin_t pin,uint8 mode,void (* InterruptHandler)(void));
std_ReturnType HAL_CCP_Compare_Mode_Init(ccp_pin_t pin,uint8 mode,void (* InterruptHandler)(void));
std_ReturnType HAL_CCP_Pwm_Mode_Init(ccp_pin_t pin,void (* InterruptHandler)(void));
std_ReturnType HAL_CCP_DeInit(ccp_pin_t ccp_pin);
uint16 HAL_CCP_Capture_Mode_Read_Value(ccp_pin_t pin);
std_ReturnType HAL_CCP_Compare_Mode_Set_Value(ccp_pin_t pin ,uint16 compare_value);
std_ReturnType HAL_CCP_PWM_Set_Duty(ccp_pin_t pin, uint16 _duty);
std_ReturnType HAL_CCP_PWM_Start(ccp_pin_t pin);
std_ReturnType HAL_CCP_PWM_Stop(ccp_pin_t pin);

#endif	/* HAL_CCP1_H */
