#include <stdio.h>

int main()
{
	char s1[]="hello";
	char *s2;
	unsigned int len;
	len =sizeof(s1);
	s2=(char *) malloc(len);
	printf("len=0x%x\n",len);
	printf("s2=0x%x\n",s2);
	
	s2 +=len;

	printf("s2=0x%x\n",s2);
	while(len)
	{
		s2--;
		len--;
		*s2 = s1[len];
		printf("s2[%d]=%c\n",len,*s2);
	}
        printf("modified in different line of branch dev\n");
	printf("s1=%s\n",s1);
	printf("s2=0x%x\n",s2);
	printf("s2=%s\n",s2);
        printf("modified in master branch\n");
        printf("modified in branch dev\n");
	return 0;
}
