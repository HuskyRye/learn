#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char s[]);

int main()
{

    system("pause");
    return 0;
}

void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; ++i, --j)
    {
        /*
        c = s[i];
        s[i] = s[j];
        s[j] = c; 
        */
        c = s[i], s[i] = s[j], s[j] = c;
    }
}
