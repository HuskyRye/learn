#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getStr1Str2(char *p, char *buf1, char *buf2);

int main()
{
    char *p = "1a2b3d4z";
    char buf1[50] = {0};
    char buf2[50] = {0};
    int ret = 0;
    ret = getStr1Str2(p, buf1, buf2);
    if (ret != 0)
    {
        printf("getStr1Str2.err:%d\n", ret);
        return ret;
    }
    printf("buf1 = %s\nbuf2 = %s\n", buf1, buf2);

    system("pause");
    return 0;
}

int getStr1Str2(char *source, char *buf1, char *buf2)
{
    if (source == NULL || buf1 == NULL || buf2 == NULL)
    {
        return -1;
    }
    int n = strlen(source);
    int i;
    for (i = 0; i < n; ++i)
    {
        if (i % 2 != 0)
        {
            //*buf1 = source[i];
            //++buf1;
            *buf1++ = source[i];
        }
        else
        {
            //*buf2 = source[i];
            //++buf2;
            *buf2++ = source[i];
        }
    }
    *buf1 = '\0';
    *buf2 = '\0';
    return 0;
}