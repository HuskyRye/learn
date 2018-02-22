/*
	Date: 2018.2.22
	Author: 刘臣轩
*/

#include <stdio.h>

int binsearch(int x, int v[], int n);
int binary_search(int x, int v[], int n);

int main()
{
    int v[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    printf("binsearch(3, v, 9) = %d\n", binsearch(3, v, 9));
    printf("binary_search(3, v, 9) = %d\n", binary_search(3, v, 9));
    return 0;
}

/* find x in v[0] <= v[1] <= ... <= v[n-1] <= v[n] */
int binsearch(int x, int v[], int n)
{
    int low = 0;
    int high = n - 1;
    int mid = (low + high) / 2;
    while (low <= high && x != v[mid]) {
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low + high) / 2;
    }
    return (x == v[mid] ? mid : -1);
}

/* find x in v[0] <= v[1] <= ... <= v[n-1] <= v[n] */
int binary_search(int x, int v[], int n)
{
    int low = 0;
    int high = n - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}
