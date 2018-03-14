#include <iostream>
#include <string>
#include <algorithm>    // for sort

using namespace std;

int main()
{
    int a, b, c;
    for (a = 123; a < 329; ++a) // 最小的一个是123，最大的一个是987/3
    {
        b = a * 2;
        c = a * 3;
        string s = to_string(a)+to_string(b)+to_string(c);  // 全部变成字符串
        sort(s.begin(), s.end());
        if (s == "123456789")       // 如果所有数字都用到了，就应该等于这个字符串
            cout << a << ' ' << b << ' ' << c << '\n';
    }
    return 0;
}