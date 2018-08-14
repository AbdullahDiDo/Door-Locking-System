/*
 * CTRL_MC.c
 *
 *  Created on: Oct 22, 2017
 *      Author: Abdullah
 */
#include "CTRL_MC.h"
uint8 g_UserPassword [PASSWORD_LENGTH]="12345";
void PasswordSet(){
	uint8 i =0 ;
	while (i<PASSWORD_LENGTH){
		EEPROM_Write_Byte(MEMORY_START_ADDRESS+i, g_UserPassword[i]);
		i++;}
}
void PasswordGet(uint8* pass){
	uint8 i =0 ;
		while (i<PASSWORD_LENGTH){
			EEPROM_Read_Byte(MEMORY_START_ADDRESS+i,pass+i);
			i++;}

}
void UnlockDoor (){
	CLEAR_BIT(MOTOR_PORT_REG,MOTOR_PIN_1);
	SET_BIT(MOTOR_PORT_REG,MOTOR_PIN_2);
	Timer_SetTime(10);
		Timer_start();
	while(g_TimePassed == 0);
	Timer_stop();
	g_TimePassed =0;
	CLEAR_BIT(MOTOR_PORT_REG,MOTOR_PIN_2);
	SET_BIT(MOTOR_PORT_REG,MOTOR_PIN_1);
	Timer_SetTime(10);
	Timer_start();
	while(g_TimePassed == 0);
	g_TimePassed =0;
	Timer_stop();
	CLEAR_BIT(MOTOR_PORT_REG,MOTOR_PIN_1);
	CLEAR_BIT(MOTOR_PORT_REG,MOTOR_PIN_2);

}
void Buzzer () {
	Timer_SetTime(90);
	SET_BIT(BUZZER_PORT_REG,BUZZER_PIN);
	Timer_start();
		while(g_TimePassed ==0);
		g_TimePassed = 0;
		Timer_stop();
		CLEAR_BIT(BUZZER_PORT_REG,BUZZER_PIN);



}
