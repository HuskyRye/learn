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
        18, "mike", 1,
        19, "mike", 2,
        20, "mike", 3,
        21, "mike", 4,
    };

    int ret = fwrite(s1, 1, sizeof(s1), fp);
    printf("%d\n", ret);

    fclose(fp);
    fp = NULL;

    fp = fopen("test.txt", "r");
    Student s2;

    //fseek
    fseek(fp, 3 * sizeof(Student), SEEK_SET);
    fread(&s2, 1, sizeof(Student), fp);
    printf("%d, %s, %d\n", s2.age, s2.name, s2.score);

    fseek(fp, 0, SEEK_SET);
    //rewind
    rewind(fp);
    fread(&s2, 1, sizeof(Student), fp);
    printf("%d, %s, %d\n", s2.age, s2.name, s2.score);

    fseek(fp, 0, SEEK_END);
    //ftell
    long int size = ftell(fp);
    printf("size = %ld\n", size);

    fclose(fp);
    fp = NULL;
    system("pause");
    return 0;
}