#include <stdio.h>
#include <string.h>

int main()
{
    int n = 0;
    scanf("%d\n", &n);
    char pass[100];
    gets(pass);

    int len = strlen(pass);
    int i = 0;
    for(i = 0; i < len; ++i)
    {
        pass[i] = (pass[i] - 'a' + n) % 26 + 'a';

    }
    printf("%s", pass);
    return 0;
}