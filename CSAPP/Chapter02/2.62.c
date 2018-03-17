/*
	Date: 2018.3.17
	Author: 刘臣轩
*/

#include <assert.h>
#include <stdio.h>

int int_shifts_are_arithmetic();

int main()
{
    assert(int_shifts_are_arithmetic());
    return 0;
}

int int_shifts_are_arithmetic()
{
    return (~0 >> 1 == ~0);
}
