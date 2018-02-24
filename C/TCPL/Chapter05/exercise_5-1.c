/*
	Date: 2018.2.24
	Author: 刘臣轩
*/

#include <stdio.h>

int getint(int* pn);

int main()
{
    int array[100];
    int i;
    for (i = 0; i < 100 && getint(&array[i]) != EOF; ++i)
        ;
    for (int j = 0; j < i; ++j)
        printf("%d ", array[j]);
    putchar('\n');
    return 0;
}

#include <ctype.h>

int getch();
void ungetch(int);

/* get next integer from input into *pn */
int getint(int* pn)
{
    int c;
    while ((isspace(c = getch())))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    int sign = (c == '-') ? -1 : 1;
    int d;
    if (c == '+' || c == '-') {
        d = c;
        if (!isdigit(c = getch())) {
            if (c != EOF)
                ungetch(c);
            ungetch(d);
            return d;
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * (*pn) + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch()
{
    return (bufp == 0) ? getchar() : buf[--bufp];
}

void ungetch(int c)
{
    if (bufp > BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
