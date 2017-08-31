#include <stdio.h>

int main()
{
	int a[5] = {1, 2, 3, 4, 5};
	int *p = a;
	int i;
	for (i = 0; i < 5; ++i)
	{
		printf("%d, ", a[i]);
		printf("%d, ", p[i]);
		printf("%d, ", *(p + i));
	}
	putchar('\n');

	return 0;
}
