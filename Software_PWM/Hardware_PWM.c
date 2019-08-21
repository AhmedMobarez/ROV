/*
 * Hardware_PWM.c
 *
 * Created: 10/14/2017 12:34:16 AM
 *  Author: Ahmed
 */ 
 #include "motormovement.h"

   //TIMER 0 SET UP FOR SERVO AND DC MOTOR
   // NON INVERTING - FAST PWM- MODE 3 - FREQUENCY 50HZ -PRESCALER 1024 - Freq= 16*10^6 / (1024 *256)=61 Hz
   
void timer0_init(){
   
   
  // DDRD |= (1<<OCR0A| 1<<OCR0B);
  // TCCR0A =0;
  // TCCR0B =0;
   
   TCCR0A |=( 1<<COM0A1 | 1<<COM0B1 | 1<<WGM00 | 1<<WGM01  );

   //Pre-Scaler clk/1024
   TCCR0B |=( 1<<CS02 | 1<<CS00 );
   
   //for the DC motors 5 pins config
   DDRD|=(1<<PORTD0 | 1<<PORTD1 | 1<<PORTD2); //check the 4 direction control pins and the which motor control pin
   
   }
   
   //TIMER 1 SET UP FOR TWO THRUSTERS
   //NON INVERTING - FAST PWM- MODE 14- FREQUENCY 50HZ- PRESCALER 8 - ICR=40,000 - Freq = 16*10^6/(8*40000)=50 Hz
 
void timer1_init(){
   
 //  DDRB |=( 1<<1 | 1<<2 ) ; 
   
   
   //TCCR1A=0;
   //TCCR1B=0;
   
   TCCR1A|=( 1<<COM1A1 | 1<<COM1B1 | 1<<WGM11 );
   TCCR1B|=( 1<<WGM13 | 1<<WGM12 | 1<<CS11);
   
   ICR1=40000;
   
   }
 
void DCMotor_move(unsigned char motorNumber, unsigned short pwm, unsigned char dir){
   
   PORTD |= motorNumber<<0;
   if(motorNumber==0){
      OCR0A=pwm;
      OCR0B=0;
      }
   else if(motorNumber==1){
      OCR0B=pwm;
      OCR0A=0;
      }
   PORTD |= dir<<1;
   PORTD |= (~dir)<<2;   
      
   
   }
/*void DCMotor_move(unsigned short pwm, bool in1, bool in2 ){
   
   //duty cycle = pwm/40,000=
   // int1 and in2 for this specific DC motor is for direction control
   //i should make another function for the other DC motor's direction control and output pwm
   OCR0A=pwm;
   
   }*/
/*   
void servoMotor_move(unsigned short pwm){
   
   OCR0B=pwm;
   
   }
*/   
void centerRightMotor_move(unsigned short pwm){
   OCR1A=pwm*256;
   
   
   }
   
void centerLeftMotor_move(unsigned short pwm){
   OCR1B=pwm*256;
   
   }