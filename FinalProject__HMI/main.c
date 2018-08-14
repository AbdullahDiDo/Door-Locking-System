/*
 * main.c
 *
 *  Created on: Oct 21, 2017
 *      Author: Abdullah
 */
#include "HMI_MC.h"
int main (){
	/* initiallize modules */
	LCD_init();
	Timer_init();
	UART_init();
	state current_state =ENTER_PASSWORD;
	GetUserPassword();
while (1){

	if (current_state == ENTER_PASSWORD){
			if( EnterPassword() ){
				current_state = MAIN_MENU;}
			else {
				current_state =ENTER_PASSWORD;  }

		}
	else if (current_state == MAIN_MENU){
		if(MainMenu() == CHANGE_PASSWORD){
			current_state =PASSWORD_CHANGE;
		}
		else {
			current_state =UNLOCKING_DOOR;
		}
	}
	else if (current_state == UNLOCKING_DOOR){
		UnlockDoor();
		current_state = MAIN_MENU;
	}
	else if (current_state == PASSWORD_CHANGE){
		ChangePassword();
		GetUserPassword();
		current_state =MAIN_MENU;
	}
	}


}
