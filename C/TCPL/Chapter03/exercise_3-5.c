/*
	Date: 2018.2.22
	Author: 刘臣轩
*/

#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
    char s[100];

    itob(5, s, 2);
    printf("itob(5, s, 2), %s\n", s);

    itob(15, s, 8);
    printf("itob(15, s, 8), %s\n", s);

    itob(172, s, 16);
    printf("itob(172, s, 16), %s\n", s);

    itob(-55, s, 2);
    printf("itob(-55, s, 2), %s\n", s);

    return 0;
}

/* convert n to characters in s - base b */
void itob(int n, char s[], int b)
{
    int sign;
    if ((sign = n) < 0)
        n = -n;
    int i = 0;
    int j;
    do {
        j = n % b;
        s[i++] = (j <= 9) ? j + '0' : j + 'A' - 10;
    } while ((n /= b) > 0);
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
