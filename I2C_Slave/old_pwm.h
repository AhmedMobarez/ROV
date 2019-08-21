/*
 * old_pwm.h
 *
 * Created: 12/10/2017 2:27:59 PM
 *  Author: Ahmed
 */ 


#ifndef OLD_PWM_H_
#define OLD_PWM_H_

#include <avr/io.h>
#include <avr/interrupt.h>


void timer_init(uint16_t TOP);
void Setup_nPWM_Channels();
void Setup_nPWM_PORT();






#endif /* OLD_PWM_H_ */