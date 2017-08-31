#include <stdio.h>
#include <stdlib.h>

typedef struct Stu
{
    //数据域
    int id;
    char name[100];
    //指针域
    struct Stu *next;
} Stu;

int main()
{
    Stu s1 = {1, "mike", NULL};
    Stu s2 = {2, "genius", NULL};
    Stu s3 = {3, "hello", NULL};
    s1.next = &s2;
    s2.next = &s3;
    s3.next = NULL;

    //遍历
    Stu *p = &s1;
    while (p != NULL)
    {
        printf("id = %d, name = %s\n", (*p).id, (*p).name);
        p = (*p).next;
    }
    system("pause");
    return 0;
}