#include <stdio.h>
#include <stdlib.h>

void expand(char s1[], char s2[]);

int main()
{
    char tmp[100];
    expand("-a-z", tmp);
    printf("tmp = %s\n", tmp);
    system("pause");
    return 0;
}

void expand(char s1[], char s2[])
{
    char c;
    int i = 0, j = 0;
    while ((c = s1[i++]) != '\0')
    {
        if (s1[i] == '-' && s1[i + 1] >= c)
        {
            ++i;
            while (c < s1[i])
            {
                s2[j++] = c++;
            }
        }
        else
        {
            s2[j++] = c;
        }
    }
    s2[j] = '\0';
}