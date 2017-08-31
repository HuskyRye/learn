#include <stdio.h>

int main()
{
	//定义一个万能指针，可以指向任何类型的变量
	void *p = NULL;

	int a = 10;
	p = &a;

	*(int *)p = 100;
	printf("*p = %d\n", *(int *)p);

	return 0;
}
