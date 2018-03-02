/*
	Date: 2018.3.1
	Author: 刘臣轩
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXLINES 5000
#define DEFLINES 10

int readlines(char* lineptr[], int nlines);
void writelines(char* linptr[], int nlines, int n);

char* lineptr[MAXLINES];

int main(int argc, char* argv[])
{
    int n;
    if (argc == 1)
        n = DEFLINES;
    else if (argc == 2 && argv[1][0] == '-')
        n = atoi(&argv[1][1]);
    else {
        printf("Usage: tail [-n]\n");
        return -1;
    }
    if (n < 1 || n > MAXLINES)
        n = DEFLINES;
    int nlines;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        writelines(lineptr, nlines, n);
        return 0;
    } else {
        printf("error: input too big\n");
        return 1;
    }
}

#include <string.h>

#define MAXLEN 1000
int get_line(char*, int);

int readlines(char* lineptr[], int maxlines)
{
    int nlines = 0;
    int len;
    char line[MAXLEN];
    char* p;
    while ((len = get_line(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = malloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writelines(char* linptr[], int nlines, int n)
{
    for (int i = (nlines - n > 0) ? (nlines - n) : 0; i < nlines; ++i)
        printf("%s\n", lineptr[i]);
}

int get_line(char* line, int limits)
{
    int i;
    int c;
    for (i = 0; i < limits - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}
