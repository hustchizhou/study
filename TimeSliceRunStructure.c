#include <stdio.h>
#include <signal.h>
#include <sys/time.h> //itmerval结构体的定义

#include "Task_PT.h"

unsigned int timerCnt=0;

//任务结构
typedef struct _TASK_COMPONENTS
{
	unsigned int Run;//程序运行标记：0不运行，1运行
	unsigned int Timer;//计时器
	unsigned int ItvTime;//任务运行间隔时间
	void (*TaskHook)(void);//要运行的任务函数
}TASK_COMPONENTS;
//定义任务清单,主要目的是定义TASKS_MAX的值
typedef enum _TASK_LIST
{
	TASK_DISP_CLOCK,
	TASK_KEY_SCAN,
	TASK_DISP_WS,
	TASKS_MAX
}TASK_LIST;
	//编写任务函数
void TaskDisplayClock(void)
{
			printf("TaskDisplayClock is running\n");
}
void TaskKeyScan(void)
{
			printf("TaskKeyScan is running\n");
}
void TaskDisplayWS(void)
{
			printf("TaskDisplayWS is running\n");
}

static TASK_COMPONENTS TaskComps[]=
{
	{0,1,1,TaskPt_Thread},
	{0,5,5,TaskKeyScan},	
	{0,1,1,TaskDisplayWS}
};

//任务标记处理
void TaskRemarks(void)
{
	unsigned int i;
	for(i=0;i<TASKS_MAX;i++)
	{
		if(TaskComps[i].Timer)
		{
			TaskComps[i].Timer--;
			if(TaskComps[i].Timer==0)
				{
					TaskComps[i].Timer = TaskComps[i].ItvTime;
					TaskComps[i].Run = 1;
				}
		}
	}
}
//任务处理
void TaskProcess(void)
{
	unsigned int i;
	for(i=0;i<TASKS_MAX;i++)
		{
			if(TaskComps[i].Run)
				{
					TaskComps[i].TaskHook();
					TaskComps[i].Run=0;
				}
		}
}

void set_time(struct itimerval *itv)
{
	itv->it_interval.tv_sec =1;
	itv->it_interval.tv_usec =0;
	itv->it_value.tv_sec=1;
	itv->it_value.tv_usec=0;
	setitimer(ITIMER_REAL,itv,NULL);
}

void alarm_handle(int sig)
{
	if(timerCnt==255)
		timerCnt=0;
	else
		timerCnt++;
	TaskRemarks();
}


int main(void)
{
	struct itimerval itv;
	signal(SIGALRM,alarm_handle);
	set_time(&itv);
	TaskPt_Init();
	while (1)
		{
			getitimer(ITIMER_REAL,&itv);
			TaskProcess();
		}
}
