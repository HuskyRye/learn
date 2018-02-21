/*
	Date: 2018.2.21
	Author: 刘臣轩
*/

#include <stdio.h>

unsigned int setbits(unsigned int x, int p, int n, unsigned int y);

int main()
{
    printf("setbits(0xFF, 4, 3, 0) = %u\n", setbits(0xFF, 4, 3, 0));
    return 0;
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
    return (x & ~(~(~0 << n) << (p - n + 1))) | ((y & ~(~0 << n)) << (p - n + 1));
}
