/*
	Date: 2018.2.23
	Author: 刘臣轩
*/

#include <stdio.h>

#define swap(t, x, y) \
    {                 \
        t _z;         \
        _z = y;       \
        y = x;        \
        x = _z;       \
    }

int main()
{
    int x = 0;
    int y = 1;
    printf("x = %d, y = %d\n", x, y);
    swap(int, x, y);
    printf("x = %d, y = %d\n", x, y);
}
