/*
	Date: 2018.2.20
	Author: 刘臣轩
*/

#include <stdio.h>

#define TABINC 8

int main()
{
    int c;
    int pos = 0;
    int nb = 0;
    int nt = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++pos;
            if (pos % TABINC != 0)
                ++nb;
            else {
                nb = 0;
                ++nt;
            }
        } else {
            for (; nt > 0; --nt)
                putchar('\t');
            if (c == '\t')
                nb = 0;
            for (; nb > 0; --nb)
                putchar(' ');
            putchar(c);
            if (c == '\n')
                pos = 0;
            else if (c == '\t')
                pos += TABINC - pos % TABINC;
            else
                ++pos;
        }
    }
    return 0;
}
