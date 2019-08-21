/*
 * LCD_Configuration.h
 *
 * Created: 4/16/2017 9:01:18 PM
 *  Author: Ahmed Said
 */ 


#ifndef LCD_CONFIGURATION_H_
#define LCD_CONFIGURATION_H_

/*LCD Control pins configuration */

#define LCD_EN_PIN_No (3U)
#define LCD_EN_DDR (DDRB)
#define LCD_EN_PORT (PORTB)

#define LCD_RW_PIN_No (2U)
#define LCD_RW_DDR (DDRB)
#define LCD_RW_PORT (PORTB)

#define LCD_RS_PIN_No (1U)
#define LCD_RS_DDR (DDRB)
#define LCD_RS_PORT (PORTB)

/*LCD Data pins Configuration */

#define LCD_D4_PIN_No (4U)
#define LCD_D4_DDR (DDRA)
#define LCD_D4_PORT (PORTA)

#define LCD_D5_PIN_No (5U)
#define LCD_D5_DDR (DDRA)
#define LCD_D5_PORT (PORTA)

#define LCD_D6_PIN_No (6U)
#define LCD_D6_DDR (DDRA)
#define LCD_D6_PORT (PORTA)

#define LCD_D7_PIN_No (7U)
#define LCD_D7_DDR (DDRA)
#define LCD_D7_PORT (PORTA)
#endif /* LCD_CONFIGURATION_H_ */