/*
	Date: 2018.2.21
	Author: 刘臣轩
*/

#include <stdio.h>

int bitcount(unsigned int x);

int main()
{
    printf("bitcount(0) = %u\n", bitcount(0));
    printf("bitcount(0xff) = %u\n", bitcount(0xff));
    return 0;
}

int bitcount(unsigned int x)
{
    int count;
    for (count = 0; x != 0; x &= (x - 1))
        ++count;
    return count;
}
