#include <stdio.h>

int main()
{
    int k, n;
    double sn = 0.0000;
    scanf("%d", &k);
    for (n = 1; sn <= k; ++n)   
    {
        sn += (1.0 / (double)n);
    }
    printf("%d", n - 1);
    return 0;
}