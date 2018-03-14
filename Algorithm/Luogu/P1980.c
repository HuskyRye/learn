#include <stdio.h>

int main()
{
	int n;
	int x;
	int tmp;
	int num = 0;
	scanf("%d %d", &n, &x);
	int i;
	for (i = 1; i <= n; ++i)
	{
		tmp = i;
		while (tmp > 0)
		{
			if ((tmp % 10) == x)
			{
				++num;
			}
			tmp /= 10;
		}
	}
	printf("%d\n", num);
	return 0;
}