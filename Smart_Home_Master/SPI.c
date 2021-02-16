/*
 * SPI.c
 *
 * Created: 10-Feb-21 12:07:50 AM
 *  Author: pc
 */ 

#include "SPI.h"

void SPI_Init(SPI_InitType status)
{
	switch (status.state)
	{
		case Master:
		SPIDir |= (1<<SS)|(1<<MOSI)|(1<<SCK);
		SPIDir &=~(1<<MISO);
		SPIPort|=(1<<SS);
		SPCR |= (1<<MSTR)|(1<<SPE)|(1<<SPR1);
		break;
		
		case Slave:
		SPIDir &=~ (1<<SS)|(1<<MOSI)|(1<<SCK);
		SPIDir |=(1<<MISO);
		SPCR |=(1<<SPE);
		break;
		
	}
}

unsigned char SPI_Receive_Transmit(unsigned char data)
{
	SPDR = data;
	while (!(SPSR &(1<<SPIF)));
	return SPDR;
	
}

void SPI_TransmitChar(unsigned char data)
{
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
	
}

unsigned char SPI_ReceiveChar(void)
{
	while(!(SPSR &(1<<SPIF)));
	return SPDR;
}