/*
 * lcd.h
 *
 * Created: 08-Feb-21 8:12:52 PM
 *  Author: pc
 */ 


#ifndef LCD_H_
#define LCD_H_
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

#define LCD_Dir				DDRA
#define LCD_Port			PORTA
#define	LCD_Dir_Control		DDRB
#define LCD_Port_Control	PORTB

#define RS	1
#define RW	2
#define EN	3


void LCD_Init();
void LCD_Cmnd(unsigned char cmnd);
void LCD_Char(unsigned char data);
void LCD_String(char* str);
void LCD_String_xy(char row, char pos, char *str);
void LCD_CharPos(int data, unsigned int row, unsigned int pos);
void LCD_Clear();





#endif /* LCD_H_ */