#include <stdio.h>
#include <ctype.h>
#include "calc.h"

//获得下一个运算符或数值操作数
int getop(char s[])
{
    int i, c;
    static int lastc = 0;
    if (lastc == 0)
    {
        c = getch();
    }
    else
    {
        c = lastc;
        lastc = 0;
    }
    while ((s[0] = c) == ' ' || c =='\t')
        c = getch();
    s[1] = '\0';
    i = 0;
    if (islower(c))
    {
        while (islower(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if (c != EOF)
        {
            lastc = c;
        }
        if (strlen(s) > 1)
        {
            return NAME;
        }
        else
        {
            return c;
        }
    }
    if (!isdigit(c) && c!= '.' && c!= '-')
    {
        return c;
    }
    if (c == '-')
    {
        if (isdigit(c = getch()) || c == '.')
        {
            s[++i] = c;
        }
        else
        {
            if (c != EOF)
            {
                lastc = c;
            }
            return '-';
        }
    }
    if (isdigit(c))
    {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    if (c == '.')
    {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    s[i] = '\0';
    if (c != EOF)
    {
        lastc = c;
    }
    return NUMBER;
}
