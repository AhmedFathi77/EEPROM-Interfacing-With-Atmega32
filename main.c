/*
 * main.c
 *
 *  Created on: Apr 19, 2018
 *      Author: leenovoz510
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
#include "EEPROM.h"
#include "LCD.h"



int main(void){


		char val = 0;
		LCD_Init();
		_delay_ms(10);
		LCD_Clear();
		/* Init EEPROM */
		EEPROM_Init();

		EEPROM_Write_Byte(0x01 ,0 ,'B'); /* Write 0x0F in the external EEPROM */
		val = EEPROM_Read_Byte(0x01 , 0);  /* Read 0x0F from the external EEPROM */
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


