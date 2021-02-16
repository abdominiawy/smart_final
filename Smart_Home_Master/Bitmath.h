/*
 * Bitmath.h
 *
 * Created: 08-Feb-21 9:02:12 PM
 *  Author: pc
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_

#define SetBit(var,bit)		var|=(1<<bit)
#define ClearBit(var,bit)	var&=~(1<<bit)
#define	ToggleBit(var,bit)	var^=(1<<bit)
#define	GetBit(var,bit)		(var>>bit)&1


#endif /* BITMATH_H_ */