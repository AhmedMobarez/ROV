/*
 * Hardware_PWM_Lib.h
 *
 * Created: 10/14/2017 12:33:48 AM
 *  Author: Ahmed
 */ 


#ifndef HARDWARE_PWM_LIB_H_
#define HARDWARE_PWM_LIB_H_

#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>


void timer0_init();
void timer1_init();
void DCMotor_move(unsigned char motorNumber, unsigned short pwm, unsigned char dir);
void centerRightMotor_move(unsigned short pwm);
void centerLeftMotor_move(unsigned short pwm);


#endif /* HARDWARE_PWM_LIB_H_ */