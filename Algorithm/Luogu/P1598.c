#include <stdio.h>

void count(char line[], int letter[]);
void print(int letter[]);

int main()
{
	char line[73];
	int letter[26] = { 0 };
	int i;
	for (i = 0; i < 4; ++i)
	{
		gets(line);
		count(line, letter);
	}
	print(letter);
	return 0;
}

void count(char line[], int letter[])
{
	int i;
	for (i = 0; i <= strlen(line); ++i)
	{
		if (line[i] < 'A' || line[i] > 'Z')
		{
			continue;
		}
		letter[(line[i] - 'A')] += 1;
	}
}

void print(int letter[])
{
	int i, j, max = 0;
	for (i = 0; i < 26; ++i)
	{
		if (letter[i] > max)
		{
			max = letter[i];
		}
	}
	for (i = max; i > 0; --i)
	{
		for (j = 0; j < 26; ++j)
		{
			printf("%s", letter[j] >= i ? "*" : " ");
			printf("%s", j < 25 ? " " : "");
		}
		printf("\n");
	}
	char c = 'A';
	for (i = 0; i < 26; ++i)
	{
		putchar(c++);
		printf("%s", i < 25 ? " " : "");
	}
}