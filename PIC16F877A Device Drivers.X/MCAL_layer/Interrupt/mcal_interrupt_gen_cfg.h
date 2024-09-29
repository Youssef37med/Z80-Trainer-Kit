/* 
 * File:   mcal_interrupt_gen_cfg.h
 * Author: Youssef Ahmed Tawfik Ali
 * https://www.linkedin.com/in/youssefahmed2001/
 * Created on February 19, 2021, 11:28 PM
 */

#ifndef MCAL_INTERRUPT_GEN_CFG_H
#define	MCAL_INTERRUPT_GEN_CFG_H

/* Includes -----------------------------------------------------------------------------*/

/* Data Type Declaration ----------------------------------------------------------------*/

/* Macros -------------------------------------------------------------------------------*/
#define INTERRUPT_FEATURE_ENABLE 1U

#define EXTERNAL_INTERRUPT_INTx_FEATURE_ENABLE      INTERRUPT_FEATURE_ENABLE
#define EXTERNAL_INTERRUPT_OnChange_FEATURE_ENABLE  INTERRUPT_FEATURE_ENABLE

#define ADC_INTERRUPT_FEATURE_ENABLE                INTERRUPT_FEATURE_ENABLE

#define TIMER0_INTERRUPT_FEATURE_ENABLE             INTERRUPT_FEATURE_ENABLE
#define TIMER1_INTERRUPT_FEATURE_ENABLE             INTERRUPT_FEATURE_ENABLE
#define TIMER2_INTERRUPT_FEATURE_ENABLE             INTERRUPT_FEATURE_ENABLE

#define EUSART_TX_INTERRUPT_FEATURE_ENABLE          INTERRUPT_FEATURE_ENABLE
#define EUSART_RX_INTERRUPT_FEATURE_ENABLE          INTERRUPT_FEATURE_ENABLE

#define MSSP_I2C_INTERRUPT_FEATURE_ENABLE           INTERRUPT_FEATURE_ENABLE
#define MSSP_SPI_INTERRUPT_FEATURE_ENABLE           INTERRUPT_FEATURE_ENABLE

#define  CCP1_INTERRUPT_FEATURE_ENABLE              INTERRUPT_FEATURE_ENABLE
#define  CCP2_INTERRUPT_FEATURE_ENABLE              INTERRUPT_FEATURE_ENABLE
/* Macro Functions ----------------------------------------------------------------------*/

/* Functions Declarations ---------------------------------------------------------------*/

#endif	/* MCAL_INTERRUPT_GEN_CFG_H */

