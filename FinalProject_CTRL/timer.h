/*
 * timer.h
 *
 *  Created on: Oct 20, 2017
 *      Author: Abdullah
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"
/*******************  configurations ********************/
#define TCNT_MAX 65536
#define PRESCALE_VALUE 1024
#define TIMER_FREQUENCY  ( (F_CPU) / (PRESCALE_VALUE) )
#define TICK_TIME  ( (1.0) / (TIMER_FREQUENCY) )

extern volatile  uint8 g_TimePassed ;
/********************  prototypes   *********************/
void Timer_init(void);
void Timer_SetTime(uint8 sec);
void Timer_start(void);
void Timer_stop(void);
#endif /* TIMER_H_ */
