/*
 * SoftPWM.c
 *
 * Created: 10/8/2017 3:17:01 PM
 *  Author: Ahmed
 */ 

 #include "SoftPWM_Lib.h"


 void Setup_Soft_PWM_Timer(){

 //Set timer 2 to  Normal, Non-PWM mode

 TCCR2A &=~ ((1U<<COM2A1)| (1U<<COM2A0)) ;
 TCCR0A &=~ ((1U<<WGM02) | (1<<WGM01) | (1<<WGM00));
 
 // PRE-Scaler = 8
 TCCR2B |=  (1U<<CS21); 
 TCCR2B &=~ ((1U<<CS20)| (1U<<CS22)) ;

 //Enable Overflow interrupt

 TIMSK2 |= (1U<<TOIE2);


 }



 void Setup_PWM_Channels(){

 Thruster_Pins[0] = PORTB4;
 Thruster_Pins[1] = PORTB5;
 Thruster_Pins[2] = PORTC0;
 Thruster_Pins[3] = PORTC1;

 }




 void Setup_PWM_PORT()
 {
 //Set PWM channels as output
 PWM_DDRC |= (1U<<Thruster_Pins[2]) | (1U<<Thruster_Pins[3]);

 PWM_DDRB |= (1U<<Thruster_Pins[0]) | (1U<<Thruster_Pins[1]) ;

 //Start with channels On

 PWM_PORTB |= ((1U<<Thruster_Pins[0]) | (1U<<Thruster_Pins[1]));
 PWM_PORTC |= ((1U<<Thruster_Pins[2]) | (1U<<Thruster_Pins[3]));


 }

 void Send_PWM(uint8_t OverFlow_Counter,uint8_t Overflows[]){

 
 if(OverFlow_Counter==Overflows[0]){			//Thruster 1
	 PWM_PORTB &=~ (1U<<Thruster_Pins[0]);
 }

 if(OverFlow_Counter==Overflows[1]){			//Thruster 2
	PWM_PORTB &=~ (1U<<Thruster_Pins[1]);
}

 if(OverFlow_Counter==Overflows[2]){			//Thruster 3
	PWM_PORTC &=~ (1U<<Thruster_Pins[2]);
 }

 if(OverFlow_Counter==Overflows[3]){			//Thruster 4
	 PWM_PORTC &=~ (1U<<Thruster_Pins[3]);
}
 

 }
 


