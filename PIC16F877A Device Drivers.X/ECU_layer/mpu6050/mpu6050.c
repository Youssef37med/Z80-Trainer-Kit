/* 
 * File:   mpu6050.c
 * Author: Youssef Ahmed Tawfik Ali
 * https://www.linkedin.com/in/youssefahmed2001/
 * Created on September 23, 2024, 3:39 PM
 */

/* Includes -----------------------------------------------------------------------------*/
#include "mpu6050.h"

/* Data Type Definition -----------------------------------------------------------------*/

/* Macros -------------------------------------------------------------------------------*/

/* Macro Functions ----------------------------------------------------------------------*/

/* Functions Definition -----------------------------------------------------------------*/
void MPU6050_Init()
{
  // Power-Up Delay & I2C_Init
  __delay_ms(100);
  HAL_I2C_Init(I2C_MASTER_MODE,0x00);
 
  // Setting The Sample (Data) Rate
  Wire.beginTransmission();
  Wire.write(0xD0);
  Wire.write(SMPLRT_DIV);
  Wire.write(0x07);
  Wire.endTransmission();
 
  // Setting The Clock Source
  Wire.beginTransmission();
  Wire.write(0xD0);
  Wire.write(PWR_MGMT_1);
  Wire.write(0x01);
  Wire.endTransmission();
  // Configure The DLPF
  Wire.beginTransmission();
  Wire.write(0xD0);
  Wire.write(CONFIG);
  Wire.write(0x00);
  Wire.endTransmission();
  // Configure The ACCEL (FSR= +-2g)
  Wire.beginTransmission();
  Wire.write(0xD0);
  Wire.write(ACCEL_CONFIG);
  Wire.write(0x00);
  Wire.endTransmission();
  // Configure The GYRO (FSR= +-2000d/s)
  Wire.beginTransmission();
  Wire.write(0xD0);
  Wire.write(GYRO_CONFIG);
  Wire.write(0x18);
  Wire.endTransmission();
  // Enable Data Ready Interrupts
  Wire.beginTransmission();
  Wire.write(0xD0);
  Wire.write(INT_ENABLE);
  Wire.write(0x01);
  Wire.endTransmission();
}

void MPU6050_Read()
{
  char buffer[40];
  int Ax,Ay,Az,T,Gx,Gy,Gz;
  // Prepare For Reading, Starting From ACCEL_XOUT_H
  Wire.beginTransmission();
  Wire.write(0xD0);
  Wire.write(ACCEL_XOUT_H);
  Wire.endTransmission();

  Wire.beginTransmission();
  Wire.write(0xD1);
  Ax = ((int)Wire.read(I2C_MASTER_SEND_ACK)<<8) | (int)Wire.read(I2C_MASTER_SEND_ACK);
  Ay = ((int)Wire.read(I2C_MASTER_SEND_ACK)<<8) | (int)Wire.read(I2C_MASTER_SEND_ACK);
  Az = ((int)Wire.read(I2C_MASTER_SEND_ACK)<<8) | (int)Wire.read(I2C_MASTER_SEND_ACK);
  T  = ((int)Wire.read(I2C_MASTER_SEND_ACK)<<8) | (int)Wire.read(I2C_MASTER_SEND_ACK);
  Gx = ((int)Wire.read(I2C_MASTER_SEND_ACK)<<8) | (int)Wire.read(I2C_MASTER_SEND_ACK);
  Gy = ((int)Wire.read(I2C_MASTER_SEND_ACK)<<8) | (int)Wire.read(I2C_MASTER_SEND_ACK);
  Gz = ((int)Wire.read(I2C_MASTER_SEND_ACK)<<8) | (int)Wire.read(I2C_MASTER_SEND_NACK);
  Wire.endTransmission();
 
  sprintf(buffer," Ax = %d    ",Ax);
  Serial.print(buffer);
 
  sprintf(buffer," Ay = %d    ",Ay);
  Serial.print(buffer);
 
  sprintf(buffer," Az = %d    ",Az);
  Serial.print(buffer);
 
  sprintf(buffer," T = %d     ",T);
  Serial.print(buffer);
 
  sprintf(buffer," Gx = %d    ",Gx);
  Serial.print(buffer);
 
  sprintf(buffer," Gy = %d    ",Gy);
  Serial.print(buffer);
 
  sprintf(buffer," Gz = %d    ",Gz);
  Serial.println(buffer);
}