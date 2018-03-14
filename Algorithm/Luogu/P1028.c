#include <stdio.h>

int half(int n);

int main()
{
	int n;
	int num;
	scanf("%d", &n);
	num = half(n);
	printf("%d", num);
	return 0;
}

int half(int n)
{
	int i = 1;
	int num = 1;
	for (i = 1; i <= (n / 2); ++i)
	{
		num += half(i);
	}
	return num;
}