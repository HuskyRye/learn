#include <stdio.h>
#include <string.h>

struct People
{
    int age;
    char name[50];
};

struct Student
{
    struct People p;
    int score;
};

int main()
{
    struct Student s1;
    s1.p.age = 18;
    strcpy(s1.p.name, "mike");
    s1.score = 59;

    struct Student *p = &s1;
    p->p.age = 19;
    strcpy(p->p.name, "wangcai");
    p->score = 60;

    struct Student s2 = {18, "mike", 59};
    printf("%d, %s, %d\n", s1.p.age, s1.p.name, s1.score);
    printf("%d, %s, %d\n", s2.p.age, s2.p.name, s2.score);

    system("pause");
    return 0;
}
