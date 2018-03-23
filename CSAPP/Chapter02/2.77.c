/*
	Date: 2018.3.22
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
    int x = 123;
    assert(A(x) == x * 17);
    assert(B(x) == x * -7);
    assert(C(x) == x * 60);
    assert(D(x) == x * -112);
    return 0;
}

int A(int x)
{
    return (x << 4) + x;
}

int B(int x)
{
    return -(x << 3) + x;
}

int C(int x)
{
    return (x << 6) - (x << 2);
}

int D(int x)
{
    return -(x << 7) + (x << 4);
}
