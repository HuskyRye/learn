#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *args[])
{
    if (argc < 2)
        return -1;
    //struct stat
    struct stat st = {0};
    stat(args[1], &st);
    int size = st.st_size;
    printf("size = %d\n", size);

    system("pause");
    return 0;
}