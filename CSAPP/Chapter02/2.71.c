/*
	Date: 2018.3.19
	Author: 刘臣轩
*/

#include <assert.h>
#include <stdio.h>

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum);

int main()
{
    assert(xbyte(0xA1B2C345, 0) == 0x00000045);
    assert(xbyte(0xA1B2C3D4, 1) == 0xFFFFFFC3);
    assert(xbyte(0xA1B2C3D4, 2) == 0xFFFFFFB2);
    assert(xbyte(0xA1B2C3D4, 3) == 0xFFFFFFA1);
    return 0;
}

int xbyte(packed_t word, int bytenum)
{
    int shift = (3 - bytenum) << 3;
    return (int)word << shift >> 24;
}
