/*
	Date: 2018.3.2
	Author: LiuChenxuan
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAXLINES 500

#define NUME 1 /* numeric sort */
#define DECR 2 /* sort in decreasing order */
#define FOLD 4 /* fold upper and lower cases */
#define DIRE 8 /* directory order */

int numcmp(const char*, const char*);
int charcmp(const char*, const char*);

void quicksort(void* lineptr[], int left, int right, int (*comp)(void*, void*));
int readlines(char* lineptr[], int nlines);
void writelines(char* lineptr[], int nlines, int decr);

static char option = 0;

int main(int argc, char* argv[])
{
    char* lineptr[MAXLINES];

    int c;
    while (--argc > 0 && (*(++argv))[0] == '-') {
        while ((c = *++argv[0])) {
            switch (c) {
            case 'n':
                option |= NUME;
                break;
            case 'r':
                option |= DECR;
                break;
            case 'f':
                option |= FOLD;
                break;
            case 'd':
                option |= DIRE;
                break;
            default:
                printf("sort: illegal option %c\n", c);
                argc = 1;
                break;
            }
        }
    }

    if (argc)
        printf("Usage: srot [-n] [-r] [-f] [-d]\n");
    else {
        int nlines;
        if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
            if (option & NUME)
                quicksort((void**)lineptr, 0, nlines - 1, (int (*)(void*, void*))numcmp);
            else
                quicksort((void**)lineptr, 0, nlines - 1, (int (*)(void*, void*))charcmp);
            writelines(lineptr, nlines, option & DECR);
            return 0;
        } else {
            printf("input too big to sort\n");
            return -1;
        }
    }
}

#include <stdlib.h>
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

void writelines(char* linptr[], int nlines, int decr)
{
    if (decr) {
        for (int i = nlines - 1; i >= 0; --i)
            printf("%s\n", linptr[i]);
    } else {
        for (int i = 0; i < nlines; ++i)
            printf("%s\n", linptr[i]);
    }
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

void quicksort(void* lineptr[], int left, int right, int (*comp)(void*, void*))
{
    if (left > right)
        return;
    void* temp = lineptr[left];
    int i = left;
    int j = right;
    while (i != j) {
        while ((*comp)(lineptr[j], temp) >= 0 && i < j)
            --j;
        while ((*comp)(lineptr[i], temp) <= 0 && i < j)
            ++i;
        if (i < j) {
            void* p;
            p = lineptr[i];
            lineptr[i] = lineptr[j];
            lineptr[j] = p;
        }
    }
    lineptr[left] = lineptr[i];
    lineptr[i] = temp;
    quicksort(lineptr, left, i - 1, comp);
    quicksort(lineptr, i + 1, right, comp);
}

int numcmp(const char* s1, const char* s2)
{
    double v1 = atof(s1);
    double v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

#include <ctype.h>

int charcmp(const char* s1, const char* s2)
{
    bool fold = (option & FOLD) ? true : false;
    bool dire = (option & DIRE) ? true : false;
    char a, b;
    do {
        if (dire) {
            while (!isalnum(*s1) && *s1 != ' ' && *s1 != '\0')
                ++s1;
            while (!isalnum(*s2) && *s2 != ' ' && *s2 != '\0')
                ++s2;
        }
        a = fold ? tolower(*s1) : *s1;
        ++s1;
        b = fold ? tolower(*s2) : *s2;
        ++s2;
        if (a == b && a == '\0')
            return 0;
    } while (a == b);
    return a - b;
}
