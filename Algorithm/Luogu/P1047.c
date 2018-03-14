#include <stdio.h>

int main()
{
	int l, m;
	scanf("%d %d", &l, &m);
	int tree[100000] = { 0 };
	int i;
	int j;
	for (i = 0; i <= l; ++i)
	{
		tree[i] = 1;
	}
	int a, b;
	for (i = 0; i < m; ++i)
	{
		scanf("%d %d", &a, &b);
		for (j = a; j <= b; ++j)
		{
			tree[j] = 0;
		}
	}
	int num = 0;
	for (i = 0; i <= l; ++i)
	{
		if (tree[i] == 1)
		{
			num++;
		}
	}
	printf("%d", num);
	return 0;
}