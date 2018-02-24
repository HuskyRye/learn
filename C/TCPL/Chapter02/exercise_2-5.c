/*
	Date: 2018.2.21
	Author: 刘臣轩
*/

#include <stdio.h>

int any(char s1[], char s2[]);

int main()
{
    printf("any(\"123456789\", \"564\") = %d\n", any("123456789", "564"));
    printf("any(\"123456789\", \"abc\") = %d\n", any("123456789", "abc"));
    return 0;
}

/* return first location in s1 where any char from s2 occurs*/
int any(char s1[], char s2[])
{
    int j = 0;
    for (int i = 0; s1[i] != '\0'; ++i) {
        for (j = 0; s2[j] != '\0'; ++j)
            if (s1[i] == s2[j])
                return i;
    }
    return -1;
}
