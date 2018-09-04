#include "I2C.h"
void I2C_Init (){
	TWSR = 0x00;		// 0 PreScaler
	TWAR = 0b00000010;
	TWBR = 0x02; 		// 400 kbit/s moode
	TWCR |= (1<<TWEN); // Enable T2C

}
void I2C_Start(){
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while(BIT_IS_CLEAR(TWCR,TWINT));
}
void I2C_Stop(){
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}
unsigned char I2C_ReadACK(){
		TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
	    while(BIT_IS_CLEAR(TWCR,TWINT));
	    return TWDR;
}
unsigned char I2C_ReadNACK(){
	TWCR = (1<<TWINT)|(1<<TWEN);
	while(BIT_IS_CLEAR(TWCR,TWINT));
	return TWDR;
}
void I2C_Write(unsigned char data){
	 TWDR = data;
	 TWCR = (1 << TWINT) | (1 << TWEN);
	 while(BIT_IS_CLEAR(TWCR,TWINT));
}
unsigned char I2C_GetStatus(){
	unsigned char status;
	status = TWSR & 0xF8;
	return status;
}
