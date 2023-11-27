/*
 * Watchdog_interface.h
 *
 *  Created on: Aug 26, 2023
 *      Author: Mustapha
 */

#ifndef MCAL_WATCHDOG_WATCHDOG_INTERFACE_H_
#define MCAL_WATCHDOG_WATCHDOG_INTERFACE_H_
#include"../../UTILS/STD_TYPES.h"

void Watchdog_enable();
void Watchdog_disable();
void Watchdog_setTime(u8 value);



#endif /* MCAL_WATCHDOG_WATCHDOG_INTERFACE_H_ */
