#include <stdio.h>

int strlen(char s[]);

int main()
{
	printf("strlen = %d\n", strlen("hello"));
}

int strlen(char s[])
{
	int i = 0;
	while(s[i] != '\0')
	{
		++i;
	}
	return i;
}
