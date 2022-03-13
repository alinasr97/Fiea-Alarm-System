/*
 * GccApplication6.c
 *
 * Created: 12-Mar-22 12:26:09 PM
 * Author : lenovo
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "UTILS.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "ADC_Interface.h"
#include "Sensors.h"

int main(void)
{
	//LCD
   DIO_SetPortDirection(PORT_C,OUTPUT);
   DIO_SetPinDirection(PORT_B,PIN0,OUTPUT);
   DIO_SetPinDirection(PORT_B,PIN1,OUTPUT);
   DIO_SetPinDirection(PORT_B,PIN2,OUTPUT);
   LCD_Init();
   //LED
   DIO_SetPinDirection(PORT_D,PIN0,OUTPUT);
   DIO_SetPinDirection(PORT_D,PIN1,OUTPUT);
   //MOTOR
   DIO_SetPinDirection(PORT_B,PIN7,OUTPUT);
   
   
   ADC_Init(REF_VCC,ADC_SCALER_64);
 
   u16 x,y;
   
    while (1) 
    {
		y=TEMP_Read();
		x=POT_VoltRead();
		if(y>=50)
		{
			DIO_SetPinValue(PORT_D,PIN1,HIGH);
			DIO_SetPinValue(PORT_D,PIN0,LOW);
			DIO_SetPinValue(PORT_B,PIN7,LOW);
			LCD_GoTo(1,1);
			LCD_WriteString("HEAT         ");
			LCD_GoTo(2,1);
			LCD_WriteString("T= ");
			LCD_WriteNumber(y);
			LCD_WriteChar('    ');
			LCD_WriteString("S= ");
			LCD_WriteNumber(x);
			while(x>=40)
			{
				DIO_SetPinValue(PORT_D,PIN0,HIGH);
				DIO_SetPinValue(PORT_D,PIN1,LOW);
				DIO_SetPinValue(PORT_B,PIN7,HIGH);
				
				LCD_GoTo(1,1);
				LCD_WriteString("FIRE!!       ");
				y=TEMP_Read();
				x=POT_VoltRead();
				LCD_GoTo(2,1);
				LCD_WriteString("T= ");
				LCD_WriteNumber(y);
				LCD_WriteChar('    ');
				LCD_WriteString("S= ");
				LCD_WriteNumber(x);
			}
		}
		else if(y<50)
		{
			DIO_SetPinValue(PORT_D,PIN1,LOW);
			DIO_SetPinValue(PORT_D,PIN0,LOW);
			DIO_SetPinValue(PORT_B,PIN7,LOW);
			LCD_GoTo(1,1);
			LCD_WriteString("Fire Fighting");
			LCD_GoTo(2,1);
			LCD_WriteString("T= ");
			LCD_WriteNumber(y);
			LCD_WriteString("        ");
		}
    }
}

