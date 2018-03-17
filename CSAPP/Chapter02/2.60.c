/*
	Date: 2018.3.17
	Author: 刘臣轩
*/

#include <assert.h>
#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b);

int main()
{
    assert(replace_byte(0x12345678, 2, 0XAB) == 0x12AB5678);
    assert(replace_byte(0x12345678, 0, 0XAB) == 0x123456AB);
    return 0;
}

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    unsigned mask = ~(0xFF << (i << 3));
    unsigned replace = b << (i << 3);
    return (x & mask) | replace;
}
