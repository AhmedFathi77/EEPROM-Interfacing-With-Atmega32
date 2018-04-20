/*
 * I2C.h
 *
 *  Created on: Apr 19, 2018
 *      Author: leenovoz510
 */

#ifndef I2C_H_
#define I2C_H_


#include "std_types.h"

void I2C_Init();
void I2C_Start();
void I2C_End();
void I2C_SendData(unsigned char Data);
unsigned char I2C_ReadData_With_AK();
unsigned char I2C_ReadData_With_NonAK();
unsigned char TWI_Get_Status(void);
void I2C_Slave_init(unsigned char Address);


#endif /* I2C_H_ */
