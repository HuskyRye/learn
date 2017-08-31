/*
    6.编写程序，实现摄氏温度与华氏温度互相转换
*/

#include "std_lib_facilities.h"

double ctof(double c)
{
    if (c < -273.15)
        throw runtime_error("Temperature below absolute zero!");
    return 9.0/5*c+32;
}

double ftoc(double f)
{
    if (f < -459.67)
        throw runtime_error("Temperature below absolute zero!");
    return (f-32)*5/9.0;
}

int main()
try {
    cout << "Enter temperature to be converted and unit (C or F)\n";
    double before = 0;
    char unit;
    cin >> before >> unit;
    double after;
    switch (unit) {
    case 'C':
        after = ctof(before);
        break;
    case 'F':
        after = ftoc(before);
        break;
    default:
        throw runtime_error("Illegal unit, must be C or F");
    }
    cout << after << ((unit == 'C') ? 'F' : 'C') << '\n';
}
catch (exception& e) {
    cerr << "exception: " << e.what() << '\n';
}