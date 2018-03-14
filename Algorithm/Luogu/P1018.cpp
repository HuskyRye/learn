/*
	Author: 刘臣轩
	Date: 2017.10.29
	Source: NOIP 2000
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <iomanip>
using namespace std;


struct hp
{
	int num[100];	// 10000
	int len;
	hp();
	hp(int n);
	hp& operator=(const char*);
	hp& operator=(const int);
	bool operator>(const hp& b) const;
	bool operator<(const hp& b) const;
	hp operator+(const hp& b) const;
	hp operator*(const hp& b) const;
	hp& operator*=(const hp& b);
};
hp::hp(){
	memset(num, 0, sizeof(num));
	len = 1;
}
hp::hp(int n) {
	*this = n;
}
hp& hp::operator=(const char* c) {
	memset(num, 0, sizeof(num));
	int n = strlen(c);
	int j = 1, k = 1;
	for (int i = n - 1; i >= 0; --i) {
		if (k == 10000)
			++j, k = 1;
		num[j] += k * (c[i] - '0');
		k *= 10;
	}
	len = j;
	return *this;
}
hp& hp::operator=(const int a) {
	return *this = to_string(a).c_str();
}
bool hp::operator>(const hp& b) const {
	if (len != b.len)
		return len > b.len;
	for (int i = len; i > 0; --i)
		if (num[i] != b.num[i])
			return num[i] > b.num[i];
	return false;
}
bool hp::operator<(const hp& b) const {
	return b > *this;
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

hp hp::operator*(const hp& b) const {
	hp c;
	c.len = len + b.len;
	for (int i = 1; i <= len; ++i) {
		for (int j = 1; j <= b.len; ++j) {
			c.num[i + j - 1] += num[i] * b.num[j];
			c.num[i + j] += c.num[i + j - 1] / 10000;
			c.num[i + j - 1] %= 10000;
		}
	 }
	while (c.num[c.len] == 0 && c.len > 1)
		--c.len;
	return c;
}
hp& hp::operator*=(const hp& b) {
	return *this = *this * b;
}
ostream& operator<<(ostream& ost, const hp& hp) {
	ost << hp.num[hp.len];
	for (int i = hp.len - 1; i > 0; --i)
		cout << setw(4) << setfill('0') << hp.num[i];
	return ost;
}

hp s[50][50];
hp f[50][10];
int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		char c;
		cin >> c;
		s[i][i] = c - '0';
		hp t = 1;
		for (int j = i - 1; j > 0; --j)
			s[j][i] = (s[j][j] * (t *= 10)) + s[j + 1][i];
		f[i][0] = s[1][i];
	}

	for (int i = 1; i <= n; ++i) {
		for (int l = 1; l <= min(k, i - 1); ++l) {
			for (int j = 1; j < i; ++j) {
				f[i][l] = max(f[i][l], f[j][l - 1] * s[j + 1][i]);
			}
		}
	}
	cout << f[n][k] << endl;
	return 0;
}