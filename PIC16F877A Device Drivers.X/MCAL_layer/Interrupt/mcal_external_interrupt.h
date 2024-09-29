/* 
 * File:   mcal_external_interrupt.h
 * Author: Youssef Ahmed Tawfik Ali
 * https://www.linkedin.com/in/youssefahmed2001/
 * Created on February 14, 2021, 11:52 PM
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H

/* Includes -----------------------------------------------------------------------------*/
#include "mcal_interrupt_config.h"

/* Data Type Declaration ----------------------------------------------------------------*/
typedef void (*InterruptHandler)(void);

typedef enum{
    FALLING = 0,
    RISING
}interrupt_INTx_edge;

typedef enum{
    INTERRUPT_EXTERNAL_INT0 =  0,       
}interrupt_INTx_src;

typedef enum{
    INTERRUPT_EXTERNAL_RB4 =  0,
    INTERRUPT_EXTERNAL_RB5,
    INTERRUPT_EXTERNAL_RB6,
    INTERRUPT_EXTERNAL_RB7,
}interrupt_RBX_src;

/* Macros -------------------------------------------------------------------------------*/

/* Macro Functions ----------------------------------------------------------------------*/
#if EXTERNAL_INTERRUPT_INTx_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
/* This routine clears the interrupt enable for the external interrupt, INT0 */
#define EXT_INT0_InterruptDisable()         (INTCONbits.INTE = 0)
/* This routine sets the interrupt enable for the external interrupt, INT0 */
#define EXT_INT0_InterruptEnable()          (INTCONbits.INTE = 1)
/* This routine clears the interrupt flag for the external interrupt, INT0 */
#define EXT_INT0_InterruptFlagClear()       (INTCONbits.INTF = 0)
/* This routine set the edge detect of the extern interrupt to negative edge */
#define EXT_INT0_RisingEdgeSet()            (OPTION_REGbits.INTEDG = 1)
/* This routine set the edge detect of the extern interrupt to positive edge */
#define EXT_INT0_FallingEdgeSet()           (OPTION_REGbits.INTEDG = 0)

#endif


#if EXTERNAL_INTERRUPT_OnChange_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
/* This routine clears the interrupt disable for the external interrupt, RBx */
#define EXT_RBx_InterruptDisable()         (INTCONbits.RBIE = 0)
/* This routine sets the interrupt enable for the external interrupt, RBx */
#define EXT_RBx_InterruptEnable()          (INTCONbits.RBIE = 1)
/* This routine clears the interrupt flag for the external interrupt, RBx */
#define EXT_RBx_InterruptFlagClear()       (INTCONbits.RBIF = 0)

#endif

/* Functions Declarations ---------------------------------------------------------------*/
void attachInterrupt_INT0(void (*InterruptHandler)(void),interrupt_INTx_edge edge);
void attachInterrupt_RBx(interrupt_RBX_src pin,void (*InterruptHandler_high)(void),void (*InterruptHandler_low)(void));

#endif	/* MCAL_EXTERNAL_INTERRUPT_H */
