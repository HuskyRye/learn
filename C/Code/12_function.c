#include <stdio.h>

void fun1()
{
	printf("fun1():无参无返回值函数\n");
}

void fun2(int a)
{
	printf("fun2():有参无返回值的函数，参数%d\n", a);
}

int fun3()
{
	printf("fun3():参有返回值的函数\n");
	return 0;
}

int fun4(int a)
{
	printf("fun4():有参有返回值的函数\n");
	//exit(250);		//结束程序
	return a;
}

int main()
{
	fun1();
	fun2(10);
	printf("fun3()返回值为%d\n", fun3());
	printf("fun4()返回值为%d\n", fun4(10));
	return 0;
}
