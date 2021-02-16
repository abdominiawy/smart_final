/*
 * SPI.h
 *
 * Created: 10-Feb-21 12:08:07 AM
 *  Author: pc
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

#define SS		4
#define MOSI	5
#define MISO	6
#define SCK		7

#define SPIDir		DDRB
#define SPIPort		PORTB



typedef enum
{
	Master=0,
	Slave
	}SPIState;
	
	
typedef enum 
{
	MSB=0,
	LSB
	}SPIDataOrder;
	
typedef struct  
{
	SPIState state;
	SPIDataOrder DataOrder;
}SPI_InitType;

void SPI_Init(SPI_InitType status);
unsigned char SPI_Receive_Transmit(unsigned char data);
void SPI_TransmitChar(unsigned char data);
unsigned char SPI_ReceiveChar(void);
 

#endif /* SPI_H_ */