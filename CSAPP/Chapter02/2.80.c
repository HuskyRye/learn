/*
	Date: 2018.3.23
	Author: 刘臣轩
*/

#include <assert.h>
#include <stdio.h>

int threeforths(int x);

int main()
{
    assert(threeforths(8) == 6);
    assert(threeforths(9) == 6);
    assert(threeforths(10) == 7);
    assert(threeforths(11) == 8);
    assert(threeforths(12) == 9);

    assert(threeforths(-8) == -6);
    assert(threeforths(-9) == -6);
    assert(threeforths(-10) == -7);
    assert(threeforths(-11) == -8);
    assert(threeforths(-12) == -9);
    return 0;
}

int threeforths(int x)
{
    // divide 4 first
    int shift = (sizeof(int) << 3) - 1;
    int x_msb = (unsigned)x >> shift;
    x = (x + (x_msb << 2) - x_msb) >> 2;
    // then multiple 3
    x = (x << 1) + x;
    return x;
}
