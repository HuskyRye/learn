#include <stdio.h>
#include <stdlib.h>

int main()
{
    //1.先定义数组类型，根据类型定义指针变量
    typedef int A[10];
    A *p = NULL; //数组指针类型的变量
    A a = {0};   //数组
    p = &a;      //建立联系
    int i = 0;
    //赋值
    for (i = 0; i < 10; ++i)
    {
        (*p)[i] = i + 1;
    }
    //遍历
    for (i = 0; i < 10; ++i)
    {
        printf("%d, ", (*p)[i]);
    }
    printf("\n");

    //2.定义一个数组指针类型
    typedef int(*P)[10];
    P p2;
    p2 = &a;
    //赋值
    for (i = 0; i < 10; ++i)
    {
        (*p2)[i] = i + 1;
    }
    //遍历
    for (i = 0; i < 10; ++i)
    {
        printf("%d, ", (*p2)[i]);
    }
    printf("\n");

    //3.直接定义数组指针变量
    int(*p3)[10];
    p3 = &a;
    //赋值
    for (i = 0; i < 10; ++i)
    {
        (*p2)[i] = i + 1;
    }
    //遍历
    for (i = 0; i < 10; ++i)
    {
        printf("%d, ", (*p2)[i]);
    }
    printf("\n");

    system("pause");
    return 0;
}