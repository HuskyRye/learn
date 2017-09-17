int any(char s1[], char s2[]);

int main()
{
	char s1[] = "hello";
	char s2[] = "ole";
	printf("%d\n", any(s1, s2));
	return 0;
}

int any(char s1[], char s2[])
{
	int i, j;
	for(i = 0; s1[i] != '\0'; ++i)
	{
		for(j = 0; s2[j] != '\0'; ++j)
		{
			if(s1[i] == s2[j])
			{
				return i;
			}
		}
	}
	return -1;
}
