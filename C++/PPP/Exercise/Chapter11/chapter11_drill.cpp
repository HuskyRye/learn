#include "std_lib_facilities.h"

int main()
{
    const int birth_year = 2001;
    cout << showbase << birth_year << '\t'
        << hex << birth_year << '\t'
        << oct << birth_year << '\t';
    const int age = 16;
    cout << dec << age << '\n';

    int a, b, c, d;
    cin >> a >> oct >> b >> hex >> c >> d;
    cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';

    cout << defaultfloat << 1234567.89 << '\t'
        << fixed << 1234567.89 << '\t'
        << scientific << 1234567.89 << '\n';

    cout << setw(8) << "张三" << " | " << "+86 12345678910" << " | " << setw(18) << "123456789@qq.com" << '\n'
        << setw(8) << "李四" << " | " << "+86 12345678910" << " | " << setw(18) << "1234567890@qq.com" << '\n'
        << setw(8) << "王二麻子" << " | " << "+86 12345678910" << " | " << setw(18) << "12345678@qq.com" << '\n'
        << setw(8) << "一二三" << " | " << "+86 12345678910" << " | " << setw(18) << "1234567@qq.com" << '\n'
        << setw(8) << "三二一" << " | " << "+86 12345678910" << " | " << setw(18) << "1234567898@qq.com" << '\n';
    return 0;
}