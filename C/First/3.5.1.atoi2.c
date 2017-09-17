#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int atoi2(char s[]);

int main()
{
    char s[] = "     -1234567489";
    printf("atoi2(\"     -1234567489\") = %d\n", atoi2("     -1234567489"));
    system("pause");
    return 0;
}

/* atoi函数：将s转换为整形数；version2， 可选的前导空白符以及一个可选的正负号 */
int atoi2(char s[])
{
    int i;
    for (i = 0; isspace(s[i]); ++i)
        ;
    int sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == '-')
    {
        ++i;
    }
    int n;
    for (n = 0; isdigit(s[i]); ++i)
    {
        n = 10 * n + (s[i] - '0');
    }
    return sign * n;
}