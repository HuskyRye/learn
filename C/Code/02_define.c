
#include <stdio.h>

//定义一个宏定义的标示符MAX，代表100
#define MAX 100

int main()
{
	//MAX = 1;//[Error] lvalue required as left operand of assignment
	printf("%d\n", MAX);
	return 0;
}
