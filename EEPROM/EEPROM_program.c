/*
 * EEPROM_program.c
 *
 *  Created on: Aug 29, 2023
 *      Author: Mustapha
 */

#include"EEPROM_interface.h"
#include"EEPROM_REG.h"

void EEPROM_WRITE(u16 address,u8 data){
	while(GET_BIT(EECR_REG,EECR_EEWE)==1);
	EEAR_REG = address;
	EEDR_REG = data;
	SET_BIT(EECR_REG,EECR_EEMWE);
	SET_BIT(EECR_REG,EECR_EEWE);
}
u8 EEPROM_READ(u16 address){
	while(GET_BIT(EECR_REG,EECR_EEWE)==1);
	EEAR_REG = address;
	SET_BIT(EECR_REG,EECR_EERE);
    return EEDR_REG;
}
