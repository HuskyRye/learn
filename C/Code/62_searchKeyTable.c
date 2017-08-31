#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//找到数组中指定字符串的位置

//宏定义
#define NUM(a) (sizeof(a) / sizeof(*a))

int searcheKeyTable(const char *table[], const int size, const char *key, int *pos);

int main()
{
    const char *keywords[] = {
        "while",
        "case",
        "static",
        "do"};
    int ret = 0;
    int pos = 0;
    ret = searcheKeyTable(keywords, NUM(keywords), "case", &pos);
    if (ret != 0)
    {
        printf("searcheKeyTable.err:%d\n", ret);
        system("pause");
        return -1;
    }
    printf("pos = %d\n", pos);
    system("pause");
    return 0;
}

int searcheKeyTable(const char *table[], const int size, const char *key, int *pos)
{
    if (table == NULL || key == NULL || pos == NULL)
    {
        return -1;
    }
    int i = 0;
    for (i = 0; i < size; ++i)
    {
        //if(key == table[i])   //能这么写是因为都指向了文字常量区
        if (strcmp(table[i], key) == 0)
        {
            *pos = i + 1;
            return 0;
        }
    }
    return -1;
}