#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int my_isspace(const char *p, int *n);
int my_isspace2(const char *p, char *buf);

int main()
{
    char *p = "      abcdefg   ";
    int n = 0;
    int ret = my_isspace(p, &n);
    if (ret != 0)
    {
        return ret;
    }
    printf("n = %d\n", n);

    char buf[100] = {0};
    ret = my_isspace2(p, buf);
    if (ret != 0)
    {
        return ret;
    }
    printf("buf = %s\n", buf);
    system("pause");
    return 0;
}

int my_isspace(const char *p, int *n)
{
    if (p == NULL || n == NULL)
    {
        return -1;
    }
    int begin = 0;
    int end = strlen(p) - 1;

    while (isspace(p[begin]) && p[begin] != 0)
    {
        ++begin;
    }

    while (isspace(p[end]) && p[end] != 0)
    {
        --end;
    }
    *n = end - begin + 1;
    return 0;
}

int my_isspace2(const char *p, char *buf)
{

    int begin = 0;
    int end = strlen(p) - 1;
    int n = 0;

    while (isspace(p[begin]) && p[begin] != 0)
    {
        ++begin;
    }

    while (isspace(p[end]) && p[end] != 0)
    {
        --end;
    }
    n = end - begin + 1;
    strncpy(buf, p + begin, n);
    buf[n] = '\0';
    return 0;
}