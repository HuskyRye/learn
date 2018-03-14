/*
	Author: 刘臣轩
	Date: 2017.10.22
	Source: NOIP 2006
*/

#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;

struct hp
{
	int num[50]{ 0 };    // 10000
	int len = 0;
	hp& operator+=(const hp&);
	hp operator+(const hp&) const;
};

hp& hp::operator+=(const hp& b)
{

	return *this = *this + b;
}

hp hp::operator+(const hp& b) const
{
	hp c;
	c.len = len > b.len ? len : b.len;
	for (int i = 0; i <= c.len; ++i) {
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

ostream& operator<<(ostream& ost, const hp& hp)
{
	ost << hp.num[hp.len];
	for (int i = hp.len - 1; i >= 0; --i) {
		ost.width(4);
		ost.fill('0');
		ost << hp.num[i];
	}
	return ost;
}

hp c[256][128];

inline hp& combination(int n, int m)
{
	if (m <= n / 2)
		return c[n][m];
	return c[n][n - m];
}

int main()
{
	ios::sync_with_stdio(false);

	int k, w;
	cin >> k >> w;

	hp one;
	one.num[0] = 1;
	for (int i = 0; i < 256; ++i)
	{
		c[i][0] = one;
		for (int j = 1; j <= i / 2; ++j) {
			c[i][j] = combination(i - 1, j - 1) + combination(i - 1,j);
		}
	}

	int a = w / k;
	int b = w % k;

	int n = pow(2, k) - 1;

	hp sum;
	int min = a < n ? a : n;
	for (int i = 2; i <= min; ++i) {
		sum += combination(n, i);
	}

	if (b) {
		int m = pow(2, b) - 1;
		min = m < n - a ? m : n - a;
		for (int i = 1; i <= min; ++i)
			sum += combination(n - i, a);
	}
	cout << sum << '\n';
}