#include <stdio.h>
#include <stdlib.h>

int invert(unsigned x, int p, int n);

int main()
{
    printf("invert(10, 4, 3) = %d\n", invert(10, 4, 3));
    /*
        0000 1010
        0001 0110 -> 22
    */
    system("pause");
    return 0;
}

/*  
    将 x 中从第 p 位开始的 n 个位求反，x 的其余各位保持不变
    xxxn nnxx
    xxx1 01xx



~0  1111 1111
<<n 1111 1000
~   0000 0111
<<p 0111 0000
<<1 1110 0000
>>n 0001 1100

^   xxx0 10xx
*/
int invert(unsigned x, int p, int n)
{
    return x ^ ~(~0 << n) << (p + 1 - n);
}