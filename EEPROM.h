/*
 * EEPROM.h
 *
 *  Created on: Apr 19, 2018
 *      Author: leenovoz510
 */

#ifndef EEPROM_H_
#define EEPROM_H_



#include "I2C.h"

void EEPROM_Init(void);
void EEPROM_Write_Byte(char dev_addr,char dev_loc,char dev_data);
uint8 EEPROM_Read_Byte(char dev_addr,char dev_loc);
#endif /* EEPROM_H_ */
