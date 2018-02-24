/*
	Date: 2018.2.24
	Author: 刘臣轩
*/

#include <stdio.h>

#pragma clang diagnostic ignored "-Wincompatible-library-redeclaration"

void strncpy(char* s, char* t, int n);
void strncat(char* s, char* t, int n);
int strncmp(char* s, char* t, int n);

int main()
{
    char s[100] = "abcdefghi";
    char t[] = "1234567";
    printf("char s[] = %s\n", s);
    printf("char t[] = %s\n", t);
    strncpy(s, t, 3);
    printf("strncpy(s, t, 3), %s\n", s);
    strncpy(s, t, 7);
    printf("strncpy(s, t, 7), %s\n", s);

    strncat(s, t, 3);
    printf("strncat(s, t, 3), %s\n", s);

    strncat(s, t, 7);
    printf("strncat(s, t, 7), %s\n", s);

    printf("strncmp(s, s, 3) = %d\n", strncmp(s, s, 3));
    printf("strncmp(s, t, 3) = %d\n", strncmp(s, t, 3));
    printf("strncmp(s, t, 10) = %d\n", strncmp(s, t, 10));

    return 0;
}

/* copy n characters from t to s */
void strncpy(char* s, char* t, int n)
{
    while (n-- > 0)
        *(s++) = *(t++);
    while (n-- > 0)
        *(s++) = '\0';
}

/* concatenate n characters of t to the end of s */
void strncat(char* s, char* t, int n)
{
    while (*s)
        ++s;
    strncpy(s, t, n);
}

/* compare at most n characters of t with s */
int strncmp(char* s, char* t, int n)
{
    for (; n-- > 0 && *s == *t; ++s, ++t)
        if (*s == '\0')
            return 0;

    return *s - *t;
}
