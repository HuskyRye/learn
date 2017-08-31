#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strcpy(char *dst, const char *src);
int my_strcpy2(char *dst, const char *src);

int main()
{
    char src[] = "abcdefgh";
    char dst[100] = {0};
    int ret = 0;

    ret = my_strcpy(dst, src);
    printf("dst = %s, ret = %d\n", dst, ret);

    memset(dst, 0, sizeof(dst));
    ret = my_strcpy2(dst, src);
    printf("dst = %s, ret = %d\n", dst, ret);

    memset(dst, 0, sizeof(dst));
    ret = my_strcpy2(NULL, src);
    printf("dst = %s, ret = %d\n", dst, ret);

    system("pause");
    return 0;
}

int my_strcpy(char *dst, const char *src)
{
    if (dst == NULL)
        return -1;
    int i = 0;

    //for(i = 0; src[i] != 0; ++i)
    for (i = 0; *(src + i) != 0; ++i)
    {
        *(dst + i) = *(src + i);
        //dst[i] = src[i];
    }
    return 0;
}

int my_strcpy2(char *dst, const char *src)
{
    if (dst == NULL)
        return -1;
    while (*dst++ = *src++)
        ;
    /*
    while (*src != 0)
    {
        
        *dst = *src;
        ++dst;
        ++src;
        
        *dst++ = *src++;
    }
    */
    *dst = 0;
    return 0;
}