#include <stdio.h>
#include <stdlib.h>

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int main()
{
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(v) / sizeof(v[0]);
    printf("binsearch(3, v, n) = %d\n", binsearch(3, v, n));
    printf("binsearch2(3, v, n) = %d\n", binsearch2(3, v, n));
    system("pause");
    return 0;
}

/* binsearch函数：已排序数组（升序）中查找x（折半查找） */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2; //折半
        if (x < v[mid])
        {
            high = mid - 1;
        }
        else if (x > v[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid; //find
        }
    }
    return -1;
}

//效率并没有什么改进，反而失掉了代码可读性
int binsearch2(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high && v[mid] != x)
    {
        if (x < v[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    return (x == v[mid]) ? mid : -1;
}