# RTOS-STACK
IT'S an RTOS stack that I made from scratch. it can be used so simple like the shown example:  
/******************************************************************************************/
void task1(void){
	DIO_vTogglePin(PORTD_ID,0);
}

void task2(void){
	DIO_vTogglePin(PORTD_ID,1);
}

void main(void){

RTOS_Init();

RTOS_CreateTask(task1, 2000, 3, 0);
RTOS_CreateTask(task2, 1000, 4, 1);

while(1);

}
/********************************************************************************************/
