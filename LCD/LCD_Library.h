/*
 * LCD_Library.h
 *
 * Created: 4/16/2017 8:52:59 PM
 *  Author: Ahmed Said
 */ 


#ifndef LCD_LIBRARY_H_
#define LCD_LIBRARY_H_
#include "LCD_Configuration.h"

void LCD_Initialize(void);
void LCD_Write_Character(char digit);
void LCD_Write_CMD(char cmd);
void LCD_Enable(void);
void LCD_Write_4bits_Mode(char data);
void LCD_Write_String(char *str);
void LCD_Go_To_X_Y(int row,int col);


#endif /* LCD_LIBRARY_H_ */