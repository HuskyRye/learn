/*
	Date: 2018.3.17
	Author: 刘臣轩
*/

#include <stdio.h>

int is_little_endian();

int main()
{
    printf("is_little_endian = %d\n", is_little_endian());
    return 0;
}

int is_little_endian()
{
    int a = 1;
    return *((char*)&a);
}
