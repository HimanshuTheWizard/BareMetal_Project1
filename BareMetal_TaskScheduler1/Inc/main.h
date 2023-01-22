#ifndef MAIN_H_
#define MAIN_H_

#include "led.h"

/*---------SRAM AND STACK LAYOUT---------*/
#define MAX_TASKS_COUNT				(4)
#define SIZE_OF_TASK_STACK			(1024U)
#define SIZE_OF_SCHEDULER_STACK		(1024U)

#define START_OF_SRAM				(0x20000000U)
#define SIZE_OF_SRAM				((192)*(1024))
#define END_OF_SRAM					((START_OF_SRAM) + (SIZE_OF_SRAM))

#define TASK1_STACK_START			(END_OF_SRAM)
#define TASK2_STACK_START			((END_OF_SRAM) + 1*(SIZE_OF_TASK_STACK))
#define TASK3_STACK_START			((END_OF_SRAM) + 2*(SIZE_OF_TASK_STACK))
#define TASK4_STACK_START			((END_OF_SRAM) + 3*(SIZE_OF_TASK_STACK))
#define SCHEDULER_STACK_START		((END_OF_SRAM) + 4*(SIZE_OF_TASK_STACK))

/*---------CLOCK CONFIGURATION---------*/
#define HSI_CLOCK					(16000000)
#define SYSTICK_CLOCK				(HSI_CLOCK)
#define TICK_HZ						(1000)


#define BLOCKED_STATE 		(0x0U)
#define RUNNING_STATE		(0x1U)

/*---------USER TASK FUNCTION DECLARATION---------*/
void task1_handler(void);
void task2_handler(void);
void task3_handler(void);
void task4_handler(void);

void SysTick_Init(uint32_t count_val);
void Tasks_Stack_Init(void);
void Enable_Processor_Faults(void);
uint32_t Get_Current_Task_PSP(void);

__attribute__((naked)) void Scheduler_Stack_Init(uint32_t scheduler_stack_start);
__attribute__((naked)) void Switch_SP_to_PSP(void);


#endif /* MAIN_H_ */
