/*
	Date: 2018.2.24
	Author: 刘臣轩
*/

#include <stdio.h>

int getfloat(float* pn);

int main()
{
    int i;
    float array[100];
    for (i = 0; i < 100 && getfloat(&array[i]) != EOF; ++i)
        ;
    for (int j = 0; j < i; ++j)
        printf("%g ", array[j]);
    putchar('\n');
    return 0;
}

#include <ctype.h>

int getch();
void ungetch(int);

/* get next floating-point number from input into *pn */
int getfloat(float* pn)
{
    int c;
    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '-' && c != '+' && c != '.') {
        ungetch(c);
        return 0;
    }
    int sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        int d = c;
        if (!isdigit(c = getch())) {
            if (c != EOF)
                ungetch(c);
            ungetch(d);
            return d;
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = (*pn) * 10 + (c - '0');
    if (c == '.')
        c = getch();
    int power = 1;
    for (; isdigit(c); c = getch()) {
        *pn = (*pn) * 10 + (c - '0');
        power *= 10;
    }
    *pn = *pn * sign / power;
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
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
