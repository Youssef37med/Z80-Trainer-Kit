/* 
 * File:   gpio.h
 * Author: Youssef Ahmed Tawfik Ali
 * https://www.linkedin.com/in/youssefahmed2001/
 * Created on September 19, 2023, 12:54 PM
 */

#ifndef GPIO_H
#define	GPIO_H

/* Includes -----------------------------------------------------------------------------*/
#include <pic16f877a.h>
#include "../mcal_std_types.h"
#include "../../MCAL_layer/device_config.h"
#include "gpio_cfg.h"

/* Data Type Declaration ----------------------------------------------------------------*/
typedef enum {
    OUTPUT=0,
    INPUT
} pinmode_t;

typedef enum {
    PA,
    PB,
    PC,
    PD,
    PE,
} port_t;

typedef enum {
    PIN0=0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
} pin_t;

typedef enum {
    LOW=0,
    HIGH
} logic_t;

/* Macros -------------------------------------------------------------------------------*/

/* Macro Functions ----------------------------------------------------------------------*/
#define SET_BIT(reg, bit)    (reg |= (1 << bit))
#define CLEAR_BIT(reg, bit)  (reg &= ~(1 << bit))
#define TOGGLE_BIT(reg, bit) (reg ^= (1 << bit))
#define READ_BIT(reg, bit)   ((reg >> bit) & 1)

/* Functions Declarations ---------------------------------------------------------------*/
void pinMode(port_t port, pin_t pin, pinmode_t mode);
void digitalWrite(port_t port, pin_t pin, logic_t logic);
logic_t digitalRead(port_t port, pin_t pin);
void togglePin(port_t Portx, pin_t Pinx);

#endif	/* GPIO_H */

