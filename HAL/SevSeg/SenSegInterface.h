/*
 * SenSegInterface.h
 *
 *  Created on: Aug 14, 2023
 *      Author: Mustapha
 */

#ifndef HAL_SEVSEG_SENSEGINTERFACE_H_
#define HAL_SEVSEG_SENSEGINTERFACE_H_

#include"../../UTILS/STD_TYPES.h"
#include"../../UTILS/BIT_MATH.h"

void CC_7SegWrite(u8 u8_port, u8 data );
void CA_7SegWrite(u8 u8_port, u8 data );

#endif /* HAL_SEVSEG_SENSEGINTERFACE_H_ */
