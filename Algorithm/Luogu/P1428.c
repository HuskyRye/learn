#include <stdio.h>

int compare(int a[], int i);

int main()
{
	int n;
	scanf("%d", &n);
	int i;
	int a[100];
	int b[100];
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		b[i] = compare(a, i);
	}
	for (i = 0; i < n; ++i)
	{
		printf("%d ", b[i]);
	}
	return 0;
}

int compare(int a[], int i)
{
	int cur = a[i];
	int num = 0;
	for (i -= 1; i >= 0; --i)
	{
		if (a[i] < cur)
		{
			num++;
		}
	}
	return num;
}