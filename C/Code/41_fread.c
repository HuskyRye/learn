#include <stdio.h>

typedef struct Student
{
    int age;
    char name[50];
    int score;
} Student;

int main()
{
    FILE *fp = fopen("test.txt", "w");

    Student s1[4] = {
        18, "mike", 59,
        19, "mike", 59,
        20, "mike", 59,
        21, "mike", 59,
    };

    int ret = fwrite(s1, sizeof(s1), 1, fp);
    printf("%d\n", ret);

    fclose(fp);
    fp = NULL;

    fp = fopen("test.txt", "r");
    Student s2[10];

    //ret = fread(s2, 1, 4 * sizeof(Student), fp);
    //printf("%d\n", ret);

    int i = 0;
    while (ret = fread(&s2[i], 1, sizeof(Student), fp) != 0)
    {
        ++i;
    }

    int n = i;
    for (i = 0; i < n; ++i)
    {
        printf("%d, %s, %d\n", s2[i].age, s2[i].name, s2[i].score);
    }

    fclose(fp);
    fp = NULL;

    system("pause");
    return 0;
}