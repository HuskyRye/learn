/*
	Date: 2018.2.19
	Author: 刘臣轩
*/

#include <stdio.h>

int main()
{
    for (int fahr = 300; fahr >= 0; fahr -= 20)
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}
