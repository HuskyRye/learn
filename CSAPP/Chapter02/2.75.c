/*
	Date: 2018.3.22
	Author: 刘臣轩
*/

#include <assert.h>
#include <inttypes.h>
#include <stdio.h>

unsigned unsigned_high_prod(unsigned x, unsigned y);
unsigned unsigned_high_prod_good(unsigned x, unsigned y);

int main()
{
    int num = 0x12345678;
    assert(unsigned_high_prod(num, num) == unsigned_high_prod_good(num, num));
    return 0;
}
int signed_high_prod(int x, int y);

unsigned unsigned_high_prod(unsigned x, unsigned y)
{
    int shift = (sizeof(int) << 3) - 1;
    int x_msb = x >> shift;
    int y_msb = y >> shift;
    return signed_high_prod(x, y) + x_msb * y + y_msb * x;
}

unsigned unsigned_high_prod_good(unsigned x, unsigned y)
{
    uint64_t mul = (uint64_t)x * y;
    return mul >> 32;
}

int signed_high_prod(int x, int y)
{
    int64_t mul = (int64_t)x * y;
    return mul >> 32;
}
