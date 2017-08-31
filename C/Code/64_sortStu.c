#include <stdio.h>
#include <stdlib.h>

//从键盘输入3个学生的信息（姓名、学号、成绩），存入一个结构体数组中，计算平均分，并按成绩高低排序并输出
typedef struct Stu
{
    char name[50];
    int id;
    double score;
} Stu;

void initStu(Stu s[], int n);
double aveStu(Stu s[], int n);
void sortStu(Stu s[], int n);
void showStu(Stu s[], int n);

int main(void)
{
    Stu s[3];
    int n = 3;

    //从键盘输入学生信息
    initStu(s, n);
    //aveStu(s, 3)：平均分
    printf("\naverage: %lf\n", aveStu(s, n));
    //showStu(s, n);
    //分数排序，降序
    sortStu(s, n);
    //打印学生信息
    showStu(s, n);

    system("pause");
    return 0;
}

void initStu(Stu s[], int n)
{
    int i = 0;
    for (i = 0; i < n; ++i)
    {
        printf("No.%d:\n", i + 1);
        printf("name:");
        scanf("%s", s[i].name);
        printf("id:");
        scanf("%d", &s[i].id);
        printf("score:");
        scanf("%lf", &s[i].score);
    }
}

double aveStu(Stu s[], int n)
{
    int i = 0;
    double sum = 0;
    for (i = 0; i < n; ++i)
    {
        sum += s[i].score;
    }
    double ave = sum / n;
    return ave;
}

void sortStu(Stu s[], int n)
{
    int i, j;
    Stu tmp;
    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (s[i].score < s[j].score)
            {
                tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }
        }
    }
}

void showStu(Stu s[], int n)
{
    int i = 0;
    for (i = 0; i < n; ++i)
    {
        printf("%s\t%d\t%lf\n", s[i].name, s[i].id, s[i].score);
    }
}