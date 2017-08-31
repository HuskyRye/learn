/*
    2.修改代码中的错误
    3.当输入小于 -273.15 的数值时，主程序产生错误
    4.将错误处理放在 ctok() 中
*/

#include "std_lib_facilities.h"

double ctok(double c)
{
    if (c < -273.15)
        throw runtime_error("Temperature below absolute zero!");
    return c+273.15;
}

double ktoc(double k)
{
    if (k < 0)
        throw runtime_error("Temperature below absolute zero!");
    return k-273.15;
}

int main()
try {
    cout << "Enter temperature to be converted and unit (C or K)\n";
    double before = 0;
    char unit;
    cin >> before >> unit;
    double after;
    switch (unit) {
    case 'C':
        after = ctok(before);
        break;
    case 'K':
        after = ktoc(before);
        break;
    default:
        throw runtime_error("Illegal unit, must be C or K");
    }
    cout << after << ((unit == 'C') ? 'K' : 'C') << '\n';
}
catch (exception& e) {
    cerr << "exception: " << e.what() << '\n';
}