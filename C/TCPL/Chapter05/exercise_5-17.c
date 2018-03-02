/*
	Date: 2018.3.2
	Author: LiuChenxuan
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 500

#define NUME 1 /* numeric sort */
#define DECR 2 /* sort in decreasing order */
#define FOLD 4 /* fold upper and lower cases */
#define DIRE 8 /* directory order */

int numcmp(char*, char*);
int charcmp(char*, char*);

void quicksort(void* lineptr[], int left, int right, int (*comp)(void*, void*));
int readlines(char* lineptr[], int nlines);
void writelines(char* lineptr[], int nlines, int decr);

void substr(char* s, char* t, int maxstr);

char option = 0;
int pos1 = 0;
int pos2 = 0;

int main(int argc, char* argv[])
{
    char* lineptr[MAXLINES];

    int c;
    while (--argc > 0 && ((c = (*(++argv))[0]) == '-' || c == '+')) {
        if (c == '-' && !isdigit(*(argv[0] + 1))) {
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
                    printf("Usage: srot [-n] [-r] [-f] [-d] [+pos1] [-pos2]\n");
                    return -1;
                }
            }
        } else if (c == '-')
            pos2 = atoi(argv[0] + 1);
        else if ((pos1 = atoi(argv[0] + 1)) < 0) {
            printf("Usage: srot [-n] [-r] [-f] [-d] [+pos1] [-pos2]\n");
            return -1;
        }
    }

    if (argc || pos1 > pos2)
        printf("Usage: srot [-n] [-r] [-f] [-d] [+pos1] [-pos2]\n");
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

#define MAXSTR 100

int numcmp(char* s1, char* s2)
{
    char str[MAXSTR];
    substr(s1, str, MAXSTR);
    double v1 = atof(str);
    substr(s2, str, MAXSTR);
    double v2 = atof(str);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

int charcmp(char* s1, char* s2)
{
    bool fold = (option & FOLD) ? true : false;
    bool dire = (option & DIRE) ? true : false;
    char a, b;

    int i = pos1;
    int j = pos1;
    int endpos;
    if (pos2 > 0)
        endpos = pos2;
    else if ((endpos = strlen(s1)) > strlen(s2))
        endpos = strlen(s2);
    do {
        if (dire) {
            while (i < endpos && !isalnum(s1[i]) && s1[i] != ' ' && s1[i] != '\0')
                ++i;
            while (j < endpos && !isalnum(s2[j]) && s2[j] != ' ' && s2[j] != '\0')
                ++j;
        }
        if (i < endpos && j < endpos) {
            a = fold ? tolower(s1[i]) : s1[i];
            ++i;
            b = fold ? tolower(s2[j]) : s2[j];
            ++j;
            if (a == b && a == '\0')
                return 0;
        }
    } while (a == b && i < endpos && j < endpos);
    return a - b;
}

void substr(char* s, char* str, int maxstr)
{
    int len = strlen(s);
    if (pos2 > 0 && len > pos2)
        len = pos2;
    else if (pos2 > 0 && len < pos2)
        printf("substr: string too short");
    int i, j;
    for (j = 0, i = pos1; i < len && j < maxstr - 1; ++i, ++j)
        str[j] = s[i];
    str[j] = '\0';
}
