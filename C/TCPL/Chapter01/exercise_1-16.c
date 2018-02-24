/*
	Date: 2018.2.19
	Author: 刘臣轩
*/

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char dst[], char src[]);

int main()
{
    char line[MAXLINE];
    char longest[MAXLINE];

    int max = 0;
    int len;
    while ((len = get_line(line, MAXLINE)) > 0) {
        printf("%d, %s", len, line);
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)
        printf("Longest line has %d characters:\n%s", max, longest);
    return 0;
}

/* keep recording the length even overflow */
int get_line(char line[], int maxline)
{
    int i, j, c;
    for (i = 0, j = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < maxline - 2) {
            line[j] = c;
            ++j;
        }
    if (c == '\n') {
        line[j] = '\n';
        ++j;
        ++i;
    }
    line[j] = '\0';
    return i;
}

void copy(char dst[], char src[])
{
    int i = 0;
    while ((dst[i] = src[i]) != '\0')
        ++i;
}
