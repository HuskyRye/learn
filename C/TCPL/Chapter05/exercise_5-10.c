/*
	Date: 2018.2.28
	Author: 刘臣轩
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char s[]);
void push(double);
double pop();
void ungets(char[]);

int main(int argc, char* argv[])
{
    char s[MAXOP];
    double op2;
    while (--argc > 0) {
        ungets(" ");
        ungets(*(++argv));
        switch (getop(s)) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 == 0)
                printf("error: zero divisor\n");
            else
                push(pop() / op2);
            break;
        default:
            printf("error: unkown command %s\n", s);
            argc = 1;
            break;
        }
    }
    printf("\t%.8g\n", pop());
    return 0;
}

#include <ctype.h>

int getch();
void ungetch(int);

int getop(char s[])
{
    int c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    int i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double a)
{
    if (sp < MAXVAL)
        val[sp++] = a;
    else
        printf("error: stack full, can't push %g\n", a);
}
double pop()
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include <string.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch()
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
void ungets(char s[])
{
    for (int i = strlen(s) - 1; i >= 0; --i)
        ungetch(s[i]);
}
