#include <stdio.h>
#include "calc.h"

#define MAXVAL 100  //栈vol的最大深度

int sp = 0;         //下一个空闲的栈位置
double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
    {
        val[sp++] = f;
    }
    else
    {
        printf("error: stack full, can't push %g\n", f);
    }
}

double pop()
{
    if (sp > 0)
    {
        return val[--sp];
    }
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void clear()
{
    sp = 0;
}