#include <stdio.h>

int main(int argc, char *argv[])
{   
    //open file
    FILE *fp = fopen(argv[1], "r");
    //read file
    char ch;
    while( (ch = fgetc(fp)) != EOF )
    {
        printf("%c", ch);
    }
    //close file
    fclose(fp);
    fp = NULL;

    //system("pause");
    return 0;
}