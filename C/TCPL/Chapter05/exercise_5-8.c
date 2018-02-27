/*
	Date: 2018.2.27
	Author: 刘臣轩
*/

#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int* pmonth, int* pday);

int main()
{
    printf("day_of_year(2018, 2, 27) = %d\n", day_of_year(2018, 2, 27));
    printf("day_of_year(2018, 2, 30) = %d\n", day_of_year(2018, 2, 30));
    int month;
    int day;
    month_day(2018, 58, &month, &day);
    printf("year_day(2018, 58, &month, &day), month = %d, day = %d\n", month, day);
    month_day(2018, 367, &month, &day);
    printf("year_day(2018, 367, &month, &day), month = %d, day = %d\n", month, day);
    return 0;
}

static char daytab[2][13] = {
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

/* set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    if (month < 1 || month > 12 || day < 1 || day > daytab[leap][month])
        return -1;
    for (int i = 1; i < month; ++i)
        day += daytab[leap][i];
    return day;
}

void month_day(int year, int yearday, int* pmonth, int* pday)
{
    if (year < 1) {
        *pmonth = -1;
        *pday = -1;
        return;
    }
    int leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    int i;
    for (i = 1; i <= 12 && yearday > daytab[leap][i]; ++i)
        yearday -= daytab[leap][i];
    if (i > 12 && yearday > 0) {
        *pmonth = -1;
        *pday = -1;
    } else {
        *pmonth = i;
        *pday = yearday;
    }
}
