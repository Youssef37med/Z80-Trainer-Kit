/* 
 * File:   hal_spi.h
 * Author: Youssef Ahmed Tawfik Ali
 * https://www.linkedin.com/in/youssefahmed2001/
 * Created on October 6, 2023, 10:16 PM
 */

/* Includes -----------------------------------------------------------------------------*/
#include "hal_spi.h"

/* Data Type Definition -----------------------------------------------------------------*/
#if MSSP_SPI_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
static void (*SPI_Report_Write_Collision_InterruptHandler)(void) = NULL;
static void (*SPI_Report_Receive_Overflow_InterruptHandle)(void) = NULL;
static void (*SPI_DefaultInterruptHandle)(void) = NULL;

static uint8 check = 0;
volatile Spi_t Spi;
#endif

/* Macros -------------------------------------------------------------------------------*/

/* Macro Functions ----------------------------------------------------------------------*/

/* Functions Definition -----------------------------------------------------------------*/
static inline void set_spi_mode(uint8 mode);
static inline void MSSP_SPI_Interrupt_Configurations(void (*InterruptHandler)(void));

void HAL_SPI_Init(uint8 mode){
    SPI_MODULE_DISABLE();
    SSPBUF = 0x00;
    set_spi_mode(mode);
    SPI_CLOCK_PHASE_IDLE_TO_ACTIVE();
    SPI_CLOCK_POLARITY_IDLE_LOW();
    SPI_DATA_SAMPLED_AT_MIDDLE();
    if(mode == SPI_SLAVE_MODE_SS_ENABLE || mode == SPI_SLAVE_MODE_SS_DISABLE)
    {
        pinMode(PC,PIN3,INPUT); // CLK -> input
        pinMode(PC,PIN4,INPUT); // SDI -> input
        pinMode(PC,PIN5,OUTPUT);// SDO -> Output
        ADC_ANALOG_DIGITAL_PORT_CONFIG(ADC_AN1_AN3_ANALOG_VREF_NOT);
        pinMode(PA,PIN5,INPUT); // SS -> Input
    }
    else
    {
        pinMode(PC,PIN3,OUTPUT);// CLK -> Output
        pinMode(PC,PIN4,INPUT); // SDI -> input
        pinMode(PC,PIN5,OUTPUT);// SDO -> Output
    }
    
    Spi.begin = HAL_SPI_Init;
    Spi.available = HAL_SPI_Available;
    Spi.write = HAL_SPI_Write_Char;
    Spi.read = HAL_SPI_Read_Char;
    Spi.set_interrupt_handler = MSSP_SPI_Interrupt_Configurations;
    Spi.print = HAL_SPI_Write_String;
    Spi.println = HAL_SPI_Write_String_ln;
    Spi.end = HAL_SPI_Deinit;
    
    SPI_MODULE_ENABLE();
}
void HAL_SPI_Deinit()
{
    SPI_MODULE_DISABLE();
    MSSP_SPI_InterruptDisable();
}
void HAL_SPI_Write_Char(uint8 data)
{
    SSPBUF = data; // Transfer The Data To The Buffer Register
    SSPCONbits.WCOL = 0;
    while(!BF);
    MSSP_SPI_InterruptFlagClear();
    SSPSTATbits.BF = 0;
}
uint8 HAL_SPI_Read_Char()
{
    uint8 data = 0;
    if(BF) // Check If Any New Data Is Received
    {
      data = SSPBUF; // Read The Buffer
      BF = 0; // Clear The Buffer-Filled Indicator Bit
      MSSP_SPI_InterruptFlagClear(); // Clear The Interrupt Flag Bit
      SSPCONbits.SSPOV = 0; // Clear The Overflow Indicator Bit
    }
    return data;
}
uint8 HAL_SPI_Available()
{
    if(SSPIF == 1){return 1;}
    else if(SSPIF == 0){return 0;}
}
void HAL_SPI_Write_String(char *text)
{
  uint16_t i;
  for(i=0;text[i]!='\0';i++)
    HAL_SPI_Write_Char(text[i]);
}
void HAL_SPI_Write_String_ln(char *text)
{
  uint16_t i;
  for(i=0;text[i]!='\0';i++)
    HAL_SPI_Write_Char(text[i]);
  HAL_SPI_Write_Char('\n');
}

static inline void set_spi_mode(uint8 mode)
{
    switch(mode)
    {
        case SPI_MASTER_MODE_FOSC_BY_4  :   SPI_SET_MODE(SPI_MASTER_MODE_FOSC_BY_4);break;
        case SPI_MASTER_MODE_FOSC_BY_16 :   SPI_SET_MODE(SPI_MASTER_MODE_FOSC_BY_16);break;
        case SPI_MASTER_MODE_FOSC_BY_64 :   SPI_SET_MODE(SPI_MASTER_MODE_FOSC_BY_64);break;
        case SPI_MASTER_MODE_TMR2_BY_2  :   SPI_SET_MODE(SPI_MASTER_MODE_TMR2_BY_2);break;
        case SPI_SLAVE_MODE_SS_ENABLE   :   SPI_SET_MODE(SPI_SLAVE_MODE_SS_ENABLE);break;
        case SPI_SLAVE_MODE_SS_DISABLE  :   SPI_SET_MODE(SPI_SLAVE_MODE_SS_DISABLE);break;
        default                         :   break;
    }
}
static inline void MSSP_SPI_Interrupt_Configurations(void (*InterruptHandler)(void))
{
#if MSSP_I2C_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
        MSSP_SPI_InterruptEnable();
        MSSP_SPI_InterruptFlagClear();
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
        SPI_DefaultInterruptHandle = InterruptHandler;
        //SPI_Report_Write_Collision_InterruptHandler = I2C_Report_Write_Collision;
        //SPI_Report_Receive_Overflow_InterruptHandle = I2C_Report_Receive_Overflow;
#endif   
}

void MSSP_SPI_ISR(void){
    MSSP_SPI_InterruptFlagClear();
    if(SPI_DefaultInterruptHandle)
    {
        SPI_DefaultInterruptHandle();
    }
    if(SSPCONbits.WCOL == 1)
    {
        if(SPI_Report_Write_Collision_InterruptHandler){SPI_Report_Write_Collision_InterruptHandler();}
        SSPCONbits.WCOL = 0;
    }
    if(SSPCONbits.SSPOV == 1)
    {
        if(SPI_Report_Receive_Overflow_InterruptHandle){SPI_Report_Receive_Overflow_InterruptHandle();}
        SSPCONbits.SSPOV = 0;
    }
}