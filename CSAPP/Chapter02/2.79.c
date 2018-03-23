/*
	Date: 2018.3.23
	Author: 刘臣轩
*/

#include <assert.h>
#include <stdio.h>

int mul3div4(int x);

int main()
{
    int x = 12345678;
    assert(mul3div4(x) == x * 3 / 4);
    return 0;
}

int mul3div4(int x)
{
    x = (x << 1) + x; // 3x
    // (x < 0 ? x + (1 << k) - 1 : x) >> k;
    int shift = (sizeof(int) << 3) - 1;
    int x_msb = (unsigned)x >> shift;
    return (x + (x_msb << 2) - x_msb) >> 2;
}
