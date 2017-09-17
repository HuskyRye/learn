#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int getint(int *pn)
{
    int c, sign, d;
    static int lastc = 0;
    if (lastc == 0)
    {
        c = getchar();
    }
    else
    {
        c = lastc;
        lastc = 0;
    }
    while ((s[0] = c) == ' ' || c =='\t')
        c = getchar();
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        lastc = c;
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        d = c;
        if (!isdigit(c = getchar()))
        {
            if (c != EOF)
            {
                lastc = c;
            }
            return d;
        }
    }
    for (*pn = 0; isdigit(c); c = getchar())
    {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF)
    {
        lastc = c;
    }
    return c;
}

int getfloat(float *pn)
{
    int c, sign, lastc;
    float power;
    static int lastc = 0;

    if (lastc == 0)
    {
        c = getchar();
    }
    else
    {
        c = lastc;
        lastc = 0;
    }
    while ((s[0] = c) == ' ' || c =='\t')
        c = getchar();
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
    {
        lastc = c;
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        c = getchar();
    }
    for (*pn = 0.0; isdigit(c); c = getchar())
    {
        *pn = 10 * *pn + (c - '0');
    }
    if (c == '.')
    {
        c = getchar();
    }
    for (power = 1.0; isdigit(c); c = getchar())
    {
        *pn = 10 * *pn + (c - '0');
        power *= 10;
    }
    *pn *= sign / power;
    if (c != EOF)
    {
        lastc = c;
    }
    return c;

}