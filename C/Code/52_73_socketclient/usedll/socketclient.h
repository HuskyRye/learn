#pragma Once
#ifdef __cplusplus
extern "C"
{
#endif

    //set one
    //初始化环境句柄
    int socketclient_init(void **handle);
    //发送信息
    int socketclient_send(void *handle, void *buf, int len);
    //接受信息
    int socketclient_receive(void *handle, void *buf, int *len);
    //释放资源
    int socketclient_destroy(void *handle);

    //set two
    //初始化环境句柄
    int socketclient_init2(void **handle);
    //发送信息
    int socketclient_send2(void *handle, void *buf, int len);
    //接受信息
    int socketclient_receive2(void *handle, void **buf, int *len);
    int socketclient_free2(void **buf);
    //释放资源
    int socketclient_destroy2(void **handle);

#ifdef __cplusplus
}
#endif
