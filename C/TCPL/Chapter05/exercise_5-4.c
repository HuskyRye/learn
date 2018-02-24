/*
	Date: 2018.2.24
	Author: 刘臣轩
*/

#include <stdio.h>
#include <string.h>

int strend(char* s, char* t);

int main()
{
    printf("strend(\"abc\", \"abc\") = %d\n", strend("abc", "abc"));
    printf("strend(\"abcdefg\", \"efg\") = %d\n", strend("abcdefg", "efg"));
    printf("strend(\"abcdefg\", \"123\") = %d\n", strend("abcdefg", "123"));
    printf("strend(\"efg\", \"abcdefg\") = %d\n", strend("efg", "abcdefg"));
    printf("strend(\"\", \"g\") = %d\n", strend("", "g"));
    return 0;
}

/* return 1 if string t occurs at the end of s */
int strend(char* s, char* t)
{
    char* bs = s;
    char* bt = t;
    while (*s)
        ++s;
    while (*t)
        ++t;
    while (*(s--) == *(t--) && s != bs && t != bt)
        ;
    if (*s == *t && t == bt && s != '\0')
        return 1;
    else
        return 0;
}
