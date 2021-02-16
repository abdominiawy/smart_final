/*
 * LCD.c
 *
 * Created: 08-Feb-21 10:41:31 PM
 *  Author: pc
 */ 
#include "Lcd_l.h" 

void LCD_Init()
{
	LCD_Dir |= 0xF0;
	LCD_Dir_Control |=(1<<RS)|(1<<RW)|(1<<EN);

	LCD_Port_Control &=~(1<<RW);
	_delay_ms(20);
	
	LCD_Cmnd(0x33);
	LCD_Cmnd(0x32);
	LCD_Cmnd(0x28);
	LCD_Cmnd(0x0C);
	LCD_Cmnd(0x06);
	LCD_Cmnd(0x01);

}

void LCD_Cmnd(unsigned char cmnd)
{
	LCD_Port = (LCD_Port & 0x0F) | (cmnd & 0xF0);//send MSB
	
	LCD_Port_Control &=~(1<<RS);
	LCD_Port_Control |=(1<<EN);
	_delay_us(10);
	LCD_Port_Control &=~(1<<EN);
	
	_delay_us(2000);
	LCD_Port = (LCD_Port & 0x0F) | (cmnd <<4);
	LCD_Port_Control |=(1<<EN);
	_delay_us(10);
	LCD_Port_Control &=~(1<<EN);
	_delay_ms(10);
}

void LCD_Char(unsigned char data)
{
	LCD_Port = (LCD_Port & 0x0F) | (data & 0xF0);//send MSB
	LCD_Port_Control |=(1<<RS);
	LCD_Port_Control |=(1<<EN);
	_delay_us(10);
	LCD_Port_Control &=~(1<<EN);
	_delay_us(2000);
	LCD_Port = (LCD_Port & 0x0F) | (data<<4);
	LCD_Port_Control |=(1<<EN);
	_delay_us(10);
	LCD_Port_Control &=~(1<<EN);
	_delay_ms(2);
}

void LCD_String(char* str)
{
	char i=0;
	while (str[i]!='\0')
	{
		LCD_Char(str[i]);
		i++;

	}
} 

void LCD_String_xy(char row, char pos, char *str)
{
	if (row ==0 && pos<16)
	LCD_Cmnd((pos&0x0F)|0x80);
	else if (row==1 && pos<16)
	LCD_Cmnd((pos & 0x0F)|0xc0);
	LCD_String(str);
}

void LCD_Clear()
{
	LCD_Cmnd(0x01);
	_delay_ms(2);
	LCD_Cmnd(0x80);
}

void LCD_CharPos(int data, unsigned row, unsigned pos)
{
	switch (row)
	{
		case 0:
		LCD_Cmnd((0x80) | (pos & 0x0F));
		LCD_Char(data);
		break;
		
		case 1:
		LCD_Cmnd((0xC0) | (pos & 0x0F));
		LCD_Char(data);
		break;
	}
}