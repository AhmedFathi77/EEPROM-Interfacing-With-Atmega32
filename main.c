/*
 * main.c
 *
 *  Created on: Apr 19, 2018
 *      Author: leenovoz510
 */

#include "EEPROM.h"
#include "LCD.h"



int main(void){


		unsigned char val = 0;
		LCD_Init();
		_delay_ms(10);
		LCD_Clear();
		/* Init EEPROM */
		EEPROM_Init();

		EEPROM_Write(0x0311,0x01); /* Write 0x0F in the external EEPROM */
		_delay_ms(100);
		EEPROM_Read(0x0311, &val); /* Read 0x0F from the external EEPROM */
		while(1)
		{
			Go_to(1 , 1);
			LCD_Print("Hello");
			Go_to(1 , 2);
			LCD_IntegerToStringPrint(val);
			Go_to(1 , 3);
			LCD_SendData(val);
			//PORTD = val;

		}
		return 0;
}


