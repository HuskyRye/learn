#include <stdio.h>

int main()
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int e = a * 60 + b; //起始分钟数
    int f = c * 60 + d; //结束分钟数
    int g = f - e;      //分钟差值
    printf("%d %d", (g / 60), (g % 60));
    return 0;
}