/*
	Date: 2018.3.19
	Author: 刘臣轩
*/

#include <assert.h>
#include <stdio.h>

int lower_one_maker(int n);

int main()
{
    assert(lower_one_maker(6) == 0x3F);
    assert(lower_one_maker(17) == 0x1FFFF);
    return 0;
}

int lower_one_maker(int n)
{
    return ~((~0) << n);
}
