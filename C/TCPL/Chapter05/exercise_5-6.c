/*
	Date: 2018.2.24
	Author: 刘臣轩
*/

#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int get_line(char* line, int maxline);
int atoi(char* s);
void itoa(int n, char* s);
void reverse(char* s);
int strindex(char* s, char* t);

#define NUMBER '0'

int getop(char* s);

int main()
{
    char s[MAXLINE];
    while (get_line(s, MAXLINE) > 0)
        printf("%s", s);

    printf("atoi(\"0\") = %d\n", atoi("0"));
    printf("atoi(\"123\") = %d\n", atoi("123"));
    printf("atoi(\"+123\") = %d\n", atoi("+123"));
    printf("atoi(\"-123\") = %d\n", atoi("-123"));

    char a[100];
    itoa(0, a);
    printf("itoa(0, a), %s\n", a);
    itoa(123, a);
    printf("itoa(123, a), %s\n", a);
    itoa(INT_MAX, a);
    printf("itoa(INT_MAX, a), %s\n", a);
    itoa(-123, a);
    printf("itoa(-123, a), %s\n", a);
    itoa(INT_MIN, a);
    printf("itoa(INT_MIN, a), %s\n", a);

    printf("strindex(\"abc\", \"abc\") = %d\n", strindex("abc", "abc"));
    printf("strindex(\"abc\", \"123\") = %d\n", strindex("abc", "123"));
    printf("strindex(\"1abc\", \"abc\") = %d\n", strindex("1abc", "abc"));

    if (getop(s) == NUMBER)
        printf("%d\n", atoi(s));

    return 0;
}

/* read a line into s, return length */
int get_line(char* line, int maxline)
{
    int c, i;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < maxline - 2)
            *(line++) = c;
    if (c == '\n') {
        *(line++) = c;
        ++i;
    }
    *line = '\0';
    return i;
}

/* convert s to integer */
int atoi(char* s)
{
    while (isspace(*s))
        ++s;
    int sign = (*s == '-') ? -1 : 1;
    if (*s == '-' || *s == '+')
        ++s;
    int val = 0;
    while (isdigit(*s)) {
        val = val * 10 + (*s - '0');
        ++s;
    }
    return val * sign;
}

inline int abs(int x)
{
    return (x < 0) ? -x : x;
}

/* convert n to characters in s */
void itoa(int n, char* s)
{
    char* t = s;
    int sign = n;
    do {
        *(s++) = abs(n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sign < 0)
        *(s++) = '-';
    *s = '\0';
    reverse(t);
}

/* reverse string s in place */
void reverse(char* s)
{
    int c;
    for (char* t = s + strlen(s) - 1; s < t; ++s, --t) {
        c = *s;
        *s = *t;
        *t = c;
    }
}

/* return index of t in s, -1 if none */
int strindex(char* s, char* t)
{
    char* sb = s;
    char* p;
    char* q;
    for (; *s != '\0'; ++s) {
        for (p = s, q = t; *q != '\0' && *p == *q; ++p, ++q)
            ;
        if (q > t && *q == '\0')
            return s - sb;
    }
    return -1;
}

int getch();
void ungetch(int);

int getop(char* s)
{
    int c;
    while ((*s = c = getch()) == ' ' || c == '\t')
        ;
    *(s + 1) = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    if (isdigit(c))
        while (isdigit(*(++s) = c = getch()))
            ;
    if (c == '.')
        while (isdigit(*(++s) = c = getch()))
            ;
    *s = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch()
{
    return (bufp == 0) ? getchar() : buf[--bufp];
}
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
