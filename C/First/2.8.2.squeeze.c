#include <stdio.h>

void squeeze(char s1[], char s2[]);
void printString(char s[]);

int main()
{
	char s1[] = "hello";
	char s2[] = "eo";
	squeeze(s1, s2);
	printString(s1);
	return 0;
}

void squeeze(char s1[], char s2[])
{
	int i, j;
	int k = 0;
	for (i = 0; s1[i] != '\0'; ++i)
	{
		for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; ++j)
			;
		if (s2[j] == '\0')
		{
			s1[k++] = s1[i];
		}
	}
	s1[k] = '\0';
}

void printString(char s[])
{
	int i = 0;
	while (s[i] != '\0')
	{
		putchar(s[i++]);
	}
}
