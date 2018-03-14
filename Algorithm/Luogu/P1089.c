#include <stdio.h>

int main()
{
    int a;     //本月预算
    int b = 0; //存了多少张
    int c = 0; //本月将剩多少
    int d = 0; //本月初总共有多少
    int i;
    int flag = 0; //标志位
    for (i = 0; i < 12; ++i)
    {
        scanf("%d", &a);
        int d = (c + 300 - a);
        if (d >= 0)
        {
            b += (d / 100);
            c = d - ((d / 100) * 100);
        }
        else
        {
            flag == 0 ? (flag = i + 1):1;
            c = 0;
        }
    }
    c = c + b * 120;
    printf("%d", (flag == 0) ? c : 0 - flag);

    return 0;
}