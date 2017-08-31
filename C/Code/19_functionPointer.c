#include <stdio.h>

void swap(int *m, int *n);

int main()
{
	int a = 11;
	int b = 22;
	printf("a = %d, b = %d\n", a, b);
	swap(&a, &b);
	printf("a = %d, b = %d\n", a, b);
	return 0;
}

void swap(int *m, int *n)
{
	int tmp;
	tmp = *m;
	*m = *n;
	*n = tmp;
	//printf("*m = %d, *n = %d\n", *m, *n);
}
