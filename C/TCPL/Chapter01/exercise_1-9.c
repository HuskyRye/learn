/*
	Date: 2018.2.19
	Author: 刘臣轩
*/

#include <stdio.h>

int main()
{
    int c;
    int lastc = 'a';
    while ((c = getchar()) != EOF) {
        if (c != ' ' || lastc != ' ')
            putchar(c);
        lastc = c;
    }
}
