#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n, r;
    cin >> n >> r;
    cout << n << '=';           // output first
    string s;
    char c[] = { "0123456789ABCDEFGHIJ" };
    while (n != 0) {
        int m = n%r;
        n /= r;
        if (m < 0) {
            m = m-r;
            ++n;
        }
        s += c[m];
    }
    reverse(s.begin(), s.end());
    cout << s << "(base" << r << ")\n";
}