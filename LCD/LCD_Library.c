/*
 * LCD_Library.c
 *
 * Created: 4/16/2017 8:52:40 PM
 *  Author: Ahmed Said
 */ 
 #define F_CPU (8000000UL)
 #include <avr/io.h>
 #include <util/delay.h>
 #include "LCD_Library.h"


 void LCD_Initialize(void){
 //Delay 15ms
 _delay_ms(15);
 //Configure pins as output
 LCD_EN_DDR |= (1U<<LCD_EN_PIN_No);
 LCD_RW_DDR |= (1U<<LCD_RW_PIN_No);
 LCD_RS_DDR |= (1U<<LCD_RS_PIN_No);

 LCD_D4_DDR |= (1U<<LCD_D4_PIN_No);
 LCD_D5_DDR |= (1U<<LCD_D5_PIN_No);
 LCD_D6_DDR |= (1U<<LCD_D6_PIN_No);
 LCD_D7_DDR |= (1U<<LCD_D7_PIN_No);

 //Send wakeup data
 LCD_Write_CMD(0x33);
 LCD_Write_CMD(0x32);

 //Function Set
 LCD_Write_CMD(0x28); //4 bit mode , 2 lines , 5*7 dots


 //LCD off
 LCD_Write_CMD(0x08);


 

 //LCD On
 LCD_Write_CMD(0x0C);

 //Entry mode
 LCD_Write_CMD(0x06);

 //LCD clear
 LCD_Write_CMD(0x01);
 }
  void LCD_Write_Character(char digit){
  //Set RW to write 
  LCD_RW_PORT &=~(1U<<LCD_RW_PIN_No);

  //Set RS to data
  LCD_RS_PORT |= (1U<<LCD_RS_PIN_No);

  //Call 4 bit mode write function
  LCD_Write_4bits_Mode(digit);
  //_delay_us(50);
  }

 void LCD_Write_CMD(char cmd){

//Set RW to write
LCD_RW_PORT &= ~(1U<<LCD_RW_PIN_No);

//Set RS to command
LCD_RS_PORT &= ~(1U<<LCD_RS_PIN_No);

//Call 4 bit mode write function
LCD_Write_4bits_Mode(cmd);

/*if(cmd==0x01 || cmd==0x01)
_delay_ms(2);

else
_delay_us(50);*/
 }


void LCD_Write_4bits_Mode(char data){

//LCD Enable
//LCD_Enable();
//Send high nibble
if(data & (1U<<4)){LCD_D4_PORT |= (1U<<LCD_D4_PIN_No);}
else {LCD_D4_PORT &=~(1U<<LCD_D4_PIN_No);}

if(data & (1U<<5)){LCD_D5_PORT |= (1U<<LCD_D5_PIN_No);}
else {LCD_D5_PORT &=~(1U<<LCD_D5_PIN_No);}

if(data & (1U<<6)){LCD_D6_PORT |= (1U<<LCD_D6_PIN_No);}
else {LCD_D6_PORT &=~(1U<<LCD_D6_PIN_No);}

if(data & (1U<<7)){LCD_D7_PORT |= (1U<<LCD_D7_PIN_No);}
else {LCD_D7_PORT &=~(1U<<LCD_D7_PIN_No);}

//LCD Enable
LCD_Enable();

//Send low nibble

if(data & (1U<<0)){LCD_D4_PORT |= (1U<<LCD_D4_PIN_No);}
else {LCD_D4_PORT &=~(1U<<LCD_D4_PIN_No);}

if(data & (1U<<1)){LCD_D5_PORT |= (1U<<LCD_D5_PIN_No);}
else {LCD_D5_PORT &=~(1U<<LCD_D5_PIN_No);}

if(data & (1U<<2)){LCD_D6_PORT |= (1U<<LCD_D6_PIN_No);}
else {LCD_D6_PORT &=~(1U<<LCD_D6_PIN_No);}

if(data & (1U<<3)){LCD_D7_PORT |= (1U<<LCD_D7_PIN_No);}
else {LCD_D7_PORT &=~(1U<<LCD_D7_PIN_No);}


LCD_Enable();
_delay_ms(2);

}



void LCD_Enable(){
//Set Enable pin to high

LCD_EN_PORT |= (1U<<LCD_EN_PIN_No);

_delay_us(1);
//Set Enable pin to low
LCD_EN_PORT &=~(1U<<LCD_EN_PIN_No);

//_delay_ms(2);

}



void LCD_Write_String(char *str){

while (*str){

LCD_Write_Character(*str);
str++;
}
_delay_us(50);

}