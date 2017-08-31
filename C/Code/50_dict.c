#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//#define MAX 111111  //最大记录数

struct dict
{
    char *key;
    char *content;
};

void format_string(char *str);
int open_dict(struct dict **p, const char *dict_filename);
int search_dict(const struct dict *p, int size, const char *key, char *content);
void free_dict(struct dict *p, int size);
int get_dict_size(FILE *fp);

int main(int argc, char *args[])
{
    argc = 2;
    args[1] = ".\\dict.txt";
    //参数不足
    if (argc < 2)
    {
        printf("usage: %s dict-filename\n", args[0]);
        return 0;
    }
    clock_t start_ms = 0; //函数执行开始时间
    clock_t end_ms = 0;   //函数执行结束时间

    struct dict *p = NULL;
    start_ms = clock();
    //打开字典
    int dict_size = open_dict(&p, args[1]);
    printf("dict_size = %d\n", dict_size);
    //字典长度为0
    if (dict_size == 0)
        return 0;
    end_ms = clock();
    //打印程序执行时间
    printf("open_dict used %ld ms\n", end_ms - start_ms);

    char key[1024];
    char content[1024];
    //获取用户输入
    while (printf("Please enter the words you want to query(enter \":q\" to exit)\n") && (scanf("%s", key)))
    {
        //格式化
        //format_string(key);
        //退出
        if (strcmp(key, ":q") == 0)
            break;
        start_ms = clock();
        //查找单词
        if (search_dict(p, dict_size, key, content) == 0)
        {
            printf("no such word\n");
        }
        else
        {
            printf("%s\n", content);
        }
        end_ms = clock();
        //打印函数执行时间
        printf("search_dict used %ld ms\n\n", end_ms - start_ms);
        memset(key, 0, sizeof(key));
        memset(content, 0, sizeof(content));
    }
    start_ms = clock();
    free_dict(p, dict_size);
    end_ms = clock();
    //打印函数执行时间
    printf("free_dict used %ld ms\n", end_ms - start_ms);
    system("pause");
    return 0;
}

//去掉字符串结尾的回车，空格字符
void format_string(char *str)
{
    size_t i;
    for (i = strlen(str) - 1; i >= 0; i--)
    {
        if (str[i] != '\n' && str[i] != ' ' && str[i] != '\r')
        {
            str[i + 1] = '\0';
            break;
        }
    }
}

int get_dict_size(FILE *fp)
{
    if (fp == NULL)
        return 0;

    int i = 0;
    char buf[2048];
    while (fgets(buf, sizeof(buf), fp) && !feof(fp))
    {
        fgets(buf, sizeof(buf), fp);
        ++i;
    }
    //printf("get.i = %d", i);
    return i;
}

int open_dict(struct dict **p, const char *dict_filename)
{
    FILE *fp = fopen(dict_filename, "rb");
    if (fp == NULL)
        return 0;

    int dict_size = get_dict_size(fp);
    if (dict_size == 0)
        return 0;

    *p = (struct dict *)malloc(dict_size * sizeof(struct dict));
    memset(*p, 0, dict_size * sizeof(struct dict));

    char buf[1024] = {0};
    size_t len = 0;
    int i = 0;
    fseek(fp, 0L, SEEK_SET);
    while (fgets(buf, sizeof(buf), fp) && !feof(fp))
    {
        len = strlen(buf);
        if (len > 0)
        {
            (*(*p + i)).key = (char *)malloc(len);
            memset((*(*p + i)).key, 0, len);
            format_string(buf);
            strcpy((*(*p + i)).key, &buf[1]);
        }
        memset(buf, 0, sizeof(buf));
        fgets(buf, sizeof(buf), fp);
        len = strlen(buf);
        if (len > 0)
        {
            (*(*p + i)).content = (char *)malloc(len);
            memset((*(*p + i)).content, 0, len);
            format_string(buf);
            strcpy((*(*p + i)).content, &buf[6]);
        }
        memset(buf, 0, sizeof(buf));
        ++i;
    }
    fclose(fp);
    return i;
}

int search_dict(const struct dict *p, int size, const char *key, char *content)
{
    int i;
    for (i = 0; i < size; ++i)
    {
        if ((p[i].key == NULL) || (p[i].content == NULL))
        {
            //printf("continue");
            continue;
        }
        if (strcmp(key, (*(p + i)).key) == 0)
        {
            strcpy(content, (*(p + i)).content);
            return 1;
        }
    }
    return 0;
}

void free_dict(struct dict *p, int size)
{
    int i = 0;
    for (i = 0; i < size; ++i)
    {
        if ((*(p + i)).key)
        {
            free((*(p + i)).key);
            (*(p + i)).key = NULL;
        }
        if ((*(p + i)).content)
        {
            free((*(p + i)).content);
            (*(p + i)).content = NULL;
        }
    }
    free(p);
    p = NULL;
}
