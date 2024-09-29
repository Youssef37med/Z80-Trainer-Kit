/* 
 * File:   hal_adc.c
 * Author: Youssef Ahmed Tawfik Ali
 * https://www.linkedin.com/in/youssefahmed2001/
 * Created on March 26, 2021, 7:21 PM
 */

/* Includes -----------------------------------------------------------------------------*/
#include "hal_adc.h"

/* Data Type Definition -----------------------------------------------------------------*/
#if ADC_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
static void (*ADC_InterruptHandler)(void) = NULL;
#endif

/* Macros -------------------------------------------------------------------------------*/

/* Macro Functions ----------------------------------------------------------------------*/

/* Functions Definition -----------------------------------------------------------------*/
static inline void adc_input_channel_port_configure(adc_channel_select_t channel);
static inline void select_result_format(uint8 result_format);
static inline void set_conversion_clock();

/**
 * @Summary Initializes the ADC
 * @Description This routine initializes the ADC.
 *              This routine must be called before any other ADC routine is called.
 *              This routine should only be called once during system initialization.
 * @Preconditions None
 * @param _adc Pointer to the ADC configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
void HAL_ADC_Init(ADC_Config config,void (*InterruptHandler)(void)){
    
    /* Disable the ADC */
    ADC_CONVERTER_DISABLE();
    /*Configure digital or analog pins*/
    ADC_ANALOG_DIGITAL_PORT_CONFIG(config);
    /* Configure the conversion clock */
    set_conversion_clock();
    /* Configure the default channel */
    ADCON0bits.CHS = ADC_CHANNEL_AN0;
    /* Configure the interrupt */
    #if ADC_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    ADC_InterruptEnable();
    ADC_InterruptFlagClear();
    ADC_InterruptHandler = InterruptHandler;
    #endif
    /* Configure the result format */
    select_result_format(ADC_RESULT_RIGHT);
    /* Enable the ADC */
    ADC_CONVERTER_ENABLE();

}

/**
 * @Summary De-Initializes the ADC
 * @param _adc Pointer to the ADC configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
void HAL_ADC_DeInit()
{
    
    /* Disable the ADC */
    ADC_CONVERTER_DISABLE();
    /* Disable the interrupt */
    #if ADC_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
    ADC_InterruptDisable();
    #endif
}

/**
 * @Summary Allows selection of a channel for conversion
 * @Description This routine is used to select desired channel for conversion.
 * @Preconditions ADC_Init() function should have been called before calling this function.
 * @param _adc Pointer to the ADC configurations
 * @param channel Defines the channel available for conversion.
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
void HAL_ADC_SelectChannel(adc_channel_select_t channel)
{
    
    /* Configure the default channel */
    ADCON0bits.CHS = channel;
    adc_input_channel_port_configure(channel);
}

/**
 * @Summary Starts conversion
 * @Description This routine is used to start conversion of desired channel.
 * @Preconditions ADC_Init() function should have been called before calling this function.
 * @param _adc Pointer to the ADC configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
void HAL_ADC_StartConversion()
{
        ADC_START_CONVERSION();
}

/**
 * @Summary Returns true when the conversion is completed otherwise false.
 * @Description This routine is used to determine if conversion is completed.
 *              When conversion is complete routine returns true. It returns false otherwise.
 * @Preconditions ADC_Init() function should have been called before calling this function.
 *                ADC_StartConversion() should have been called before calling this function.
 * @param _adc Pointer to the ADC configurations
 * @param conversion_status The conversion status
 *          true  - If conversion is complete
 *          false - If conversion is not completed
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
uint8 HAL_ADC_IsConversionDone()
{

        uint8 conversion_status = (uint8)(ADC_CONVERSION_STATUS());
        return conversion_status;
}

/**
 * @Summary Returns the ADC conversion value.
 * @Description This routine is used to get the analog to digital converted value.
 *              This routine gets converted values from the channel specified.
 * @Preconditions   This routine returns the conversion value only after the conversion is complete.
 *                  Completion status can be checked using ADC_IsConversionDone() routine.
 * @param _adc Pointer to the ADC configurations
 * @param conversion_result The converted value.
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
uint16 HAL_ADC_GetConversionResult()
{
    uint16 conversion_result = 0;
    conversion_result = (uint16)((ADRESH << 8) + ADRESL);
    return conversion_result;
}

/**
 * @Summary Returns the ADC conversion value, also allows selection of a channel for conversion.
 * @Description This routine is used to select desired channel for conversion.
 *              This routine is get the analog to digital converted value.
 * @Preconditions ADC_Init() function should have been called before calling this function.
 * @param _adc Pointer to the ADC configurations
 * @param channel Defines the channel available for conversion.
 * @param conversion_result The converted value.
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
uint16 HAL_ADC_Read(adc_channel_select_t channel){
    /* select the A/D channel */
    ADC_SelectChannel(channel);
    /*wait the acquisition time*/
    __delay_us(30);
    /* Start the conversion */
    ADC_StartConversion();
    /* Check if conversion is completed */
    while(ADC_CONVERSION_STATUS());
    uint16 conversion_result = ADC_GetConversionResult();
    return conversion_result;
    
}

static inline void adc_input_channel_port_configure(adc_channel_select_t channel)
{
    switch(channel){
        case ADC_CHANNEL_AN0 : SET_BIT(TRISA, 0); break; /* Disable the digital output driver */
        case ADC_CHANNEL_AN1 : SET_BIT(TRISA, 1); break; /* Disable the digital output driver */
        case ADC_CHANNEL_AN2 : SET_BIT(TRISA, 2); break; /* Disable the digital output driver */
        case ADC_CHANNEL_AN3 : SET_BIT(TRISA, 3); break; /* Disable the digital output driver */
        case ADC_CHANNEL_AN4 : SET_BIT(TRISA, 5); break; /* Disable the digital output driver */
        case ADC_CHANNEL_AN5 : SET_BIT(TRISE, 0); break; /* Disable the digital output driver */
        case ADC_CHANNEL_AN6 : SET_BIT(TRISE, 1); break; /* Disable the digital output driver */
        case ADC_CHANNEL_AN7 : SET_BIT(TRISE, 2); break; /* Disable the digital output driver */
        default : /* Nothing */;
    }
}
static inline void select_result_format(uint8 result_format)
{
    if(ADC_RESULT_RIGHT == result_format){
        ADC_RESULT_RIGHT_FORMAT();
    }
    else if(ADC_RESULT_LEFT == result_format){
        ADC_RESULT_LEFT_FORMAT();
    }
    else{
        ADC_RESULT_RIGHT_FORMAT();
    }
}
static inline void set_conversion_clock()
{
    
    if     (_XTAL_FREQ <= (1.25*1000000)){ADC_SET_CONVERSION_CLOCK(ADC_CONVERSION_CLOCK_FOSC_DIV_2);}
    else if(_XTAL_FREQ <= (2.5*1000000)) {ADC_SET_CONVERSION_CLOCK(ADC_CONVERSION_CLOCK_FOSC_DIV_4);}
    else if(_XTAL_FREQ <= (5*1000000))   {ADC_SET_CONVERSION_CLOCK(ADC_CONVERSION_CLOCK_FOSC_DIV_8);}
    else if(_XTAL_FREQ <= (10*1000000))  {ADC_SET_CONVERSION_CLOCK(ADC_CONVERSION_CLOCK_FOSC_DIV_16);}
    else if(_XTAL_FREQ <= (20*1000000))  {ADC_SET_CONVERSION_CLOCK(ADC_CONVERSION_CLOCK_FOSC_DIV_32);}
    else{}
}

void ADC_ISR(void)
{
    ADC_InterruptFlagClear();
    if(ADC_InterruptHandler){
        ADC_InterruptHandler();
    }
}