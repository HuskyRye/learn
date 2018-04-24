/*
    Date: 2018.4.24
    Author: 刘臣轩
*/

#include <stdio.h>
#include <stdarg.h>

#define LOCALFMT 100

void minprintf(char* fmt, ...);

int main()
{
    printf("%d\n", 123);
    minprintf("%d\n", 123);

    printf("%o\n", 123);
    minprintf("%o\n", 123);

    printf("%u\n", 123);
    minprintf("%u\n", 123);

    printf("%c\n", 'a');
    minprintf("%c\n", 'a');

    printf("%s\n", "abc");
    minprintf("%s\n", "abc");

    printf("%f\n", 123.45);
    minprintf("%f\n", 123.45);

    printf("%g\n", 0.000000123);
    minprintf("%g\n", 0.000000123);

    printf("%p\n", 0xabcd);
    minprintf("%p\n", 0xabcd);

    printf("%-15.10s\n", "hello, world");
    minprintf("%-15.10s\n", "hello, world");

    return 0;
}

void minprintf(char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);

    char* p;
    int i;
    char localfmt[LOCALFMT];

    int ival;
    unsigned uval;
    double dval;
    char* sval;
    void* vval;

    for (p = fmt; *p; ++p) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }

        i = 0;
        localfmt[i++] = '%';            /* %-0.0d */
        while (*(p+1) && !isalpha(*(p+1)))
            localfmt[i++] = *(++p);     /* collect chars */
        localfmt[i++] = *(p+1);         /* format letter */
        localfmt[i] = '\0';

        switch (*(++p)) {
        case 'd':
        case 'i':
        case 'c':
            ival = va_arg(ap, int);
            printf(localfmt, ival);
            break;
        case 'x':
        case 'X':
        case 'u':
        case 'o':
            uval = va_arg(ap, unsigned);
            printf(localfmt, uval);
            break;
        case 'f':
        case 'e':
        case 'E':
        case 'g':
        case 'G':
            dval = va_arg(ap, double);
            printf(localfmt, dval);
            break;
        case 's':
            sval = va_arg(ap, char*);
            printf(localfmt, sval);
            break;
        case 'p':
            vval = va_arg(ap, void*);
            printf(localfmt, vval);
            break;
        default:
            putchar(localfmt);
            break;
        }
    }
    va_end(ap);
}