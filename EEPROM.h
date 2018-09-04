

#ifndef EEPROM_H_
#define EEPROM_H_

#include "mainHeader.h"
#include "I2C.h"

void EEPROM_Init();
unsigned char EEPROM_Read(unsigned short Address, unsigned char * Data);
unsigned char EEPROM_Write(unsigned short Address, unsigned char Data);


#endif /* EEPROM_H_ */
