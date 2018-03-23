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
    int num = 123;
    assert(A(num) == num * 17);
    assert(B(num) == num * -7);
    assert(C(num) == num * 60);
    assert(D(num) == num * -112);
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
