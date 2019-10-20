#include <stdio.h>
#pragma pack()
typedef struct A{
	char a;
	int b;
	int c;
} structA;
#pragma pack()
typedef struct B{
	char a;
	char b;
	structA p1;
	char d;
} structB;

int main()
{
	structB *p2;
	structA *p1;
	p2 =(structB *)0x00000000;
	p1 =(structA *) &(p2->p1);
	printf("p2=0x%x,&p2.a=0x%x,&p2.b=0x%x,&p2.p1=0x%x,&p2.d=0x%x\n", p2, &p2->a,&p2->b,&p2->p1,&p2->d);
	//printf("p2.p1=0x%x\n",p1);
	printf("p1=0x%x,&p1.a=0x%x,&p1.b=0x%x,&p1.c=0x%x\n", p1,&p1->a,&p1->b,&p1->c);
	printf("sizeof(structA)= %d, sizeof(structB) = %d\n", sizeof(structA),sizeof(structB));
        return 0;
}
