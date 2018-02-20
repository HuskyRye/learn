/*
	Date: 2018.2.20
	Author: 刘臣轩
*/

#include <stdio.h>

void in_comment();
void in_quote(int c);

int main()
{
    int c, d;
    while ((c = getchar()) != EOF) {
        if (c == '/') {
            if ((d = getchar()) == '*')
                in_comment();
            else {
                putchar(c);
                putchar(d);
            }
        } else if (c == '\"' || c == '\'')
            in_quote(c);
        else
            putchar(c);
    }
    return 0;
}

void in_comment()
{
    int c = getchar();
    int d = getchar();
    while (c != '*' || d != '/') {
        c = d;
        d = getchar();
    }
}

void in_quote(int c)
{
    int d;
    putchar(c);
    while ((d = getchar()) != c) {
        putchar(d);
        if (d == '\\')
            putchar(getchar());
    }
    putchar(d);
}
