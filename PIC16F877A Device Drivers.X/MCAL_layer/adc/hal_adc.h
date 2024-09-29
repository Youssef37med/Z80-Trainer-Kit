/* 
 * File:   hal_adc.h
 * Author: Youssef Ahmed Tawfik Ali
 * https://www.linkedin.com/in/youssefahmed2001/
 * Created on March 26, 2021, 7:21 PM
 */

#ifndef HAL_ADC_H
#define	HAL_ADC_H

/* Includes -----------------------------------------------------------------------------*/
#include "pic16f877a.h"
#include "../mcal_std_types.h"
#include "../../MCAL_Layer/gpio/gpio.h"
#include "../../MCAL_Layer/Interrupt/mcal_internal_interrupt.h"
#include "hal_adc_cfg.h"

/* Data Type Declaration ----------------------------------------------------------------*/
typedef enum
{
    ADC_CHANNEL_AN0 = 0,
    ADC_CHANNEL_AN1,
    ADC_CHANNEL_AN2,
    ADC_CHANNEL_AN3,
    ADC_CHANNEL_AN4,
    ADC_CHANNEL_AN5,
    ADC_CHANNEL_AN6,
    ADC_CHANNEL_AN7,
}adc_channel_select_t;

/**
 * @brief  A/D Conversion Clock Select
 * @note   If the A/D FRC clock source is selected, a delay of one TCY (instruction cycle) 
 *         is added before the A/D clock starts.
 * @note   This allows the SLEEP instruction to be executed before starting a conversion.
 */
typedef enum
{
    ADC_CONVERSION_CLOCK_FOSC_DIV_2 = 0,
    ADC_CONVERSION_CLOCK_FOSC_DIV_8,
    ADC_CONVERSION_CLOCK_FOSC_DIV_32,
    ADC_CONVERSION_CLOCK_FOSC_DIV_FRC,
    ADC_CONVERSION_CLOCK_FOSC_DIV_4,
    ADC_CONVERSION_CLOCK_FOSC_DIV_16,
    ADC_CONVERSION_CLOCK_FOSC_DIV_64
}adc_conversion_clock_t;

/**
 * @brief Analog-To-Digital Port Configuration Control
 * @note  When ADC_AN4_ANALOG_FUNCTIONALITY is configured, this means
 *        AN4,AN3,AN2,AN1,AN0 are Analog functionality.
 */
typedef enum
{
     ADC_AN0_ANALOG_VREF_P_N         =0x0F,
     ADC_AN0_ANALOG_VREF_NOT         =0x0E,
     ADC_AN1_ANALOG_VREF_P_N         =0x0D,
     ADC_AN4_ANALOG_VREF_P_N         =0x0C,
     ADC_AN5_ANALOG_VREF_P_N         =0x0B,
     ADC_AN5_ANALOG_VREF_P           =0x0A,
     ADC_AN5_ANALOG_VREF_NOT         =0x09,
     ADC_AN7_ANALOG_VREF_P_N         =0x08,
     ADC_ALL_DIGITAL_FUNCTIONALITY   =0x06,
     ADC_AN1_ANALOG_VREF_P           =0x05,
     ADC_AN1_AN3_ANALOG_VREF_NOT     =0x04,
     ADC_AN4_ANALOG_VREF_P           =0x03,
     ADC_AN4_ANALOG_VREF_NOT         =0x02,
     ADC_AN7_ANALOG_VREF_P           =0x01,
     ADC_ALL_ANALOG_FUNCTIONALITY    =0x00,
}ADC_Config;

/* Macros -------------------------------------------------------------------------------*/
#define ADC_RESULT_RIGHT    0x01U
#define ADC_RESULT_LEFT     0x00U

#define ADC_CONVERSION_COMPLETED  0x01U
#define ADC_CONVERSION_INPROGRESS 0x00U

/* Macro Functions ----------------------------------------------------------------------*/
/* A/D Conversion Status : A/D conversion in progress / A/D Idle */
#define ADC_CONVERSION_STATUS()  (ADCON0bits.GO_DONE)

/**
 * @brief Start the Analog-To-Digital Conversion
 */
#define ADC_START_CONVERSION()  (ADCON0bits.GO_DONE = 1)

/**
 * @brief  Analog-To-Digital Control
 * @note   ADC_CONVERTER_ENABLE()  : Enable the Analog-To-Digital
 *         ADC_CONVERTER_DISABLE() : Disable the Analog-To-Digital
 */
#define ADC_CONVERTER_ENABLE()  (ADCON0bits.ADON = 1)
#define ADC_CONVERTER_DISABLE() (ADCON0bits.ADON = 0)

/**
 * @brief  Analog-To-Digital Port Configuration Control
 * @note   Example : ADC_ANALOG_DIGITAL_PORT_CONFIG(ADC_AN4_ANALOG_FUNCTIONALITY);
		   When ADC_AN4_ANALOG_FUNCTIONALITY is configured, this means
 *         AN4,AN3,AN2,AN1,AN0 are Analog functionality.
 *         @ref Analog-To-Digital Port Configuration Control
 */
#define ADC_ANALOG_DIGITAL_PORT_CONFIG(_CONFIG) (ADCON1bits.PCFG = _CONFIG)

/**
 * @brief  A/D Result Format Select
 */
#define ADC_RESULT_RIGHT_FORMAT()  (ADCON1bits.ADFM = 1)
#define ADC_RESULT_LEFT_FORMAT()   (ADCON1bits.ADFM = 0)

#define ADC_SET_CONVERSION_CLOCK(clk) {ADCS0 = clk & 0x01;ADCS1 = clk & 0x02;ADCS2 = clk & 0x04;}

#define ADC_CHANNEL_SELECT()

/* Functions Declarations ---------------------------------------------------------------*/
void HAL_ADC_Init(ADC_Config config,void (*InterruptHandler)(void));
void HAL_ADC_DeInit();
void HAL_ADC_SelectChannel(adc_channel_select_t channel);
void HAL_ADC_StartConversion();
uint8 HAL_ADC_IsConversionDone();
uint16 HAL_ADC_GetConversionResult();
uint16 HAL_ADC_Read(adc_channel_select_t channel);

#endif	/* HAL_ADC_H */
