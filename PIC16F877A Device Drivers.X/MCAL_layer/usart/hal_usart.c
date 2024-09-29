/* 
 * File:   hal_usart.c
 * Author: Youssef Ahmed Tawfik Ali
 * https://www.linkedin.com/in/youssefahmed2001/
 * Created on April 6, 2021, 8:53 PM
 */

/* Includes -----------------------------------------------------------------------------*/
#include "hal_usart.h"

/* Data Type Definition -----------------------------------------------------------------*/
#if EUSART_TX_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
    static void (*EUSART_TxInterruptHandler)(void) = NULL;
#endif
#if EUSART_RX_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
    static void (*EUSART_RxInterruptHandler)(void) = NULL;
    static void (*EUSART_FramingErrorHandler)(void) = NULL;
    static void (*EUSART_OverrunErrorHandler)(void) = NULL;
#endif
    
volatile Serial_t Serial;

/* Macros -------------------------------------------------------------------------------*/

/* Macro Functions ----------------------------------------------------------------------*/

/* Functions Definition -----------------------------------------------------------------*/
static void USART_Baud_Rate_Calculation();
static void USART_ASYNC_RX_Restart(void);
static void EUSART_FramingErrorHandler_Isr();
static void EUSART_OverrunErrorHandler_Isr();

void HAL_USART_ASYNC_Init(uint32 baud)
{
    USART_MODULE_DISABLE();
    USART_ASYNCHRONOUS_MODE_ENABLE();
    USART_Baud_Rate_Calculation(baud);
    USART_ASYNCHRONOUS_9Bit_TX_DISABLE();
    USART_ASYNCHRONOUS_TX_ENABLE();
    
    USART_ASYNCHRONOUS_9Bit_RX_DISABLE();
    USART_ASYNCHRONOUS_RX_ENABLE();
    
    pinMode(PC,PIN6,INPUT);
    pinMode(PC,PIN7,INPUT);
    
    EUSART_FramingErrorHandler = EUSART_FramingErrorHandler_Isr;
    EUSART_OverrunErrorHandler = EUSART_OverrunErrorHandler_Isr;
    
    Serial.begin = HAL_USART_ASYNC_Init;
    Serial.read = HAL_USART_Read_Char;
    Serial.write = HAL_USART_Write_Char;
    Serial.print = HAL_USART_Write_String;
    Serial.println = HAL_USART_Write_String_ln;
    Serial.end = HAL_USART_ASYNC_DeInit;
    Serial.set_interrupt_handler = HAL_USART_Set_Interrupt_Handler;
    Serial.available = HAL_USART_is_Available;
    USART_MODULE_ENABLE();
}
void HAL_USART_ASYNC_DeInit(){
    USART_MODULE_DISABLE(); /* Disable EUSART Module */
}
uint8 HAL_USART_is_Available(void)
{
    if(RCIF == 1){return 1;}
    else if(RCIF == 0){return 0;}
    else{}
}
uint8 HAL_USART_Read_Char(void)
{
    if(RCIF == 1)
    {
        uint8 data = RCREG;
        return data;
    }
}
void HAL_USART_Write_Char(uint8 character)
{
    while(!USART_READ_TSR_STATUS());
    TXREG = character;
}
void HAL_USART_Write_String(uint8 *_data)
{
    uint16 char_counter = 0;
    for(char_counter=0; _data[char_counter]!='\0'; char_counter++){
        HAL_USART_Write_Char(_data[char_counter]);
    }
}
void HAL_USART_Write_String_ln(uint8 *_data)
{
    uint16 char_counter = 0;
    for(char_counter=0; _data[char_counter]!='\0'; char_counter++){
        HAL_USART_Write_Char(_data[char_counter]);
    }
    HAL_USART_Write_Char('\n');
}
void HAL_USART_Set_Interrupt_Handler(void (* InterruptHandler_Tx)(void),void (* InterruptHandler_Rx)(void))
{
    if(InterruptHandler_Tx)
    {
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
        EUSART_TX_InterruptEnable();
        EUSART_TxInterruptHandler = InterruptHandler_Tx;
    }
    if(InterruptHandler_Rx)
    {
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
        EUSART_RX_InterruptEnable();
        EUSART_RxInterruptHandler = InterruptHandler_Rx;
    }
}

static void USART_Baud_Rate_Calculation(uint32 baud)
{
    float Baud_Rate_Temp = 0;
    if(baud <= 2400)
    {
        USART_ASYNCHRONOUS_SET_LOW_SPEED();
        Baud_Rate_Temp = (_XTAL_FREQ - baud*64)/(baud*64);
    }
    else if (baud > 2400)
    {
        USART_ASYNCHRONOUS_SET_HIGH_SPEED();
        Baud_Rate_Temp = (_XTAL_FREQ - baud*16)/(float)(baud*16);
    }
    if(Baud_Rate_Temp < 255)
    {SPBRG = (uint8)((uint32)Baud_Rate_Temp);}
}
static void USART_ASYNC_RX_Restart(void)
{
    USART_ASYNCHRONOUS_RX_DISABLE(); /* Disables receiver */
    USART_ASYNCHRONOUS_RX_ENABLE(); /* Enables receiver */
}

void EUSART_TX_ISR(void)
{
    if(EUSART_TxInterruptHandler){
        EUSART_TxInterruptHandler();
    }else { /* Nothing */}
}

void EUSART_RX_ISR(void)
{
    if(EUSART_RxInterruptHandler){
        EUSART_RxInterruptHandler();
    }else { /* Nothing */}
    if(EUSART_FramingErrorHandler && (FERR == EUSART_FRAMING_ERROR_DETECTED)){
        EUSART_FramingErrorHandler();
    }else { /* Nothing */}
    if(EUSART_OverrunErrorHandler && (OERR == EUSART_OVERRUN_ERROR_DETECTED)){
        EUSART_OverrunErrorHandler();
    }else { /* Nothing */}
}

static void EUSART_FramingErrorHandler_Isr()
{
    char dummy = RCREG;  // Read RCREG to clear RCIF and discard the byte
}

static void EUSART_OverrunErrorHandler_Isr()
{
    USART_ASYNC_RX_Restart();
}