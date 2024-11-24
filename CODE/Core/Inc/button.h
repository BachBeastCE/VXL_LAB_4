/*
 * button.h
 *
 *  Created on: Oct 5, 2023
 *      Author: KAI
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"



#define NORMAL_STATE SET
#define PRESSED_STATE RESET

extern const int MAX_BUTTON;
extern int button_flag[5];

//DEFINE BUTTON GPIO A
#define MODIFY_BUTTON GPIO_PIN_13
#define MODE_BUTTON GPIO_PIN_14
#define CHOOSE_BUTTON GPIO_PIN_15


void getKeyInput();
int isButtonPressed(int button_index);
int isButtonLongPressed(int button_index);

#endif /* INC_BUTTON_H_ */

