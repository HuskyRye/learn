#include <stdio.h>
#include <stdlib.h>
#include "itcastlog.h"

int main()
{
	printf("__FILE__ = %s\n__LINE__ = %d\n", __FILE__, __LINE__);
	int a = 10;
	ITCAST_LOG(__FILE__, __LINE__, 1, 0, "a = %d\n", a);
	system("pause");
	return 0;
}