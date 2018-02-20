/*
	Date: 2018.2.19
	Author: 刘臣轩
*/

#include <stdio.h>

float celsius(float fahr);

int main()
{
    for (int fahr = 0; fahr <= 300; fahr += 20)
        printf("%3d %6.1f\n", fahr, celsius(fahr));
}

/* convert fahrenheit into celsius */
float celsius(float fahr)
{
	return (5.0 / 9.0) * (fahr - 32);
}
