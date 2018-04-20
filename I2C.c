
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

void I2C_Init(){
	TWSR = 0x00;		// 0 PreScaler
	TWBR = 0x0C; 		// 400 kbit/s moode
	TWCR |= (1<<TWEN);	// Enable T2C
}
void I2C_Start(){
	 TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while((TWCR &(1<<TWINT))==0);

}
void I2C_End(){
	 TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}
void I2C_SendData(unsigned char Data){
	TWDR = Data;

	 TWCR = (1<<TWINT)|(1<<TWEN);
	while((TWCR & (1<<TWINT)) == 0){}
}
unsigned char I2C_ReadData_With_AK(){
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	// Wait until TWINT flag set to make sure Start Bit is send successfully
	while((TWCR & (1<<TWINT)) == 0);
	return TWDR;
}
unsigned char I2C_ReadData_With_NonAK(){
	TWCR = (1<<TWINT)|(1<<TWEN);
	while((TWCR & (1<<TWINT)) == 0);
	return TWDR;
}

unsigned char TWI_Get_Status(void)
{
	unsigned char status;
    // masking to eliminate first 3 bits and get the last 5 bits (status bits)
    status = TWSR & 0xF8;
    return status;
}
void I2C_Slave_init(unsigned char Address){
	TWAR = Address;
	TWCR |= (1<<TWEN);	// Enable T2C
	TWCR |=(1<<TWINT);	// Clear TWINT flag before sending the start bit
	TWCR |=(1<<TWEA);	// Enable Acknowledgement
}
