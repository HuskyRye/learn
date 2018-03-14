#include <stdio.h>
#include <string.h>

void reverse(char s[], int begin, int end, char d[]);

//全局变量pos，记录d[]中当前位置
int pos = 0;

int main()
{
	char s[30];	//src，用于存放输入的字符串
	char d[30] = { 0 };	//用于存放翻转后的字符串，由于翻转后可能去除部分0，导致前后长度不一致，所以使用另外的数组保存结果
	int begin = 0;
	scanf("%s", s);
	int i;
	for (i = 0; s[i] != '\0'; ++i)
	{
		if (s[i] == '%')
		{
			//从开头到%前的一位
			reverse(s, begin, i - 1, d);
			d[pos] = '%';	//添加%
			//之后不能再进行翻转
			begin = -1;
		}
		// '.' 和 '/' 是一个套路
		else if (s[i] == '.' || s[i] == '/')
		{
			reverse(s, begin, i - 1, d);
			d[pos++] = s[i];
			//将开始位置设置到符号的下一位
			begin = i + 1;
		}
		//在字符串终止前进行翻转，1.处理整形 2.处理小数或分数的剩余部分 3.避免%前的部分被重新翻转
		else if (s[i + 1] == '\0' && begin != -1)
		{
			reverse(s, begin, i, d);

		}
	}
	printf("%s\n", d);
	return 0;
}

//翻转函数，去除首位空格，将翻转后的结果放入d[]
void reverse(char s[], int begin, int end, char d[])
{
	//跳过结尾为0的
	while (s[end] == '0')
	{
		if (begin == end)
		{
			break;
		}
		--end;
	}
	//跳过开头为0的
	while (s[begin] == '0')
	{
		if (begin == end)
		{
			break;
		}
		++begin;
	}
	//翻转
	for (; begin <= end; --end)
	{
		//默认拷贝一位，即0
		d[pos++] = s[end];
	}
	return;
}