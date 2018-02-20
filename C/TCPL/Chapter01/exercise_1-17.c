/*
	Date: 2018.2.19
	Author: 刘臣轩
*/

#include <stdio.h>
#define MAXLINE		1000
#define LONGLINE	80

int get_line(char line[], int maxline);

int main()
{
	int len;
	char line[MAXLINE];
	while ((len = get_line(line, MAXLINE)) > 0)
		if (len > LONGLINE)
			printf("%s", line);
	return 0;
}

int get_line(char line[], int maxline)
{
	int i, j, c;
	for (i = 0, j = 0; (c = getchar()) != EOF && c != '\n'; ++i)
		if (i < maxline - 2) {
			line[j] = c;
			++j;
		}
	if (c == '\n') {
		line[j] = c;
		++j;
		++i;
	}
	line[j] = '\0';
	return i;
}
