/*
 * LCD.h
 *
 * Created: 12-Feb-21 2:44:44 PM
 *  Author: pc
 */ 


#ifndef LCD_H_
#define LCD_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define RS	1
#define RW	2
#define EN	3

#define LCD_Dir						DDRA
#define LCD_Port					PORTA
#define LCD_Port_Control			PORTB
#define LCD_Dir_Control				DDRB

void LCD_Init();
void LCD_cmnd(unsigned char cmnd);
void LCD_Char(unsigned char data);
void LCD_String(char* str);
void LCD_String_xy(char row,char pos,char* str);
void LCD_clear();

#endif /* LCD_H_ */