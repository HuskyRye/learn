#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 1000

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);
int strrindex(char source[], char searchfor[]);

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int found = 0;

    long lineno = 0;
    int c;
    int except = 0;
    int number = 0;
    while (--argc > 0 && (*++argv)[0] == '-')
    {
        while (c = **(++argv))
        {
            switch (c)
            {
            case 'x':
                except = 1;
                break;
            case 'n':
                number =  1;
                break;
            default:
                printf("find: illegal option %c \n", c);
                argc = 0;
                found = -1;
                break;
            }
        }
    }
    if (argc != 1)
    {
        printf("Usage: find -x -n pattern\n");
    }
    else
    {
        while (getline(line, MAXLINE) > 0)
        {
            // if (strindex(line, argv[1]) >= 0)
            lineno++;
            if (strstr(line, argv[1]) != NULL != except)
            {
                if (number)
                    printf("%ld", lineno);
                printf("%s", line);
                ++found;
            }
        }

    }
    system("pause");
    return found;
}

//将行保存到s中，并返回该行的长度
int getline(char s[], int max)
{
    int c, i;
    i = 0;
    while (--max > 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if (c == '\n')
    {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

//返回t在s中的位置，未找到则返回-1
int strindex(char s[], char t[])
{
    int i, j, k;
    for (i = 0; s[i] != '\0'; ++i)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k)
        {
            ;
        }
        if (k > 0 && t[k] == '\0')
        {
            return i;
        }
    }
    return -1;
}

//返回字符串t在s中最右边出现的位置
int strrindex(char s[], char t[])
{
    int i, j, k;
    int pos = -1;
    for (i = 0; s[i] != '\0'; ++i)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k)
        {
            ;
        }
        if (k > 0 && t[k] == '\0')
        {
            pos = i;
        }
    }
    return pos;
}

/*
Ah love! Could you and I with him conspire
To grasp this sorry scheme of things entire,
Would we not shatter it to bits - and then
Remould it nearer to the heart's desire!
*/