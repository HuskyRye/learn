#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp = fopen("test.txt", "w");

    /*
    char *p1 = "hello\n";
    fputs(p1, fp);
    char *p2= "abc\n";
    fputs(p2, fp); 
    */

    char *p[] = {"hello\n", "abc\n", "mike\n"};
    int i;
    int n = sizeof(p) / sizeof(p[0]);
    for (i = 0; i < n; ++i)
    {
        fputs(p[i], fp);
    }

    fclose(fp);
    fp = NULL;

    return 0;
}