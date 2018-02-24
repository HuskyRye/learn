/*
	Date: 2018.2.21
	Author: 刘臣轩
*/

#include <stdio.h>

int htoi(char s[]);

int main()
{
    printf("htoi(\"0x0\") = %d\n", htoi("0x0"));
    printf("htoi(\"0X1\") = %d\n", htoi("0X1"));
    printf("htoi(\"A\") = %d\n", htoi("A"));
    printf("htoi(\"0xa\") = %d\n", htoi("0xa"));
    printf("htoi(\"0x12\") = %d\n", htoi("0x12"));
    printf("htoi(\"0x1A\") = %d\n", htoi("0x1A"));
    printf("htoi(\"0xEF12\") = %d\n", htoi("0xEF12"));
    return 0;
}

/* convert hexadecimal string s to interger */
int htoi(char s[])
{
    int i = 0;
    // ignore optional 0x or 0X
    if (s[i] == '0') {
        ++i;
        if (s[i] == 'x' || s[i] == 'X')
            ++i;
    }
    int n = 0;
    int hexdigit;
    while (s[i] != '\0') {
        if (s[i] >= '0' && s[i] <= '9')
            hexdigit = s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            hexdigit = s[i] - 'a' + 10;
        else if (s[i] >= 'A' && s[i] <= 'F')
            hexdigit = s[i] - 'A' + 10;
        else
            break;
        n = 16 * n + hexdigit;
        ++i;
    }
    return n;
}
