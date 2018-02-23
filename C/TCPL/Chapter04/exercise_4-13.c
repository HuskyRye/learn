/*
	Date: 2018.2.23
	Author: 刘臣轩
*/

#include <stdio.h>
#include <string.h>

void reverse(char s[]);

int main()
{
    char s[] = "abcdefg";
    reverse(s);
    printf("%s\n", s);
    return 0;
}

void reverser(char s[], int i, int len);

void reverse(char s[])
{
    reverser(s, 0, strlen(s) - 1);
}

void reverser(char s[], int i, int len)
{
    int c;
    int j = len - i;
    if (i < j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        reverser(s, i + 1, len);
    }
}
