#include <stdio.h>

void squeeze(char s[], int c);
void printString(char s[]);

int main()
{
	char s[] = "hello";
	squeeze(s, 'l');
	printString(s);
	return 0;
}

void squeeze(char s[], int c)
{
	int i, j;
	for(i = j = 0; s[i] != '\0'; ++i)
	{
		if(s[i] != c)
			s[j++] = s[i];
	}
	s[j] = '\0';
}

void printString(char s[])
{
	int i = 0;
	while(s[i] != '\0')
	{
		putchar(s[i++]); 
		//printf("%c", s[i++]);
	}
}
