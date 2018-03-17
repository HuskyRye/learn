/*
	Date: 2018.3.17
	Author: 刘臣轩
*/

#include <assert.h>
#include <stdio.h>

unsigned srl(unsigned x, int k);
int sra(int x, int k);

int main()
{
    unsigned uval = 0x1245678;
    int ival = 0x12345678;
    assert(srl(uval, 2) == uval >> 2);
    assert(sra(ival, 2) == ival >> 2);
    return 0;
}

unsigned srl(unsigned x, int k)
{
    unsigned xsra = (int)x >> k;
    int w = sizeof(int) << 3;
    unsigned mask = ~(-1 << (w - k));
    return mask & xsra;
}

int sra(int x, int k)
{
    int xsrl = (unsigned)x >> k;
    int w = sizeof(int) << 3;
    int sign = 1 << (w - k - 1) & xsrl;
    int mask = ~(sign - 1);
    return xsrl | mask;
}
