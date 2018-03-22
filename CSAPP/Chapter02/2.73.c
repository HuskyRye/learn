/*
	Date: 2018.3.22
	Author: 刘臣轩
*/

#include <assert.h>
#include <limits.h>
#include <stdio.h>

int saturating_add(int x, int y);

int main()
{
    assert(saturating_add(INT_MAX, 1) == INT_MAX);
    assert(saturating_add(1, 2) == 3);
    assert(saturating_add(INT_MIN, -1) == INT_MIN);
    return 0;
}

int saturating_add(int x, int y)
{
    int shift = (sizeof(int) << 3) - 1;
    int sum = x + y;
    /* MSB, Most Significant Bit */
    int x_msb = x >> shift;
    int y_msb = y >> shift;
    int sum_msb = sum >> shift;
    int neg_off = x_msb && y_msb && !sum_msb;
    int pos_off = !x_msb && !y_msb && sum_msb;
    (neg_off && (sum = INT_MIN)) || ((pos_off) && (sum = INT_MAX));
    return sum;
}
