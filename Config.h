/*
 * config.h
 *
 *  Created on: Aug 1, 2022
 *      Author: Mustapha
 */

#ifndef CONFIG_H_
#define CONFIG_H_
#include <avr/io.h>
#include "MCAL/DIO/DIO_REG.H"

/*Limits*/
#define MAX_TEMP                    45
#define MIN_LIGHT                   800
#define openangle                   0
#define closeangle                  -89


//Emergency bottom
#define EmergencyBottomPIN_STOP     PIN3
#define EmergencyBottomPIN          PIN2
#define EmergencyBottomPORT         GroupD

//Emergency LED
#define EmergencyLEDPIN             PIN6
#define EmergencyLEDPORT            GroupB

//lamp
#define lamp220PIN                  PIN5
#define lamp220PORT                 GroupB

//Buzzer
#define BuzzerPort                  GroupB
#define BuzzerPin                   PIN4



#endif /* CONFIG_H_ */
