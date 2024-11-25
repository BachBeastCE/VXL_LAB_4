#include "scheduler.h"



// THE ARRAY OF TASK
static sTask SCH_tasks_G[SCH_MAX_TASKS];
//static uint8_t array_Of_Task_ID[SCH_MAX_TASKS];
static uint32_t newTaskID = 0;
//static uint32_t rearQueue = 0;
static uint32_t count_SCH_Update = 0;
static uint32_t Get_New_Task_ID(void);
uint8_t current_index_task;
//static uint32_t Get_New_Task_ID(void);
//static void TIMER_Init(void);

// ERROR CODE
uint8_t Error_code_G ;
uint8_t Error_port ;
uint8_t Last_error_code_G;
uint32_t Error_tick_count_G;

static uint32_t Get_New_Task_ID(void) {
   newTaskID++;
   if (newTaskID == NO_TASK_ID)
   {
      newTaskID++;
   }
   return newTaskID;
}

void SCH_Init(){
	uint8_t i;
	for (i = 0; i <SCH_MAX_TASKS; i++) {
		SCH_Delete_Task(i);
	}
	 // Reset the global error variable
	 // − SCH_Delete_Task() will generate an error code,
	 // (because the task array is empty)
	 Error_code_G= 0;
	 //Timer_init();
	 MX_IWDG_Init(); //Watchdog init
}



void SCH_Update(void){
    // check if there is a task at this location
    count_SCH_Update++;
    if (SCH_tasks_G[0].pTask && SCH_tasks_G[0].RunMe == 0)
    {
       if (SCH_tasks_G[0].Delay > 0)
       {
          SCH_tasks_G[0].Delay = SCH_tasks_G[0].Delay - 1;
       }
       if (SCH_tasks_G[0].Delay == 0)
       {
          SCH_tasks_G[0].RunMe = 1;
       }
    }
	Watchdog_Refresh();
}

uint32_t SCH_Add_Task(void(* pFunction)(), uint32_t DELAY, uint32_t PERIOD){
    uint8_t newTaskIndex = 0;
    uint32_t sumDelay = 0;
    uint32_t newDelay = 0;
    for (newTaskIndex = 0; newTaskIndex < SCH_MAX_TASKS; newTaskIndex++)
    {
       sumDelay = sumDelay + SCH_tasks_G[newTaskIndex].Delay;
       if (sumDelay > DELAY)
       {
          newDelay = DELAY - (sumDelay - SCH_tasks_G[newTaskIndex].Delay);
          SCH_tasks_G[newTaskIndex].Delay = sumDelay - DELAY;
          for (uint8_t i = SCH_MAX_TASKS - 1; i > newTaskIndex; i--)
          {
             SCH_tasks_G[i].pTask = SCH_tasks_G[i - 1].pTask;
             SCH_tasks_G[i].Period = SCH_tasks_G[i - 1].Period;
             SCH_tasks_G[i].Delay = SCH_tasks_G[i - 1].Delay;
             SCH_tasks_G[i].TaskID = SCH_tasks_G[i - 1].TaskID;
          }
          SCH_tasks_G[newTaskIndex].pTask = pFunction;
          SCH_tasks_G[newTaskIndex].Delay = newDelay;
          SCH_tasks_G[newTaskIndex].Period = PERIOD;

          if (SCH_tasks_G[newTaskIndex].Delay == 0)
          {
             SCH_tasks_G[newTaskIndex].RunMe = 1;
          }
          else
          {
             SCH_tasks_G[newTaskIndex].RunMe = 0;
          }
          SCH_tasks_G[newTaskIndex].TaskID = Get_New_Task_ID();
          return SCH_tasks_G[newTaskIndex].TaskID;
       }
       else
       {
          if (SCH_tasks_G[newTaskIndex].pTask == 0x0000)
          {
             SCH_tasks_G[newTaskIndex].pTask = pFunction;
             SCH_tasks_G[newTaskIndex].Delay = DELAY - sumDelay;
             SCH_tasks_G[newTaskIndex].Period = PERIOD;
             if (SCH_tasks_G[newTaskIndex].Delay == 0)
             {
                SCH_tasks_G[newTaskIndex].RunMe = 1;
             }
             else
             {
                SCH_tasks_G[newTaskIndex].RunMe = 0;
             }
             SCH_tasks_G[newTaskIndex].TaskID = Get_New_Task_ID();
             return SCH_tasks_G[newTaskIndex].TaskID;
          }
       }
    }
    return SCH_tasks_G[newTaskIndex].TaskID;
}

uint8_t SCH_Delete_Task(uint32_t TASK_INDEX){
    uint8_t Return_code = 0;
    uint8_t taskIndex;
    uint8_t j;

    if (TASK_INDEX != NO_TASK_ID)
    {
       for (taskIndex = 0; taskIndex < SCH_MAX_TASKS; taskIndex++)
       {
          if (SCH_tasks_G[taskIndex].TaskID == TASK_INDEX)
          {
             Return_code = 1;
             if (taskIndex != 0 && taskIndex < SCH_MAX_TASKS - 1)
             {
                if (SCH_tasks_G[taskIndex + 1].pTask != 0x0000)
                {
                   SCH_tasks_G[taskIndex + 1].Delay += SCH_tasks_G[taskIndex].Delay;
                }
             }
             for (j = taskIndex; j < SCH_MAX_TASKS - 1; j++)
             {
                SCH_tasks_G[j].pTask = SCH_tasks_G[j + 1].pTask;
                SCH_tasks_G[j].Period = SCH_tasks_G[j + 1].Period;
                SCH_tasks_G[j].Delay = SCH_tasks_G[j + 1].Delay;
                SCH_tasks_G[j].RunMe = SCH_tasks_G[j + 1].RunMe;
                SCH_tasks_G[j].TaskID = SCH_tasks_G[j + 1].TaskID;
             }
             SCH_tasks_G[j].pTask = 0;
             SCH_tasks_G[j].Period = 0;
             SCH_tasks_G[j].Delay = 0;
             SCH_tasks_G[j].RunMe = 0;
             SCH_tasks_G[j].TaskID = 0;
             return Return_code = 0;
          }
       }
    }
    return Return_code; // return status
}

void SCH_Dispatch_Task(void){
    if (SCH_tasks_G[0].RunMe > 0)
    {
       (*SCH_tasks_G[0].pTask)(); // Run the task
       SCH_tasks_G[0].RunMe = 0;  // Reset RunMe
       sTask temtask = SCH_tasks_G[0];
       SCH_Delete_Task(temtask.TaskID);
       if (temtask.Period != 0)
       {
          SCH_Add_Task(temtask.pTask, temtask.Period, temtask.Period);
       }
    }
	// Report system status
	SCH_Report_Status();
	// The scheduler enters idlemode at this point
	//SCH_Go_To_Sleep();
}

void SCH_Go_To_Sleep(){}

void SCH_Report_Status(void) {
#ifdef SCH_REPORT_ERRORS
	//ONLYAPPLIES IFWEAREREPORTINGERRORS
	// Check for answer error code
	if (Error_code_G != Last_error_code_G) {
		// Negative logic onLEDs assumed
		Error_port = 255 - Error_code_G;
		Last_error_code_G = Error_code_G;
		if (Error_code_G != 0){
			Error_tick_count_G= 60000;
		} else {
			Error_tick_count_G= 0;
		}
	}
	else {
		if (Error_tick_count_G != 0){
			if (--Error_tick_count_G== 0) {
				Error_code_G= 0; // Reset error code
			}
		}
	}
#endif
}


/*

 voidHAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
 SCH_Update() ;
 }

*/

/*

The dispatcher is the only component in the SuperLoop:
void main(void){
while(1){
	SCH_Dispatch_Tasks() ;
}

*/

////INIT TIMER_10ms
//static void TIMER_Init(){
//    cli(); //Disable interupt
//
//    /*Reset Timer/counter1*/
//    TCCR1A = 0;
//    TCCC1B = 0;
//    TIMSK = 0;
//
//    /*Set up timer/counter 1*/
//    TCC1B != (1 << CS11)| (1 << CS10); //Prescale = 64
//    TCNT1 = CONTER_START;
//    TIMSK1 = (1<<TOIE1); // Overflow interupt enable
//    sei(); //Enable interupt
//}
//
//ISR (TIMER_OVF_vect){
//    TCNT1 = CONTER_START;
//    SCH_Update();
//}
//
//static uint32_t Get_New_Task_ID(void){
//    newTaskID++;
//    if(newTaskID == NO_TASK_ID){
//        newTaskID++;
//    }
//    return newTaskID;
//}


//WATCHDOG
IWDG_HandleTypeDef hiwdg;
static uint32_t counter_for_watchdog = 0;

void MX_IWDG_Init(void) {
    hiwdg.Instance = IWDG;
    hiwdg.Init.Prescaler = IWDG_PRESCALER_32; // Chia tần số để định thời gian cho watchdog
    hiwdg.Init.Reload = 4095; // Giá trị reload để định thời gian
    if (HAL_IWDG_Init(&hiwdg) != HAL_OK) {
        Error_Handler(); // Gọi hàm xử lý lỗi nếu khởi tạo thất bại
    }
}



void Watchdog_Refresh(void) {
    HAL_IWDG_Refresh(&hiwdg); // Làm mới watchdog
}


uint8_t Is_Watchdog_Reset(void){
  if(counter_for_watchdog > 3){
	  return 1;
  }
  	  return 0;
}

void Watchdog_Counting(void){
  counter_for_watchdog++;
}

void Reset_Watchdog_Counting(void){
  counter_for_watchdog = 0;
}

