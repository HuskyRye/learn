#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
int myremove(char s[]);

int main()
{
	char line[MAXLINE];		//current input
	while(getline(line, MAXLINE) > 0)
		if(myremove(line) > 0)
			printf("\"%s\n", line);
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

/*remove函数：删掉空格及制表符，忽略空行*/
int myremove(char s[])
{
	int i;
	i = 0;
	while(s[i] != '\n')
		++i;
	--i;
	while(i >= 0 && (s[i] == ' ' || s[i] == '\t'))
		--i ;
	if(i >= 0)
	{
		++i;
		s[i] = '\"';
		++i;
		s[i] = '\0';
	}
	return i;
}

