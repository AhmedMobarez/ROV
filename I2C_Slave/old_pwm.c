/*
 * old_pwm.c
 *
 * Created: 12/10/2017 2:28:15 PM
 *  Author: Ahmed
 */ 
#include "old_pwm.h"

 volatile uint16_t PWM[6]={2880,2880,2880,2880,2880,2880};
 volatile unsigned char Thruster_Pins[6];
 volatile unsigned char OCRB_Counter =0;

 
 void timer_init(uint16_t TOP){


	 //Set timer 1 to  Normal, Non-PWM , CTC mode

	 TCCR1A &=~ ((1U<<COM1A1)| (1U<<COM1A0));
	 TCCR1A &=~ ((1U<<COM1B1)| (1U<<COM1B0)) ;
	 TCCR1A &=~ ((1U<<WGM10) | (1<<WGM11));
	 TCCR1B |= (1U<<WGM12) | (1U<<WGM13);


	 //Set top value

	 ICR1 = TOP;
	 // PRE-Scaler = 8
	 TCCR1B |=  (1U<<CS11) ;
	 TCCR1B &=~ ((1U<<CS10)| (1U<<CS12)) ;

	 //Enable Overflow & OCRA interrupts

	 TIMSK1 |= (1U<<OCIE1B) | (1U<<OCIE1A)  ;


 }


 void Setup_nPWM_Channels(){

	Thruster_Pins[0] = PORTD0;
	Thruster_Pins[1] = PORTD1;
	Thruster_Pins[2] = PORTD2;
	Thruster_Pins[3] = PORTD3;
	Thruster_Pins[4] = PORTD4;
	Thruster_Pins[5] = PORTD5;
	
	 
	 
 }



 void Setup_nPWM_PORT()
 {
	 //Set PWM channels as output
	 DDRD |=  (1U<<Thruster_Pins[0]) | (1U<<Thruster_Pins[1]) | (1U<<Thruster_Pins[2]) | (1U<<Thruster_Pins[3]) | (1U<<Thruster_Pins[4]) | (1U<<Thruster_Pins[5]);


	 //Start with channels Off

	 PORTD &=~  (1U<<Thruster_Pins[0]) | (1U<<Thruster_Pins[1]) | (1U<<Thruster_Pins[2]) | (1U<<Thruster_Pins[3]) | (1U<<Thruster_Pins[4]) | (1U<<Thruster_Pins[5]) ;
	 


 }




 