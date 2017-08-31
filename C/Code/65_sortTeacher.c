#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//重写结构体嵌套一级指针老师和二级指针学生的代码

//结构体类型，每个导师有三个学生
typedef struct Teacher
{
    char *tName; //导师
    char **stu;  //三个学生
    int age;
} Teacher;

//在createTeacher中分配空间
int createTeacher(Teacher **p /*out*/, int n1, int n2);

//给成员赋值
void initTeacher(Teacher *p, int n1, int n2);

//打印结构体成员信息
void printTeacher(Teacher *p, int n1, int n2);

//根据导师名字排序, 降序
void sortTeacher(Teacher *p, int n);

//释放空间，在函数内部把p赋值为NULL
void freeTeacher(Teacher **p, int n1, int n2);

int main(void)
{
    int ret = 0;
    int n1 = 3; //导师个数
    int n2 = 3; //学生
    Teacher *p = NULL;

    ret = createTeacher(&p, n1, n2);
    if (ret != 0)
    {
        printf("createTeacher err:%d\n", ret);
        system("pause");
        return ret;
    }

    initTeacher(p, n1, n2); //给成员赋值

    //打印成员，排序前
    printf("before:\n");
    printTeacher(p, n1, n2);

    //根据导师名字排序, 降序
    sortTeacher(p, n1);

    //打印成员，排序后
    printf("\nafter:\n");
    printTeacher(p, n1, n2);

    //释放空间，在函数内部把p赋值为NULL
    freeTeacher(&p, n1, n2);

    system("pause");
    return 0;
}

//在createTeacher中分配空间
int createTeacher(Teacher **p /*out*/, int n1, int n2)
{
    if (p == NULL || n1 == 0 || n2 == 0)
        return -1;
    int i, j;
    Teacher *tmp = (Teacher *)malloc(n1 * sizeof(Teacher));
    if (tmp == NULL)
        return -2;
    for (i = 0; i < n1; ++i)
    {
        tmp[i].tName = (char *)malloc(30 * sizeof(char));
        if (tmp[i].tName == NULL)
            return -3;
        tmp[i].stu = (char **)malloc(n2 * sizeof(char *));
        if (tmp[i].stu == NULL)
            return -4;
        for (j = 0; j < n2; ++j)
        {
            tmp[i].stu[j] = (char *)malloc(30 * sizeof(char));
            if (tmp[i].stu[j] == NULL)
                return -5;
        }
    }
    *p = tmp;
    return 0;
}

//给成员赋值
void initTeacher(Teacher *p, int n1, int n2)
{
    if (p == NULL)
        return;
    int i, j;
    for (i = 0; i < n1; ++i)
    {
        printf("Teacher No.%d:\n", i + 1);
        printf("name:");
        scanf("%s", p[i].tName);
        printf("age:");
        scanf("%d", &p[i].age);
        for (j = 0; j < n2; ++j)
        {
            printf("\tStudent No.%d:\n", j + 1);
            printf("\tname:");
            scanf("%s", p[i].stu[j]);
        }
    }
}

//打印结构体成员信息
void printTeacher(Teacher *p, int n1, int n2)
{
    if (p == NULL)
        return;
    int i, j;
    for (i = 0; i < n1; ++i)
    {
        printf("%s\t%d:", p[i].tName, p[i].age);
        for (j = 0; j < n2; ++j)
        {
            printf("\t%s", p[i].stu[j]);
        }
        putchar('\n');
    }
}

//根据导师名字排序, 降序
void sortTeacher(Teacher *p, int n)
{
    if (p == NULL)
        return;
    int i, j;
    Teacher tmp;
    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (strcmp(p[i].tName, p[j].tName) > 0)
            {
                tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            }
        }
    }
}

//释放空间，在函数内部把p赋值为NULL
void freeTeacher(Teacher **p, int n1, int n2)
{
    if (*p == NULL || p == NULL || n1 == 0 || n2 == 0)
        return;
    int i, j;
    for (i = 0; i < n1; ++i)
    {
        for (j = 0; j < n2; ++j)
        {
            if ((*p)[i].stu[j] != NULL)
            {
                free((*p)[i].stu[j]);
                (*p)[i].stu[j] = NULL;
            }
        }
        if ((*p)[i].stu != NULL)
        {
            free((*p)[i].stu);
            (*p)[i].stu = NULL;
        }
        if ((*p)[i].tName != NULL)
        {
            free((*p)[i].tName);
            (*p)[i].tName = NULL;
        }
    }
    if (*p != NULL)
    {
        free(*p);
        *p = NULL;
    }
}