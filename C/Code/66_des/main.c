#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "des.h"

#define SIZE_4K 1024*4

void menu();
void EncFile();
void DecFile();

int main()
{
    int cmd = 0;
    while(1)
    {
        menu();
        printf("cmd:");
        scanf("%d", &cmd);
        //printf("cmd = %c\n", cmd);
        switch(cmd)
        {
        case 1:
            EncFile();
            break;
        case 2:
            DecFile();
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
	printf("=====================\n");
	printf("1 encrypt file\n");
	printf("2 decrypt file\n");
	printf("3 clear\n");
	printf("4 exit\n");
	printf("=====================\n");
}

void EncFile()
{
    FILE *rFd = NULL;
	FILE *wFd = NULL;
	char rPath[512] = { 0 }; //源文件路径， 需要加密文件路
	char wPath[512] = { 0 }; //目标路径， 保存加密后的文件
	unsigned char srcBuf[SIZE_4K] = { 0 }; //SIZE_4K
	int rLen = 0;
	unsigned char dstBuf[SIZE_4K] = { 0 }; //SIZE_4K
	int wLen = 0;
	int ret = 0;
    printf("please enter the file you want to encrypt:");
	scanf("%s", rPath);

	printf("please enter the file after encrypt:");
	scanf("%s", wPath);

    //打开源文件
    rFd = fopen(rPath, "rb+");
    if(rFd == NULL)
    {
        perror("EncFile fopen rPath");
        return;
    }

    //打开目标文件
    wFd = fopen(wPath, "wb+");
    if(wFd == NULL)
    {
        perror("EncFile fopen wPath");
        return;
    }

    //循环读文件，等于SIZE_4K
    while((rLen = fread(srcBuf, 1, SIZE_4K, rFd)) == SIZE_4K)
    {
        //加密文件
        ret = DesEnc_raw(srcBuf, rLen, dstBuf, &wLen);
        if(ret != 0)
        {
            printf("DesEnc_raw err\n");
            goto End;
            return;
        }
        //写加密文件
        ret = fwrite(dstBuf, 1, wLen, wFd);
        if(ret != wLen)
        {
            printf("EncFile write_raw err\n");
            goto End;
            return;
        }
    }
    //加密文件，小于SIZE_4K
    ret = DesEnc(srcBuf, rLen, dstBuf, &wLen);
    if(ret != 0)
    {
        printf("DesEnc err\n");
        goto End;
        return;
    }
    //写加密文件
    ret = fwrite(dstBuf, 1, wLen, wFd);
    if(ret != wLen)
    {
        printf("EncFile write err\n");
        goto End;
        return;
    }
//关闭文件
End:
    if(rFd != NULL)
        fclose(rFd);
    if(wFd != NULL)
        fclose(wFd);

}

void DecFile()
{
    FILE *rFd = NULL;
	FILE *wFd = NULL;
	char rPath[512] = { 0 }; //源文件路径， 需要读取文件路
	char wPath[512] = { 0 }; //目标路径， 保存解密后的文件
	unsigned char srcBuf[SIZE_4K] = { 0 }; //SIZE_4K
	int rLen = 0;
	unsigned char dstBuf[SIZE_4K] = { 0 }; //SIZE_4K
	int wLen = 0;
	int ret = 0;
    printf("please enter the file you want to decrypt:");
	scanf("%s", rPath);

	printf("please enter the file after decrypt:");
	scanf("%s", wPath);

    //打开源文件
    rFd = fopen(rPath, "rb+");
    if(rFd == NULL)
    {
        perror("DecFile fopen rPath");
        return;
    }

    //打开目标文件
    wFd = fopen(wPath, "wb+");
    if(wFd == NULL)
    {
        perror("DecFile fopen wPath");
        return;
    }

    //循环读文件，等于SIZE_4K
    while((rLen = fread(srcBuf, 1, SIZE_4K, rFd)) == SIZE_4K)
    {
        //解密文件
        ret = DesDec_raw(srcBuf, rLen, dstBuf, &wLen);
        if(ret != 0)
        {
            printf("DesDec_raw err\n");
            goto End;
            return;
        }
        //写解密文件
        ret = fwrite(dstBuf, 1, wLen, wFd);
        if(ret != wLen)
        {
            printf("DecFile write_raw err\n");
            goto End;
            return;
        }
    }
    //加密文件，小于SIZE_4K
    ret = DesDec(srcBuf, rLen, dstBuf, &wLen);
    if(ret != 0)
    {
        printf("DesDec err\n");
        goto End;
        return;
    }
    //写加密文件
    ret = fwrite(dstBuf, 1, wLen, wFd);
    if(ret != wLen)
    {
        printf("DecFile write err\n");
        goto End;
        return;
    }
//关闭文件
End:
    if(rFd != NULL)
        fclose(rFd);
    if(wFd != NULL)
        fclose(wFd);

}