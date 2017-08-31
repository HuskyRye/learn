
#include <stdio.h>

int main()
{
	int a;
	printf("请输入a：");
	scanf("%d", &a);
	printf("a = %d\n", a);

	int b;
	int c;
	printf("请输入b c:");
	scanf("%d %d", &b, &c);
	printf("b = %d, c = %d\n", b, c);

	//清除上一步的\n，不处理
	char d;
	scanf("%c", &d);
	//d = getchar();

	char e;
	printf("请输入字符e：");
	scanf("%c", &e);
	//e = getchar();
	printf("e = %c\n", e);

	return 0;
}
