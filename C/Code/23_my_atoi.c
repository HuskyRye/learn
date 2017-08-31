#include <stdio.h>

int my_atoi(char *str);

int main()
{
	printf("num1 = %d\n", my_atoi("+123"));
	printf("num2 = %d\n", my_atoi("-123"));
	printf("num3 = %d\n", my_atoi("123"));
	return 0;
}

int my_atoi(char *str)
{
	int flag = 1;
	if(*str == '-')
	{
		flag = -1;
		++str;
	}
	else if(*str == '+')
	{
		++str;
	}
	int num = 0;
	while(*str != '\0')
	{
		num = num * 10 + (*str - '0');
		++str;
	}
	return flag*num;
}
