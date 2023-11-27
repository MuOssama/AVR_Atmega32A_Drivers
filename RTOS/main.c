/*
 * main.c
 *
 *  Created on: Sep 2, 2023
 *      Author: Mustapha
 */

#include"MCAL/DIO/DIO_INTERFACE.h"
#include"RTOS/RTOS_interface.h"
#include"avr/io.h"

void LED1();
void LED2();
void LED3();

void main(){
    RTOS_init();


	DIO_SetPin_Direction(GroupA,PIN0,OUTPUT);
	DIO_SetPin_Direction(GroupA,PIN1,OUTPUT);
	DIO_SetPin_Direction(GroupA,PIN2,OUTPUT);

	RTOS_createTask(1000,0,&LED1);
	RTOS_createTask(2000,1,&LED2);
	RTOS_createTask(3000,2,&LED3);

	while(1){
	}
}


void LED1(){
	PORTA ^= (1<<PIN0);
}

void LED2(){
	PORTA ^= (1<<PIN1);
}
void LED3(){
	PORTA ^= (1<<PIN2);
}


