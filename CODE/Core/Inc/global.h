#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

//INCLUDE LIBRARY
#include "main.h"
#include "button.h"
#include "7SEG.h"

//DEFINE GPIO PIN - PORT A

#define LED_RED_1  GPIO_PIN_1
#define LED_YELLOW_1  GPIO_PIN_2
#define LED_GREEN_1  GPIO_PIN_3
#define LED_RED_2  GPIO_PIN_4
#define LED_YELLOW_2  GPIO_PIN_5
#define LED_GREEN_2  GPIO_PIN_6
#define LED_PINK GPIO_PIN_7

//DEFINE GPIO PIN - PORT B
#define SEG0 GPIO_PIN_0
#define SEG1 GPIO_PIN_1
#define SEG2 GPIO_PIN_2
#define SEG3 GPIO_PIN_3
#define SEG4 GPIO_PIN_4
#define SEG5 GPIO_PIN_5
#define SEG6 GPIO_PIN_6

#define EN0 GPIO_PIN_7
#define EN1 GPIO_PIN_8
#define EN2 GPIO_PIN_9
#define EN3 GPIO_PIN_10

//DEFINE STATE
#define INIT 0

#define RED_LED_AUTO 11
#define YELLOW_LED_AUTO 12
#define GREEN_LED_AUTO 13

#define RED_GREEN_MAN 21
#define	RED_YELLOW_MAN 22
#define GREEN_RED_MAN 23
#define YELLOW_RED_MAN 24

#define RED_LED_SET 31
#define YELLOW_LED_SET 32
#define GREEN_LED_SET 33


//DEFINE BUTTON FLAG

#define modify_button 0
#define mode_button 1
#define choose_button 2

//DEFINE VARIABLE
extern int status1;
extern int status2;
extern int lockcount1;
extern int lockcount2;
extern int count1;
extern int count2;
extern int count3;

extern int time_red;
extern int time_yellow; // red = green + yellow
extern int time_green;

//DEFINE FUNTION

void GPIO_Init(void);
void ResetLight1();
void ResetLight2();
void RedLight1();
void YellowLight1();
void GreenLight1();
void RedLight2();
void YellowLight2();
void GreenLight2();


#endif /* INC_GLOBAL_H_ */
