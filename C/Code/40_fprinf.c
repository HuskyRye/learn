#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 500

void write_file();
void read_file();

int main()
{
    write_file();
    read_file();
    //system("pause");
    return 0;
}

void write_file()
{
    FILE *fp = fopen("test.txt", "w");
    srand((unsigned int)time(NULL));
    int i;
    int n;
    for (i = 0; i <= MAX; ++i)
    {
        n = rand() % 100;
        fprintf(fp, "%d\n", n);
    }

    fclose(fp);
    fp = NULL;
}

void read_file()
{
    FILE *fp = fopen("test.txt", "r");
    int a[MAX];
    int i = 0;
    while (fscanf(fp, "%d\n", &a[i]) && !feof(fp))
    {
        ++i;
    }
    int n = i;
    int j;
    int tmp;
    for (i = 0; i < n - 1; ++i)
    {
        for (j = 0; j < n - 1 - i; ++j)
        {
            if (a[j] > a[j + 1])
            {
                tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }
    fclose(fp);
    fp = fopen("test.txt", "w");
    for (i = 0; i < n; ++i)
    {
        //printf("%d\n", a[i]);
        fprintf(fp, "%d\n", a[i]);
    }

    fclose(fp);
    fp = NULL;
}
