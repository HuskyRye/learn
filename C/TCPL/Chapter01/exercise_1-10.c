/*
	Date: 2018.2.19
	Author: 刘臣轩
*/

#include <stdio.h>

int main()
{
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\t')
            printf("\\t");
        else if (c == '\b')
            printf("\\b");
        else if (c == '\\')
            printf("\\\\");
        else
            putchar(c);
    }
}
