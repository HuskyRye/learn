#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//将字符串数组进行排序

int sort(char **array1, int num1, char (*array2)[30], int num2, char ***myp3 /*out*/, int *num3);
void print_p3(char **p3, int len3);
void free_p3(char ***myp, int n);

int main()
{
    int ret = 0;
    char *p1[] = {"aa", "ccccccc", "bbbbbb"};
    char buf2[][30] = {"111111", "3333333", "222222"};
    char **p3 = NULL;
    int len1, len2, len3, i = 0;

    len1 = sizeof(p1) / sizeof(*p1);
    len2 = sizeof(buf2) / sizeof(buf2[0]);

    ret = sort(p1, len1, buf2, len2, &p3, &len3);
    if (ret != 0)
    {
        printf("sort.err:%d\n", ret);
        system("pause");
        return -1;
    }
    print_p3(p3, len3);
    free_p3(&p3, len3);

    system("pause");
    return 0;
}

int sort(char **array1, int num1, char (*array2)[30], int num2, char ***myp3, int *num3)
{
    if (array1 == NULL || array2 == NULL || num3 == NULL)
    {
        return -1;
    }
    int num = num1 + num2;
    *num3 = num;
    char **tmp = (char **)malloc(num * sizeof(char *));
    if (tmp == NULL)
    {
        return -2;
    }
    int i, j;

    /*  for(i = 0; i < num; ++i)
    {
        //*(tmp + i)
        tmp[i] = (char *)malloc(30 * sizeof(char));
    } */
    for (i = 0; i < num1; ++i)
    {
        tmp[i] = (char *)malloc((strlen(array1[i]) + 1) * sizeof(char));
        strcpy(tmp[i], array1[i]);
    }
    for (i = 0; i < num2; ++i)
    {
        tmp[i + num1] = (char *)malloc((strlen(array2[i]) + 1) * sizeof(char));
        strcpy(tmp[i + num1], array2[i]);
    }

    char *p == NULL;
    //sort
    for (i = 0; i < num; ++i)
    {
        for (j = i + 1; j < num; ++j)
        {
            if (strcmp(tmp[i], tmp[j]) > 0)
            {
                p = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = p;
            }
        }
    }
    *myp3 = tmp;
    return 0;
}

void print_p3(char **p3, int len3)
{
    if (p3 == NULL)
        return;
    int i = 0;
    for (i = 0; i < len3; ++i)
    {
        printf("%s, ", p3[i]);
    }
    printf("\n");
}

void free_p3(char ***myp, int n)
{
    if (myp == NULL)
        return;
    int i = 0;
    for (i = 0; i < n; ++i)
    {
        free((*myp)[i]);
        (*myp)[i] = NULL;
    }
    if (*myp != NULL)
    {
        free(*myp);
        *myp = NULL;
    }
}
