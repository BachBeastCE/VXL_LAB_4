#ifndef INC_7SEG_H_
#define INC_7SEG_H_

#include "main.h"

//DEFINE GPIO PIN FOR 7SEG
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

extern const int MAX_LED;
extern int index_led;
extern int led_buffer [4];

void display7SEG(int num);
void update7SEG ( int index );
void run7SEG();

#endif /* INC_7SEG_H_ */
