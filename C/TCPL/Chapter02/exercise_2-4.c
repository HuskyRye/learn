/*
	Date: 2018.2.21
	Author: 刘臣轩
*/

#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main()
{
    char s1[] = "123456789";
    char s2[] = "159";
    squeeze(s1, s2);
    printf("squeeze(\"123456789\", \"159\");\ns1 = %s\n", s1);
    return 0;
}

/* delete each char in s1 which is in s2 */
void squeeze(char s1[], char s2[])
{
    int j = 0;
    int k = 0;
    for (int i = 0; s1[i] != '\0'; ++i) {
        for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; ++j)
            ;
        if (s2[j] == '\0')
            s1[k++] = s1[i];
    }
    s1[k] = '\0';
}
