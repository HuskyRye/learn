#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("test.txt", "r");

    char buf[100];

    /*
    fgets(buf, sizeof(buf), fp);
    printf("buf = %s\n", buf);

    fgets(buf, sizeof(buf), fp);
    printf("buf = %s\n", buf);

    fgets(buf, sizeof(buf), fp);
    printf("buf = %s\n", buf);

    fgets(buf, sizeof(buf), fp);
    printf("buf = %s\n", buf);

    memset(buf, 0, sizeof(buf));
    fgets(buf, sizeof(buf), fp);
    printf("buf = %s\n", buf);
    */

    while (fgets(buf, sizeof(buf), fp) && !(feof(fp)))
    {
        printf("buf = %s", buf);
    }

    fclose(fp);
    fp = NULL;

    system("pause");
    return 0;
}