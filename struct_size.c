#include <stdio.h>
#include <stdint.h>
typedef struct A{
	char a;
	char b;
	long c;
}structA;

void main(void)
{
//	structA *p;
//	p= (structA *)0x0;
//	printf("a addr=%d\tb addr=%d\t c addr=%d\n",(int)&(p->a),(int)&(p->b),(int)&(p->c));
//	printf("p+1 addr=%d\n",++p);
//	printf("a addr=%d\tb addr=%d\t c addr=%d\n",(int)&(p->a),(int)&(p->b),(int)&(p->c));
//	printf("structA byte size =%d \n",(int)sizeof(structA));
	int a[4]={1,2,3,4};
	int b[4]={5,6,7,8};
	int *ptr1,*ptr2;
	ptr1=(int *)(&a+1);
	//int d=(int)a+4;
	intptr_t d=(uintptr_t)a+4;
	ptr2=(int *)d;
	int *c=(a+1);
	printf("%x,%x,%x\n",ptr1,ptr2,c);
	printf("%p,%p,%p\n",ptr1,ptr2,c);
	printf("%x,%x,%x\n",*ptr1,*ptr2,*c);
	*ptr1 =9;
	*ptr2=10;
	printf("%d,%d,%d\n",*ptr1,*ptr2,*c);

}
