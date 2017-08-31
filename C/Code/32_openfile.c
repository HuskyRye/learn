#include <stdio.h>

int main()
{
    FILE *fp = NULL;
    fp = fopen("./text.txt", "w");
    //"w", no such file, create one, if exist, clear and open
    //"r", no such file, fail
    //"a", no such file, create one, if exist move the cursor to the end of the file
    fp = fopen("./text2.txt", "r");
    if (fp == NULL)
    {
        perror("fopen");
    }

    fp = fopen("./text2.txt", "a");
    perror("fopen");

    system("pause");
    return 0;
}