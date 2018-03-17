/*
	Date: 2018.3.17
	Author: 刘臣轩
*/

#include <assert.h>
#include <stdio.h>

int A(int x);
int B(int x);
int C(int x);
int D(int x);

int main()
{
    int all_bit_zero = 0;
    int all_bit_one = ~0;

    assert(A(all_bit_one) == 1);
    assert(A(all_bit_zero) == 0);
    assert(A(0x12345678) == 0);
    printf("A Accepted\n");

    assert(B(all_bit_zero) == 1);
    assert(B(all_bit_one) == 0);
    assert(B(0x12345678) == 0);
    printf("B Accepted\n");

    assert(C(all_bit_one) == 1);
    assert(C(all_bit_zero) == 0);
    assert(C(0x12345678) == 0);
    assert(C(0x123456FF) == 1);
    printf("C Accepted\n");

    assert(D(all_bit_one) == 0);
    assert(D(all_bit_zero) == 1);
    assert(D(0x12345678) == 0);
    assert(D(0x00345678) == 1);
    printf("D Accepted\n");

    return 0;
}

int A(int x)
{
    return !(~x);
}

int B(int x)
{
    return !x;
}

int C(int x)
{
    return !((x & 0xFF) ^ 0xFF);
}

int D(int x)
{
    int shift = (sizeof(int) - 1) << 3;
    return !((unsigned)x >> shift);
}
