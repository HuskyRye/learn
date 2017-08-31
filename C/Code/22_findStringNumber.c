#include <stdio.h>
#define MAXLINE 1000
#include <string.h>

int main()
{
	char *p = "11abcd111122abcd333abcd3322abcd3333322qqq";
	int i = 0;
	char *tmp = NULL;
	while (1)
	{
		tmp = strstr(p, "abcd");
		if (tmp == NULL)
		{
			break;
		}
		else
		{
			++i;
			p = tmp + strlen("abcd");
		}
	}
	printf("%d", i);
	return 0;
}
