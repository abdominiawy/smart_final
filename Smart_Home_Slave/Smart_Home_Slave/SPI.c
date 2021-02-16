/*
 * SPI.c
 *
 * Created: 12-Feb-21 2:41:17 PM
 *  Author: pc
 */ 

#include "SPI.h"

void SPI_Init(SPI_InitType status)
{
	switch (status.state)
	{
		case Master:
		SPIDir |=(1<<SS)|(1<<MOSI)|(1<<SCK);
		SPIDir&=~(1<<MISO);
		SlaveDis();
		SPCR   |= (1<<MSTR)|(1<<SPE);
		break;
		
		case Slave:
		SPIDir &=~(1<<SS)|(1<<MOSI)|(1<<SCK);
		SPIDir |=(1<<MISO);
		SPCR   |= (1<<SPE)|(1<<SPR1);
		break;
		
	}
}

unsigned char SPI_receive_Transmit(unsigned char data)
{
	SPDR = data;
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}

void SPI_TransmitChar(unsigned char Data)
{
	SPDR = Data;
	while(!(SPSR & (1<<SPIF)));
}

unsigned char SPI_ReceiveChar(void)
{
	while (!(SPSR & (1<<SPIF)));
	return SPDR;
	
}