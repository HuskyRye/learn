#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFLINES 5
#define LINES 100
#define MAXLINE 100

int main(int argc, char *argv[])
{

    int n, i;
    int pos = 0;
    char *p;

    char line[MAXLINE];
    char *lineptr[LINES] = {NULL};
    if (argc == 1)
    {
        n = DEFLINES;
    }
    else if (argc == 2 && (*++argv)[0] == '-')
    {
        sscanf(argv[1], "-%d", &n);
    }
    else
    {
        printf("tail -n\n");
        return -1;
    }

    while (gets(line) && strlen(line) > 0)
    {
        p = (char *)malloc(sizeof(strlen(line) + 1));
        strcpy(p, line);
        lineptr[pos++] = p;
        if (pos == LINES)
        {
            break;
        }
    }
    pos -= n;
    if (pos < 0)
    {
        pos = 0;
    }
    for (i = 0; i < n; ++i)
    {
        printf("%d: %s\n", i + 1, lineptr[pos++]);
    }
    system("pause");
    return 0;
}
