#include <stdio.h>
#include <stdlib.h>

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main()
{
    char tmp[100];
    char t[] = "\tasdjklgjalgkd\nasdlkjglkdgj\t";
    printf("t = %s\n", t);
    escape(tmp, t);
    printf("tmp = %s\n", tmp);
    unescape(t, tmp);
    printf("t = %s\n", t);
    system("pause");
    return 0;
}

void escape(char s[], char t[])
{
    int i;
    int j = 0;
    for (i = 0; t[i] != '\0'; ++i)
    {
        switch (t[i])
        {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        default:
            s[j++] = t[i];
            break;
        }
    }
    s[j] = '\0';
}

void unescape(char s[], char t[])
{
    int i;
    int j = 0;
    for (i = 0; t[i] != '\0'; ++i)
    {
        if (t[i] == '\\')
        {
            switch (t[++i])
            {
            case 'n':
                s[j++] = '\n';
                break;
            case 't':
                s[j++] = '\t';
                break;
            default:
                s[j++] = '\\';
                s[j++] = t[i];
                break;
            }
        }
        else
        {
            s[j++] = t[i];
        }
    }
    s[j] = '\0';
}
