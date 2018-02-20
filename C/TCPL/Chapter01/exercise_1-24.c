/*
	Date: 2018.2.20
	Author: 刘臣轩
*/

#include <stdio.h>

void in_comment();
void in_quote(int c);

int main()
{
    int c;
    int brace = 0; // {}
    int brack = 0; // []
    int paren = 0; // ()
    while ((c = getchar()) != EOF) {
        if (c == '/' && (c = getchar()) == '*')
            in_comment();
        else if (c == '\'' || c == '\"')
            in_quote(c);
        else {
            if (c == '{')
                ++brace;
            else if (c == '}')
                --brace;
            else if (c == '[')
                ++brack;
            else if (c == ']')
                --brack;
            else if (c == '(')
                ++paren;
            else if (c == ')')
                --paren;
        }
        if (brace < 0)
            printf("Unbalanced braces\n");
        else if (brack < 0)
            printf("Unbalanced brackets\n");
        else if (paren < 0)
            printf("Unbalanced parentheses\n");
    }
    if (brace > 0)
        printf("Unbalanced braces\n");
    if (brack > 0)
        printf("Unbalanced brackets\n");
    if (paren > 0)
        printf("Unbalanced parentheses\n");
}

void in_comment()
{
    int c, d;
    c = getchar();
    d = getchar();
    while (c != '*' || d != '/') {
        c = d;
        d = getchar();
    }
}
void in_quote(int c)
{
    int d;
    while ((d = getchar()) != c)
        if (d == '\\')
            getchar();
}
