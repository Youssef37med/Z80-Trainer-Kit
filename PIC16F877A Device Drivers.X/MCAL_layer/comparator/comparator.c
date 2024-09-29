/* 
 * File:   comparator.c
 * Author: Youssef Ahmed Tawfik Ali
 * https://www.linkedin.com/in/youssefahmed2001/
 * Created on May 21, 2021, 9:53 PM
 */

/* Includes -----------------------------------------------------------------------------*/
#include "comparator.h"

/* Data Type Definition -----------------------------------------------------------------*/

/* Macros -------------------------------------------------------------------------------*/

/* Macro Functions ----------------------------------------------------------------------*/

/* Functions Definition -----------------------------------------------------------------*/
void Comparator_Init()
{
    CMCONbits.CM0 = 1;
    CMCONbits.CM1 = 1;
    CMCONbits.CM2 = 0;
    CMCONbits.C1INV = 0;
    CMCONbits.C2INV = 0;
    CMCONbits.C1OUT = 1;
    CMCONbits.C2OUT = 1;
    pinMode(PA,PIN0,INPUT);
    pinMode(PA,PIN3,INPUT);
    pinMode(PA,PIN4,OUTPUT);
    
    pinMode(PA,PIN1,INPUT);
    pinMode(PA,PIN2,INPUT);
    pinMode(PA,PIN5,OUTPUT);
}
