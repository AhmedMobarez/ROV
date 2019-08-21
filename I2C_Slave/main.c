/*
 * I2C_Slave.c
 *
 * Created: 11/11/2017 9:34:18 PM
 * Author : Ahmed
 */ 

#include "I2C_Library.h"
#include <avr/interrupt.h>
#include "old_pwm.h"





volatile uint16_t pwm=0;
volatile extern unsigned char I2C_data[6];
volatile extern uint16_t PWM[6];
volatile uint16_t intervals[6]= {2000,8000,14000,20000,26000,33000};
volatile extern unsigned char Thruster_Pins[6];
volatile extern unsigned char OCRB_Counter;
 volatile unsigned char i=0;
 volatile unsigned char j=0;
 volatile unsigned char k=0;

int main(void)
{

sei();	


I2C_slave_init(0x04); 
timer_init(39999);
Setup_nPWM_Channels();
Setup_nPWM_PORT();
OCR1A = intervals[k];
DDRB |= (1U<<PORTB1) | (1U<<PORTB2) | (1U<<PORTB3) | (1U<<PORTB4);
PORTB &=~ ((1U<<PORTB1) | (1U<<PORTB2) | (1U<<PORTB3) | (1U<<PORTB4));


	while (1)
	{
	}
}

ISR(TIMER1_COMPA_vect){

	PORTD |= (1U<<Thruster_Pins[k]);
	OCR1B = intervals[k] + PWM[k];
	k++;
	if(k==4)
	k=0;

	OCR1A = intervals[k];
}



//OCRB sets pins low
ISR(TIMER1_COMPB_vect){

	PORTD &=~ (1U<<Thruster_Pins[OCRB_Counter]);

	OCRB_Counter++;
	if(OCRB_Counter==4)
	OCRB_Counter=0;
}




ISR(TWI_vect) {
	
	switch( TWSR & TWSR_Mask)
	{
		// Slave Receiver Mode   

		// Address + write has been received
		case 0X60: 
		TWCR = (1 << TWINT) | (1 << TWEA)| (1<<TWEN) | (1 << TWIE); // Clear flag, Enable ack response
		break;


		//TO DO : case 0x68 , case 0x88
		
		// Data has been received, Ack will be returned
		case 0X80: 
		
		// Clear flag, Enable ack response
		if(i==0){
		pwm = I2C_readack();
		i++;
		pwm = (pwm<<8) ;}

		else if(i==1){
		pwm |= I2C_readack();
		i=0;
		for (int a=0;a<4;a++)
		{
			PWM[a]=pwm;
		}

		}

		
		break;		
		
		}

	
/*	for(int a=0;a<6;a++){
	PWM[a]=pwm;
	i=0;
	}*/
	
	TWCR |= (1<<TWINT)| (1 << TWEA);
}
