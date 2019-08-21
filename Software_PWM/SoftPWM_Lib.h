/*
 * SoftPWM_Lib.h
 *
 * Created: 10/8/2017 3:16:40 PM
 *  Author: Ahmed
 */ 


#ifndef SOFTPWM_LIB_H_
#define SOFTPWM_LIB_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#define PWM_Channels 5
#define PWM_PORTC PORTC
#define PWM_PORTB PORTB
#define PWM_DDRC DDRC
#define PWM_DDRB DDRB

//uint16_t Soft_PWM_TOP[PWM_Channels];
//uint16_t Soft_PWM_COMPARE[PWM_Channels];
//uint16_t Soft_PWM_CURRENT[PWM_Channels];
uint16_t Thruster_Pins[PWM_Channels];


//void Setup_Hardware_PWM_Timer();
void Setup_Soft_PWM_Timer();
void Setup_PWM_Channels();
void Setup_PWM_PORT();
void Send_PWM();



#endif /* SOFTPWM_LIB_H_ */