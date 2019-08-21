/*
 * I2C_Library.c
 *
 * Created: 11/11/2017 9:35:09 PM
 *  Author: Ahmed
 */ 
 #include "I2C_Library.h"

 void I2C_init(void)
 {
	//No Prescaler	 
	 TWSR &= ~( (1U<<TWPS0) | (1U<<TWPS1) );

	 // Set SCL_CLK
	 TWBR = ((F_CPU/SCL_CLK)-16) /2 ;

 }

 void I2C_start(unsigned char address){

	 //Send START condition
	 TWCR |= (1U<<TWEN) | (1U<<TWSTA) | (1U <<TWINT);

	 // Wait for START transmission
	 while( ! (TWCR & (1U<<TWINT) ) );

	 //Sending address
	 TWDR = address<<1 ;
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


 unsigned char I2C_readack(void)
 {

	//Initialize receive  
	 TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	 //wait for TWINT flag to be set
	 while(!(TWCR & (1<<TWINT)));

	 return TWDR;

 }


  unsigned char I2C_readaNack(void)
  {

	  //Initialize receive
	  TWCR = (1<<TWINT) | (1<<TWEN);
	  //wait for TWINT flag to be set
	  while(!(TWCR & (1<<TWINT)));

	  return TWDR;

  }


   void I2C_write(  uint16_t data )
   {
	   
	   
	   // send data to the previously addressed device
	   TWDR = data;
	   TWCR = (1<<TWINT) | (1<<TWEN);

	   // wait until transmission completed
	   while(!(TWCR & (1<<TWINT)));

	   

   }