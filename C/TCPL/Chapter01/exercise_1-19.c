#include <stdio.h>
#include <string.h>
#define MAXLINE	1000

int get_line(char line[], int maxline);
void reverse(char s[]);

int main()
{
	char line[MAXLINE];
	while (get_line(line, MAXLINE)) {
		reverse(line);
		printf("%s", line);
	}
	return 0;
}

int get_line(char line[], int maxline)
{
	int c, i, j;
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

void reverse(char s[])
{
	int i = 0;
	int j = strlen(s) - 2;
	char temp;
	while (i < j) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		++i;
		--j;
	}
}
