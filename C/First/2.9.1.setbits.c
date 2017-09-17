#include <stdio.h>
#include <stdlib.h>

int setbits(unsigned x, int p, int n, unsigned y);

int main()
{
    printf("setbits(10, 4, 3, 3) = %d\n", setbits(10, 4, 3, 3));
    /*  x   0000 1010
        y   0000 0011
        =   0000 1110 -> 14
    */
    system("pause");
    return 0;
}

/*
将x中从第p位开始的n个位设置为y中最右边的n位的值
x   xxxn nnxx
y   yyyy ynnn

x   xxx0 00xx
y   000n nn00

|   xxxn nnxx

y   yyyy ynnn

0    0000 0000
~   1111 1111
<<n 1111 1000
~   0000 0111
&   0000 0nnn

<<p 0nnn 0000
<<1 nnn0 000
>>n 00nn n000

x   xxxn nnxx

0   0000 0000
~   1111 1111
<<n 1111 1000
~   0000 0111
<<p 0111 0000
<<1 1110 0000
>>n 0001 1100
~   1110 0011

&   xxx0 00xx

*/
int setbits(unsigned x, int p, int n, unsigned y)
{
    return ~((~(~0 << n)) << (p + 1 - n)) & x | (y & ~(~0 << n)) << (p + 1 - n);
}
