#include <stdio.h>
#define MAXLINE 1000 

int atoi(char s[]);

int main()
{
	char s[] = "132456";
	printf("atoi(\"132456\") = %d", atoi(s));
}

int atoi(char s[])
{
	int i;
	int n = 0;
	for(i = 0; isdigit(s[i]); ++i)
	{
		n = n * 10 + (s[i] - '0');
	}
	return n;
}
