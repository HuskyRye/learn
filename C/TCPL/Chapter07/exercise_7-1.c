/*
    Date: 2018.3.16
    Author: 刘臣轩
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int c;
    if (strcmp("lower", argv[0]) == 0)
        while ((c = getchar()) != EOF)
            putchar(tolower(c));
    else
        while ((c = getchar()) != EOF)
            putchar(toupper(c));
    return 0;
}