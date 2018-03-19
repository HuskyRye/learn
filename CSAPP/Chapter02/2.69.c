/*
	Date: 2018.3.19
	Author: 刘臣轩
*/

#include <assert.h>
#include <stdio.h>

unsigned rotate_left(unsigned x, int n);

int main()
{
    assert(rotate_left(0x12345678, 4) == 0x23456781);
    assert(rotate_left(0x12345678, 20) == 0x67812345);
    assert(rotate_left(0x12345678, 0) == 0x12345678);
    assert(rotate_left(0x12345678, 32) == 0x12345678);
    return 0;
}

unsigned rotate_left(unsigned x, int n)
{
    int w = sizeof(unsigned) << 3;
    unsigned upper = x << n;
    unsigned lower = x >> (w - n);
    return upper | lower;
}
