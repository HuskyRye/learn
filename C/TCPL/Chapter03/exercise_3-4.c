/*
	Date: 2018.2.22
	Author: 刘臣轩
*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
    printf("%d", -128 % 10);
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
    int sign = n;
    int i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int temp;
    for (int i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
