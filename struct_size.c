#include <stdio.h>
typedef struct A{
	char a;
	char b;
	long c;
}structA;

void main(void)
{
	structA *p;
	p= (structA *)0x0;
	printf("a addr=%d\tb addr=%d\t c addr=%d\n",(int)&(p->a),(int)&(p->b),(int)&(p->c));
	printf("p+1 addr=%d\n",++p);
	printf("a addr=%d\tb addr=%d\t c addr=%d\n",(int)&(p->a),(int)&(p->b),(int)&(p->c));
	printf("structA byte size =%d \n",(int)sizeof(structA));
}
