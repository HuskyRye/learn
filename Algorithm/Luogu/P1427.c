#include <stdio.h>

int main()
{
	int a[100];
	int i;
	for (i = 0; i < 100; ++i)
	{
		scanf("%d", &a[i]);
		if (a[i] == 0)
		{
			break;
		}
	}
	for (i -= 1; i >= 0; --i)
	{
		printf("%d ", a[i]);
	}
	return 0;
}