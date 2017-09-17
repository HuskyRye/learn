#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000 //进行排序的最大文本行数

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int mysort(char *linept[], int nlines);

int main()
{
    int nlines;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        mysort(lineptr, nlines);
        writelines(lineptr, nlines);
        system("pause");
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        system("pause");
        return -1;
    }
}

#define MAXLEN 1000
int getline(char *, int);

int readlines(char *lineptr[], int maxlines)
{
    int nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    /* while ((len = getline(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (p = malloc(len)) == NULL)
        {
            return -1;
        }
        else{
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    } */
    while (nlines < maxlines)
    {
        p = gets(line);
        if (p == NULL)
        {
            return nlines;
        }
        p = malloc(strlen(line) + 1);
        if (p == NULL)
        {
            return -1;
        }
        strcpy(p, line);
        lineptr[nlines++] = p;
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
    {
        printf("%s\n", *lineptr++);
    }
}

int mysort(char *linept[], int n)
{
    int i, j;
    char *tmp;
    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (strcmp(lineptr[i], lineptr[j]) > 0)
            {
                tmp = lineptr[i];
                lineptr[i] = lineptr[j];
                lineptr[j] = tmp;
            }
        }
    }
}