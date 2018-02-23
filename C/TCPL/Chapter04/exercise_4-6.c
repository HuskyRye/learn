/*
	Date: 2018.2.23
	Author: 刘臣轩
*/

#include <math.h> // for fmod(), sin(), exp(), pow()
#include <stdio.h>
#include <stdlib.h> // for atof()
#include <string.h> // for strcmp()

#define MAXOP 100 // max size of operand or operator
#define NUMBER '0' // signal that a nubmer was found
#define NAME 'n' // signal that a name was found

int getop(char[]);
void push(double);
double pop();
void clear();
void mathfnc(char[]);

// Reverse Polish calculator
int main()
{
    int type;

    double op2, op3, v;
    char s[MAXOP];

    int var = 0;
    double variable[26] = { 0 };

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case NAME:
            mathfnc(s);
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
        case '=':
            pop();
            if (var >= 'A' && var <= 'Z')
                variable[var - 'A'] = pop();
            else
                printf("error: no variable name\n");
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
        case 'v':
            push(v);
            break;
        case '\n':
            v = pop();
            printf("\t%.8g\n", v);
            break;
        default:
            if (type >= 'A' && type <= 'Z')
                push(variable[type - 'A']);
            else
                printf("error: unknown command %s\n", s);
            break;
        }
        var = type;
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

/* check string s for supported math functions */
void mathfnc(char s[])
{
    double op2;
    if (strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if (strcmp(s, "pow") == 0) {
        op2 = pop();
        push(pow(pop(), op2));
    } else
        printf("error: %s not supported\n", s);
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
    s[1] = '\0';
    int i = 0;
    if (islower(c)) {
        while (islower(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if (c != EOF)
            ungetch(c);
        if (strlen(s) > 1)
            return NAME; // maybe a name
        else
            return c; // maybe a command
    }
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
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
