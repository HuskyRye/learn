#include <stdio.h>

void my_strcpy(char *dst, char *src);

int main()
{
	char src[] = "hello world";
	char dst[100];

	my_strcpy(dst, src);
	printf("dst = %s\n", dst);

	return 0;
}

void my_strcpy(char *dst, char *src)
{
	int i = 0;
	while (*(src + i) != '\0')
	{
		*(dst + i) = *(src + i);
		++i;
	}
}
