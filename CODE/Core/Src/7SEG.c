#include "7SEG.h"

const int MAX_LED = 4;
int index_led = 0;
int led_buffer [4] = {1, 2, 3, 4};

void display7SEG(int num){
	switch (num){
	case 0:{
	    HAL_GPIO_WritePin(GPIOB, SEG0, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG1, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG2, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG3, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG4, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG5, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG6, GPIO_PIN_SET);
	    break;
	}
	case 1:{
	    HAL_GPIO_WritePin(GPIOB, SEG0, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOB, SEG1, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG2, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG3, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOB, SEG4, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOB, SEG5, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOB, SEG6, GPIO_PIN_SET);
	    break;
	}
	case 2:{
	    HAL_GPIO_WritePin(GPIOB, SEG0, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG1, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG2, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOB, SEG3, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG4, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG5, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOB, SEG6, GPIO_PIN_RESET);
	    break;
	}
	case 3:{
	    HAL_GPIO_WritePin(GPIOB, SEG0, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG1, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG2, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG3, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG4, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOB, SEG5, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOB, SEG6, GPIO_PIN_RESET);
	    break;
	}
	case 4:{
	    HAL_GPIO_WritePin(GPIOB, SEG0, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOB, SEG1, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG2, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG3, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOB, SEG4, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOB, SEG5, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG6, GPIO_PIN_RESET);
	    break;
	}
	case 5:{
	    HAL_GPIO_WritePin(GPIOB, SEG0, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG1, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOB, SEG2, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG3, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG4, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOB, SEG5, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG6, GPIO_PIN_RESET);
	    break;
	}
	case 6:{
	    HAL_GPIO_WritePin(GPIOB, SEG0, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG1, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOB, SEG2, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG3, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG4, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG5, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG6, GPIO_PIN_RESET);
	    break;
	}
	case 7:{
	    HAL_GPIO_WritePin(GPIOB, SEG0, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG1, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG2, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG3, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOB, SEG4, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOB, SEG5, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOB, SEG6, GPIO_PIN_SET);
	    break;
	}
	case 8:{
	    HAL_GPIO_WritePin(GPIOB, SEG0, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG1, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG2, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG3, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG4, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG5, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG6, GPIO_PIN_RESET);
	    break;
	}
	case 9:{
	    HAL_GPIO_WritePin(GPIOB, SEG0, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG1, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG2, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG3, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG4, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOB, SEG5, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG6, GPIO_PIN_RESET);
	    break;
	}
	}
}

void update7SEG ( int index ){
	switch ( index ){
	case 0:{
		// Display the first 7 SEG with led_buffer [0]
		display7SEG(led_buffer[0]);
		HAL_GPIO_WritePin(GPIOB, EN0, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, EN1, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, EN2, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, EN3, GPIO_PIN_SET);
		break ;
	}
	case 1:{
		// Display the second 7 SEG with led_buffer [1]
		display7SEG(led_buffer[1]);
	    HAL_GPIO_WritePin(GPIOB, EN0, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOB, EN1, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, EN2, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, EN3, GPIO_PIN_SET);
		break ;
	}
	case 2:{
		// Display the third 7 SEG with led_buffer [2]
		display7SEG(led_buffer[2]);
	    HAL_GPIO_WritePin(GPIOB, EN0, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOB, EN1, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, EN2, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, EN3, GPIO_PIN_SET);
		break ;
	}
	case 3:
	{
		// Display the forth 7 SEG with led_buffer [3]
		display7SEG(led_buffer[3]);
	    HAL_GPIO_WritePin(GPIOB, EN0, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(GPIOB, EN1, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, EN2, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, EN3, GPIO_PIN_RESET);
		break ;
	}
	}
}

void run7SEG(){
	update7SEG (index_led++);
	if(index_led == MAX_LED){index_led=0;}
}

