#include <stdio.h>
#include <stdlib.h>

int add(int a, int b);
int minus(int a, int b);
void fun(int x, int y, int (*p)(int a, int b));

int main()
{
    fun(1, 2, add);
    fun(10, 5, minus);
    system("pause");
    return 0;
}

int add(int a, int b)
{
    return a + b;
}
int minus(int a, int b)
{
    return a - b;
}

void fun(int x, int y, int (*p)(int a, int b))
{
    printf("fun run\n");
    int a = p(x, y);
    printf("a = %d\n", a);
}
