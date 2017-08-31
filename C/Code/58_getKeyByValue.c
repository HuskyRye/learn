#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int trimSpace(char *inbuf, char *outbuf);
int getKeyByValue(char *keyvaluebuf, char *keybuf, char *valuebuf, int *valuebuflen);

int main()
{
    char *keyVal = "key4        = ";
    char *key = "key4";
    char value[100] = {0};
    int len = 0;
    int ret = 0;
    ret = getKeyByValue(keyVal, key, value, &len);
    if (ret != 0)
    {
        printf("getKeyByValue.err:%d\n", ret);
        system("pause");
        return -1;
    }
    printf("value = %s\nlen = %d\n", value, len);
    /*
    char *p = "      abcdefg     ";
    char buf[100] = {0};
    int ret = trimSpace(p, buf);
    if(ret != 0)
    {
        printf("trimSpace.err:%d\n", ret);
        return ret;
    }
    printf("buf = %s\n", buf); 
    */

    system("pause");
    return 0;
}

int trimSpace(char *inbuf, char *outbuf)
{
    if (inbuf == NULL || outbuf == NULL)
    {
        return -1;
    }
    int begin = 0;
    int end = strlen(inbuf) - 1;
    int n = 0;

    while (isspace(inbuf[begin]) && inbuf[begin] != 0)
    {
        ++begin;
    }

    while (isspace(inbuf[end]) && inbuf[end] != 0 && end > 0)
    {
        --end;
    }
    while (end == 0)
    {
        return -2;
    }
    n = end - begin + 1;
    strncpy(outbuf, inbuf + begin, n);
    outbuf[n] = '\0';
    return 0;
}

/* 
键值对（“key = value”）字符串，在开发中经常使用
要求1：请自己定义一个接口，实现根据key获取.
要求2：编写测试用例。
要求3：键值对中间可能有n多空格，请去除空格

注意：键值对字符串格式可能如下：
"key1 = value1"
"key2 =       value2"
"key3  = value3"
"key4        = value4"
"key5   =   "
"key6   =" 
*/
int getKeyByValue(char *keyvaluebuf, char *keybuf, char *valuebuf, int *valuebuflen)
{
    if (keyvaluebuf == NULL || keybuf == NULL || valuebuf == NULL || valuebuflen == NULL)
    {
        return -1;
    }
    //查找匹配键值
    char *p = NULL;
    p = strstr(keyvaluebuf, keybuf);
    if (p == NULL)
    {
        return -2;
    }
    p = p + strlen(keybuf);
    p = strstr(p, "=");
    if (p == NULL)
    {
        return -3;
    }
    p = p + strlen("=");

    int ret = 0;
    ret = trimSpace(p, valuebuf);
    if (ret != 0)
    {
        printf("trimSpace.err:%d\n", ret);
        return ret;
    }
    *valuebuflen = strlen(valuebuf);

    return 0;
}