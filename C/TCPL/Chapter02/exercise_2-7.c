/*
	Date: 2018.2.21
	Author: 刘臣轩
*/

#include <stdio.h>

unsigned int invert(unsigned int x, int p, int n);

int main()
{
    printf("invert(0xFF, 4, 3) = %u\n", invert(0xFF, 4, 3));
    return 0;
}

unsigned int invert(unsigned int x, int p, int n)
{
    return x ^ (~(~0 << n) << (p - n + 1));
}
