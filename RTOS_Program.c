
#include"RTOS_Interface.h"
#include"../MCAL/Timer/Timer0_Interface.h"
#include "../HELPERS/Utils.h"

Tasks ArrOfTasks[MaxTasks]={{NULL_PTR}};



void RTOS_Init(void)
{
	/*Timer Init*/
	TIMER0_SetConfig();
	/*pass Scheduler to TimerCallBackFunction*/
	/* Set SysTick*/
	TIMER0_DelayMilliSeconds_without_Blocking(Scheduler,SYSTICK_MS);
}

void Scheduler(void)
{
	uint8 Count;
	for(Count=0;Count<MaxTasks;Count++)
	{
		if((ArrOfTasks[Count].PtrToFun!=NULL_PTR)&&(ArrOfTasks[Count].State!=SUSPEND))
		{
			if((ArrOfTasks[Count].FirstDelay)==0)
			{
				ArrOfTasks[Count].PtrToFun();
				ArrOfTasks[Count].FirstDelay=ArrOfTasks[Count].Peridicty-1;
			}
			else
			{
					ArrOfTasks[Count].FirstDelay--;
			}
		}
		else
		{
			/*Do Nothing*/
		}
	}
}

uint8 RTOS_CreateTask(void(*CFun)(void),uint32 CopyPeriodicty,uint8 priority,uint32 CopyFirstDelay)
{
	uint8 ReturnStatus=OK;
	if(ArrOfTasks[priority].PtrToFun==NULL_PTR)
	{
	 ArrOfTasks[priority].PtrToFun=CFun;
	 ArrOfTasks[priority].Peridicty=CopyPeriodicty;
	 ArrOfTasks[priority].State=RESUME;
	 ArrOfTasks[priority].FirstDelay=CopyFirstDelay;
	}
	else
	{
		/*not create Task*/
		ReturnStatus=NOK;
	}
	return ReturnStatus;
}
void RTOS_DeleteTask(uint8 priority)
{
	ArrOfTasks[priority].PtrToFun=NULL_PTR;
}
void RTOS_SuspendTask(uint8 priority)
{
	ArrOfTasks[priority].State=SUSPEND;
}
void RTOS_ResumeTask(uint8 priority)
{
	ArrOfTasks[priority].State=RESUME;
}
