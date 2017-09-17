#include <stdio.h>
#define MAXLINE 100

int getline();
void copy();

int max;				// 目前为止发现的最长行的长度 
char line[MAXLINE];		//当前的输入行 
char longest[MAXLINE];	//最长的行 

int main()
{
	int len;				//当前行长度
	extern int max;			//在每个需要访问外部变量的函数中，必须声明相应的外部变量，说明其类型
	extern char longest[];
	 
	max = 0;
	while((len = getline()) > 0)
	{
		printf("len = %d\n", len);
		if(len > max)
		{
			max = len;
			copy();	
		}	
	} 
	if(max > 0)
	{
		printf("max = %d, %s", max, longest);
	}
	return 0;
}

/*getline函数：将一行读入到line中并返回其长度*/
int getline()
{
	
	int c, i;
	extern char line[];
	
	for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
	{
		if(i < MAXLINE - 2)
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

/*copy函数，将line复制到longest*/
void copy()
{
	int i;
	extern char line[], longest[];
	i = 0;
	while((longest[i] = line [i]) != '\0')
		++i;
}

