#include <stdio.h>
#include <stdlib.h>

int add(int n);

int main()
{
    int n = add(100);
    printf("n = %d\n", n);
    system("pause");
    return 0;
}

int add(int n)
{
    if (n == 1)
    {
        return n;
    }
    return n + add(n - 1);
}
