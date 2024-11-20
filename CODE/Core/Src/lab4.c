/*
 * LAB4.c
 *
 *  Created on: Nov 20, 2024
 *      Author: ASUS
 */

#include <lab4.h>

void initLab4(){
	  SCH_Init() ;

	  SCH_Add_Task(oneshotLed , 5000 , 0);
	  SCH_Add_Task(turnOnLedRed , 1000 , 4000);
	  SCH_Add_Task(turnOnLedYellow , 1000 , 2000);
	  SCH_Add_Task(turnOnLedGreen , 1000 , 1000);
}
void oneshotLed(void){
	HAL_GPIO_WritePin(GPIOA, oneshot, SET);
}

void turnOnLedRed(void){
	HAL_GPIO_TogglePin(GPIOA, RED);
}
void turnOnLedYellow(void){
	 HAL_GPIO_TogglePin(GPIOA, YELLOW);
}
void turnOnLedGreen(void){
	 HAL_GPIO_TogglePin(GPIOA, GREEN);
}
