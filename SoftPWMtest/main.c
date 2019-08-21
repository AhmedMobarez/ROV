/*
 * New_Soft_PWM.c
 *
 * Created: 11/20/2017 7:49:24 PM
 * Author : Ahmed
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>


int main(void)
{
  sei();
  DDRB |= (1u<<5);
  PORTB &=~ (1U<<5);
  
//Set timer 1 to  Normal, Non-PWM , CTC mode

TCCR1A &=~ ((1U<<COM1A1)| (1U<<COM1A0)) ;
TCCR1A &=~ ((1U<<WGM10) | (1<<WGM11));
TCCR1B |= (1U<<WGM12) | (1U<<WGM13);


//Set top value

ICR1 = 65000;
// PRE-Scaler = 8
TCCR1B |=  (1U<<CS11) ;
TCCR1B &=~ ((1U<<CS10)| (1U<<CS12)) ;

//Enable Overflow & OCRA interrupts

TIMSK1 |= (1U<<ICIE1) | (1U<<OCIE1A)  ;



  /* Replace with your application code */
    while (1)
    {
    }
}


ISR(TIMER1_CAPT_vect){

/* for (int i = 0; i < 5; i++) {
   Sorted_PWM[i] = PWM[i];
 }

 Bubble_Sort(Sorted_PWM,6);
OCR_Counter=0;

 OCR1A = Sorted_PWM[OCR_Counter];
 */

//PORTD ^=  (1U<<PWM[0]) | (1U<<PWM[1]) | (1U<<PWM[2]) | (1U<<PWM[3]) | (1U<<PWM[4]) | (1U<<PWM[5]) ;
//PORTD =0;
//OCR1A = Sorted_PWM[0];

PORTB ^= (1U<<5);
//delay(5);
//TCNT1 =0;

}


ISR(TIMER1_COMPA_vect){


//PORTB &=~ (1U<<5);
//delay(10000);

}