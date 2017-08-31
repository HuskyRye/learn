#include <stdio.h>

void print_array(char *a[], int n);

int main()
{
	char *p[] = {"hello", "abc", "123"};
	int n = sizeof(p) / sizeof(*p);
	print_array(p, n);
}

void print_array(char *a[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		printf("%s\n", a[i]);
	}
}
