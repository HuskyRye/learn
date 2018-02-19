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
