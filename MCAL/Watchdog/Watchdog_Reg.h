/*
 * Watchdog_Reg.h
 *
 *  Created on: Aug 26, 2023
 *      Author: Mustapha
 */

#ifndef MCAL_WATCHDOG_WATCHDOG_REG_H_
#define MCAL_WATCHDOG_WATCHDOG_REG_H_

#define WDTCR_REG  *((volatile u8 *)0x41)
//prescaler for timimg the watch dog
#define WDTCR_WDP0  0
#define WDTCR_WDP1  1
#define WDTCR_WDP2  2


#define WDTCR_WDE  3
#define WDTCR_WDTOE 4

#endif /* MCAL_WATCHD zOG_WATCHDOG_REG_H_ */
