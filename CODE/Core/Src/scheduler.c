#include "scheduler.h"

#ifdef __cplusplus
extern "C"(
#endif


#define INTERRUPT_CYLCE 10 //interrupt = 10ms
#define PRESCALER 79
#define CONTER_START 65536 - INTERRUPT_CYCLE * 1000 * 8/79 //16M is core clock

typedef struct{
    void (* pTask)(void);
    unit32_t Delay;
    unit32_t Period;
    unit32_t RunMe;
    unit32_t TaskID;
} sTask;

// THE ARRAY OF TASK
static sTask SCH_task_G[SCH_MAX_TASKS];
static unit8_t array_Of_Task_ID[SCH_MAX_TASKS];
static unit32_t newTaskID = 0;
static unit32_t rearQueue = 0;
static unit32_t count_SCH_Update = 0;

static unit32_t Get_New_Task_ID(void);
static void TIMER_Init(void);

void SCH_Init(){
    TIMER_Init();
}

void SCH_Update(void){
    //check if there is a task at this location
    count_SCH_Update++;
    if(SCH_task_G[0].pTask && SCH_task_G[0].RunMe ==0){
        if(SCH_task_G[0].Delay>0){
            SCH_task_G[0].Delay = SCH_task_G[0].Delay -1;
        }
        if(SCH_task_G[0].Delay==0){
            SCH_task_G[0].RunMe = 1;
        }
    }
}

unit32_t SCH_Add_Task(void(* pFunc)(), unit32_t DELAY, unit32_t PERIOD){
    unit8_t newTaskIndex = 0;
    unit32_t sumDelay = 0;
    unit32_t newDelay = 0;
    for(newTaskIndex = 0; newTaskIndex < SCH_MAX_TASKS; newTaskIndex++){
        sumDelay = sumDelay + SCH_tasks_G[newTaskIndex].Delay;
        if(sumDelay > DELAY){
            newDelay = DELAY - (sumDelay - SCH_task_G[newTaskIndex].Delay);
            SCH_task_G[newTaskIndex].Delay = sumDelay - DELAY;
            for(uint8_t i = SCH_MAX_TASKS -1;i > newTaskIndex; i--){
                SCH_task_G[i].pTask = SCH_task_G[i-1].pTask;
                SCH_task_G[i].Period = SCH_task_G[i-1].Period;
                SCH_task_G[i].Delay = SCH_task_G[i-1].Delay;
                SCH_task_G[i].TaskID = SCH_task_G[i-1].TaskID;
            }
            SCH_task_G[newTaskIndex].pTask = pFunc;
            SCH_task_G[newTaskIndex].Delay = newDelay;
            SCH_task_G[newTaskIndex].Period = PERIOD;

            if(SCH_task_G[newTaskIndex].Delay == 0){
                SCH_task_G[newTaskIndex].RunME = 1;
            }
            else{
                SCH_task_G[newTaskIndex].RunME = 0;
            }
            SCH_task_G[newTaskIndex].TaskID = Get_New_Task_ID();
            return SCH_task_G[newTaskIndex].TaskID;
        }
        else{
            if(SCH_task_G[newTaskIndex].pTask == 0x0000){
                SCH_task_G[newTaskIndex].pTask = pFunc;
                SCH_task_G[newTaskIndex].Delay = DELAY - sumDelay;
                SCH_task_G[newTaskIndex].Period = PERIOD;
                if(SCH_task_G[newTaskIndex].Delay ==0){
                    SCH_task_G[newTaskIndex].RunMe =1;
                }
                else{
                    SCH_task_G[newTaskIndex].RunMe =0;
                }
                SCH_task_G[newTaskIndex].TaskID = Get_New_Task_ID();
                return SCH_task_G[newTaskIndex].TaskID;
            }
        }
    }
    return SCH_task_G[newTaskIndex].TaskID;
}

unit8_t SCH_Delete_Task(unit32_t taskID){
    unit8_t Return_code = 0;
    unit8_t taskIndex;
    unit8_t j;

    if(taskID != NO_TASK_ID){
        for (taskIndex ==0 ; taskIndex < SCH_MAX_TASKS; taskIndex++){
            if(SCH_task_G[taskIndex].TaskID == taskID){
                Return_code = 1;
                if(taskIndex != 0 && taskIndex < SCH_MAX_TASKS-1){
                    if(SCH_task_G[taskIndex+1].pTask != 0x0000){
                        SCH_task_G[taskIndex+1].Delay += SCH_task_G[taskIndex].Delay;
                    }
                }
                for(j = taskIndex; j <SCH_MAX_TASKS -1;j++){
                    SCH_task_G[j].pTask = SCH_task_G[j+1].pTask;
                    SCH_task_G[j].Period = SCH_task_G[j+1].Period;
                    SCH_task_G[j].Delay = SCH_task_G[j+1].Delay;
                    SCH_task_G[j].RunMe = SCH_task_G[j+1].RunMe;
                    SCH_task_G[j].TaskID = SCH_task_G[j+1].TaskID;
                }
                SCH_task_G[j].pTask = 0;
                SCH_task_G[j].Period = 0;
                SCH_task_G[j].Delay = 0;
                SCH_task_G[j].RunMe = 0;
                SCH_task_G[j].TaskID = 0;
                return Return_code = 0;
            }

        }

    }
    return Return_code; //return status
}

void SCH_Dispatch_Task(void){
    if(SCH_task_G[0].RunMe>0){
        (*SCH_task_G[0].pTask)(); //Run the task
        SCH_task_G[0].RunMe = 0; //Reset RunMe
        sTask temtask = SCH_task_G[0];
        SCH_Delete_Task(temtask.TaskID);
        if(temtask.Period !=0){
            SCH_Add_Task(temtask.pTask, temtask.Period,temtask.Period);
        }
    }
}

//INIT TIMER_10ms
static void TIMER_Init(){
    cli(); //Disable interupt

    /*Reset Timer/counter1*/
    TCCR1A = 0;
    TCCC1B = 0;
    TIMSK = 0;

    /*Set up timer/counter 1*/
    TCC1B != (1 << CS11)| (1 << CS10); //Prescale = 64
    TCNT1 = CONTER_START;
    TIMSK1 = (1<<TOIE1); // Overflow interupt enable
    sei(); //Enable interupt
}

ISR (TIMER_OVF_vect){
    TCNT1 = CONTER_START;
    SCH_Update();
}

static unit32_t Get_New_Task_ID(void){
    newTaskID++;
    if(newTaskID == NO_TASK_ID){
        newTaskID++;
    }
    return newTaskID;
}

#ifdef __cplusplus
)
#endif
