/*
	Date: 2018.2.23
	Author: 刘臣轩
*/

#include <ctype.h>
#include <math.h> // -lm when compile
#include <stdio.h>

double atof(char s[]);
int atoi(char s[]);

int main()
{
    printf("atof(\"123\") = %g\n", atof("123"));
    printf("atof(\"-123\") = %g\n", atof("-123"));
    printf("atof(\"123.45\") = %g\n", atof("123.45"));
    printf("atof(\"-123.45\") = %g\n", atof("-123.45"));
    printf("atof(\"123.45e6\") = %g\n", atof("123.45e6"));
    printf("atof(\"-123.45e6\") = %g\n", atof("-123.45e6"));
    printf("atof(\"123.45e-6\") = %g\n", atof("123.45e-6"));
    printf("atof(\"-123.45e-6\") = %g\n", atof("-123.45e-6"));
    return 0;
}

/* convert string s to double */
double atof(char s[])
{
    int i;
    for (i = 0; isspace(s[i]); ++i)
        ;
    int sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        ++i;
    double val;
    for (val = 0.0; isdigit(s[i]); ++i)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        ++i;
    double power;
    for (power = 1.0; isdigit(s[i]); ++i) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    val = sign * val / power;
    int exponent = 0;
    if (s[i] == 'e' || s[i] == 'E')
        exponent = atoi(&s[++i]);

    return val * pow(10, exponent);
}

int atoi(char s[])
{
    return (int)atof(s);
}
