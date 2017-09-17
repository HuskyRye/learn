#include <stdio.h>

int main()
{
	char c;
	while((c = getchar()) != EOF)
	//用CTRL + Z输入EOF，end of file，文件结束 
	{
		//printf("%d\n", c); 
		putchar(c);
	}
	printf("EOF = %d\n", EOF); 
	//见<stdio.h>
	return 0;
}
