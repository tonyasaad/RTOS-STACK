
typedef struct  Task
{
	void(*PtrToFun)(void);
	uint32 Peridicty;
	uint32 FirstDelay;
	uint8 State;
}Tasks;


#define SUSPEND 0
#define RESUME  1
#define OK  1
#define NOK 0


