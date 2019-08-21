/*
 * I2C_Library.h
 *
 * Created: 11/11/2017 9:34:51 PM
 *  Author: Ahmed
 */ 


#ifndef I2C_LIBRARY_H_
#define I2C_LIBRARY_H_
#define F_CPU (16000000UL)
#define SCL_CLK (100000UL)
#define TWSR_Mask (0xF8)
#include <avr/io.h>



void I2C_init(void);
void I2C_start(unsigned char address);
void I2C_stop(void);
void I2C_write(uint16_t data);
unsigned char I2C_readack(void);
unsigned char I2C_readNack(void);





#endif /* I2C_LIBRARY_H_ */