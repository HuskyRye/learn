#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("err: ./cp src dst\n");
        return -1;
    }

    FILE *rFp = fopen(argv[1], "rb");
    FILE *wFp = fopen(argv[2], "wb");

    char buf[4 * 1024];
    unsigned int len;
    while ((len = fread(buf, 1, sizeof(buf), rFp)) != 0)
    {
        printf("len = %u\n", len);
        fwrite(buf, 1, len, wFp);
    }

    fclose(rFp);
    fclose(wFp);

    system("pause");
    return 0;
}
