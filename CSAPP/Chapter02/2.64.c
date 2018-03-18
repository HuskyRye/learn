/*
	Date: 2018.3.17
	Author: 刘臣轩
*/

#include <assert.h>
#include <stdio.h>

int any_odd_one(unsigned x);

int main()
{
    assert(any_odd_one(0) == 0);
    assert(any_odd_one(2) == 1);
    assert(any_odd_one(0x55555555) == 0);
    assert(any_odd_one(0xaaaaaaaa) == 1);
    return 0;
}

int any_odd_one(unsigned x)
{
    return !!(x & 0xaaaaaaaa);
}
