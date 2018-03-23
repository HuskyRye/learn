/*
	Date: 2018.3.22
	Author: 刘臣轩
*/

#include <assert.h>
#include <stdio.h>

int divide_power2(int x, int k);

int main()
{
    int x = 0x12345678;
    assert(divide_power2(x, 1) == x / 2);
    assert(divide_power2(x, 2) == x / 4);
    assert(divide_power2(x, 3) == x / 8);
    assert(divide_power2(x, 4) == x / 16);
    return 0;
}

int divide_power2(int x, int k)
{
    // return (x < 0 ? x + (1 << k) - 1 : x) >> k;
    int shift = (sizeof(int) << 3) - 1;
    int x_msb = (unsigned)x >> shift;
    return (x + (x_msb << k) - x_msb) >> k;
}
