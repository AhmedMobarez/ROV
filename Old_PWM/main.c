/*
 * Old_PWM.c
 *
 * Created: 11/30/2017 9:17:16 PM
 * Author : Ahmed
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
 volatile uint16_t PWM[4]={2880,2880,2880,2880};
 volatile uint16_t intervals[6]= {2000,8000,14000,20000,26000,33000};
 volatile unsigned char Thruster_Pins[4];
 volatile unsigned char OCRA_Counter =0;
  volatile unsigned char OCRB_Counter =0;
  volatile unsigned char k=0;

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
	
	
	
}



void Setup_nPWM_PORT()
{
	//Set PWM channels as output
	DDRD |=  (1U<<Thruster_Pins[0]) | (1U<<Thruster_Pins[1]) | (1U<<Thruster_Pins[2]) | (1U<<Thruster_Pins[3]);


	//Start with channels Off

	PORTD &=~  (1U<<Thruster_Pins[0]) | (1U<<Thruster_Pins[1]) | (1U<<Thruster_Pins[2]) | (1U<<Thruster_Pins[3]) ;
	


}



int main(void)
{
	timer_init(40000);
	Setup_nPWM_Channels();
	Setup_nPWM_PORT();
	sei();
	OCR1A = 2000;

    /* Replace with your application code */
    while (1) 
    {
    }
}




// OCRA sets pins high

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
