#include <stdio.h>

int main()
{
	int a[10] = { 0 };
	int i;
	int num = 0;
	for (i = 0; i < 10; ++i)
	{
		scanf("%d", &a[i]);
	}
	int h;
	scanf("%d", &h);
	h += 30;
	for (i = 0; i < 10; ++i)
	{
		if (a[i] <= h)
		{
			++num;
		}
	}
	printf("%d\n", num);
	return 0;
}