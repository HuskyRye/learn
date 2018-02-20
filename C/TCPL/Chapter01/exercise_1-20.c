#include <stdio.h>

#define TABINC 8

int main()
{
    int c;
    int pos = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            for (int j = TABINC - pos % TABINC; j > 0; --j) {
                putchar(' ');
                ++pos;
            }
        } else if (c == '\n') {
            putchar(c);
            pos = 0;
        } else {
            putchar(c);
            ++pos;
        }
    }
    return 0;
}
