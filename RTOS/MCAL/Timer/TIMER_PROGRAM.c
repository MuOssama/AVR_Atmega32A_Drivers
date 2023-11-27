/*
 * TIMER.PROGRAM.c
 *
 *  Created on: Jun 30, 2022
 *      Author: Mustapha
 */
#include"../../UTILS/STD_TYPES.h"
#include"../../UTILS/BIT_MATH.h"
#include"TIMER_INTERFACE.h"
#include"TIMER_REG.h"
#include <stddef.h>

void (*Timer0_CM_ptrToFunc)(void) = NULL;

void Timer0_init(){
	/*CTC PWM Mode*/
   CLR_BIT(TCCR0_REG,TCCR0_WGM00);
   SET_BIT(TCCR0_REG,TCCR0_WGM01);

   /*Prescaler Clock Select*/
   // 64  clk prescaler
   SET_BIT(TCCR0_REG,TCCR0_CS00);
   SET_BIT(TCCR0_REG,TCCR0_CS01);
   CLR_BIT(TCCR0_REG,TCCR0_CS02);

   //to make the compare match time is 1ms
    OCR0_REG = 125;
   //Set interrupts
   SET_BIT(TIMSK_REG,TIMSK_TOIE0);

}

u8 Timer0_SetCallbackFunc(void (*ptrToFunc)(void)){
	u8 errorState = 0;
	if(ptrToFunc != NULL){
		Timer0_CM_ptrToFunc = ptrToFunc;
	}
	else{
		errorState = 1;
	}
	return errorState;
	
}


void __vector_11 (void) __attribute__((signal));
void __vector_11 (void){
  if(Timer0_CM_ptrToFunc != NULL){
	  Timer0_CM_ptrToFunc();
  }
  else{
	  // do nothing!
  }


}
