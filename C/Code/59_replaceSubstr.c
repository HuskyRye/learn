#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
有字符串有以下特征（“abcd11111abcd2222abcdqqqqq”）,求写一个函数接口，输出以下结果。
	把字符串替换成（dcba11111dcba2222dcbaqqqqq），并把结果传出。
	要求：
		1. 正确实现接口和功能
		2. 编写测试用例
	
	src:    原字符串
	dst:    生成的或需要填充的字符串
	sub:    需要查找的子字符串
	new_sub:提换的新子字符串

	return : 0 成功
			-1 失败

    int replaceSubstr(char *src, char** dst, char *sub, char *new_sub);
*/

int replaceSubstr(/*in*/ char *src, /*out*/ char **dst, /*in*/ char *sub, /*in*/ char *new_sub);
void free_dst(char **dst);

int main()
{
    char *p = "abcd11111abcd2222abcdqqqqq";
    char *dst = NULL;
    char *sub = "abcd";
    char *new_sub = "aaa";
    int ret = replaceSubstr(p, &dst, sub, new_sub);
    if (ret != 0)
    {
        printf("replaceSubstr.err:%d\n", ret);
        system("pause");
        return ret;
    }
    printf("p = %s\n", p);
    printf("dst = %s\n", dst);
    free_dst(&dst);
    free_dst(&dst);
    system("pause");
    return 0;
}

int replaceSubstr(/*in*/ char *src, /*out*/ char **dst, /*in*/ char *sub, /*in*/ char *new_sub)
{
    if (src == NULL || dst == NULL || sub == NULL || new_sub == NULL)
    {
        return -1;
    }
    char *start = src;
    char *p = strstr(start, sub);
    char tmp[512] = {0};
    int len = 0;

    while (*start != '\0')
    {
        p = strstr(start, sub);
        if (p != NULL)
        {
            len = p - start;
            if (len > 0)
            {
                strncat(tmp, start, len);
            }
            strncat(tmp, new_sub, strlen(new_sub));
            start = p + strlen(sub);
        }
        else
        {
            strcat(tmp, start);
            break;
        }
    }
    char *buf = (char *)malloc(strlen(tmp) + 1);
    strcpy(buf, tmp);
    *dst = buf;

    return 0;
}

void free_dst(char **dst)
{
    if (dst != NULL)
    {
        free(dst);
        *dst == NULL;
    }
}