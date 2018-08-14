/*
 * timer.c
 *
 *  Created on: Oct 20, 2017
 *      Author: Abdullah Ahmed
 */

#include "timer.h"
#define REQ_TICKS(SEC) ( (TCNT_MAX)-( (SEC)/(TICK_TIME) ) )/* macro to get the required ticks */

volatile uint8 g_TimePassed =0 ; /* global variable to check if time passed */
static uint8 g_TimerSecs = 0;
ISR(TIMER1_OVF_vect){
	g_TimePassed = 1;
	TCNT1=REQ_TICKS(g_TimerSecs);
}

void Timer_init(){

	/*  Normal mode COM1B0=0 COM1B1=0  COM1A0 =0 COM1A1=0
	 *  Pescaler 1024 CS12=1 CS11=0 CS10=1
	 *  enable global interrupt
	 */
	TCCR1B |= (1<<CS12) | (1<<CS10);
	SET_BIT(SREG,7);
}
void Timer_SetTime(uint8 sec){
	/* set the required time and get value for TCNT1 register */
	g_TimerSecs = sec ;
	TCNT1 = REQ_TICKS(g_TimerSecs);
}
void Timer_start(void){
	/* set the TOIE1 bit to start the timer */
	SET_BIT(TIMSK,TOIE1);
}
void Timer_stop(void){
	/* clear the TOIE1 bit to stop the timer */
	CLEAR_BIT(TIMSK,TOIE1);
	TCNT1=0;
}
