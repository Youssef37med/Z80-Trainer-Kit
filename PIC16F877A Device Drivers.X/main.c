/* 
 * File:   main.c
 * Author: Youssef Ahmed Tawfik Ali
 * https://www.linkedin.com/in/youssefahmed2001/
 * Created on May 21, 2021, 9:53 PM
 */

/* Includes -----------------------------------------------------------------------------*/
#include "MCAL_layer/gpio/gpio.h"
#include "MCAL_layer/Interrupt/mcal_interrupt_config.h"
#include "MCAL_layer/Interrupt/mcal_external_interrupt.h"
#include "MCAL_layer/timer1/hal_timr1.h"
#include "MCAL_layer/timer2/hal_timr2.h"
#include "MCAL_layer/timer0/hal_timr0.h"
#include "MCAL_layer/ccp/hal_ccp.h"
#include "MCAL_layer/comparator/comparator.h"
#include "ECU_layer/chr_lcd/ecu_chr_lcd.h"
#include "ECU_layer/keypad/ecu_keypad.h"
#include "MCAL_layer/usart/hal_usart.h"
#include "MCAL_layer/spi/hal_spi.h"
#include "MCAL_layer/i2c/hal_i2c.h"
#include "ECU_layer/mpu6050/mpu6050.h"

/* Data Type Definition -----------------------------------------------------------------*/

/* Macros -------------------------------------------------------------------------------*/
#define PROCESSOR_READY_TO_READ_PORT PB
#define PROCESSOR_READY_TO_READ_PIN  PIN3
#define PROCESSOR_STATUS_PORT        PB
#define PROCESSOR_STATUS_PIN         PIN4

/* Macro Functions ----------------------------------------------------------------------*/

/* Functions Declarations ---------------------------------------------------------------*/
void USART_RX_Interrupt_Handler();
void GPIO_Init();

int main() {
    
    HAL_USART_ASYNC_Init(38400);
    Serial.set_interrupt_handler(NULL,USART_RX_Interrupt_Handler);
    GPIO_Init();
    
    while(1)
	{
        
    }
    
    return (EXIT_SUCCESS);
}

/* Functions Definition ---------------------------------------------------------------*/
void GPIO_Init()
{
    /* Initialization of Data Port */
    pinMode(PD,PIN0,OUTPUT);
    pinMode(PD,PIN1,OUTPUT);
    pinMode(PD,PIN2,OUTPUT);
    pinMode(PD,PIN3,OUTPUT);
    pinMode(PD,PIN4,OUTPUT);
    pinMode(PD,PIN5,OUTPUT);
    pinMode(PD,PIN6,OUTPUT);
    pinMode(PD,PIN7,OUTPUT);
    
    digitalWrite(PD,PIN0,LOW);
    digitalWrite(PD,PIN1,LOW);
    digitalWrite(PD,PIN2,LOW);
    digitalWrite(PD,PIN3,LOW);
    digitalWrite(PD,PIN4,LOW);
    digitalWrite(PD,PIN5,LOW);
    digitalWrite(PD,PIN6,LOW);
    digitalWrite(PD,PIN7,LOW);
    
    /* Initialization of pin which indicate processor ready to read data from serial */
    pinMode(PROCESSOR_READY_TO_READ_PORT,PROCESSOR_READY_TO_READ_PIN,OUTPUT);
    digitalWrite(PROCESSOR_READY_TO_READ_PORT,PROCESSOR_READY_TO_READ_PIN,LOW);
    
    /* Initialization of pin which indicate the status of processor ready for receive another data */
    pinMode(PROCESSOR_STATUS_PORT,PROCESSOR_STATUS_PIN,INPUT);
}
void USART_RX_Interrupt_Handler()
{
    char data = Serial.read();
    
    if(!RB4)
    {
        PORTD = data;
        Serial.write(data);

        PORTBbits.RB3 = 1;
        while(!RB4);
        PORTBbits.RB3 = 0;
    }
    else
    {
        Serial.println("ERROR");
    }
    
    //digitalWrite(PROCESSOR_READY_TO_READ_PORT,PROCESSOR_READY_TO_READ_PIN,HIGH);
    //while(!digitalRead(PROCESSOR_STATUS_PORT,PROCESSOR_STATUS_PIN));
    //digitalWrite(PROCESSOR_READY_TO_READ_PORT,PROCESSOR_READY_TO_READ_PIN,LOW);
}