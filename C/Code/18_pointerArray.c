#include <stdio.h>

int main()
{
	int a[3] = {0, 1, 2};
	//ึธี๋สýื้
	int *p[3];
	int i = 0;
	int n = sizeof(p) / sizeof(p[0]);
	for (i = 0; i < n; ++i)
	{
		p[i] = &a[i]; //a + i;
	}
	for (i = 0; i < n; ++i)
	{
		printf("%p\n", p[i]);
		printf("%d\n", *p[i]);
	}

	return 0;
}
