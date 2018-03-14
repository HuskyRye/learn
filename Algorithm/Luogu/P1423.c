#include <stdio.h>

int main()
{
	double d;
	scanf("%lf", &d);
	double n = 2;
	int i = 0;
	while (d > 0)
	{
		d -= n;
		n *= 0.98;
		++i;
	}
	printf("%d\n", i);
	return 0;
}