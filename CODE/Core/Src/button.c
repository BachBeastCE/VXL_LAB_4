#include "button.h"

const int MAX_BUTTON = 5;

int KeyReg0[5]={SET,SET,SET,SET,SET};
int KeyReg1[5]={SET,SET,SET,SET,SET};
int KeyReg2[5]={SET,SET,SET,SET,SET};
int KeyReg3[5]={SET,SET,SET,SET,SET};


//int KeyReg0 = NORMAL_STATE;
//int KeyReg1 = NORMAL_STATE;
//int KeyReg2 = NORMAL_STATE;
//int KeyReg3 = NORMAL_STATE; // STATE BEFORE

int TimeOutForKeyPress =  500; //PRESS 5 second

int button_pressed[5]={0,0,0,0,0};
int button_long_pressed[5]={0,0,0,0,0};
int button_flag[5]={0,0,0,0,0};

//int button1_pressed = 0;
//int button1_long_pressed = 0;
//int button1_flag = 0;

int isButtonPressed(int button_index){
	if(button_flag[button_index] == 1){
		button_flag[button_index] = 0;
		return 1;
	}
	return 0;
}

int isButtonLongPressed(int button_index){
	if(button_long_pressed[button_index] == 1){
		button_long_pressed[button_index] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int button_index){
	//TODO
	//HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
	button_flag[button_index] = 1;
}

void getKeyInput(){
	for(int i=0;i<MAX_BUTTON;i++){
		 KeyReg2[i] = KeyReg1[i];
		 KeyReg1[i] = KeyReg0[i];
		  // Add your key
		 KeyReg0[0] = HAL_GPIO_ReadPin(GPIOA, MODIFY_BUTTON);
		 KeyReg0[1] = HAL_GPIO_ReadPin(GPIOA, MODE_BUTTON);
		 KeyReg0[2] = HAL_GPIO_ReadPin(GPIOA, CHOOSE_BUTTON);

		 if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
			 if (KeyReg2[i] != KeyReg3[i]){
				 KeyReg3[i] = KeyReg2[i];

				 if (KeyReg3[i] == PRESSED_STATE){
					 TimeOutForKeyPress = 500;
					 //subKeyProcess();
					 button_flag[i] = 1;
				 }
			 }
			 else{
				 TimeOutForKeyPress --;
				 if (TimeOutForKeyPress == 0){
					 TimeOutForKeyPress = 500;
					 if (KeyReg3[i] == PRESSED_STATE){
		        		//subKeyProcess();
						 button_flag[i] = 1;
					 }
				 }
			 }
		 }






	}
}

