#include <stdio.h>

int main()
{
    char comet[7];
    char group[7];
    scanf("%s", comet);
    scanf("%s", group);
    int sum1 = 1;
    int sum2 = 1;
    int i = 0;
    while (comet[i] != '\0')
    {
        sum1 *= (comet[i++] - 'A' + 1);
    }
    i = 0;
    while (group[i] != '\0')
    {
        sum2 *= (group[i++] - 'A' + 1);
    }
    printf("%s", ((sum1 % 47) == (sum2 % 47)) ? "GO" : "STAY");
    return 0;
}