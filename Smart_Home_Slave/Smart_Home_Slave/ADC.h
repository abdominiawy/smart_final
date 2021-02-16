/*
 * ADC.h
 *
 * Created: 12-Feb-21 2:44:08 PM
 *  Author: pc
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>


void ADC_Init();
unsigned int ADC_Read(unsigned char channel);


#endif /* ADC_H_ */