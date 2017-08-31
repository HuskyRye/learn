#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socketclient.h"

int main01()
{
    void *handle = NULL;
    int ret = 0;
    ret = socketclient_init(&handle);
    if(ret != 0)
    {
        printf("socketclient_init.err:%d\n", ret);
        system("pause");
        return ret;
    }

    char buf[100] = "abcdefg";
    ret = socketclient_send(handle, buf, strlen(buf));
    if(ret != 0)
    {
        printf("socketclient_send.err:%d\n", ret);
        system("pause");
        return ret;       
    }
    printf("socketclient_send\n");

    memset(buf, 0, sizeof(buf));
    int len = 0;
    ret = socketclient_receive(handle, buf, &len);
    if(ret != 0)
    {
        printf("socketclient_receive.err:%d\n", ret);
        system("pause");
        return ret;
    }
    printf("socketclient_receive:%s, len = %d\n", buf, len);

    ret = socketclient_destroy(handle);
    if(ret != 0)
    {
        printf("socketclient_destroy.err:%d\n", ret);
        system("pause");
        return ret;       
    }
    handle = NULL;

    system("pause");
    return 0;
}

int main()
{
    void *handle = NULL;
    int ret = 0;
    ret = socketclient_init2(&handle);
    if(ret != 0)
    {
        printf("socketclient_init2.err:%d\n", ret);
        system("pause");
        return ret;
    }

    char buf[100] = "abcdefg";
    ret = socketclient_send2(handle, buf, strlen(buf));
    if(ret != 0)
    {
        printf("socketclient_send2.err:%d\n", ret);
        system("pause");
        return ret;       
    }
    printf("socketclient_send2\n");
    void *str = NULL;

    int len = 0;
    ret = socketclient_receive2(handle, &str, &len);
    if(ret != 0)
    {
        printf("socketclient_receive2.err:%d\n", ret);
        system("pause");
        return ret;
    }
    printf("socketclient_receive2:%s, len = %d\n", (char *)str, len);
    ret = socketclient_free2(&str);

    ret = socketclient_destroy2(&handle);
    if(ret != 0)
    {
        printf("socketclient_destroy2.err:%d\n", ret);
        system("pause");
        return ret;       
    }

    system("pause");
    return 0;    
}