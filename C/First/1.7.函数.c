#include <stdio.h>

int power(int m, int n);

int main()
{
	int i;
	for(i = 0; i < 10; ++i)
	{
		printf("i = %d\t2^%d = %-5d-3^%d = %d\n", i, i, power(2,i), i, power(-3,i));
	}
	return 0;	
}

int power(int base, int n)
{
	int p;
	for(p = 1; n > 0; --n)
		p = p * base;
	return p;
}
