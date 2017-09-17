#include <stdio.h>

#define MAXLINE 1000 	//maximum input line size
#define LONGLINE 10	

int getline(char line[], int maxline);

/*print lines longer than LONGLINE*/
int main()
{
	int len;				//current line length
	char line[MAXLINE];		//current input line
	
	while((len = getline(line, MAXLINE)) > 0)
	{
		if(len > LONGLINE)
		{
			printf("longer than %d : %s", LONGLINE ,line);
		}
	}
	return 0;
}

/*getline函数：将一行读入到line中并返回其长度*/
int getline(char line[], int maxline)
{
	int c, i;
	for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
	{
		if(i < maxline - 2)
		{
			line[i] = c;	
		}	
	}
	if(c == '\n')
	{
		line[i] = c;
		++i;
	}	
	line[i] = '\0';
	return i-1;
} 
