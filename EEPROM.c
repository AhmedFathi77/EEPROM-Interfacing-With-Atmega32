/*
 * EEPROM.c
 *
 *  Created on: Apr 19, 2018
 *      Author: leenovoz510
 */

#include "EEPROM.h"

void EEPROM_Init(void)
{
	I2C_Init(); // just initialize the TWI module inside the MC
}

void EEPROM_Write_Byte(char dev_addr,char dev_loc,char dev_data)
{
	I2C_Start();

    //write the device address and so we need to get A8 A9 A10 address bits and R/W=0 (write)
    I2C_SendData(dev_addr);

    //send the required location address
    I2C_SendData(dev_loc);

    //write byte to eeprom
    I2C_SendData(dev_data);


    I2C_End();

}

uint8 EEPROM_Read_Byte(char dev_addr,char dev_loc){
	uint8 Data;
	I2C_Start();

    //write the device address and so we need to get A8 A9 A10 address bits and R/W=0 (write)
    I2C_SendData(dev_addr);

    //send the required location address
    I2C_SendData(dev_loc);


    //send a repeated start
    I2C_Start();


    //write the device address and so we need to get A8 A9 A10 address bits and R/W=1 (Read)
    I2C_SendData(dev_addr|0x01);
    Data = I2C_ReadData_With_NonAK();

    I2C_End();
    return Data;
}








