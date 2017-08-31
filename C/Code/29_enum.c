#include <stdio.h>

enum Colors
{
    pink,
    red,
    green,
    white,
    blue,
    yellow
};

int main()
{
    int flag = 1;
    if (flag == red)
    {
        printf("red\n");
    }

    enum Color flag2;
    flag2 = pink;

    system("pause");
    return 0;
}