#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int my_strstr(char *p, int *n);

int main()
{
    char *p = "11abcd111122abcd3333322abcd333322qqq";
    int n = 0;

    int ret = 0;
    ret = my_strstr(p, &n);
    if (ret != 0)
    {
        return ret;
    }

    printf("n = %d\n", n);

    system("pause");
    return 0;
}

int my_strstr(char *p, int *n)
{
    int i = 0;
    char *tmp = p;
    //while version
    while ((tmp = strstr(tmp, "abcd")) != NULL)
    {
        ++i;
        tmp = tmp + strlen("abcd");
        if (*tmp == 0)
        {
            break;
        }
    }
    //间接赋值
    *n = i;
    return 0;
}