/*
    7.用一些 Number 执行习题 2 的程序
*/

#include "std_lib_facilities.h"
#include "chapter14_ex06.h"

template<class T> ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "{";
    for (int i = 0; i<v.size()-1; ++i)
        os << ' ' << v[i] << ',';
    os << ' ' << v[v.size()-1] << " }";
    return os;
}

template<typename T, typename U>
T f(vector<T> vt, vector<U> vu)
{
    T sum = 0;
    for (int i = 0; i < vt.size() && i < vu.size(); ++i)
        sum = sum + vt[i] * vu[i];
    return sum;
}

int main()
try {
    vector<Number<int>> v1;
    for (int i = 0; i<10; ++i)
        v1.push_back(i);
    cout << "v1: " << v1 << "\n";
    vector<Number<int>> v2;
    for (int i = 0; i<8; ++i)
        v2.push_back(i*1.6);
    cout << "v2: " << v2 << "\n";
    cout << "f(v1,v2): " << f(v1, v2) << "\n";
}
catch (exception& e) {
    cerr << "Exception: " << e.what() << "\n";
}
catch (...) {
    cerr << "Exception\n";
}