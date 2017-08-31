#include <stdio.h>
#include <stdlib.h>	
#include "memwatch.h"

int main()
{
	char *p = malloc(100);
	free(p);
	system("pause");
	return 0;
}