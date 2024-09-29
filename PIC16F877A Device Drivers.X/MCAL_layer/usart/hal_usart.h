/* 
 * File:   hal_usart.h
 * Author: Youssef Ahmed Tawfik Ali
 * https://www.linkedin.com/in/youssefahmed2001/
 * Created on April 6, 2021, 8:53 PM
 */

#ifndef HAL_USART_H
#define	HAL_USART_H

/* Includes -----------------------------------------------------------------------------*/
#include "pic16f877a.h"
#include "../mcal_std_types.h"
#include "../../MCAL_Layer/gpio/gpio.h"
#include "../../MCAL_Layer/Interrupt/mcal_internal_interrupt.h"
#include "hal_usart_cfg.h"

/* Data Type Declaration ----------------------------------------------------------------*/
typedef struct{
    void (* begin)(uint32);
    void (* write)(uint8);
    void (* print)(uint8 *_data);
    void (* println)(uint8 *_data);
    uint8 (* read)(void);
    void (* end) (void);
    uint8 (* available)(void);
    void (* set_interrupt_handler)(void (* InterruptHandler_Tx)(void),void (* InterruptHandler_Rx)(void));
}Serial_t;

extern volatile Serial_t Serial;

/* Macros -------------------------------------------------------------------------------*/
/* EUSART Framing Error */
#define EUSART_FRAMING_ERROR_DETECTED 1
#define EUSART_FRAMING_ERROR_CLEARED  0
/* EUSART Overrun Error */
#define EUSART_OVERRUN_ERROR_DETECTED 1
#define EUSART_OVERRUN_ERROR_CLEARED  0

/* Macro Functions ----------------------------------------------------------------------*/
/* Enable / Disable EUSART Module */
#define USART_MODULE_ENABLE()  (RCSTAbits.SPEN = 1)
#define USART_MODULE_DISABLE() (RCSTAbits.SPEN = 0)
/* Selecting EUSART Working Mode */
#define USART_ASYNCHRONOUS_MODE_ENABLE() (TXSTAbits.SYNC = 0)
#define USART_SYNCHRONOUS_MODE_ENABLE()  (TXSTAbits.SYNC = 1)
/* Baud Rate Generator Asynchronous Speed Mode */
#define USART_ASYNCHRONOUS_SET_HIGH_SPEED() (TXSTAbits.BRGH = 1)
#define USART_ASYNCHRONOUS_SET_LOW_SPEED()  (TXSTAbits.BRGH = 0)

/* EUSART Transmit Enable */
#define USART_ASYNCHRONOUS_TX_ENABLE()              (TXSTAbits.TXEN = 1)
#define USART_ASYNCHRONOUS_TX_DISABLE()             (TXSTAbits.TXEN = 0)
/* EUSART 9-Bit Transmit Enable */
#define USART_ASYNCHRONOUS_9Bit_TX_ENABLE() (TXSTAbits.TX9 = 1)
#define USART_ASYNCHRONOUS_9Bit_TX_DISABLE() (TXSTAbits.TX9 = 0)
/*read if TSR is empty or not*/
#define USART_READ_TSR_STATUS()          (TXSTAbits.TRMT)

/* EUSART Receiver Enable */
#define USART_ASYNCHRONOUS_RX_ENABLE() (RCSTAbits.CREN = 1)
#define USART_ASYNCHRONOUS_RX_DISABLE() (RCSTAbits.CREN = 0)
/* EUSART 9-Bit Receiver Enable */
#define USART_ASYNCHRONOUS_9Bit_RX_ENABLE() (RCSTAbits.RX9 = 1)
#define USART_ASYNCHRONOUS_9Bit_RX_DISABLE() (RCSTAbits.RX9 = 0)

/* Functions Declarations ---------------------------------------------------------------*/
void HAL_USART_ASYNC_Init(uint32 baud);
void HAL_USART_ASYNC_DeInit();

uint8 HAL_USART_is_Available(void);
uint8 HAL_USART_Read_Char(void);
void HAL_USART_Write_Char(uint8 character);
void HAL_USART_Write_String(uint8 *_data);
void HAL_USART_Write_String_ln(uint8 *_data);
void HAL_USART_Set_Interrupt_Handler(void (* InterruptHandler_Tx)(void),void (* InterruptHandler_Rx)(void));

#endif	/* HAL_USART_H */
