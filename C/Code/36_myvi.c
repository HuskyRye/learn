#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp = fopen(argv[1], "w");

    char buf[1024];
    while(fgets(buf, sizeof(buf), stdin) && (strncmp(buf, ":wq", 3) != 0))
    {
        //fgets:read by line

        // fgets(buf, sizeof(buf), stdin);
        // if(strncmp(buf, ":wq", 3) == 0)
        // {
        //     break;
        // }
        int i;
        int n = strlen(buf);
        for(i = 0; i < n; ++i)
        {
            fputc(buf[i], fp);
        }
    }

    fclose(fp);
    fp = NULL;

    return 0;
}