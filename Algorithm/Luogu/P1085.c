#include <stdio.h>

int main()
{
    int i;
    int b, c;
    int flag = 0;
    int day = 0;
    for (i = 0; i < 7; ++i)
    {
        scanf("%d%d", &b, &c);
        if ((b + c) > flag)
        {
            flag = b + c;
            day = i + 1;
        }
    }
    printf("%d", (flag > 8) ? day : 0);
    return 0;
}