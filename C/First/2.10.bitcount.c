#include <stdio.h>
#include <stdlib.h>

int bitcount(unsigned x)
{
    int n = 0;
    //for (; x != 0; x >>= 1)
    /*
        x &= x - 1
        1011
    -1  1010
     &  1010
    -1  1001
     &  1000
    -1  0111
     &  0000
    n = 3

        1000 1000 0000
    -1       0111 1111     

    */
    for (; x != 0; x &= x - 1)
    {
        ++n;
    }
    return n;
}

int main()
{
    printf("bitcount(10) = %d\n", bitcount(10));
    system("pause");
    return 0;
}