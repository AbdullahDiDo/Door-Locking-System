/*
 * CTRL_MC.h
 *
 *  Created on: Oct 22, 2017
 *      Author: Abdullah
 */

#ifndef CTRL_MC_H_
#define CTRL_MC_H
#include "std_types.h"
#include "uart.h"
#include "timer.h"
#include "micro_config.h"
#include "common_macros.h"
#include "External_EEPROM.h"
#include "string.h"
/* Password length */
#define PASSWORD_LENGTH 5

/* MACROS used for UART communication */
#define GET_PASSWORD 0
#define CHANGE_PASSWORD 1
#define UNLOCK_DOOR 2
#define CONTROL_MC_READY 3
#define ERROR2 4
#define MC2_DONE 5
/* motor configuration*/
#define  MOTOR_PORT_REG PORTC
#define  MOTOR_DDR_REG DDRC
#define MOTOR_PIN_1 PC2
#define  MOTOR_PIN_2 PC3
/* memory addresses */
#define MEMORY_START_ADDRESS 0x0311
/* user password */
extern uint8 g_UserPassword [PASSWORD_LENGTH];
void PasswordSet(void);
void PasswordGet(uint8*);
void UnlockDoor (void);
void Buzzer (void);
/* Buuzer */
#define BUZZER_PIN PD2
#define BUZZER_DDR DDRD
#define BUZZER_PORT_REG PORTD
#endif /* CTRL_MC_H_ */
