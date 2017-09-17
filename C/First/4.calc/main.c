#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100

int main()
{
    int type, var = 0;
    double op1, op2, v;
    char s[MAXOP];

    double variable[26] = {0.0};

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case NAME:
            mathfnc(s);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '*':
            push(pop() * pop());
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
            {
                push(pop() / op2);
            }
            else
            {
                printf("error: zero divisor\n");
            }
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
            {
                push(fmod(pop(), op2));
            }
            else
            {
                printf("error: zero divisor\n");
            }
            break;
        case '=':
            pop();
            if (var >= 'A' && var <= 'Z')
            {
                variable[var - 'A'] = pop();
            }
            else
            {
                printf("error: no variable name\n");
            }
            break;
        case '\n':
            v = pop();
            printf("\t%.8g\n", v);
            break;
        case '?':   /* print top element of the stack */
            op2 = pop();
            printf("\t%.8g\n", op2);
            push(op2);
            break;
        case 'c':
            clear();
            break;
        case 'd':   /* duplicate top element of the stack */
            op2 = pop();
            push(op2);
            push(op2);
            break;
        case 's':   /* swap the top two elements */
            op1 = pop();
            op2 = pop();
            push(op1);
            push(op2);
            break;
        default:
            if (type >= 'A' && type <= 'Z')
            {
                push(variable[type - 'A']);
            }
            else if (type == 'v')
            {
                push(v);
            }
            else
            {
                printf("error: unkown command %s\n", s);
            }
            break;
        }
        var = type;
    }
    return 0;
}