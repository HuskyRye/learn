#include <stdio.h>

typedef struct Student
{
    int a;
} Student;

int main()
{
    //typefef给一个已存在的类型起一个别名，不创建类型
    Student a = {
        1,
    };
    printf("%d\n", a.a);

    system("pause");
    return 0;
}