/* 
 * File:   hal_spi.h
 * Author: Youssef Ahmed Tawfik Ali
 * https://www.linkedin.com/in/youssefahmed2001/
 * Created on October 6, 2023, 10:16 PM
 */

#ifndef HAL_SPI_H
#define	HAL_SPI_H

/* Includes -----------------------------------------------------------------------------*/
#include "pic16f877a.h"
#include "../mcal_std_types.h"
#include "../../MCAL_Layer/gpio/gpio.h"
#include "../../MCAL_Layer/Interrupt/mcal_internal_interrupt.h"
#include "../../MCAL_layer/adc/hal_adc.h"

/* Data Type Declaration ----------------------------------------------------------------*/
typedef struct{
    void (* begin)(uint32);
    void (* end)(void);
    void (* write)(uint8);
    void (* print)(uint8 *_data);
    void (* println)(uint8 *_data);
    uint8 (* read)(void);
    uint8 (* available)(void);
    void (* set_interrupt_handler)(void (* InterruptHandler_Tx)(void),void (* InterruptHandler_Rx)(void));
}Spi_t;

extern volatile Spi_t Spi;

/* Macros -------------------------------------------------------------------------------*/
#define SPI_MASTER_MODE_FOSC_BY_4   0x00
#define SPI_MASTER_MODE_FOSC_BY_16  0x01
#define SPI_MASTER_MODE_FOSC_BY_64  0x02
#define SPI_MASTER_MODE_TMR2_BY_2   0x03
#define SPI_SLAVE_MODE_SS_ENABLE    0X04
#define SPI_SLAVE_MODE_SS_DISABLE   0X05

#define SPI_MASTER_MODE             0x00
#define SPI_SLAVE_MODE              0x01

/* Macro Functions ----------------------------------------------------------------------*/
#define SPI_CLOCK_PHASE_IDLE_TO_ACTIVE() (SSPSTATbits.CKE = 0)
#define SPI_CLOCK_PHASE_ACTIVE_TO_IDLE() (SSPSTATbits.CKE = 1)

#define SPI_CLOCK_POLARITY_IDLE_HIGH()   (SSPCONbits.CKP = 1)
#define SPI_CLOCK_POLARITY_IDLE_LOW()   (SSPCONbits.CKP = 0)

#define SPI_DATA_SAMPLED_AT_END()        (SSPSTATbits.SMP = 1)
#define SPI_DATA_SAMPLED_AT_MIDDLE()     (SSPSTATbits.SMP = 0)

#define SPI_MODULE_ENABLE()              (SSPCONbits.SSPEN = 1)
#define SPI_MODULE_DISABLE()              (SSPCONbits.SSPEN = 0)

#define SPI_SET_MODE(mode)               (SSPCONbits.SSPM = mode)

/* Functions Declarations ---------------------------------------------------------------*/
void HAL_SPI_Init(uint8 mode);
void HAL_SPI_Deinit();
void HAL_SPI_Write_Char(uint8 data);
void HAL_SPI_Write_String(char *text);
void HAL_SPI_Write_String_ln(char *text);
uint8 HAL_SPI_Read_Char();
uint8 HAL_SPI_Available();

#endif	/* HAL_SPI_H */

