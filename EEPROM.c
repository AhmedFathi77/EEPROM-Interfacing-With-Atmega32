#include "EEPROM.h"
void EEPROM_Init(){
	I2C_Init();
}
unsigned char EEPROM_Read(unsigned short Address, unsigned char *Data){
	I2C_Start();
	if(I2C_GetStatus()!= TW_START){
		return 0;
	}

	I2C_Write((unsigned char)(0xA0 | ((Address & 0x0700)>>7)));
	if(I2C_GetStatus()!= TW_MT_SLA_W_ACK){
		return 0;
	}
	I2C_Write((unsigned char)(Address));
	if(I2C_GetStatus()!= TW_MT_DATA_ACK){
			return 0;
	}
	I2C_Start();
	if(I2C_GetStatus()!= TW_REP_START){
		return 0;
	}
	I2C_Write((unsigned char)(0xA0 | ((Address & 0x0700)>>7))|1);
	if(I2C_GetStatus()!= TW_MT_SLA_R_ACK){
		return 0;
	}
	*Data = I2C_ReadNACK();
	if(I2C_GetStatus()!= TW_MR_DATA_NACK){
		return 0;
	}

	I2C_Stop();
	return 1;

}
unsigned char EEPROM_Write(unsigned short Address, unsigned char Data){
	I2C_Start();
	if(I2C_GetStatus() != TW_START){
		return 0;
	}

	I2C_Write((unsigned char)(0xA0 | ((Address & 0x0700)>>7)));
	if(I2C_GetStatus()!= TW_MT_SLA_W_ACK){
		return 0;
	}
	I2C_Write((unsigned char)(Address));
	if(I2C_GetStatus()!= TW_MT_DATA_ACK){
			return 0;
	}
	I2C_Write(Data);
	if(I2C_GetStatus()!= TW_MT_DATA_ACK){
			return 0;
	}

	I2C_Stop();
	return 1;
}
