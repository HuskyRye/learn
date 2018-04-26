/*
    Date: 2018.4.26
    Author: 刘臣轩
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop();

int main()
{
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
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
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %gn\n", f);
}

double pop()
{
    return (sp == 0 ? 0.0 : val[--sp]);
}

#include <ctype.h>

int getop(char s[])
{
    int c;
    while ((c = getchar()) != EOF) {
        s[0] = c;
        if (c != ' ' && c != '\t')
            break;
    }
    s[1] = '\0';
    if (c == EOF)
        return EOF;
    else if (!isdigit(c))
        return c;
    else {
        double f;
        ungetc(c, stdin);
        scanf("%f", &f);
        sprintf(s, "%f", f);
        return NUMBER;
    }
}