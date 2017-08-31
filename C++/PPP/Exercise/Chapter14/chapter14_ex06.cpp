/*
    6.使用 Number<T> 类重新完成上面的习题，其中 T 可以是任何数值类型。
    尝试实现 % 运算符，观察对 Number<double> 和 Number<int> 进行 % 运算的结果
*/

#include "std_lib_facilities.h"
#include "chapter14_ex06.h"

int main()
try {
    cout << "int:\n";
    Number<int> i1;
    cout << "i1 (default constructed): " << i1 << "\n";
    Number<int> i2 = 2;
    cout << "i2 (constructed with argument): " << i2 << "\n";
    Number<int> i3(i2);
    cout << "i3 (copy constructed from i2): " << i3 << "\n";
    Number<int> i4;
    i4 = i2;
    cout << "i4 (copy assigned from i2): " << i4 << "\n";
    Number<int> i5 = 6;
    cout << "i5 (constructed with argument): " << i5 << "\n";
    cout << "i2 + i5 = " << i2+i5 << "\n";
    cout << "i5 - i2 = " << i5-i2 << "\n";
    cout << "i2 * i5 = " << i2*i5 << "\n";
    cout << "i5 / i2 = " << i5/i2 << "\n";
    cout << "i5 % i2 = " << i5%i2 << "\n";
    cout << "Number<int> i6 = ";
    Number<int> i6;
    cin >> i6;
    cout << "i6 (get assigned from cin): " << i6 << '\n';

    cout << "\ndouble:\n";
    Number<double> d1;
    cout << "d1 (default constructed): " << d1 << "\n";
    Number<double> d2 = 2.2;
    cout << "d2 (constructed with argument): " << d2 << "\n";
    Number<double> d3(d2);
    cout << "d3 (copy constructed from d2): " << d3 << "\n";
    Number<double> d4;
    d4 = d2;
    cout << "d4 (copy assigned  from d2): " << d4 << "\n";
    Number<double> d5 = 5.5;
    cout << "d5 (constructed with argument): " << d5 << "\n";
    cout << "d2 + d5 = " << d2+d5 << "\n";
    cout << "d5 - d2 = " << d5-d2 << "\n";
    cout << "d2 * d5 = " << d2*d5 << "\n";
    cout << "d5 / d2 = " << d5/d2 << "\n";
    // cout << "d5 % d2 = " << d5%d2 << "\n";

    Number<double> d6;
    cout << "Number<double> d6 = ";
    cin >> d6;
    cout << "d6 (get assigned from cin): " << d6 << '\n';

    cout << "\nchar:\n";
    Number<char> c1;
    cout << "c1 (default constructed): " << c1 << "\n";
    Number<char> c2 = 'x';
    cout << "c2 (constructed with argument): " << c2 << "\n";
    Number<char> c3(c2);
    cout << "c3 (copy constructed from c2): " << c3 << "\n";
    Number<char> c4;
    c4 = c2;
    cout << "c4 (copy assigned  from c2): " << c4 << "\n";
    Number<char> c5 = 'C';
    cout << "c5 (constructed with argument): " << c5 << "\n";
    cout << "c2 + c5 = " << c2+c5 << "\n";
    cout << "c5 - c2 = " << c5-c2 << "\n";
    cout << "c2 * c5 = " << c2*c5 << "\n";
    cout << "c5 / c2 = " << c5/c2 << "\n";
    cout << "c5 % c2 = " << c5%c2 << "\n";
    Number<char> c6;
    cout << "Number<char> c6 = ";
    cin >> c6;
    cout << "c6 (get assigned from cin): " << c6 << '\n';

    cout << "\nstring:\n";
    Number<string> s1;
    cout << "s1 (default constructed): " << s1 << "\n";
    Number<string> s2("xxx");
    cout << "s2 (constructed with argument): " << s2 << "\n";
    Number<string> s3(s2);
    cout << "s3 (copy constructed from s2): " << s3 << "\n";
    Number<string> s4;
    s4 = s2;
    cout << "s4 (copy assigned  from s2): " << s4 << "\n";
    Number<string> s5("ABCD!");
    cout << "s5 (constructed with argument): " << s5 << "\n";
    cout << "s2 + s5 = " << s2+s5 << "\n";
    Number<string> s6;
    cout << "Number<string> s6 = ";
    cin >> s6;
    cout << "s6 (get assigned from cin): " << s6 << '\n';

    return 0;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
