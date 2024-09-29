/* 
 * File:   hal_i2c.c
 * Author: Youssef Ahmed Tawfik Ali
 * https://www.linkedin.com/in/youssefahmed2001/
 * Created on May 21, 2021, 9:53 PM
 */

/* Includes -----------------------------------------------------------------------------*/
#include "hal_i2c.h"

/* Data Type Definition -----------------------------------------------------------------*/
#if MSSP_I2C_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
static void (*I2C_Report_Write_Collision_InterruptHandler)(void) = NULL;
static void (*I2C_Report_Receive_Overflow_InterruptHandle)(void) = NULL;
static void (*I2C_DefaultInterruptHandle_Req)(void) = NULL;
static void (*I2C_DefaultInterruptHandle_Rec)(void) = NULL;
static uint8 check = 0;
#endif

volatile Wire_t Wire;
static volatile char i2c_mode = -1;

/* Macros -------------------------------------------------------------------------------*/

/* Macro Functions ----------------------------------------------------------------------*/

/* Functions Declarations ---------------------------------------------------------------*/
static inline void MSSP_I2C_Mode_GPIO_CFG(void);
static inline void MSSP_I2C_Interrupt_Configurations();

void HAL_I2C_Init(uint8 mode,uint8 slave_address){
    /* Disable MSSP I2C Module */
    MSSP_MODULE_DISABLE();
    
    Wire.begin = HAL_I2C_Init;
    Wire.beginTransmission = HAL_I2C_Master_Send_Start;
    Wire.endTransmission = HAL_I2C_Master_Send_Stop;
    Wire.restartTransmission = HAL_I2C_Master_Send_Repeated_Start;
    Wire.end = HAL_I2C_DeInit;
    Wire.setClock = HAL_I2C_setClock;
    Wire.write = HAL_I2C_Write;
    Wire.print = HAL_I2C_Print;
    Wire.println = HAL_I2C_Println;
    Wire.read = HAL_I2C_Read;
    Wire.available = HAL_I2C_available;
    Wire.requestFrom = HAL_I2C_Request_From;
    Wire.onReceive = HAL_I2C_Set_Handler_Rec;
    Wire.onRequest = HAL_I2C_Set_Handler_Req;
    if(I2C_MASTER_MODE == mode)
    {
        /* I2C Slave Mode Configurations */
        I2C_SET_MODE(I2C_MASTER_MODE_DEFINED_CLOCK);
        /* I2C Master Mode Clock Configurations */
        HAL_I2C_setClock(100000);
        /*set master mode variable*/
        i2c_mode = I2C_MASTER_MODE;
    }
    else if(I2C_SLAVE_MODE == mode)
    {
        /* I2C Slave Mode General Call Configurations */
        I2C_GENERAL_CALL_DISABLE();
        /* Clear the Write Collision Detect */
        SSPCONbits.WCOL = 0; /* No Collision */
        /* Clear the Receive Overflow Indicator */
        SSPCONbits.SSPOV = 0; /* No Overflow */
        /* Release the clock */
        I2C_CLOCK_STRETCH_DISABLE();
        /* Assign the I2C Slave Address */
        if((slave_address % 2) == 0)
            SSPADD = slave_address;
        else
            SSPADD = slave_address << 1;
        /* I2C Slave Mode Configurations */
        I2C_SET_MODE(I2C_SLAVE_MODE_7BIT_ADDRESS);
        /*set master mode variable*/
        i2c_mode = I2C_SLAVE_MODE;
        /* Interrupt Configurations */
        #if MSSP_I2C_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
              MSSP_I2C_Interrupt_Configurations();
        #endif
    }
    else { /* Nothing */ }
    /* MSSP I2C Slew Rate Control */
    I2C_SLEW_RATE_DISABLE();
    /* MSSP I2C SMBus Control */
    I2C_SMBus_DISABLE();
    /* I2C Master Mode GPIO Configurations */
    MSSP_I2C_Mode_GPIO_CFG();
    /* Enable MSSP I2C Module */
    MSSP_MODULE_ENABLE();
}

void HAL_I2C_setClock(uint32 clock){
    /*  I2C Master mode, clock = FOSC/(4 * (SSPADD + 1)) */
    SSPADD = (uint8)(((_XTAL_FREQ / 4.0) / clock) - 1);
}

void HAL_I2C_DeInit(){
    
    /* Disable MSSP I2C Module */
    MSSP_MODULE_DISABLE();
    /* Interrupt Configurations */
    #if MSSP_I2C_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
            MSSP_I2C_InterruptDisable();
            MSSP_I2C_BUS_COL_InterruptDisable();
    #endif
    
}

std_ReturnType HAL_I2C_Master_Send_Start(){
    std_ReturnType ret = E_NOT_OK;
    
    /* Initiates Start condition on SDA and SCL pins */
    SSPCON2bits.SEN = 1; /* Initiates Start condition on SDA and SCL pins. Automatically cleared by hardware. */
    /* Wait for the completion of the Start condition */
    while(SSPCON2bits.SEN);
    /* Clear The MSSP Interrupt Flag bit -> SSPIF */
    MSSP_I2C_InterruptFlagClear();
    /* Report The Start Condition Detection */
    if(I2C_START_BIT_DETECTED == SSPSTATbits.S){
        ret = E_OK; /* Indicates that a Start bit has been detected last */
    }
    else{
        ret = E_NOT_OK; /* Start bit was not detected last */
    }
    
    return ret;
}

std_ReturnType HAL_I2C_Master_Send_Repeated_Start(){
    std_ReturnType ret = E_NOT_OK;
    
    /* Initiates Repeated Start condition on SDA and SCL pins */
    SSPCON2bits.RSEN = 1; /* Initiates Repeated Start condition on SDA and SCL pins. Automatically cleared by hardware */
    /* Wait for the completion of the Repeated Start condition */
    while(SSPCON2bits.RSEN);
    /* Clear The MSSP Interrupt Flag bit -> SSPIF */
    MSSP_I2C_InterruptFlagClear();
    ret = E_OK;
    
    return ret;
}

std_ReturnType HAL_I2C_Master_Send_Stop(){
    std_ReturnType ret = E_NOT_OK;
    
    /* Initiates Stop condition on SDA and SCL pins */
    SSPCON2bits.PEN = 1; /* Initiates Stop condition on SDA and SCL pins. Automatically cleared by hardware */
    /* Wait for the completion of the Stop condition */
    while(SSPCON2bits.PEN);
    /* Clear The MSSP Interrupt Flag bit -> SSPIF */
    MSSP_I2C_InterruptFlagClear();
    /* Report The Stop Condition Detection */
    if(I2C_STOP_BIT_DETECTED == SSPSTATbits.P){
        ret = E_OK; /* Indicates that a Stop bit has been detected last */
    }
    return ret;
}

uint8 HAL_I2C_Master_Write(uint8 i2c_data){
    uint8 _ack = I2C_ACK_NOT_RECEIVED_FROM_SLAVE;
    /* Write Data to the Data register */
    SSPBUF = i2c_data;
    /* Wait The transmission to be completed */
    while(SSPSTATbits.BF || SSPSTATbits.R_nW);
    /* Clear The MSSP Interrupt Flag bit -> SSPIF */
    MSSP_I2C_InterruptFlagClear();
    /* Report the acknowledge received from the slave */
    if(I2C_ACK_RECEIVED_FROM_SLAVE == SSPCON2bits.ACKSTAT){
        _ack = I2C_ACK_RECEIVED_FROM_SLAVE; /* Acknowledge was received from slave */
    }
    else{
        _ack = I2C_ACK_NOT_RECEIVED_FROM_SLAVE; /* Acknowledge was not received from slave */
    }
    
    return _ack;
}
void HAL_I2C_Slave_Write(uint8 i2c_data){
    if(R_nW)
    {
      char Dummy = SSPBUF;
      SSPBUF = i2c_data ;
      I2C_CLOCK_STRETCH_DISABLE();
      while(BF);
    }
}
uint8 HAL_I2C_Write(uint8 i2c_data){
    uint8 ack = I2C_ACK_NOT_RECEIVED_FROM_SLAVE;
    if(i2c_mode == I2C_MASTER_MODE)     {ack = HAL_I2C_Master_Write(i2c_data);}
    else if (i2c_mode == I2C_SLAVE_MODE){HAL_I2C_Slave_Write(i2c_data);}
    return ack;
}
uint8 HAL_I2C_Print(uint8 *i2c_data){
    uint8 ack = I2C_ACK_NOT_RECEIVED_FROM_SLAVE;
    uint16 char_counter = 0;
    for(char_counter=0; i2c_data[char_counter]!='\0'; char_counter++){
        ack = HAL_I2C_Write(i2c_data[char_counter]);
    }
    return ack;
}
uint8 HAL_I2C_Println(uint8 *i2c_data){
    uint8 ack = I2C_ACK_NOT_RECEIVED_FROM_SLAVE;
    uint16 char_counter = 0;
    for(char_counter=0; i2c_data[char_counter]!='\0'; char_counter++){
        ack = HAL_I2C_Write(i2c_data[char_counter]);
    }
    HAL_I2C_Write('\n');
    return ack;
}
uint8 HAL_I2C_Master_Read(uint8 ack){
    MSSP_I2C_InterruptFlagClear();
    uint8 i2c_data = 0;
    /* Master Mode Receive Enable */
    I2C_MASTER_RECEIVE_ENABLE();
    /* Wait for buffer full flag : A complete byte received */
    while(!SSPSTATbits.BF || SSPSTATbits.R_nW);
    /* Copy The data registers to buffer variable */
    i2c_data = SSPBUF;
    /* Send ACK or NACK after read */
    if(I2C_MASTER_SEND_ACK == ack){
        SSPCON2bits.ACKDT = 0; /* Acknowledge */
        /* Initiates Acknowledge sequence on SDA and SCL pins and transmit ACKDT data bit. */
        SSPCON2bits.ACKEN = 1; 
        while(SSPCON2bits.ACKEN); /* Automatically cleared by hardware */
    }
    else if(I2C_MASTER_SEND_NACK == ack){
        SSPCON2bits.ACKDT = 1; /* Not Acknowledge */
        /* Initiates Acknowledge sequence on SDA and SCL pins and transmit ACKDT data bit. */
        SSPCON2bits.ACKEN = 1;
        while(SSPCON2bits.ACKEN); /* Automatically cleared by hardware */
    }
    else { /* Nothing */ }
    
    return i2c_data;
}
uint8 HAL_I2C_Slave_Read(){
    I2C_CLOCK_STRETCH_ENABLE();
    uint8 data = 0;
    if(SSPSTATbits.R_nW == 0 && SSPSTATbits.D_nA == 0)
    {
        uint8 dummy_buffer = SSPBUF;
        while(!SSPSTATbits.BF);
        data = SSPBUF;
    }
    else if(SSPSTATbits.R_nW == 0 && SSPSTATbits.D_nA == 1)
    {
        //while(!SSPSTATbits.BF);
        data = SSPBUF;
    }
    MSSP_I2C_InterruptFlagClear();
    I2C_CLOCK_STRETCH_DISABLE();
    return data;
}
uint8 HAL_I2C_Read(uint8 ack){
    uint8 i2c_data = 0;
    if(i2c_mode == I2C_MASTER_MODE)     {i2c_data = HAL_I2C_Master_Read(ack);}
    else if (i2c_mode == I2C_SLAVE_MODE){i2c_data = HAL_I2C_Slave_Read();}
    return i2c_data;
}
uint8 HAL_I2C_available(){
    MSSP_I2C_InterruptFlagClear();
    uint8 ret = 0;
    if(PIR1bits.SSPIF){ret = 1;}
    else{ret = 0;}
    return ret;
}
void HAL_I2C_Set_Handler_Req(void (* InterruptHandler_Req)(void)){
    I2C_DefaultInterruptHandle_Req = InterruptHandler_Req;
}
void HAL_I2C_Set_Handler_Rec(void (* InterruptHandler_Rec)(void)){
    I2C_DefaultInterruptHandle_Rec = InterruptHandler_Rec;
}
void HAL_I2C_Request_From(uint8 address){
    Wire.restartTransmission();
    if((address % 2) == 0)
        Wire.write(address + 1);//shift 7bit address and R/W is HIGH(read from slave)
    else
        Wire.write((address << 1) + 1);//shift 7bit address and R/W is HIGH(read from slave)
}

void MSSP_I2C_ISR(void){
#if MSSP_I2C_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE    
    MSSP_I2C_InterruptFlagClear();
    if(I2C_DefaultInterruptHandle_Req && SSPSTATbits.R_nW == 1){
        I2C_DefaultInterruptHandle_Req();
    }
    if(I2C_DefaultInterruptHandle_Rec && SSPSTATbits.R_nW == 0){
        I2C_DefaultInterruptHandle_Rec();
    }
    if(SSPCONbits.SSPOV == 1){
        SSPCONbits.SSPOV = 0;
        if(I2C_Report_Receive_Overflow_InterruptHandle){
            I2C_Report_Receive_Overflow_InterruptHandle();
        }
    }
    
#endif
}

void MSSP_I2C_BC_ISR(void){
#if MSSP_I2C_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
    MSSP_I2C_BUS_COL_InterruptFlagClear();
    SSPCONbits.WCOL = 0;
    if(I2C_Report_Write_Collision_InterruptHandler){
        I2C_Report_Write_Collision_InterruptHandler();
    }
#endif
}

static inline void MSSP_I2C_Mode_GPIO_CFG(void){
    pinMode(PC,PIN3,INPUT);
    pinMode(PC,PIN4,INPUT);
    //TRISCbits.TRISC3 = 1; /* Serial clock (SCL) is Input */
    //TRISCbits.TRISC4 = 1; /* Serial data (SDA) is Input */
}

static inline void MSSP_I2C_Interrupt_Configurations(){
#if MSSP_I2C_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
        MSSP_I2C_InterruptEnable();
        MSSP_I2C_BUS_COL_InterruptEnable();
        MSSP_I2C_InterruptFlagClear();
        MSSP_I2C_BUS_COL_InterruptFlagClear();
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
        //I2C_Report_Write_Collision_InterruptHandler = I2C_Report_Write_Collision;
        //I2C_Report_Receive_Overflow_InterruptHandle = I2C_Report_Receive_Overflow;
#endif   
}


