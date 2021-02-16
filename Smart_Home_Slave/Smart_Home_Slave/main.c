/*
 * Smart_Home_Slave.c
 *
 * Created: 12-Feb-21 2:34:46 PM
 * Author : AbdElrahman Ehab
 */ 


#include  "ADC.h"
#include  "LCD.h"
#include  "DC_MOTOR.h"
#include  "SPI.h"
#include <avr/io.h>
#include <stdio.h>


int main(void)
{
LCD_Init();
ADC_Init();
DC_Motor_Init();

DDRC |= (1<<6);

SPI_InitType InitData = {Slave, MSB};
SPI_Init(InitData);

char buffer[2];
unsigned char cmd;
unsigned short adc_value =0;



    while (1) 
    {
	
		cmd = SPI_ReceiveChar(); //est2bal data mn master
		_delay_ms(100);
		
		switch(cmd)
		{
			case '1':
			PORTC |=(1<<6);
			LCD_clear();
			LCD_String("Light ON");
			break;
			
			case '2':
			PORTC &=~(1<<6);
			LCD_clear();
			LCD_String("Light OFF");
			break;
			
			case '3':
			DC_Motor_Direction('W');
			LCD_clear();
			LCD_String_xy(0,1,"DC Motor ON");
			LCD_String_xy(0,2,"Forward Dir");;
			break;
			
			case '4':
			DC_Motor_Direction('S');
			LCD_clear();
			LCD_String_xy(0,1,"DC Motor ON");
			LCD_String_xy(0,2,"Backward Dir");
			break;
			
			case 0x44:
				adc_value = ADC_Read(0);
				adc_value /= 4;			
			    itoa(adc_value,buffer,10);
				
			if (SPI_receive_Transmit(buffer[0]) == 0x21)
			{
				LCD_clear();
				LCD_String_xy(0,0,"Reading");
				LCD_String_xy(1,0,"Temperature");
				
			}
			if (SPI_receive_Transmit(buffer[1]) == 0x22)
			 LCD_clear();
			break;
		}
	
    }
}

