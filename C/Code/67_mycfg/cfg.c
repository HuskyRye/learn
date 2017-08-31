#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 8*1024

/* 
功能：获取非空字符串
参数：
	inbuf： 原始字符串buf首地址
	outbuf：非空字符串buf首地址
返回值：
	成功：0
	失败：非0
*/
int trimSpace(char *inbuf, char *outbuf)
{
	if (inbuf == NULL || outbuf == NULL)
	{
		return -1;
	}

	char *p = inbuf;
	int begin = 0;
	int end = strlen(p) - 1;
	int n = 0;

	if (end < 0){
		return -2;
	}

	//从左往右移动，如果当前字符为空，而且没有结束
	while (isspace(p[begin]) && p[begin] != 0)
	{
		begin++; //位置从右移动一位
	}

	//从右往左移动，如果当前字符为空
	while (isspace(p[end]) && end > 0)
	{
		end--; //往左移动
	}

	if (end == 0)
	{
		return -2;
	}

	n = end - begin + 1; //非空元素个数

	strncpy(outbuf, p + begin, n);
	outbuf[n] = 0;

	return 0;
}

int ReadCfgFile(char *file, char *key, char *value, int *len)
{
    if(file == NULL || key == NULL || value == NULL || len == NULL)
        return -1;
    int ret = 0;
    char lineBuf[1024] = {0};
    char *p = NULL;
    int flag = 0;
    FILE *fp = fopen(file, "r+");
    if(fp == NULL)
    {
        ret = -2;
        goto End;
    }
    while(fgets(lineBuf, sizeof(lineBuf), fp) != NULL)
    {
        p = strstr(lineBuf, key);
        if(p == NULL)
            continue;
        p = p + strlen(key);
        p = strstr(p, "=");
        if(p == NULL)
            continue;
        p = p + strlen("=");
        ret = trimSpace(p, value);
        if(ret == 0)
        {
            *len = strlen(value);
            flag = 1;
            goto End;
        }
        else
            goto End;
    }

End:
    if(fp != NULL)
    {
        fclose(fp);
        fp == NULL;
    }
    if(flag == 0)
    {
        ret = -3;
        printf("no such value for key %s\n", key);
    }
    return ret;
}

int WriteCfgFile(char *file, char *key, char *value, int len)
{
    if(file == NULL || key == NULL || value == NULL)
        return -1;
    int ret = 0;
    char lineBuf[1024] = {0};
    char buf[SIZE] = {0};
    char *p = NULL;
    int flag = 0;
    FILE *fp = fopen(file, "r+");
    if(fp == NULL)
    {
        fp = fopen(file, "w+");
        {
            if(fp == NULL)
            {
                ret = -2;
                goto End;
            }
        }
    }

    //get file size
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    if(size >= SIZE)
    {
        ret = -3;
        printf("over 8K, not support!");
        goto End;
    }
    rewind(fp);

    while(fgets(lineBuf, sizeof(lineBuf), fp) != NULL)
    {
        if(strstr(lineBuf, key) != NULL)
        {
            flag = 1;
            sprintf(lineBuf, "%s = %s\n", key, value);
            strcat(buf, lineBuf);
        }
        else
            strcat(buf, lineBuf);
    }
    if(0 == flag)
    {
        fprintf(fp, "%s = %s\n", key, value);
    }
    else
    {
        //关闭文件
		if (fp != NULL)
		{
			fclose(fp);
			fp = NULL;
		}

		fp = fopen(file, "w+"); 
		if (fp == NULL)
		{
			ret = -4;
			goto End;
		}
		//重写写内容
		fputs(buf, fp);
    }
End:
    if (fp != NULL)
    {
        fclose(fp);
        fp = NULL;
    }
    return ret;
}