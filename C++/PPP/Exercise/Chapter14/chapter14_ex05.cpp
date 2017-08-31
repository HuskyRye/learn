/*
    5.定义 Int 类，该类包含一个 int 类的成员。定义该类的构造函数、赋值操作和 + - * / 运算符。
    定义 << 和 >> 运算符实现方便的 I/O
*/

#include "std_lib_facilities.h"

struct Int {
public:
    Int() : val { 0 } {}
    Int(int v) : val { v } {}
    Int& operator=(const Int& a);
    Int operator+(const Int& a);
    Int operator-(const Int& a);
    Int operator*(const Int& a);
    Int operator/(const Int& a);
    int get() const { return val; }
private:
    int val;
};

Int& Int::operator=(const Int& a)
{
    val = a.val;
    return *this;
}

Int Int::operator+(const Int& a)
{
    return Int(this->val+a.val);
}

Int Int::operator-(const Int& a)
{
    return Int(this->val-a.val);
}

Int Int::operator*(const Int& a)
{
    return Int(this->val*a.val);
}

Int Int::operator/(const Int& a)
{
    return Int(this->val/a.val);
}

ostream& operator<<(ostream& os, const Int& a)
{
    os << a.get();
    return os;
}

istream& operator>>(istream& is, Int &a)
{
    int v;
    is >> v;
    a = v;
    return is;
}

int main()
try {
    Int i1;
    cout << "i1 (default constructed): " << i1 << "\n";
    Int i2 = 2;
    cout << "i2 (constructed with argument): " << i2 << "\n";
    Int i3(i2);
    cout << "i3 (copy constructed from i2): " << i3 << "\n";
    Int i4;
    i4 = i2;
    cout << "i4 (copy assigned from i2): " << i4 << "\n";
    Int i5 = 6;
    cout << "i5 (constructed with argument): " << i5 << "\n";
    cout << "i2 + i5 = " << i2+i5 << "\n";
    cout << "i5 - i2 = " << i5-i2 << "\n";
    cout << "i2 * i5 = " << i2*i5 << "\n";
    cout << "i5 / i2 = " << i5/i2 << "\n";
    cout << "Int i6 = ";
    Int i6;
    cin >> i6;
    cout << "i6 (get assigned from cin): " << i6 << '\n';
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
