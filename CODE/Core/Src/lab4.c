/*
 * LAB4.c
 *
 *  Created on: Nov 20, 2024
 *      Author: ASUS
 */

#include <lab4.h>

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
