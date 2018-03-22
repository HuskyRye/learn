/*
	Date: 2018.3.17
	Author: 刘臣轩
*/

#include <assert.h>
#include <stdio.h>

int int_size_is_32();
int int_size_is_32_for_16bits();

int main()
{
    /*
		A. If the value of the right operand is negative or is greater than or equal to the width of the promoted left operand, the behavior it undefined.
	 */
    assert(int_size_is_32());
    assert(int_size_is_32_for_16bits());
    return 0;
}

int int_size_is_32()
{
    int set_msb = 1 << 31;
    int beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}

int int_size_is_32_for_16bits()
{
    int set_msb = 1 << 15 << 15 << 1;
    int beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}
