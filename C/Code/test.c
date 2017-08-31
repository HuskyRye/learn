#include <stdio.h>
#include <string.h>

int main()
{
    //第一个字符串数组，C语言中没有字符串类型，用char[]代替
    char *a[] = {"A", "B", "C", "D"};
    char *b[] = {"B", "C"};

    //获取需要比较的两个数组的长度
    int lenA = sizeof(a) / sizeof(a[0]);
    int lenB = sizeof(b) / sizeof(b[0]);
    //printf("lenA = %d, lenB = %d\n", lenA, lenB);

    //判断并输出是否重复
    int i = 0, j = 0, k = 0;
    for (i = 0; i < lenA; ++i)
    {
        for (j = 0; strcmp(a[i], b[j]) != 0; ++j)
        {
            if (j == lenB - 1)
            {
                //在这里处理重复的元素a[i]
                printf("%s\n", a[i]);
            }
        }
    }

    return 0;
}
