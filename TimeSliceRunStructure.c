#include <stdio.h>
#include <signal.h>
#include <sys/time.h> //itmerval�ṹ��Ķ���

#include "Task_PT.h"

unsigned int timerCnt=0;

//����ṹ
typedef struct _TASK_COMPONENTS
{
	unsigned int Run;//�������б�ǣ�0�����У�1����
	unsigned int Timer;//��ʱ��
	unsigned int ItvTime;//�������м��ʱ��
	void (*TaskHook)(void);//Ҫ���е�������
}TASK_COMPONENTS;
//���������嵥,��ҪĿ���Ƕ���TASKS_MAX��ֵ
typedef enum _TASK_LIST
{
	TASK_DISP_CLOCK,
	TASK_KEY_SCAN,
	TASK_DISP_WS,
	TASKS_MAX
}TASK_LIST;
	//��д������
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

//�����Ǵ���
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
//������
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
