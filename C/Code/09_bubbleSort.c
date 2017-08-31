#include <stdio.h>

int main()
{
	int a[] = {1, -34, -4, 3, 6};
	int n = sizeof(a) / sizeof(a[0]);
	int i;
	int j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d,", a[i]);
	}
}
