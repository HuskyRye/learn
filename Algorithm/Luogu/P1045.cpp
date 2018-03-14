/*
	Author: 刘臣轩
	Date: 2017.11.10
	Source: NOIP 2003 普及
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <cstring>
using namespace std;

struct hp
{
	short num[1005];
	int len;
	hp();
	hp(int n);
	hp operator*(const hp&) const;
	hp& operator*=(const hp&);
};
hp::hp() {
	memset(num, 0, sizeof(num));
	len = 1;
}
hp::hp(int n) {
	num[1] = n;
	len = 1;
}
hp hp::operator*(const hp& b) const {
	hp c;
	c.len = min(len + b.len, 1000);
	for (int i = 1; i <= min(len, 500); ++i)
		for (int j = 1; j <= min(b.len, 500); ++j)
			c.num[i+j-1] += num[i] * b.num[j];
	for (int i = 1; i <= c.len; ++i) {
		c.num[i+1] += c.num[i] / 10;
		c.num[i] %= 10;
	}
	while (c.num[c.len] == 0 && c.len > 1)
		--c.len;
	return c;

}
hp& hp::operator*=(const hp& b) {
	return *this = *this * b;
}
ostream& operator<<(ostream& ost, hp& hp) {
	for (int i = 500; i >= 50; i -= 50) {
		for (int j = i; j > i-50; --j)
			cout << hp.num[j];
		cout << endl;
	}
	return ost;
}

hp quickpow(int a, int b) {
	if (b == 0)
		return 1;
	hp r = quickpow(a, b/2);
	r *= r;
	if (b % 2)
		r *= a;
	return r;
}

int main() {
	ios::sync_with_stdio(false);
	int p;
	cin >> p;
	cout << int(p*log10(2)+1) << endl;
	hp ans = quickpow(2, p);
	ans.num[1] -= 1;
	cout << ans << endl;
	return 0;
}