/*
	Date: 2018.3.17
	Author: 刘臣轩
*/

#include <assert.h>
#include <stdio.h>

int leftmost_one(unsigned x);

int main()
{
    assert(leftmost_one(0xFF00) == 0x8000);
    assert(leftmost_one(0x6600) == 0x4000);
    return 0;
}

int leftmost_one(unsigned x)
{
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);
    return x ^ (x >> 1);
}
