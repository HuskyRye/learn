/*
	Date: 2018.3.12
	Author: 刘臣轩
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct key {
    char* word;
    int count;
} keytab[] = {
    { "auto", 0 },
    { "break", 0 },
    { "case", 0 },
    { "char", 0 },
    { "const", 0 },
    { "continue", 0 },
    { "default", 0 },
    { "unsigned", 0 },
    { "void", 0 },
    { "volatile", 0 },
    { "while", 0 },
};

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof(struct key))

int getword(char*, int);
int binsearch(char*, struct key*, int);

int main()
{
    int n;
    char word[MAXWORD];
    while (getword(word, MAXWORD) != EOF) {
        // printf("%s\thah\n", word);
        if (isalpha(word[0]))
            if ((n = binsearch(word, keytab, NKEYS)) >= 0)
                ++(keytab[n].count);
    }
    for (n = 0; n < NKEYS; ++n) {
        if (keytab[n].count > 0)
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
    }
    return 0;
}

int binsearch(char* word, struct key* tab, int n)
{
    int low = 0;
    int high = n - 1;
    int mid;
    int cond;
    while (low <= high) {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int getch();
void ungetch(int c);

int comment()
{
    int c;
    while ((c = getch() != EOF)) {
        if (c == '*') {
            if ((c = getch()) == '/')
                break;
            else
                ungetch(c);
        }
    }
    return c;
}

int getword(char* word, int lim)
{
    int c;
    char* w = word;
    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *(w++) = c;

    if (isalpha(c) || c == '_' || c == '#') {
        for (; --lim > 0; ++w) {
            *w = getch();
            if (!(isalnum(*w) || *w == '_')) {
                ungetch(*w);
                break;
            }
        }
    } else if (c == '\'' || c == '\"') {
        for (; --lim > 0; ++w) {
            *w = getch();
            if (*w == '\\')
                *(++w) = getch(); // one character
            else if (*w == c) {
                ++w;
                break;
            } else if (*w == EOF)
                break;
        }
    } else if (c == '/') {
        int d = getch();
        if (d == '*')
            comment();
        else
            ungetch(c);
    }
    *w = '\0';
    return c;
}

#define BUFLEN 100
char buf[BUFLEN];
int bufp = 0;

int getch()
{
    return (bufp == 0 ? getchar() : buf[--bufp]);
}
void ungetch(int c)
{
    if (bufp >= BUFLEN)
        printf("errro: too many characters for ungetch\n");
    else
        buf[bufp++] = c;
}
