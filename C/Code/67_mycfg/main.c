#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cfg.h"

#define CFGNAME "mycfg.ini"

void menu();
void MyRead();
void MyWrite();

int main()
{
    int cmd = 0;
    while(1)
    {
        menu();
        printf("cmd: ");
        scanf("%d", &cmd);
        switch(cmd)
        {
        case 1:
            MyRead();
            break;
        case 2:
            MyWrite();
            break;
        case 3:
            system("cls");
            break;
        default:
            exit(0);
            break;
        }
    }
    system("pause");
    return 0;
}

void menu()
{
    printf("===========================\n");
	printf("1 read config file\n");
	printf("2 write config file\n");
	printf("3 clear\n");
	printf("4 exit\n");
	printf("===========================\n");
}

void MyRead()
{
    char key[256] = {0};
    char value[1024] = {0};
    int len = 0;
    int ret = 0;
    printf("please enter the key:");
    scanf("%s", key);
    ret = ReadCfgFile(CFGNAME, key, value, &len);
    if(ret != 0)
    {
        printf("ReadCfgFile err:%d\n", ret);
        return;
    }
    printf("\nRead: %s = %s, len = %d\n", key, value, len);

}

void MyWrite()
{
    char key[256] = {0};
    char value[1024] = {0};
    int len = 0;
    int ret = 0;
    printf("please enter the key:");
    scanf("%s", key);
    printf("please enter the key value:");
    scanf("%s", value);
    len = sizeof(value);

    ret = WriteCfgFile(CFGNAME, key, value, len);
    if(ret != 0)
    {
        printf("WriteCfgFile err:%d\n", ret);
        return;
    }
    printf("\nWrite: %s = %s, len = %d\n", key, value, len);
}