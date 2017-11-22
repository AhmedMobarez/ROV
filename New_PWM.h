/*
 * New_PWM.h
 *
 * Created: 11/20/2017 7:49:58 PM
 *  Author: Ahmed
 */ 


#ifndef NEW_PWM_H_
#define NEW_PWM_H_
#include <avr/io.h>
#include <avr/interrupt.h>



void init(uint16_t icr);
void Setup_nPWM_Channels();
void Setup_nPWM_PORT();
void Send_PWM();
void Bubble_Sort(uint16_t arr[], unsigned char n);



#endif /* NEW_PWM_H_ */