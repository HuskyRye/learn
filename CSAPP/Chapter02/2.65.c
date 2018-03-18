/*
	Date: 2018.3.17
	Author: 刘臣轩
*/

#include <assert.h>
#include <stdio.h>

int odd_ones(unsigned x);

int main()
{
    assert(odd_ones(0) == 0);
    assert(odd_ones(2) == 1);
    assert(odd_ones(0x55555555) == 0);
    assert(odd_ones(0x7fffffff) == 1);
    return 0;
}

int odd_ones(unsigned x)
{
    x ^= (x >> 16);
    x ^= (x >> 8);
    x ^= (x >> 4);
    x ^= (x >> 2);
    x ^= (x >> 1);
    return x & 1;
}
