#include <stdio.h>

int main()
{
    float fahr, celsius;

    int lower = -20;
    int upper = 160;
    int step = 20;

    printf("Celsius to Fahrenheit table\n");

    celsius = lower;
    while (celsius <= upper) {
        fahr = (9.0 / 5.0) * celsius + 32;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius += step;
    }
}
