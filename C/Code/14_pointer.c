
#include <stdio.h>

int main()
{
	//定义一个空指针
	int *p = NULL;
	int a = 10;
	//把a的地址赋给指针，指针指向a
	p = &a;

	//操作指针所指向的内存
	if (p != NULL)
		*p = 100;

	//*p等价于p[0]
	printf("*p = %d, a = %d, p[0] = %d\n", *p, a, p[0]);
	printf("p = %p, &a = %p\n", p, &a);
	printf("&p = %p\n", &p);

	return 0;
}
