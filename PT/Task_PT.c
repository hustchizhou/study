#include "Task_PT.h"

struct pt task_pt;
extern timerCnt;
void TaskPt_Init(void)
{
	PT_INIT(&task_pt);
}

void TaskPt_Thread(void)
{
	static struct pt *pt=&task_pt;
	PT_BEGIN(pt);
	PT_WAIT_UNTIL(pt, timerCnt%3==0);
	printf("TaskPt is running\n");
	PT_END(pt);
}