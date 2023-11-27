/*
 * TIMER_INTERFACE.h
 *
 *  Created on: Jun 30, 2022
 *      Author: Mustapha
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_
#include"../../UTILS/STD_TYPES.h"

void Timer0_init();

u8 Timer0_SetCallbackFunc(void (*ptrToFunc)(void));




#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
