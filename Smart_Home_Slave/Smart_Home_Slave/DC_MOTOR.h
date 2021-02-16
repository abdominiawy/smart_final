/*
 * DC_MOTOR.h
 *
 * Created: 12-Feb-21 2:44:24 PM
 *  Author: pc
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include <avr/io.h>
#define F_CPU 16000000UL 
#include <util/delay.h> 



void DC_Motor_Init();
void DC_Motor_Direction(unsigned char);



#endif /* DC_MOTOR_H_ */