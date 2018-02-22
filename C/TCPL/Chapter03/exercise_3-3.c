/*
	Date: 2018.2.22
	Author: 刘臣轩
*/

#include "stdio.h"

#define MAXLINE 1000

void expand(char s1[], char s2[]);
int get_line(char line[], int maxline);

int main()
{
    char line[MAXLINE];
    char s[MAXLINE];
    while (get_line(line, MAXLINE) > 0) {
        expand(line, s);
        printf("%s", s);
    }
    return 0;
}

/* expand shorthand notation in s1 into string s2 */
void expand(char s1[], char s2[])
{
    int c;
    int i = 0;
    int j = 0;
    while ((c = s1[i++]) != '\0') {
        if (s1[i] == '-' && c < s1[i + 1]) {
            ++i;
            while (c < s1[i])
                s2[j++] = c++;
        } else
            s2[j++] = c;
    }
    s2[j] = '\0';
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
