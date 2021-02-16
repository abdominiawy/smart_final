/*
 * SPI.h
 *
 * Created: 12-Feb-21 2:43:53 PM
 *  Author: pc
 */ 


#ifndef SPI_H_
#define SPI_H_
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define SS		4
#define MOSI	5
#define MISO	6
#define SCK		7 

#define SPIDir	DDRB 
#define SPIPort PORTB 

#define SlaveEn()	(SPIPort&=~(1<<SS))
#define SlaveDis()	(SPIPort|=(1<<SS))

typedef enum 
{
	Master = 0,
	Slave 
}SPIstate;
	
typedef enum 
{
MSB=0,
LSB	
}SPIDataOrderType;

typedef struct  
{
	SPIstate state;
	SPIDataOrderType DataOdrer;
}SPI_InitType;

void SPI_Init(SPI_InitType status);
unsigned char SPI_receive_Transmit(unsigned char data);
void SPI_TransmitChar(unsigned char Data);
unsigned char SPI_ReceiveChar(void);



#endif /* SPI_H_ */