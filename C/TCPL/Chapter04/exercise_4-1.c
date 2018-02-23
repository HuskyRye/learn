/*
	Date: 2018.2.23
	Author: 刘臣轩
*/

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int strrindex(char s[], const char t[]);
int get_line(char line[], int maxline);

int main()
{
    char line[MAXLINE];
    const char pattern[] = "abc";
    while (get_line(line, MAXLINE) > 0)
        printf("%d\n", strrindex(line, pattern));
    return 0;
}

/* returns rightmost index of t in s, -1 if none*/
int strrindex(char s[], const char t[])
{
    int j, k;
    for (int i = strlen(s) - strlen(t); i >= 0; --i) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k)
            ;
        if (t[k] == '\0')
            return i;
    }
    return -1;
}

int get_line(char line[], int maxline)
{
    int i, j, c;
    for (i = 0, j = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < maxline - 2)
            line[j++] = c;
    if (c == '\n') {
        line[j++] = c;
        ++i;
    }
    line[j] = '\0';
    return i;
}
