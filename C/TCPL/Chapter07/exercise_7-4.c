/*
    Date: 2018.4.24
    Author: 刘臣轩
*/

#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

#define LOCALFMT 100

void minscanf(char* fmt, ...);

int main()
{
    return 0;
}

void minscanf(char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);

    char localfmt[LOCALFMT];

    int* ival;
    unsigned* uval;
    double* dval;
    char* sval;

    int i = 0;
    for (char* p = fmt; *p; ++p) {
        if (*p != '%') {
            localfmt[i++] = *p;
            continue;
        }
        localfmt[i++] = '%';
        while (*(p+1) && !isaplha(*(p+1)))
            localfmt[i++] = *(++p);
        localfmt[i++] = *(p+1);
        localfmt[i] = '\0';
        switch (*(++p)) {
        case 'd':
        case 'i':
            ival = va_arg(ap, int*);
            scanf(localfmt, ival);
            break;
        case 'x':
        case 'o':
        case 'u':
            uval = va_arg(ap, unsigned*);
            scanf(localfmt, uval);
            break;
        case 'f':
        case 'e':
        case 'g':
            dval = va_arg(ap, double*);
            scanf(localfmt, dval);
            break;
        case 's':
            sval = va_arg(ap, char*);
            scanf(localfmt, sval);
            break;
        }
        i = 0;
    }
    va_end(ap);
}