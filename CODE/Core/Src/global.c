#include "global.h"

void GPIO_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* USER CODE BEGIN MX_GPIO_Init_1 */
    /* USER CODE END MX_GPIO_Init_1 */

    // Enable GPIO Ports Clock
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

    // Configure GPIO pin Output Level for PB0
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);

    // Configure GPIO pins : PB0 as output
    GPIO_InitStruct.Pin = GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    // Configure GPIO pins : PA13, PA14, PA15 as input with pull-up
    GPIO_InitStruct.Pin = GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* USER CODE BEGIN MX_GPIO_Init_2 */

    // Configure GPIO pins : PA1 PA2 PA3 PA4 PA5 PA6 PA7 as output
    GPIO_InitStruct.Pin = GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 |
                          GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    // Configure GPIO pins : PB1 PB2 PB3 PB4 PB5 PB6 PB7 PB8 PB9 PB10 PB11 PB12 PB13 as output
    GPIO_InitStruct.Pin = GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 |
                          GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8 |
                          GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12 |
                          GPIO_PIN_13;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

void ResetLight1(){
	HAL_GPIO_WritePin(GPIOA,LED_RED_1 , RESET);
	HAL_GPIO_WritePin(GPIOA,LED_YELLOW_1 , RESET);
	HAL_GPIO_WritePin(GPIOA,LED_GREEN_1 , RESET);
}

void ResetLight2(){
	HAL_GPIO_WritePin(GPIOA,LED_RED_2 , RESET);
	HAL_GPIO_WritePin(GPIOA,LED_YELLOW_2 ,  RESET);
	HAL_GPIO_WritePin(GPIOA,LED_GREEN_2 , RESET);
}
void RedLight1(){
	HAL_GPIO_WritePin(GPIOA,LED_RED_1 , SET);
	HAL_GPIO_WritePin(GPIOA,LED_YELLOW_1 , RESET);
	HAL_GPIO_WritePin(GPIOA,LED_GREEN_1 , RESET);
}
void YellowLight1(){
	HAL_GPIO_WritePin(GPIOA,LED_RED_1 , RESET);
	HAL_GPIO_WritePin(GPIOA,LED_YELLOW_1 , SET);
	HAL_GPIO_WritePin(GPIOA,LED_GREEN_1 , RESET);
}
void GreenLight1(){
	HAL_GPIO_WritePin(GPIOA,LED_RED_1 , RESET);
	HAL_GPIO_WritePin(GPIOA,LED_YELLOW_1 , RESET);
	HAL_GPIO_WritePin(GPIOA,LED_GREEN_1 , SET);
}
void RedLight2(){
	HAL_GPIO_WritePin(GPIOA,LED_RED_2 , SET);
	HAL_GPIO_WritePin(GPIOA,LED_YELLOW_2 , RESET);
	HAL_GPIO_WritePin(GPIOA,LED_GREEN_2 , RESET);
}
void YellowLight2(){
	HAL_GPIO_WritePin(GPIOA,LED_RED_2 , RESET);
	HAL_GPIO_WritePin(GPIOA,LED_YELLOW_2 , SET);
	HAL_GPIO_WritePin(GPIOA,LED_GREEN_2 , RESET);
}
void GreenLight2(){
	HAL_GPIO_WritePin(GPIOA,LED_RED_2 , RESET);
	HAL_GPIO_WritePin(GPIOA,LED_YELLOW_2 , RESET);
	HAL_GPIO_WritePin(GPIOA,LED_GREEN_2 , SET);
}

