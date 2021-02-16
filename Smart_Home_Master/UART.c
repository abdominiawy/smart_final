/*
 * UART.c
 *
 * Created: 10-Feb-21 10:17:12 PM
 *  Author: pc
 */ 

#include "UART.h"

void UART_INit()
{
	UCSRB = (1<<TXEN)|(1<<RXEN);
	UCSRC = (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
	UBRRL = MyUBRR;
	UBRRH = (MyUBRR>>8);
}
void UART_SendChar(char data)
{
	while(!(UCSRA & (1<<UDRE)));
	data = UDR ;
}

unsigned char UART_ReceiveChar(void)
{
	while((UCSRA & (1<<RXC))==0);
	return UDR;
}

void UART_SendString(char*str)
{
	unsigned char i=0;
	while(str[i]!='\0')
	{
		UART_SendChar(str[i]);
	}
	
}