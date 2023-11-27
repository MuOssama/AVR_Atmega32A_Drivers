/*
 * DIO.H
 *
 *  Created on: Jun 24, 2022
 *      Author: Mustapha
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_
#include"../../UTILS/STD_TYPES.h"
#include"../../UTILS/BIT_MATH.h"
#include"DIO_REG.h"


void DIO_SetPin_Value(u8 u8_port, u8 u8_pin, u8 value);
void DIO_SetPin_Direction(u8 u8_port, u8 u8_pin, u8 direction);
void DIO_SetPort_Value(u8 u8_port,u8 value);
void DIO_SetPort_Direction(u8 u8_port,u8 value);
u8 DIO_GetPinValue(u8 u8_port, u8 u8_pin);


//PORTS
#define GroupA 0
#define GroupB 1
#define GroupC 2
#define GroupD 3

//PINS
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7



#define HIGH 1
#define LOW 0
#define OUTPUT 1
#define INPUT 0


#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
