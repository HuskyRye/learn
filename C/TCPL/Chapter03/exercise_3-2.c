/*
	Date: 2018.2.22
	Author: 刘臣轩
*/

#include <stdio.h>

#define MAXLINE 1000

void escape(char s[], char t[]);
void unescape(char s[], char t[]);
int get_line(char line[], int maxline);

int main()
{
    char line[MAXLINE];
    char s[MAXLINE];
    while (get_line(line, MAXLINE) > 0) {
        escape(s, line);
        printf("%s\n", s);
        unescape(s, s);
        printf("%s", s);
    }
}

/* expand newline and tab into visible sequences */
void escape(char s[], char t[])
{
    int j = 0;
    for (int i = 0; t[i] != '\0'; ++i) {
        switch (t[i]) {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        default:
            s[j++] = t[i];
            break;
        }
    }
    s[j] = '\0';
}

/* convert escape sequences int real characters */
void unescape(char s[], char t[])
{
    int j = 0;
    for (int i = 0; t[i] != '\0'; ++i) {
        if (t[i] == '\\') {
            switch (t[++i]) {
            case 'n':
                s[j++] = '\n';
                break;
            case 't':
                s[j++] = '\t';
                break;
            default:
                s[j++] = '\\';
                s[j++] = t[i];
                break;
            }
        } else
            s[j++] = t[i];
    }
    s[j] = '\0';
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
