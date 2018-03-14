#include <stdio.h>

int isprime(int n);

int main()
{
	char word[200] = { 0 };
	int letter[26] = { 0 };
	scanf("%s", word);
	int i;
	for (i = 0; word[i] != '\0'; ++i)
	{
		letter[word[i] - 'a'] += 1;
	}
	int maxn = 0;
	int minn = 200;
	for (i = 0; i < 26; ++i)
	{
		if (letter[i] > maxn)
		{
			maxn = letter[i];
		}
		else if (letter[i] < minn && letter[i] != 0)
		{
			minn = letter[i];
		}
	}
	if (isprime(maxn - minn))
	{
		printf("Lucky Word\n%d", maxn - minn);
	}
	else
	{
		printf("No Answer\n%d", 0);
	}
	return 0;
}

int isprime(int n)
{
	if (n < 2)
	{
		return 0;
	}
	int i;
	for (i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}