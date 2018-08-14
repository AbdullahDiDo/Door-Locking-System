/*
 * HMI_MC.h
 *
 *  Created on: Oct 21, 2017
 *      Author: Abdullah
 */

#ifndef HMI_MC_H_
#define HMI_MC_H_

/* include header files */
#include "timer.h"
#include "keypad.h"
#include "lcd.h"
#include "uart.h"
#include "string.h"

#define PASSWORD_LENGTH 5
/* MACROS used for UART communication */
#define GET_PASSWORD 0
#define CHANGE_PASSWORD 1
#define UNLOCK_DOOR 2
#define CONTROL_MC_READY 3
#define ERROR 4
#define MC2_DONE 5
/* current state */
typedef enum {ENTER_PASSWORD,MAIN_MENU,PASSWORD_CHANGE,UNLOCKING_DOOR,DOOR_UNLOCKING_CLOSING} state ;



/* function prototypes */
uint8 EnterPassword(void);
void GetUserPassword(void);
uint8 MainMenu(void);
void UnlockDoor(void);
void Buzzer (void);
void ChangePassword (void);
#endif /* HMI_MC_H_ */
