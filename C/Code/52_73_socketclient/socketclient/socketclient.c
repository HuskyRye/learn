#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "socketclient.h"

typedef struct SocketHandle
{
    char ip[100];
    unsigned int port;
    void *buf;
    int len;
}SocketHandle;

//初始化环境句柄
__declspec(dllexport)
int socketclient_init(void **handle)
{
    if(handle == NULL)
        return -1;
    SocketHandle *hd = NULL;
    hd = (SocketHandle *)malloc(sizeof(SocketHandle));
    if(hd == NULL)
        return -2;
    memset(hd, 0, sizeof(SocketHandle));
    strcpy(hd->ip, "255.255.255.255");
    hd->port = 8888;
    hd->buf = NULL;
    hd->len = 0;

    *handle = (void *)hd;

    return 0;
}
//发送信息
__declspec(dllexport)
int socketclient_send(void *handle, void *buf, int len)
{
    if(handle == NULL || buf == NULL)
        return -1;

    SocketHandle *hd = (SocketHandle *)handle;

    if(hd->buf != NULL)
    {
        free(hd->buf);
        hd->buf = NULL;
    }
    hd->buf = (char *)malloc(len);
    if(hd->buf == NULL)
        return -2;

    memcpy(hd->buf, buf, len);
    hd->len = len;
    
    return 0;
}
//接受信息
__declspec(dllexport)
int socketclient_receive(void *handle, void *buf, int *len)
{
    if(handle == NULL || buf == NULL)
        return -1;
    SocketHandle *hd = (SocketHandle *)handle;
    if(hd->buf != NULL)        
    {
        memcpy(buf, hd->buf, hd->len);
        *len = hd->len;
    }
    else
        return -2;
    return 0;
}
//释放资源
__declspec(dllexport)
int socketclient_destroy(void *handle)
{
    if(handle == NULL)
        return -1;
    SocketHandle *hd = (SocketHandle *)handle;
        
    if(hd->buf != NULL)
    {
        free(hd->buf);
        hd->buf = NULL;
    }
    if(hd != NULL)
    {
        free(hd);
        hd == NULL;
    }
    return 0;
}


//初始化环境句柄
__declspec(dllexport)
int socketclient_init2(void **handle)
{
    return socketclient_init(handle);
}
//发送信息
__declspec(dllexport)
int socketclient_send2(void *handle, void *buf, int len)
{
    socketclient_send(handle, buf, len);
    return 0;
}
//接受信息
__declspec(dllexport)
int socketclient_receive2(void *handle, void **buf, int *len)
{
    if(handle == NULL || buf == NULL)
        return -1;
    SocketHandle *hd = (SocketHandle *)handle;
    if(hd->buf != NULL)        
    {
        char *tmp = (char *)malloc(hd->len + 1);
        if(tmp == NULL)
            return -3;
        memset(tmp, 0, hd->len + 1);
        //memcpy(buf, hd->buf, hd->len);
        //strcpy(tmp, (char *)hd->buf);
        strncpy(tmp, (char *)hd->buf, hd->len);

        *buf = (void *)tmp;
        *len = hd->len;
    }
    else
        return -2;
    return 0;
}
__declspec(dllexport)
int socketclient_free2(void **buf)
{
    if(buf == NULL)
        return -1;
    if(*buf != NULL)
    {
        free(*buf);
        *buf = NULL;
    }
    return 0;
}
//释放资源
__declspec(dllexport)
int socketclient_destroy2(void **handle)
{
    socketclient_destroy(*handle);
    *handle = NULL;
    return 0;
}