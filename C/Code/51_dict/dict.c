#include "dict.h"

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
