/*
 * LCD_Interface.h
 *
 * Created: 12-Mar-22 12:47:34 PM
 *  Author: lenovo
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


#define F_CPU 8000000UL
#include <util/delay.h>
#include "UTILS.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"




void LCD_Init(void);
void LCD_SendCommand(u8 cmd);
void LCD_WriteChar(u8 ch);
void LCD_WriteString(u8 *ptr);
void LCD_GoTo(u8 Y, u8 X);
void LCD_WriteNumber(u64 num);
void LCD_WriteNumberInBinary(u8 num);
void LCD_CreateCharacter(u8 *pattern, u8 location);
void LCD_WriteNumberInHex(u8 num);
void LCD_WriteNumber_4D(u16 num);
void LCD_Clear(void);

void LCD_WriteData(u8 data);


#endif /* LCD_INTERFACE_H_ */