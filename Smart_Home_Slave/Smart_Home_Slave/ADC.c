/*
 * ADC.c
 *
 * Created: 12-Feb-21 2:41:55 PM
 *  Author: pc
 */ 
#include "ADC.h"


void ADC_Init()
{
	ADMUX |= (1<<REFS0)|(1<<REFS1);
	ADCSRA |=(1<<ADEN)|(1<<ADATE)|(1<<ADPS0)|(ADPS1)|(ADPS2)|(1<<ADIE);
	
}

unsigned int ADC_Read(unsigned char channel)
{
	unsigned int result=0;
	ADMUX |=((1<<REFS0) |(1<<REFS1)) | (channel & 0x07);
	//start conversion
	ADCSRA |= (1<<ADSC);
	//check on ADIF flag
	while (!(ADCSRA & (1<<ADIF)));
	ADCSRA |= (1<<ADIF);
	//get results
	result = ADCL;
	result |= (ADCH<<8); //ADCH (2bits) | ADCL (8bits)
	return result;
}
