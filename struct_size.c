#include <stdio.h>
typedef struct A{
	char a;
	char b;
	long c;
}structA;

void main(void)
{
	structA p[10];
	//p= (structA *)0x0;
	printf("a addr=%x\tb addr=%x\t c addr=%x\n",&(p->a),&(p->b),&(p->c));
	printf("p[1] addr=%x\n",&p[1]);
	printf("structA byte size =%d \n",sizeof(structA));
	printf("hello world\n");
}
