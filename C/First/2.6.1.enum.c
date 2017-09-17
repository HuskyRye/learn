#include <stdio.h>
#define MAXLINE 1000

int getline(char s[], int lim);

int main()
{
	char line[MAXLINE];
	printf("getline = %d\n", getline(line , MAXLINE));
	
}

int getline(char s[], int lim)
{
	enum loop { NO, YES };
	enum loop okloop = YES;
	//enum loop { NO, YES } okloop = YES;
	int c;
	int i = 0;
	while(okloop == YES)
	{
		if(i >= lim - 1)
			okloop = NO;
		else if((c = getchar()) == EOF)
			okloop = NO;
		else if(c == '\n')
			okloop = NO;
		else
			s[i] = c;
			++i;
	}
	return i;
}

