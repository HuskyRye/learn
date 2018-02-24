/*
	Date: 2018.2.21
	Author: 刘臣轩
*/

#include <stdio.h>

int lower(int c);

int main()
{
    int c;
    while ((c = getchar()) != EOF)
        putchar(lower(c));
    return 0;
}

int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
