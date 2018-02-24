/*
	Date: 2018.2.21
	Author: 刘臣轩
*/

#include <limits.h>
#include <stdio.h>

unsigned int rightrot(unsigned int x, int n);

int main()
{
    printf("rightrot(0xF0, 4) = %u\n", rightrot(0xF0, 4));
    printf("rightrot(0x0F, 4) = %u\n", rightrot(0x0F, 4));
    return 0;
}

unsigned int rightrot(unsigned int x, int n)
{
    /*
	unsigned int temp = (unsigned int)~0;
	int width;
	for (width = 1; (temp >>= 1) > 0; ++width)
		;
	*/
    int width = sizeof(unsigned int) * CHAR_BIT;
    if ((n = n % width) <= 0)
        return x;
    return ((x & ~(~0 << n)) << (width - n)) | (x >> n);
}
