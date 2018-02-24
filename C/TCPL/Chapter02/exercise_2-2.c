/*
	Date: 2018.2.21
	Author: 刘臣轩
*/

#include <stdio.h>

#define LIM 1000

enum loop { NO,
    YES };

int main()
{
    int c;
    char s[LIM];
    /*
    for (int i = 0; i < LIM - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
		s[i] = c;
	*/

    enum loop okloop = YES;
    int i = 0;
    while (okloop) {
        if (i >= LIM - 1)
            okloop = NO;
        else if ((c = getchar()) == '\n')
            okloop = NO;
        else if (c == EOF)
            okloop = NO;
        else {
            s[i] = c;
            ++i;
        }
    }
}
