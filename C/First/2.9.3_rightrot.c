#include <stdio.h>
#include <stdlib.h>

int rightrot(unsigned x, int n);

int main()
{
    printf("rightrot(10, 3) = %d\n", rightrot(10, 3));
    /*
        0000 0000 0000 0000 0000 0000 0000 1010
        0100 0000 0000 0000 0000 0000 0000 0001 -> 1,073,741,825
    */
    system("pause");
    return 0;
}

/*
    将 x 循环右移（从最右端溢出的位从左端移入） n 位
    0000 abcd
    0000 000d
    d000 0000
|   d000 abcd

    d000 0abc

    cd00 00ab
    bcd0 000a
*/
int rightrot(unsigned x, int n)
{
    int i = 0;
    int tmp;
    int length;
    unsigned a = (unsigned)~0;
    printf("a = %u\n", a);
    for (length = 1; (a >>= 1) > 0; ++length)
    {
    }
    printf("length = %d\n", length);
    for (i = 0; i < n; ++i)
    {
        tmp = (x & 1) << (length - 1);
        x >>= 1;
        x |= tmp;
    }
    return x;
}