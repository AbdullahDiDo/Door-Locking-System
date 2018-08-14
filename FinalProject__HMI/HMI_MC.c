/*
 * HMI_MC.c
 *
 *  Created on: Oct 21, 2017
 *      Author: Abdullah
 */
#include "HMI_MC.h"
/* use-password */
 uint8 g_UserPassword[PASSWORD_LENGTH]  ;

void GetUserPassword(){
		UART_sendByte(GET_PASSWORD);
		while(UART_recieveByte() != CONTROL_MC_READY);
		UART_receiveString(g_UserPassword);
		}
uint8 EnterPassword(void){
	uint8 a_PasswordLength =0;
	uint8 i =0;
	uint8 a_key;
	uint8 a_UserPassword1[5];
	LCD_displayString("Enter Password:");
	LCD_goToRowColumn(1,0);
	while (a_PasswordLength++ < PASSWORD_LENGTH){
			a_key = KeyPad_getPressedKey();
			LCD_displayCharacter('*');
			a_UserPassword1[i++] =a_key;
			_delay_ms(500);}
	a_UserPassword1[i]='\0';
	a_PasswordLength =0;
	i =0;
	uint8 j =1 ;
	LCD_clearScreen();
	LCD_goToRowColumn(0,0);
	LCD_displayString("Again Please:");
	LCD_goToRowColumn(1,0);
	while (a_PasswordLength++ < PASSWORD_LENGTH){
					a_key = KeyPad_getPressedKey();
					if(a_key !=a_UserPassword1[i])
						j=0;
					LCD_displayCharacter('*');
					i++;
				_delay_ms(500);}

	LCD_clearScreen();

	if(j && ComparePassword(a_UserPassword1,g_UserPassword))
	{
		return 1;
	}

	return 0;
}
uint8 MainMenu(){
	uint8 a_key ;
	LCD_goToRowColumn(0,0);
	LCD_displayString("*:Change Password");
	LCD_goToRowColumn(2,0);
	LCD_displayString("#:Unlock door");
	a_key=KeyPad_getPressedKey();
	LCD_clearScreen();
	if(a_key =='*')
		return CHANGE_PASSWORD;
	else
		return UNLOCK_DOOR;
}
void UnlockDoor(){
	LCD_goToRowColumn(0,0);
	uint8 a_PasswordLength =0;
	uint8 a_UserPassword[PASSWORD_LENGTH];
	uint8 a_key ;
	uint8 i =0;
	uint8 j =0;
	LCD_displayString("Please re-enter Password:");
	while (j<3){
	while (a_PasswordLength++ < PASSWORD_LENGTH){
					a_key = KeyPad_getPressedKey();
					LCD_displayCharacter('*');
					a_UserPassword[i++] =a_key;
					_delay_ms(500);}
	if (ComparePassword(a_UserPassword,g_UserPassword))
		{LCD_clearScreen();
		LCD_goToRowColumn(0,0);
		LCD_displayString("Door is unlocking ...");
		UART_sendByte(UNLOCK_DOOR);
		while(UART_recieveByte() != CONTROL_MC_READY);
		Timer_SetTime(20);
		Timer_start();
		while(g_TimePassed ==0);
		g_TimePassed =0;
		Timer_stop();
		LCD_clearScreen();
		return ;
	}j++;
}LCD_clearScreen();
	Buzzer();
	}
void Buzzer (){
	LCD_clearScreen();
	LCD_displayString("ERROR");
	UART_sendByte(ERROR);
	Timer_SetTime(90);
		Timer_start();
	while(g_TimePassed == 0);
	g_TimePassed =0 ;
	Timer_stop();
}
void ChangePassword(void){
	uint8 a_PasswordLength =0;
	uint8 i=0;
	uint8 a_key ;
	uint8 a_UserPassword[PASSWORD_LENGTH];
	LCD_displayString("Please enter old password:");
	while (a_PasswordLength++ < PASSWORD_LENGTH){
					a_key = KeyPad_getPressedKey();
					a_UserPassword[i] =a_key;
					LCD_displayCharacter('*');
					i++;
					_delay_ms(500);}
					a_UserPassword[i]='\0';
					i=0;
					a_PasswordLength=0;
					if(ComparePassword(a_UserPassword,g_UserPassword)){
						LCD_clearScreen();
						LCD_displayString("Please enter New Password:");
						while (a_PasswordLength++ < PASSWORD_LENGTH){
									a_key = KeyPad_getPressedKey();
									a_UserPassword[i] =a_key;
									LCD_displayCharacter('*');
									i++;
									_delay_ms(500);}
						a_UserPassword[i]='\0';
						LCD_goToRowColumn(3,0);
						LCD_clearScreen();
						UART_sendByte(CHANGE_PASSWORD);
						while (UART_recieveByte() != CONTROL_MC_READY);
						UARTString(a_UserPassword);
						UART_sendString(a_UserPassword);
						LCD_displayString("Password Changed !");
						_delay_ms(500);
						while(UART_recieveByte()!=MC2_DONE);
						LCD_clearScreen();
						return;
					}Buzzer();
}

