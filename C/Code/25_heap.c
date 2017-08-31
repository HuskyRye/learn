#include <stdio.h>
#include <stdlib.h>

int main()
{
	//malloc(配置内存空间)，返回一个地址
	int *p = (int *)malloc(sizeof(int));
	*p = 10;
	printf("*p = %d\n", *p);
	//释放先前配置的内存
	if (NULL != p)
	{
		free(p);
		p = NULL;
	}
	//堆区数组
	p = (int *)malloc(10 * sizeof(int));
	p[0] = 1;
	*(p + 0) = 1;
	printf("p[0] = %d\n", p[0]);
	if (NULL != p)
	{
		free(p);
		p = NULL;
	}
	return 0;
}
