#ifndef EEPROM_REG_H
#define EEPROM_REG_H

#include"../../UTILS/STD_TYPES.h"
#include"../../UTILS/BIT_MATH.h"

#define EEAR_REG *((volatile u16*) 0x3E) //EEPROM Address Register
#define EEDR_REG *((volatile u8*) 0x3D)  //EEPROM DATA Register

#define EECR_REG *((volatile u8*) 0x3C) //EEPROM Control Register
#define EECR_EERE 0    //EEPROM Read Enable
#define EECR_EEWE 1    //EEPROM Write Enable
#define EECR_EEMWE 2   //EEPROM Master Write Enable
#define EECR_EERIE 3   //EEPROM Ready Interrupt Enable



#endif
