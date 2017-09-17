#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define abs(x) ((x) < 0 ? -(x) : (x))

void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; ++i, --j)
    {
        c = s[i], s[i] = s[j], s[j] = c;
    }
}

void itoa2(int n, char s[], int w)
{
    int i, sign;
    sign = n;
    i = 0;
    do
    {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sign < 0)
    {
        s[i++] = '-';
    }
    while (i < w)
    {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}

int main()
{
    char tmp[100] = {0};
    itoa2(-2147483648, tmp, 15);
    printf("tmp = %s\n", tmp);
    system("pause");
    return 0;
}