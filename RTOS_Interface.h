#ifndef RTOS_INTERFACE_H
#define RTOS_INTERFACE_H

#include"../HELPERS/std_types.h"
#include"RTOS_Private.h"
#include "RTOS_Config.h"
uint8 RTOS_CreateTask(void(*CFun)(void),uint32 CopyPeriodicty,uint8 priority,uint32 CopyFirstDelay);
void RTOS_Init(void);
void Scheduler(void);
void RTOS_DeleteTask(uint8 priority);
void RTOS_SuspendTask(uint8 priority);
void RTOS_ResumeTask(uint8 priority);
#endif
