#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    double n = 0;
    if (a > 400)
    {
        n += (0.5663 * (a - 400));
        a = 400;
    }
    if (a > 150)
    {
        n += (0.4663 * (a - 150));
        a = 150;
    }
    if (a >= 0)
    {
        n += (0.4463 * a);
    }
    printf("%.1lf", n);
    return 0;
}