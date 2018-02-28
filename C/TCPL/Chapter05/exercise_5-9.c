/*
	Date: 2018.2.28
	Author: 刘臣轩
*/

#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int* pmonth, int* pday);

int main()
{
    printf("day_of_year(2018, 2, 28) = %d\n", day_of_year(2018, 2, 28));
    int month;
    int day;
    month_day(2018, 59, &month, &day);
    printf("year_day(2018, 59, &month, &day), month = %d, day = %d\n", month, day);
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
    char* p = *(daytab + leap);
    while (--month)
        day += *(++p);
    return day;
}

void month_day(int year, int yearday, int* pmonth, int* pday)
{

    int leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    char* p = *(daytab + leap);
    while (yearday > *(++p))
        yearday -= *p;
    *pmonth = p - *(daytab + leap);
    *pday = yearday;
}
