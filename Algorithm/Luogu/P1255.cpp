/*
	Author: 刘臣轩
	Date: 2017.11.6
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstring>
using namespace std;

struct hp
{
	int num[400];	// 10000
	int len;
	hp();
	hp(int n);
	hp operator+(const hp&) const;
	hp& operator+=(const hp&);
};

hp::hp() {
	memset(num, 0, sizeof(num));
	len = 1;
}
hp::hp(int n) {
	num[1] = n;
	len = 1;
}
hp hp::operator+(const hp& b) const {
	hp c;
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
hp& hp::operator+=(const hp& b) {
	return *this = *this + b;
}
ostream& operator<<(ostream& ost, const hp& hp) {
	ost << hp.num[hp.len];
	for (int i = hp.len - 1; i >= 1; --i)
		ost << setw(4) << setfill('0') << hp.num[i];
	return ost;
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	hp a = 1, b = 1, c = 1;
	for (int i = 2; i <= n; ++i) {
		c = a + b;
		a = b;
		b = c;
	}
	cout << (n == 0 ? 0 : c) << endl;
	return 0;
}