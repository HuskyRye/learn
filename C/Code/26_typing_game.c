#include <stdio.h>
#include <conio.h>
#define MAX 51
void help();
void start(char *str);
void on_game(char *str);

int main()
{
	char str[MAX] = {0};
	while (1)
	{
		help();		//游戏说明菜单
		start(str); //产生随机字母
		getch();
		on_game(str);	  //开始游戏
		if (getch() == 27) //ESC
		{
			break;
		}
		system("cls"); //清屏
	}
	return 0;
}

void help()
{
	printf("\n*******************************************");
	printf("\n*输入过程中无法退出，输入出错则以 _ 表示！*");
	printf("\n*按任意键开始游戏，按下首字母时开始计时！ *");
	printf("\n*******************************************\n\n");
}

void start(char *str)
{
	srand((unsigned int)time(NULL));
	int i;
	for (i = 0; i < MAX - 1; ++i)
	{
		*(str + i) = rand() % 26 + 'a';
	}

	*(str + i) = '\0';
}

void on_game(char *str)
{
	char ch;
	int i;
	int count = 0;
	time_t t_start, t_end;

	system("cls");
	printf("\n%s\n", str);

	for (i = 0; i < MAX - 1; ++i)
	{
		ch = getch();
		if (i == 0)
		{
			t_start = time(NULL);
		}
		if (ch == *(str + i))
		{
			putchar(ch);
			++count;
		}
		else
			putchar('_');
	}

	t_end = time(NULL);

	printf("\n完成输入！\n用时 %ld s\n", t_end - t_start);
	printf("正确率%lf %%\n", ((double)count / (MAX - 1)) * 100);
}
