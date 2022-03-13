/*
 * Sensors.h
 *
 * Created: 12-Mar-22 1:01:53 PM
 *  Author: lenovo
 */ 


#ifndef SENSORS_H_
#define SENSORS_H_


#include "STD_TYPES.h"
#include "UTILS.h"
#include "DIO_Interface.h"
#include "ADC_Interface.h"

#define POT_CH  CH_0 //potentiometer
#define LM35_CH CH_1 //Temperature sensor

u16 POT_VoltRead(void);

u16 TEMP_Read(void);

#endif /* SENSORS_H_ */