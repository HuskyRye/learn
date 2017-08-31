#include <stdio.h>

int main()
{
    FILE *fp = fopen("test.txt", "w");
    fputs("1", fp);

    //fclose(fp);
    fflush(fp);

    while (1)
    {
    };

    return 0;
}