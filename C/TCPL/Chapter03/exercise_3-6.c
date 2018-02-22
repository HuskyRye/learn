/*
	Date: 2018.2.22
	Author: 刘臣轩
*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itoa(int n, char s[], int w);
void reverse(char s[]);

int main()
{
    char s[100];

    itoa(0, s, 5);
    printf("itoa(0, s, 5), %s\n", s);

    itoa(123, s, 5);
    printf("itoa(123, s, 5), %s\n", s);

    itoa(INT_MAX, s, 5);
    printf("itoa(INT_MAX, s, 5), %s\n", s);

    itoa(-123, s, 5);
    printf("itoa(-123, s, 5), %s\n", s);

    itoa(INT_MIN, s, 5);
    printf("itoa(INT_MIN, s, 5), %s\n", s);

    return 0;
}

/* convert n to characters in s, w characters wide */
void itoa(int n, char s[], int w)
{
    int sign = n;
    int i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sign < 0)
        s[i++] = '-';
    while (i < w)
        s[i++] = ' ';
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
