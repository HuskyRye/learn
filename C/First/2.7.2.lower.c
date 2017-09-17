#include <stdio.h>
#include <ctype.h>


int lower(int c);

int main()
{
	printf("lower A = %c\n", lower('A'));
	printf("tolower A = %c\n", tolower('A'));
} 

int lower(int c)
{
	if(c >= 'A' && c <= 'Z')
		return c - 'A' + 'a';
	else
		return c;
}
