/*
 * string.c
 *
 *  Created on: Oct 21, 2017
 *      Author: Abdullah
 */
#include "string.h"
 uint8 ComparePassword(uint8* str1,uint8* str2)
 {	uint8 i =0;
	 while (str1[i]!='\0'){
		 if (str1[i] !=str2[i]){
			 return 0;}
	 i++ ;}
	 return 1;
 }
 void  CopyString(uint8* str1,uint8* str2){
	 uint8 i =0;
	 while(str1[i] != '\0'){
		 str1[i]=str2[i];
		 i++ ;
	 }
	 str2[i]='\0';
 }
void UARTString (uint8* str){
	uint8 i =0;
	while(str[i] !='\0'){
		i++;
	}
	str[i]='#';

}
