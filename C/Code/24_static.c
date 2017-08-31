#include <stdio.h>

extern void fun();

int main()
{
	fun();
	fun();
	fun();

	return 0;
}

void fun()
{
	//static局部变量在编译阶段就分配空间，离开作用域不释放，只能用常量初始化
	static int i = 0;
	++i;
	printf("i = %d\n", i);
}
