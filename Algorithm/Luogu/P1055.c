#include <stdio.h>
int main()
{
    char isbn[14];
    scanf("%s", isbn);
    int i;
    int j = 1;
    int n = 0;
    for (i = 0; i < 11; ++i)
    {
        if (isbn[i] != '-')
        {
            n += (isbn[i] - '0') * j++;
        }
    }
    int a = n % 11;
    int tmp = isbn[12];
    isbn[12] = a == 10 ? 'X' : a + '0';
    if (tmp == isbn[12])
    {
        printf("Right");
    }
    else
    {
        printf("%s\n", isbn);
    }
    return 0;
}