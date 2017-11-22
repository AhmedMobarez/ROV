/*
 * New_PWM.c
 *
 * Created: 11/20/2017 7:52:14 PM
 *  Author: Ahmed
 */ 
 #include "New_PWM.h"

  uint16_t PWM[6]={18000,3000,15000,10000,5000,1000};
  volatile unsigned char Thruster_Pins[6];
  uint16_t Sorted_PWM[6]= {0};

void init(uint16_t TOP){

//Set timer 1 to  Normal, Non-PWM , CTC mode

TCCR1A &=~ ((1U<<COM1A1)| (1U<<COM1A0)) ;
TCCR1A &=~ ((1U<<WGM10) | (1<<WGM11));
TCCR1B |= (1U<<WGM12) | (1U<<WGM13);


//Set top value

ICR1 = TOP;
// PRE-Scaler = 8
TCCR1B |=  (1U<<CS11) ;
TCCR1B &=~ ((1U<<CS10)| (1U<<CS12)) ;

//Enable Overflow & OCRA interrupts

TIMSK1 |= (1U<<ICIE1) | (1U<<OCIE1A)  ;


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


	  //Start with channels On

	  PORTD |=  (1U<<Thruster_Pins[0]) | (1U<<Thruster_Pins[1]) | (1U<<Thruster_Pins[2]) | (1U<<Thruster_Pins[3]) | (1U<<Thruster_Pins[4]) | (1U<<Thruster_Pins[5]) ;
	  


  }


   void Send_PWM(){

	   
	   if(OCR1A == PWM[0] ){		//Thruster 1
		   PORTD &=~ (1U<<Thruster_Pins[0]);
	   }

	   if(OCR1A == PWM[1]){			//Thruster 2
		   PORTD &=~ (1U<<Thruster_Pins[1]);
	   }

	   if(OCR1A == PWM[2]){			//Thruster 3
		   PORTD &=~ (1U<<Thruster_Pins[2]);
	   }

	   if(OCR1A == PWM[3]){			//Thruster 4
		   PORTD &=~ (1U<<Thruster_Pins[3]);
	   }

	   if(OCR1A == PWM[4]){			//Thruster 5
		   PORTD &=~ (1U<<Thruster_Pins[4]);
	   }

	    if(OCR1A == PWM[5]){			//Thruster 6
		    PORTD &=~ (1U<<Thruster_Pins[5]);
	    } 

   }



   // A utility function to swap two elements
  
   void swap(uint16_t* a, uint16_t* b)
   {
	   uint16_t t = *a;
	   *a = *b;
	   *b = t;
   }

   
   // An optimized version of Bubble Sort
   void Bubble_Sort(uint16_t arr[], unsigned char n)
   {
	   
	   uint8_t swapped;
	   for (int i = 0; i < n-1; i++)
	   {
		   swapped = 0;
		   for (int j = 0; j < n-i-1; j++)
		   {
			   if (arr[j] > arr[j+1])
			   {
				   swap(&arr[j], &arr[j+1]);
				   swapped = 1;
			   }
		   }

		   // IF no two elements were swapped by inner loop, then break
		   if (swapped == 0)
		   break;
	   }
   }