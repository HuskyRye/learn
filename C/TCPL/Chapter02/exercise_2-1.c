/*
	Date: 2018.2.21
	Author: 刘臣轩
*/

#include <limits.h>
#include <stdio.h>

int main()
{
    printf("signed char min = %d, %d\n", SCHAR_MIN, -(char)((unsigned char)~0 >> 1) - 1);
    printf("signed char max = %d, %d\n", SCHAR_MAX, (char)((unsigned char)~0 >> 1));
    printf("unsigned char max = %u, %u\n", UCHAR_MAX, (unsigned char)~0);
    putchar('\n');

    printf("signed short min = %d, %d\n", SHRT_MIN, -(short)((unsigned short)~0 >> 1) - 1);
    printf("signed short max = %d, %d\n", SHRT_MAX, (short)((unsigned short)~0 >> 1));
    printf("unsigned short max = %u, %u\n", USHRT_MAX, (unsigned short)~0);
    putchar('\n');

    printf("signed int min = %d, %d\n", INT_MIN, -(int)((unsigned int)~0 >> 1) - 1);
    printf("signed int max = %d, %d\n", INT_MAX, (int)((unsigned int)~0 >> 1));
    printf("unsigned int max = %u, %u\n", UINT_MAX, (unsigned int)~0);
    putchar('\n');

    printf("signed long min = %ld, %ld\n", LONG_MIN, -(long)((unsigned long)~0 >> 1) - 1);
    printf("signed long max = %ld, %ld\n", LONG_MAX, (long)((unsigned long)~0 >> 1));
    printf("unsigned long max = %lu, %lu\n", ULONG_MAX, (unsigned long)~0);
    putchar('\n');
}
