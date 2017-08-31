#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	//设置种子
	//time(NULL)获取徐同当前时间
	srand((unsigned int)time(NULL));
	//srand(100);

	int i, num;
	for (i = 0; i < 10; i++)
	{
		num = rand(); //rand()产生随机数
		printf("num = %d\n", num);
	}
	return 0;
}
