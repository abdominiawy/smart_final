/*
 * UART.h
 *
 * Created: 10-Feb-21 10:16:47 PM
 *  Author: pc
 */ 


#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#define F_CPU 16000000UL
#define BaudRate 9600 

#ifndef DoubleSpeed
#define MyUBRR ((F_CPU / (16UL * BaudRate)) - 1)
#else
#define MyUBRR ((F_CPU / (8UL * BaudRate)) - 1)
#endif

void UART_INit();
void UART_SendChar(char);
unsigned char UART_ReceiveChar();
void UART_SendString(char*);




#endif /* UART_H_ */