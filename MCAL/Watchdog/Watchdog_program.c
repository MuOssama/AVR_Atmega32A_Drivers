/*
 * Watchdog_program.c
 *
 *  Created on: Aug 26, 2023
 *      Author: Mustapha
 */

#include"Watchdog_Reg.h"
#include"Watchdog_interface.h"
#include"../../UTILS/STD_TYPES.h"
#include"../../UTILS/BIT_MATH.h"

void Watchdog_enable(){
	SET_BIT(WDTCR_REG,WDTCR_WDE);
}
void Watchdog_disable(){
	/* Write logical one to WDTOE and WDE */
	WDTCR_REG = (1<<WDTCR_WDTOE) | (1<<WDTCR_WDE);
	/* Turn off WDT */
	WDTCR_REG  = 0x00;
}
void Watchdog_setTime(u8 value){
	switch(value){
	case 0: CLR_BIT(WDTCR_REG,WDTCR_WDP0);CLR_BIT(WDTCR_REG,WDTCR_WDP1);CLR_BIT(WDTCR_REG,WDTCR_WDP2);break;
	case 1: SET_BIT(WDTCR_REG,WDTCR_WDP0);CLR_BIT(WDTCR_REG,WDTCR_WDP1);CLR_BIT(WDTCR_REG,WDTCR_WDP2);break;
}

}
