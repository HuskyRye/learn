/*
	Date: 2018.3.13
	Author: 刘臣轩
*/

#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

struct BigInterger {
    int num[200];
    int len;
    BigInterger()
    {
        memset(num, 0, sizeof(num));
        len = 1;
    }
    BigInterger& operator=(const char* s);
    BigInterger operator+(const BigInterger& b) const;
};

BigInterger& BigInterger::operator=(const char* s)
{
    while (*s == '0')
        ++s;
    int n = strlen(s);
    int j = 1, k = 1;
    for (int i = n - 1; i >= 0; --i) {
        if (k == 10000) {
            ++j;
            k = 1;
        }
        num[j] += k * (s[i] - '0');
        k *= 10;
    }
    len = j;
    return *this;
}

BigInterger BigInterger::operator+(const BigInterger& b) const
{
    BigInterger c;
    c.len = max(len, b.len);
    for (int i = 1; i <= c.len; ++i) {
        c.num[i] += num[i] + b.num[i];
        if (c.num[i] >= 10000) {
            c.num[i] -= 10000;
            ++c.num[i + 1];
        }
    }
    if (c.num[c.len + 1] > 0)
        ++c.len;
    return c;
}

istream& operator>>(istream& ist, BigInterger& bigint)
{
    string temp;
    ist >> temp;
    bigint = temp.c_str();
    return ist;
}

ostream& operator<<(ostream& ost, const BigInterger& bigint)
{
    cout << bigint.num[bigint.len];
    for (int i = bigint.len - 1; i >= 1; --i)
        ost << setw(4) << setfill('0') << bigint.num[i];
    return ost;
}

int main()
{
    ios::sync_with_stdio(false);
    BigInterger a, b;
    cin >> a >> b;
    cout << a + b << endl;
    return 0;
}
