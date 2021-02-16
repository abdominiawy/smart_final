/*
 * DC_MOTOR.c
 *
 * Created: 12-Feb-21 2:43:20 PM
 *  Author: pc
 */ 

#include "DC_MOTOR.h"

void DC_Motor_Init()
{
	DDRC |= (1<<4) | (1<<5) ;
	DDRD |= (1<<5);
	OCR1A = 200;
	TCCR1A = (1<<WGM10) | (1<<COM1A1);
	TCCR1B = (1<<WGM12) | (1<<CS11) | (1<<CS10);	
}

void DC_Motor_Direction(unsigned char Direction)
{
	switch (Direction)
	{
		case'W':
		PORTC |= (1<<4);
		PORTC &=~(1<<5);
		break;
		
		case'S':
		PORTC |= (1<<5);
		PORTC &=~(1<<4);		
		break;
	}
}