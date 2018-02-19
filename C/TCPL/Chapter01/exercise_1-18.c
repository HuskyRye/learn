#include <stdio.h>
#include <string.h>
#define MAXLINE	1000

int get_line(char line[], int maxline);
int remove_blanks(char line[]);

int main()
{
	char line[MAXLINE];
	while (get_line(line, MAXLINE)) {
		if (remove_blanks(line) > 0)
			printf("%s", line);
	}
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

int remove_blanks(char line[]){
	int i = strlen(line);
	i -= 2;
	while(i >= 0 && (line[i] == ' ' || line[i] == '\t'))
		--i;
	if (i >= 0) {
		++i;
		line[i] = '\n';
		++i;
		line[i] = '\0';
	}
	return i;
}
