/*
	Date: 2018.3.17
	Author: 刘臣轩
*/

#include <assert.h>
#include <stdio.h>

int main()
{
    unsigned x = 0x89ABCDEF;
    unsigned y = 0x76543210;
    unsigned res = (x & 0xFF) | (y & ~0xFF);
    assert(res == 0x765432EF);
    return 0;
}
