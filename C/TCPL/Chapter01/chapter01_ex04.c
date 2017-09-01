#include <stdio.h>
/*
当 celsius = 0, 20, ..., 300时，
分别打印温度摄氏与华氏温度对照表
*/
int main()
{
    double fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;
    while (celsius <= upper) {
        fahr = 9.0*celsius/5.0+32.0;
        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius += step;
    }
}
