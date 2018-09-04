

#ifndef I2C_H_
#define I2C_H_

#define TW_START         0x08 // start has been sent
#define TW_REP_START     0x10 // repeated start
#define TW_MT_SLA_W_ACK  0x18 // Master transmit ( slave address + Write request ) to slave + Ack received from slave
#define TW_MT_SLA_R_ACK  0x40 // Master transmit ( slave address + Read request ) to slave + Ack received from slave
#define TW_MT_DATA_ACK   0x28 // Master transmit data and ACK has been received from Slave.
#define TW_MR_DATA_ACK   0x50 // Master received data and send ACK to slave
#define TW_MR_DATA_NACK  0x58 // Master received data but doesn't send ACK to slave


#include "mainHeader.h"

void I2C_Init ();
void I2C_Start();
void I2C_Stop();
unsigned char I2C_ReadACK();
unsigned char I2C_ReadNACK();
void I2C_Write(unsigned char toWrite);
unsigned char I2C_GetStatus();


#endif /* I2C_H_ */
