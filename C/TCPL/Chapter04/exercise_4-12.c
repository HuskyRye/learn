/*
	Date: 2018.2.23
	Author: 刘臣轩
*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void itoa(int n, char s[]);

int main()
{
    char s[100];

    itoa(0, s);
    printf("itoa(0, s), %s\n", s);

    itoa(123, s);
    printf("itoa(123, s), %s\n", s);

    itoa(INT_MAX, s);
    printf("itoa(INT_MAX, s), %s\n", s);

    itoa(-123, s);
    printf("itoa(-123, s), %s\n", s);

    itoa(INT_MIN, s);
    printf("itoa(INT_MIN, s), %s\n", s);

    return 0;
}

/* convert n to characters in s */
void itoa(int n, char s[])
{
    static int i;
    if (n / 10)
        itoa(n / 10, s);
    else {
        i = 0;
        if (n < 0)
            s[i++] = '-';
    }
    s[i++] = abs(n % 10) + '0';
    s[i] = '\0';
}
