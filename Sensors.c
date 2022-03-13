/*
 * CFile1.c
 *
 * Created: 12-Mar-22 1:02:16 PM
 *  Author: lenovo
 */ 
#include "Sensors.h"

u16 POT_VoltRead(void)
{
	u16 adc=ADC_Read(POT_CH);
	u16 volt=((u32)5000*adc)/1024;
	return volt;
}

u16 TEMP_Read(void)
{
	u16 adc=ADC_Read(LM35_CH);
	u16 volt=((u32)5000*adc)/1024;
	u16 temp=volt/10;
	return temp;
}