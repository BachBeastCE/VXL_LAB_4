/*
 * scheduler.h
 *
 *  Created on: Nov 13, 2024
 *      Author: ASUS
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

// INCLUDE
#include "main.h"

// DEFINE
#define NO_TASK_ID 0

// VARIABLE
const int SCH_MAX_TASKS = 100;

// FUNTION
void SCH_Init();
void SCH_Update(void);
unit32_t SCH_Add_Task(void(* pFunc)(), unit32_t DELAY, unit32_t PERIOD);
unit8_t SCH_Delete_Task(unit32_t taskID);
void SCH_Dispatch_Task(void);



#endif /* INC_SCHEDULER_H_ */
