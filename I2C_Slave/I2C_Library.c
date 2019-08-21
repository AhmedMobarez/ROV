/*
 * I2C_Library.c
 *
 * Created: 11/11/2017 9:35:09 PM
 *  Author: Ahmed
 */ 
 #include "I2C_Library.h"
 unsigned char I2C_data[2];

 void I2C_master_init(void)
 {
	//No Prescaler	 
	 TWSR &=~ ( (1U<<TWPS0) | (1U<<TWPS1) );

	 // Set SCL_CLK
	 TWBR = ((F_CPU/SCL_CLK)-16) /2 ;

 }

 void I2C_slave_init(unsigned char address){
  TWAR = (address<<1);
  
  //Activate pull-up resistors
  //DDRC &= ~((1U << PORTC4) | (1U<< PORTC5));
  //PORTC |= (1 << PORTC4) | (1 << PORTC5);

  TWCR = (1<<TWEN) | (1 << TWIE) | (1 << TWINT) | (1 << TWEA); // Enable I2C

  TWCR &= ~ (1 << TWSTA);
  TWCR &= ~ (1 << TWSTO);

}

unsigned char I2C_readack(void)
{

	//Acknowledge data transmission 
	TWCR = (1 << TWINT) | (1 << TWEA)| (1<<TWEN) | (1 << TWIE); 


	//return data
	return TWDR;

}

uint16_t shift(){
int value;
value = I2C_data[0];
value = value<<8;
value |= I2C_data[1];

return value;
}



void I2C_start(unsigned char address){

	//Send START condition 
	TWCR |= (1U<<TWEN) | (1U<<TWSTA) | (1U <<TWINT);

	// Wait for START transmission
	while( ! (TWCR & (1U<<TWINT) ) );

	//Sending address 
	TWDR = address;
	TWCR |= (1U<<TWINT) | (1U<<TWEN);

	// Wait for address transmission
	while( ! (TWCR & (1U<<TWINT) ) );

 }

 void I2C_stop(){

	//Send STOP condition
	TWCR |= (1U<<TWEN) | (1U<<TWSTO) | (1U<<TWINT);

	// Wait for STOP transmission
	while( TWCR & (1U<<TWSTO) );

 }


  unsigned char I2C_readaNack(void)
  {

	  //Initialize receive
	  TWCR = (1<<TWINT) | (1<<TWEN);
	  //wait for TWINT flag to be set
	  while(!(TWCR & (1<<TWINT)));

	  return TWDR;

  }

  void I2C_write( unsigned char data )
  {
	  
	  
	  TWDR = data; // put data in the TWDR Register to be sent.
	  TWCR |= (1 << TWINT) | (1 << TWEN); // clear flag before sending, and enable module

	

 }




 





/*
 void Hardware_PWM_init(){

	 //Clear on Compare match, Set at Bottom, Non inverting mode
	 TCCR1A &=~ ((1U<<COM1A0) | (1U<<COM1B0));
	 TCCR1A |= (1U<<COM1A1) | (1U<<COM1B1) ;

	 //Set Fast PWM , ICR1 = TOP
	 TCCR1A |= (1U<<WGM11);
	 TCCR1B |= (1U<<WGM12) | (1U<<WGM13);

	 //Set Prescalar = 8
	 TCCR1B |= (1U<<CS11);

	 //Set top
	 ICR1 = 39999;

	 //Set OCR
	 DDRB |= (1U<<PORTB1) | (1U<<PORTB2);



 } */
