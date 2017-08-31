#include <stdio.h>

int main()
{
	int a = 10;
	//const 修饰*p，即指针所指的内存只读
	const int *p = &a;
	//*p = 100;		//assignment of read-only location '*p'
	p = NULL;

	return 0;
}
