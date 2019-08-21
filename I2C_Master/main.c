/*
 * I2C_Master.c
 *
 * Created: 11/12/2017 5:14:07 PM
 * Author : Ahmed
 */ 

 #include "I2C_Library.h"
 #include <avr/interrupt.h>


int main(void)
{
    /* Replace with your application code */
	I2C_init();
	sei();
	

while (1)
    {
	I2C_start(0X04);
	I2C_write(20000);
	I2C_stop();

    }

}

