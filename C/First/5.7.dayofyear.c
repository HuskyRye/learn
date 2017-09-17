#include <stdio.h>
#include <stdlib.h>

static char daytab[2][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if (month < 1 || month > 12 || day > daytab[leap][month - 1] || day < 1)
    {
        return -1;
    }
    for (i = 0; i < month - 1; i++)
    {
        day += daytab[leap][i];
    }
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    if (year < 1)
    {
        *pmonth = -1;
        *pday = -1;
        return;
    }
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if (year > (leap ? 366, 365))
    {
        *pmonth = -1;
        *pday = -1;
        return;
    }
    for (i = 0; yearday > daytab[leap][i]; ++i)
    {
        yearday -= daytab[leap][i];
    }
    *pmonth = i + 1;
    *pday = yearday;
}

int main()
{
    printf("%d\n", day_of_year(2012, 3, 1));
    printf("%d\n", day_of_year(2017, 3, 1));

    int month = 0;
    int day = 0;
    month_day(2012, 61, &month, &day);
    printf("%d.%d\n", month, day);

    month_day(2017, 60, &month, &day);
    printf("%d.%d\n", month, day);

    system("pause");
    return 0;
}