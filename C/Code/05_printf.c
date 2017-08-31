#include <stdio.h>

int main()
{
	int a = 10;

	//%%输出一个%
	printf("%%d\n");

	//%nd，以n个字符输出，没有的字符以空字符填充，默认右对齐
	printf("%5d\n", a);

	//%0nd，以n个字符输出，没有的字符以0填充，默认右对齐
	printf("%05d\n", a);

	//%-nd，以n个字符输出，没有的字符以空字符填充，左对齐
	printf("%-5d\n", a);

	//0和-不能同时使用
	printf("%-05d\n", a);

	double pie = 3.14;
	//默认小数点后面有6位，不够补0
	printf("%lf\n", pie);
	//m.n，代表总共有m个字符，小数点后面有n位
	printf("%8.3lf\n", pie);
}
