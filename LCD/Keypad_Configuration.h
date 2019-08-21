/*
 * Keypad_Configuration.h
 *
 * Created: 4/18/2017 9:16:48 PM
 *  Author: Ahmed Said
 */ 


#ifndef KEYPAD_CONFIGURATION_H_
#define KEYPAD_CONFIGURATION_H_

#include "avr/io.h"
//Columns configuration

#define ColumnOne_DDR (DDRD)
#define ColumnOne_PORT (PORTD)
#define ColumnOne_PIN_No (0U)

#define ColumnTwo_DDR (DDRD)
#define ColumnTwo_PORT (PORTD)
#define ColumnTwo_PIN_No (1U)

#define ColumnThree_DDR (DDRD)
#define ColumnThree_PORT (PORTD)
#define ColumnThree_PIN_No (2U)

#define ColumnFour_DDR (DDRD)
#define ColumnFour_PORT (PORTD)
#define ColumnFour_PIN_No (3U)


//Rows Configuration

#define RowOne_DDR (DDRD)
#define RowOne_PORT (PORTD)
#define RowOne_PIN_No (4U)

#define RowTwo_DDR (DDRD)
#define RowTwo_PORT (PORTD)
#define RowTwo_PIN_No (5U)

#define RowThree_DDR (DDRD)
#define RowThree_PORT (PORTD)
#define RowThree_PIN_No (6U)

#define RowFour_DDR (DDRD)
#define RowFour_PORT (PORTD)
#define RowFour_PIN_No (7U)

#endif /* KEYPAD_CONFIGURATION_H_ */