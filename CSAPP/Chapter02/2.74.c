/*
	Date: 2018.3.22
	Author: 刘臣轩
*/

#include <assert.h>
#include <limits.h>
#include <stdio.h>

int tsub_ok(int x, int y);

int main()
{
    assert(tsub_ok(1, 2) == 1);
    assert(tsub_ok(-1, INT_MAX) == 1);
    assert(tsub_ok(-2, INT_MAX) == 0);
}

int tadd_ok(int x, int y);

int tsub_ok(int x, int y)
{
    int add_ok = tadd_ok(x, -y);
    return (y == INT_MIN) ^ add_ok;
}

int tadd_ok(int x, int y)
{
    int shift = (sizeof(int) << 3) - 1;
    int sum = x + y;
    /* MSB, Most Significant Bit */
    int x_msb = x >> shift;
    int y_msb = y >> shift;
    int sum_msb = sum >> shift;
    int neg_off = x_msb && y_msb && !sum_msb;
    int pos_off = !x_msb && !y_msb && sum_msb;
    return !(neg_off || pos_off);
}
