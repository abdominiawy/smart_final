/*
 * smart_home.c
 *
 * Created: 08-Feb-21 8:12:06 PM
 * Author : AbdElrahman Ehab
 */ 

#include "SPI.h"
#include "Lcd_l.h"
#include "UART.h"
#include <avr/interrupt.h>

volatile unsigned char x = 0, y = 0;
volatile unsigned int cnt = 0;


int main(void)
{
	
LCD_Init();
UART_INit();
SPI_InitType InitData = {Master,MSB};
SPI_Init(InitData);
SPIPort &=~(1<<SS);

LCD_String("hello-Abdo");
LCD_String_xy(1,0,"temperature: ");


	TCCR1B = (1<<CS12)|(1<<CS10)|(1<<WGM12); 
	TIMSK = (1<<OCIE1A);
	TCCR1A = (1<<COM1A0);
	OCR1A = 15625;
	
	sei();
	SPI_TransmitChar(0x44);
	_delay_ms(200);
	x = SPI_Receive_Transmit(0x21);
	_delay_ms(200);
	y = SPI_Receive_Transmit(0x22);
	LCD_CharPos(x,1,12);
	LCD_CharPos(y,1,13);

    while (1) 
    {	
		SPI_TransmitChar(UART_ReceiveChar()); //hb3at eldata mn elmaster
		_delay_ms(300);
    }
}


ISR(TIMER1_COMPA_vect)
{
	cnt++;
	if (cnt > 9)
	{
		SPI_TransmitChar(0x44);
		_delay_ms(200);
		x = SPI_Receive_Transmit(0x21);
		_delay_ms(200);
		y = SPI_Receive_Transmit(0x22);
		cnt = 0;
		LCD_CharPos(x,1,12);
		LCD_CharPos(y,1,13);
	}
}
