/*
 * LCD.c
 *
 * Created: 4/16/2017 8:50:31 PM
 * Author : Ahmed Said
 */ 


 #include "LCD_Library.h"
 #include "Keypad_Library.h"

int main(void)
{
    /* Replace with your application code */
LCD_Initialize();
Keypad_Initialize();


  char digit;

  digit = Keypad_Read();
  LCD_Write_Character(digit);
}

