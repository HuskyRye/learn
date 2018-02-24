/*
	Date: 2018.2.24
	Author: 刘臣轩
*/

#include <stdio.h>

#pragma clang diagnostic ignored "-Wincompatible-library-redeclaration"

void strcat(char* s, char* t);

int main()
{
    char s[10] = "abc";
    char t[] = "123";
    strcat(s, t);
    printf("%s\n", s);
    return 0;
}

/* concatenate t to the end of s */
void strcat(char* s, char* t)
{
    while (*s)
        s++;
    while ((*s++ = *t++))
        ;
}
