/*
	Date: 2018.3.19
	Author: 刘臣轩
*/

#include <assert.h>
#include <stdio.h>

int fits_bits(int x, int n);

int main()
{
    assert(fits_bits(0x7F, 8) == 1);
    assert(fits_bits(0xFF, 8) == 0);
    assert(fits_bits(0xFFFFFF80, 8) == 1);
    assert(fits_bits(0xFFFFFF00, 8) == 0);
    return 0;
}

int fits_bits(int x, int n)
{
    x >>= (n - 1);
    return !x || !(~x);
}
