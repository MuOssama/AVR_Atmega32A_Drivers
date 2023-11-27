/*
 * RTOS_program.c
 *
 *  Created on: Sep 2, 2023
 *      Author: Mustapha
 */

#ifndef RTOS_RTOS_PROGRAM_C_
#define RTOS_RTOS_PROGRAM_C_
#include <stddef.h>
#include"../UTILS/STD_TYPES.h"
#include"../UTILS/BIT_MATH.h"
#include "../MCAL/Timer/TIMER_INTERFACE.h"
#include "../MCAL/GIE/GIE_INTERFACE.h"
#include "RTOS_interface.h"

#define maxRTOSTasks 3

typedef struct{
	u16 periodisity;
	void (*TaskFunc)(void);
}RTOS_task;

RTOS_task RTOSTasks[maxRTOSTasks];



void RTOS_init(){
	Timer0_init();
	Globle_Intrrupt_Enable();
	Timer0_SetCallbackFunc(&RTOS_scheduler);
}

void RTOS_createTask(u16 Copy_priodisity, u8 Copy_pariority, void (*Func)(void)){
	RTOSTasks[Copy_pariority].periodisity = Copy_priodisity;
	RTOSTasks[Copy_pariority].TaskFunc = Func;
}

void RTOS_scheduler(){
	static u16 cnt=0;
	cnt++;
	for(u8 i=0;i<maxRTOSTasks;i++){
		if(cnt % RTOSTasks[i].periodisity ==0){
			if(RTOSTasks[i].TaskFunc != NULL){
				RTOSTasks[i].TaskFunc();
			}
		}
		else{
			//dont do anything
		}

	}
}

#endif /* RTOS_RTOS_PROGRAM_C_ */

