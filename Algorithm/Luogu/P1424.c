#include <stdio.h>

int main()
{
	long int num = 0;
	long int day;
	int x;
	scanf("%d %d", &x, &day);
	int i = 0;
	for (i = 0; i < day; ++i)
	{
		if (x < 6)
		{
			num += 250;
		}
		else if (x == 7)
		{
			x = 0;
		}
		x++;
	}
	printf("%d\n", num);

	return 0;
}