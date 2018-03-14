#include <stdio.h>

int main()
{
	int n, sign = 1;
	scanf("%d", &n);
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	while (n > 0 && n % 10 == 0)
	{
		n /= 10;
	}
	if (n == 0)
	{
		printf("%d", 0);
	}
	while (n > 0)
	{
		printf("%d", n % 10);
		n /= 10;
	}
	return 0;
}