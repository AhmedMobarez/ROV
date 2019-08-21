/*
 * Software_PWM.c
 *
 * Created: 10/7/2017 6:28:18 PM
 * Author : Ahmed
 */ 


#include "SoftPWM_Lib.h"

 volatile  uint8_t OverFlow_Counter=1;
 uint8_t Overflows[PWM_Channels];


ISR(TIMER2_OVF_vect){
if(OverFlow_Counter >= 156){
	TCNT2 =0;
	OverFlow_Counter=1;
	PWM_PORTB |= ((1U<<Thruster_Pins[0]) | (1U<<Thruster_Pins[1]));
	PWM_PORTC |= ((1U<<Thruster_Pins[2]) | (1U<<Thruster_Pins[3]));
	}

	Send_PWM(OverFlow_Counter,Overflows);

OverFlow_Counter++;
}









int main(void)
{

Setup_Soft_PWM_Timer();
Setup_PWM_Channels();
Setup_PWM_PORT();
sei();

    /* Replace with your application code */
    while (1) 
    {
	}
 }


