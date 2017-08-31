#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *a, int n);
void printArray(int *a, int n);

int main()
{
    int a[] = {10, 8, 1, 2, 5, 6, 8, 7, 3, 4};
    /*
        10, 8, 1, 2, 5, 6, 8, 7, 3, 4
        8, 10, 1, 2, 5, 6, 8, 7, 3, 4
        1, 10, 8, 2, 5, 6, 8, 7, 3, 4
        1, 8, 10, 2, 5, 6, 8, 7, 3, 4
        ...
        1, 2, 3, 4, 5, 6, 8, 8, 7, 10
    */
    int n = sizeof(a) / sizeof(a[0]);

    printf("before\n");
    printArray(a, n);

    selectionSort(a, n);

    printf("after\n");
    printArray(a, n);
    system("pause");
    return 0;
}

void selectionSort(int *a, int n)
{
    int i, j, tmp;
    //selectionSort
    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (a[i] > a[j])
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

void printArray(int *a, int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");
}