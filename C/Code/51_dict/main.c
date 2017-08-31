#include "dict.h"

int main(int argc, char *args[])
{
    //argc = 2;
    //args[1] = ".\\dict.txt";
    //参数不足
    if (argc < 2)
    {
        printf("usage: %s dict-filename\n", args[0]);
        system("pause");
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
