/*
 * main.c
 *
 *  Created on: Oct 22, 2017
 *      Author: Abdullah
 */

#include "CTRL_MC.h"
int main() {
	UART_init();
	EEPROM_Init();
	Timer_init();
	PasswordSet();
	MOTOR_DDR_REG |=(1<<MOTOR_PIN_1)|(1<<MOTOR_PIN_2);
	CLEAR_BIT(MOTOR_PORT_REG,MOTOR_PIN_1);
	CLEAR_BIT(MOTOR_PORT_REG,MOTOR_PIN_2);
	SET_BIT(BUZZER_DDR,BUZZER_PIN);
	CLEAR_BIT(BUZZER_PORT_REG,BUZZER_PIN);
	UART_sendByte(CONTROL_MC_READY);
while (1){
	uint8 Byte =UART_recieveByte();
	if(Byte == GET_PASSWORD){
		PORTA=0;
		PasswordGet(g_UserPassword);
		UART_sendByte(CONTROL_MC_READY);
		UARTString(g_UserPassword);
		UART_sendString(g_UserPassword);
	}
	else if(Byte==CHANGE_PASSWORD){

		UART_sendByte(CONTROL_MC_READY);
		UART_receiveString(g_UserPassword);
		PasswordSet();
		UART_sendByte(MC2_DONE);
	}
	else if (Byte == UNLOCK_DOOR)
	{	UART_sendByte(CONTROL_MC_READY);
		UnlockDoor();

	}
	else if (Byte== ERROR2){

		Buzzer();
	}

}


	return 0;
}
