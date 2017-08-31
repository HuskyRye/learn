#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*有一个字符串符合以下特征（“abcdef,acccd,eeee,aaaa,e3eeee,ssss,”）

	写两个函数(API)，输出以下结果
	第一个API(第二种内存模型： 二维数组)
	1)以逗号分隔字符串，形成二维数组，并把结果传出
	2)把二维数组行数运算结果也传出
	int spitString(const char *str, char c, char buf[10][30], int *count);

	第二个API(第三种内存模型：动态生成二维内存)
	1)以逗号分隔字符串，形成一个二级指针。
	2)把一共拆分多少行字符串个数传出
	int spitString2(const char *str, char c, char **myp, int *count);

	要求：
	1, 能正确表达功能的要求，定义出接口。
	2, 正确实现接口和功能.
	3, 编写正确的测试用例.
*/

int spitString(const char *str, char c, char buf[10][30] /*in*/, int *count);
int spitString2(const char *str, char c, char **myp /*in*/, int *count);
char **getMem(int n);
int getMem2(char ***myp, int n);
void freemyp(char ***myp, int n);

int main()
{
    const char *str = "abcdef,acccd,eeee,aaaa,e3eeee,ssss";
    int ret = 0;
    char buf[10][30];
    int n = 0;
    ret = spitString(str, ',', buf, &n);
    if (ret != 0)
    {
        printf("spitString.err:%d\n", ret);
        system("pause");
        return ret;
    }
    int i = 0;
    for (i = 0; i < n; ++i)
    {
        printf("%s\n", buf[i]);
    }

    printf("\n");

    char **myp = NULL;
    //myp = getMem(6);
    ret = getMem2(&myp, 6);
    if (ret != 0)
    {
        printf("getMem2.err:%d\n", ret);
        return ret;
    }
    if (myp == NULL)
    {
        return -1;
    }
    ret = spitString2(str, ',', myp, &n);
    if (ret != 0)
    {
        printf("spitString2.err:%d\n", ret);
        system("pause");
        return ret;
    }
    for (i = 0; i < n; ++i)
    {
        printf("%s\n", buf[i]);
    }
    freemyp(&myp, n);

    system("pause");
    return 0;
}

int spitString(const char *str, char c, char buf[10][30] /*in*/, int *count)
{
    if (str == NULL || count == NULL)
    {
        return -1;
    }
    const char *start = str;
    char *p = NULL;
    int i = 0;
    int len = 0;
    while (*start != '\0')
    {
        p = strchr(start, c);
        if (p != NULL)
        {
            len = p - start;
            strncpy(buf[i], start, len);
            buf[i][len] = '\0';
            ++i;
            start = p + 1;
        }
        else
        {
            strcpy(buf[i], start);
            ++i;
            break;
        }
    }
    if (i == 0)
    {
        return -2;
    }
    *count = i;
    return 0;
}

int spitString2(const char *str, char c, char **buf /*in*/, int *count)
{
    if (str == NULL || count == NULL || buf == NULL)
    {
        return -1;
    }
    const char *start = str;
    char *p = NULL;
    int i = 0;
    int len = 0;
    while (*start != '\0')
    {
        p = strchr(start, c);
        if (p != NULL)
        {
            len = p - start;
            strncpy(buf[i], start, len);
            buf[i][len] = '\0';
            ++i;
            start = p + 1;
        }
        else
        {
            strcpy(buf[i], start);
            ++i;
            break;
        }
    }
    if (i == 0)
    {
        return -2;
    }
    *count = i;
    return 0;
}

char **getMem(int n)
{
    char **buf = NULL;
    buf = (char **)malloc(n * sizeof(char *));
    if (buf == NULL)
    {
        return NULL;
    }
    int i = 0;
    for (i = 0; i < n; ++i)
    {
        buf[i] = (char *)malloc(30);
    }
    return buf;
}

int getMem2(char ***myp, int n)
{
    char **buf = NULL;
    buf = (char **)malloc(n * sizeof(char *));
    if (buf == NULL)
    {
        return -1;
    }
    int i = 0;
    for (i = 0; i < n; ++i)
    {
        buf[i] = (char *)malloc(30);
    }
    *myp = buf;
    return 0;
}

void freemyp(char ***myp, int n)
{
    int i = 0;
    for (i = 0; i < n; ++i)
    {
        free((*myp)[i]);
        (*myp)[i] = NULL;
    }
    if (*myp != NULL)
    {
        free(*myp);
        *myp = NULL;
    }
}