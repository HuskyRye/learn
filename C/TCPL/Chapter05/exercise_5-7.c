/*
	Date: 2018.2.24
	Author: 刘臣轩
*/

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXSTOR 5000

char* lineptr[MAXLINES];
char linestor[MAXSTOR];

int readlines(char* lineptr[], char* linestro, int maxlines);
void writelines(char* lineptr[], int nlines);

void quicksort(char* lineptr[], int left, int right);

int main()
{
    int nlines;
    if ((nlines = readlines(lineptr, linestor, MAXLINES)) >= 0) {
        quicksort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000
int get_line(char* line, int limits);

int readlines(char* lineptr[], char* linestor, int maxlines)
{
    char line[MAXLEN];
    char* p = linestor;
    char* linestop = linestor + MAXSTOR;

    int nlines = 0;
    int len;
    while ((len = get_line(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || p + len > linestop)
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    }
    return nlines;
}

void writelines(char* lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

void quicksort(char* lineptr[], int left, int right)
{
    if (left >= right)
        return;
    int i = left;
    int j = right;
    char* temp = lineptr[left];
    char* t;
    while (i != j) {
        while (strcmp(lineptr[j], temp) >= 0 && i < j)
            --j;
        while (strcmp(lineptr[i], temp) <= 0 && i < j)
            ++i;
        if (i < j) {
            t = lineptr[i];
            lineptr[i] = lineptr[j];
            lineptr[j] = t;
        }
    }
    lineptr[left] = lineptr[i];
    lineptr[i] = temp;

    quicksort(lineptr, left, i - 1);
    quicksort(lineptr, i + 1, right);
}

int get_line(char* line, int limits)
{
    int i, c;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < limits - 2)
            *(line++) = c;
    if (c == '\n') {
        *(line++) = c;
        ++i;
    }
    *line = '\0';
    return i;
}
