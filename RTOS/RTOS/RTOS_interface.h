/*
 * RTOS_interface.h
 *
 *  Created on: Sep 2, 2023
 *      Author: Mustapha
 */

#ifndef RTOS_RTOS_INTERFACE_H_
#define RTOS_RTOS_INTERFACE_H_


void RTOS_init();

void RTOS_createTask(u16 Copy_priodesity, u8 Copy_pariority, void (*Func)(void));

void RTOS_scheduler();

#endif /* RTOS_RTOS_INTERFACE_H_ */
