/*
 * SevSegProgram.c
 *
 *  Created on: Aug 14, 2023
 *      Author: Mustapha
 */
#include"SenSegInterface.h"

void CC_7SegWrite(u8 u8_port, u8 data ){
	u8 SSEG_u8Number[10]={  0b00111111, /* 0 */
				  0b00000110, /* 1 */
				  0b01011011, /* 2 */
				  0b01001111, /* 3 */
				  0b01100110, /* 4 */
				  0b01101101, /* 5 */
				  0b01111101, /* 6 */
				  0b00000111, /* 7 */
				  0b01111111, /* 8 */
				  0b01101111 /* 9 */};
	DIO_SetPort_Value(u8_port,SSEG_u8Number[data]);

}

void CA_7SegWrite(u8 u8_port, u8 data ){
	u8 SSEG_u8Number[10]={  ~0b00111111, /* 0 */
				  ~0b00000110, /* 1 */
				  ~0b01011011, /* 2 */
				  ~0b01001111, /* 3 */
				 ~ 0b01100110, /* 4 */
				 ~ 0b01101101, /* 5 */
				 ~ 0b01111101, /* 6 */
				 ~ 0b00000111, /* 7 */
				 ~ 0b01111111, /* 8 */
				  ~0b01101111 /* 9 */};
	DIO_SetPort_Value(u8_port,SSEG_u8Number[data]);

}

