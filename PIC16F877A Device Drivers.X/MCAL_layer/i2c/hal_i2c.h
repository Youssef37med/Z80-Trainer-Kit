/* 
 * File:   hal_i2c.h
 * Author: Youssef Ahmed Tawfik Ali
 * https://www.linkedin.com/in/youssefahmed2001/
 * Created on May 21, 2021, 9:53 PM
 */

#ifndef HAL_I2C_H
#define	HAL_I2C_H

/* Includes -----------------------------------------------------------------------------*/
#include "pic16f877a.h"
#include "../mcal_std_types.h"
#include "../../MCAL_Layer/gpio/gpio.h"
#include "../../MCAL_Layer/Interrupt/mcal_internal_interrupt.h"

/* Data Type Declaration ----------------------------------------------------------------*/
typedef struct{
    void (* begin)(uint8 mode,uint8 slave_address);
    void (* end)(void);
    void (* setClock)(uint32 clock);
    std_ReturnType (* beginTransmission)(void);
    std_ReturnType (* endTransmission)(void);
    std_ReturnType (* restartTransmission)(void);
    uint8 (* write)(uint8 i2c_data);
    uint8 (* print)(uint8 *i2c_data);
    uint8 (* println)(uint8 *i2c_data);
    uint8 (* read)(uint8 ack);
    uint8 (* available) (void);
    uint8 (* requestFrom) (uint8 ack);
    void (* onReceive) (void (* InterruptHandler_Rec)(void));
    void (* onRequest) (void (* InterruptHandler_Req)(void));
}Wire_t;

extern volatile Wire_t Wire;

/* Macros -------------------------------------------------------------------------------*/
/* Slave Mode Data/Address Indication */
#define I2C_LAST_RT_BYTE_DATA	  1
#define I2C_LAST_RT_BYTE_ADDRESS  0
/* Stop Condition Indication */
#define I2C_STOP_BIT_DETECTED     1
#define I2C_STOP_BIT_NOT_DETECTED 0
/* Start Condition Indication */
#define I2C_START_BIT_DETECTED     1
#define I2C_START_BIT_NOT_DETECTED 0
/* I2C : Master or Slave Mode */
#define I2C_MASTER_MODE 1
#define I2C_SLAVE_MODE  0
/* Master Synchronous Serial Port Mode Select */
#define I2C_SLAVE_MODE_7BIT_ADDRESS					0x06U
#define I2C_SLAVE_MODE_10BIT_ADDRESS				0x07U
#define I2C_SLAVE_MODE_7BIT_ADDRESS_SS_INT_ENABLE	0x0EU
#define I2C_SLAVE_MODE_10BIT_ADDRESS_SS_INT_ENABLE	0x0FU
#define I2C_MASTER_MODE_DEFINED_CLOCK				0x08U
#define I2C_MASTER_MODE_FIRMWARE_CONTROLLED			0x0BU
/* Acknowledge Status bit (Master Transmit mode only) */
#define I2C_ACK_RECEIVED_FROM_SLAVE     0
#define I2C_ACK_NOT_RECEIVED_FROM_SLAVE 1
/* Acknowledge Data bit (Master Receive mode only) */
#define I2C_MASTER_SEND_ACK  0
#define I2C_MASTER_SEND_NACK 1

/* Macro Functions ----------------------------------------------------------------------*/
/* Slew Rate Enable/Disable */
#define I2C_SLEW_RATE_DISABLE()         (SSPSTATbits.SMP = 1)
#define I2C_SLEW_RATE_ENABLE()          (SSPSTATbits.SMP = 0)
/* SMBus Enable/Disable */
#define I2C_SMBus_DISABLE()             (SSPSTATbits.CKE = 0)
#define I2C_SMBus_ENABLE()              (SSPSTATbits.CKE = 1)
/* General Call Enable */
#define I2C_GENERAL_CALL_DISABLE()      (SSPCON2bits.GCEN = 0)
#define I2C_GENERAL_CALL_ENABLE()       (SSPCON2bits.GCEN = 1)
/* Master Mode Receive Enable */
#define I2C_MASTER_RECEIVE_DISABLE()    (SSPCON2bits.RCEN = 0)
#define I2C_MASTER_RECEIVE_ENABLE()     (SSPCON2bits.RCEN = 1)
/* Master Synchronous Serial Port Enable */
#define MSSP_MODULE_ENABLE()            (SSPCONbits.SSPEN = 1)
#define MSSP_MODULE_DISABLE()           (SSPCONbits.SSPEN = 0)
/* Clock Stretch */
#define I2C_CLOCK_STRETCH_ENABLE()          (SSPCONbits.CKP = 0)
#define I2C_CLOCK_STRETCH_DISABLE()         (SSPCONbits.CKP = 1)
/* set mode of i2c */
#define I2C_SET_MODE(mode)                  (SSPCONbits.SSPM = mode)

/* Functions Declarations ---------------------------------------------------------------*/
void HAL_I2C_Init(uint8 mode,uint8 slave_address);
void HAL_I2C_DeInit();
void HAL_I2C_setClock(uint32 clock);
std_ReturnType HAL_I2C_Master_Send_Start();
std_ReturnType HAL_I2C_Master_Send_Repeated_Start();
std_ReturnType HAL_I2C_Master_Send_Stop();
uint8 HAL_I2C_Master_Write(uint8 i2c_data);
uint8 HAL_I2C_Master_Read(uint8 ack);
uint8 HAL_I2C_available();
uint8 HAL_I2C_Slave_Read();
uint8 HAL_I2C_Read(uint8 ack);
void HAL_I2C_Request_From(uint8 address);
void HAL_I2C_Slave_Write(uint8 i2c_data);
uint8 HAL_I2C_Write(uint8 i2c_data);
uint8 HAL_I2C_Print(uint8 *i2c_data);
uint8 HAL_I2C_Println(uint8 *i2c_data);
void HAL_I2C_Set_Handler_Req(void (* InterruptHandler_Req)(void));
void HAL_I2C_Set_Handler_Rec(void (* InterruptHandler_Rec)(void));
#endif	/* HAL_I2C_H */
