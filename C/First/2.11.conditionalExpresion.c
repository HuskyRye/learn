#include <stdio.h>
#include <stdlib.h>

void printArray(int a[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        printf("%2d%c", a[i], (i % 10 == 9 || i == n - 1) ? '\n' : ' ');
    }
}

int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : c;
}
/*
int lower(int c)
{
	if(c >= 'A' && c <= 'Z')
		return c - 'A' + 'a';
	else
		return c;
}
*/

int main()
{
    int a[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    printArray(a, 15);

    printf("You have %d item%s.\n", sizeof(a) / sizeof(a[0]), (a[14] == 1) ? "" : "s");

    printf("lower A = %c\n", lower('A'));

    system("pause");
    return 0;
}