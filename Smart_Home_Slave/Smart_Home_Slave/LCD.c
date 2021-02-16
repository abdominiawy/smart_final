/*
 * LCD.c
 *
 * Created: 12-Feb-21 2:41:39 PM
 *  Author: pc
 */ 

#include "LCD.h"




void LCD_Init()
{
	//Direction of Data Pins 
	LCD_Dir |= 0xF0 ;//A4 to A7 are output
	LCD_Dir_Control |=(1<<RS)|(1<<RW)|(1<<EN); //Direction of control pins are output
	LCD_Port_Control &=~(1<<RW);
	_delay_ms(20);
	LCD_cmnd(0x33);
	LCD_cmnd(0x32);
	LCD_cmnd(0x28);
	LCD_cmnd(0x0c);
	LCD_cmnd(0x06);
	LCD_cmnd(0x01);	
}

void LCD_cmnd(unsigned char cmnd)
{
	LCD_Port =(LCD_Port&0x0F) | (cmnd&0xF0);
	LCD_Port_Control &=~(1<<RS);
	LCD_Port_Control |=(1<<EN);
	_delay_us(10);
	LCD_Port_Control &=~(1<<EN);
	
	_delay_us(2000);
	LCD_Port = (LCD_Port & 0x0F) | (cmnd << 4);
	LCD_Port_Control |= (1<<EN);
	_delay_us(10);
	LCD_Port_Control &=~(1<<EN);
	_delay_ms(10);
	
}

void LCD_Char(unsigned char data)
{
	LCD_Port = (LCD_Port & 0x0F) | (data & 0xF0);
	LCD_Port_Control |=(1<<RS);
	LCD_Port_Control |=(1<<EN);
	_delay_us(10);
	LCD_Port_Control &=~(1<<EN);
	_delay_us(2000);
	
	LCD_Port = (LCD_Port & 0x0F) | (data << 4 );
	LCD_Port_Control |=(1<<EN);
	_delay_us(10);
	LCD_Port_Control &=~(1<<EN);
	
}

void  LCD_String(char* str)
{
	char i=0;
	while(str[i]!='\0')
	{
			LCD_Char(str[i]);
			i++;
	}
}

void LCD_String_xy(char row,char pos,char* str)
{
	if (row==0 && pos<16)
	LCD_cmnd((pos&0x0F)|0x80);
	else if (row==1 && pos<16)
	LCD_cmnd((pos&0x0F)|0xc0);
	LCD_String(str);
}

void LCD_clear()
{
	LCD_cmnd(0x01);
	_delay_us(2000);
	LCD_cmnd(0x80);
}