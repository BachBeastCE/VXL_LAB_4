/*
 * LAB4.h
 *
 *  Created on: Nov 20, 2024
 *      Author: ASUS
 */

#ifndef INC_LAB4_H_
#define INC_LAB4_H_

//INCLUDE
#include "scheduler.h"

//DEFINE GPIO
#define oneshot GPIO_PIN_2
#define RED GPIO_PIN_3
#define YELLOW GPIO_PIN_4
#define GREEN GPIO_PIN_5

//TASK
void oneshotLed(void);
void turnOnLedRed(void);
void turnOnLedYellow(void);
void turnOnLedGreen(void);

//FUCTION
void initLab4();

#endif /* INC_LAB4_H_ */
