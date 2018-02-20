/*
	Date: 2018.2.19
	Author: 刘臣轩
*/

#include <stdio.h>

int main()
{
    int c;
    int nb = 0;
    int nt = 0;
    int nl = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++nb;
        else if (c == '\t')
            ++nt;
        else if (c == '\n')
            ++nl;
    }
    printf("Blanks is %d, tabs is %d, newlines is %d\n", nb, nt, nl);
}
