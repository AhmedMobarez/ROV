/*
 * Keypad_Library.c
 *
 * Created: 4/18/2017 8:43:54 PM
 *  Author: Ahmed Said
 */ 
 #include "Keypad_Library.h"

 


 char keypad_char [4][4] =
 {

	 {'1','2','3','+'},
	 {'4','5','6','-'},
	 {'7','8','9','*'},
	 {'#','0','C','/'}

 };



 void Keypad_Initialize(void){

 //Set columns as output

 ColumnOne_DDR |= (1U<<ColumnOne_PIN_No);
 ColumnTwo_DDR |= (1U<<ColumnTwo_PIN_No);
 ColumnThree_DDR |= (1U<<ColumnThree_PIN_No);
 ColumnFour_DDR |= (1U<<ColumnFour_PIN_No);


 //Set columns to High

  ColumnOne_PORT |= (1U<<ColumnOne_PIN_No);
  ColumnTwo_PORT |= (1U<<ColumnTwo_PIN_No);
  ColumnThree_PORT |= (1U<<ColumnThree_PIN_No);
  ColumnFour_PORT |= (1U<<ColumnFour_PIN_No);

  //Set Rows to input

  RowOne_DDR   &=~ (1U<<RowOne_PIN_No);
  RowTwo_DDR   &=~ (1U<<RowTwo_PIN_No);
  RowThree_DDR &=~ (1U<<RowThree_PIN_No);
  RowFour_DDR  &=~ (1U<<RowFour_PIN_No);


  //Set Rows to High

  RowOne_PORT   |= (1U<<RowOne_PIN_No);
  RowTwo_PORT   |= (1U<<RowTwo_PIN_No);
  RowThree_PORT |= (1U<<RowThree_PIN_No);
  RowFour_PORT  |= (1U<<RowFour_PIN_No);
 }







 char Row_One(uint8_t index){

	 char digit ;

	 digit =keypad_char [0][index];

	 return digit;
 }

 char Row_Two(uint8_t index){

	 char digit ;

	 digit =keypad_char [1][index];

	 return digit;
 }

 char Row_Three(uint8_t index){

	 char digit;

	 digit =keypad_char [2][index];

	 return digit;
 }

 char Row_Four(uint8_t index){

	 char digit ;

	 digit =keypad_char [4][index];

	 return digit;
 }





char Keypad_Read(void)
{
// For loop to change columns value to zero and check the rows

uint8_t index = 0, value = 0;
char digit=0;
for(index =0; index<4 ; index++)
{
	
	 // Set columns to High
	   ColumnOne_PORT |= (1U<<ColumnOne_PIN_No);
	   ColumnTwo_PORT |= (1U<<ColumnTwo_PIN_No);
	   ColumnThree_PORT |= (1U<<ColumnThree_PIN_No);
	   ColumnFour_PORT |= (1U<<ColumnFour_PIN_No);


	//Alternate columns to low
	PORTD &=~ (1U<<index);
	
	//Record Port state
	value = PIND & 0XF0 ;
	

	//Check Row
	if (value != 0xF0){

	switch(value){

	case 0xE0 :
	digit = Row_One(index);
	break;

	case 0xD0:
	digit = Row_Two(index);
	break;

	case 0xB0:
	digit = Row_Three(index);
	break;

	case 0x70:
	digit = Row_Four(index);
	break;

	default:
	break;

	}



	}
	
}
return digit;

}




