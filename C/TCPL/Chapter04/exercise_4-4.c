/*
	Date: 2018.2.23
	Author: 刘臣轩
*/

#include <math.h> // for fmod()
#include <stdio.h>
#include <stdlib.h> // for atof()

#define MAXOP 100 // max size of operand or operator
#define NUMBER '0' // signal that a nubmer was found

int getop(char[]);
void push(double);
double pop();

void clear();
// Reverse Polish calculator
int main()
{
    int type;
    double op2, op3;
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
            if (op2 != 0)
                push(pop() / op2);
            else
                printf("error: zero divisior\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0)
                push(fmod(pop(), op2));
            else
                printf("error: zero divisior\n");
            break;
        case '?':
            op2 = pop();
            printf("\t%.8g\n", op2);
            push(op2);
            break;
        case 'c':
            clear();
            break;
        case 'd':
            op2 = pop();
            push(op2);
            push(op2);
            break;
        case 's':
            op2 = pop();
            op3 = pop();
            push(op2);
            push(op3);
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

#define MAXVAL 100 // maximum depth of val stack

int sp = 0; // next free stack position
double val[MAXVAL]; // value stack

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop()
{
    if (sp > 0)
        return val[--sp];
    else
        printf("error: stack empty\n");
    return 0;
}

void clear()
{
    sp = 0;
}

#include <ctype.h>

int getch();
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    // s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    int i = 0;
    if (c == '-') {
        if (isdigit(c = getch()) || c == '.')
            s[++i] = c;
        else {
            if (c != EOF)
                ungetch(c);
            return '-';
        }
    }
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

#define BUFSIZE 100

char buf[BUFSIZE]; // buffer for ungetch
int bufp = 0;

// get a possibly pushed back character
int getch()
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

// push character back on input
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
