/*
	Author: 刘臣轩
	Date: 2017.11.5
	Source: NOIP 2012 Day1 T2
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

struct Minister
{
	int left;
	int right;
}minister[1010];

struct hp
{
	int num[1000];	// 10000
	int len;
	hp();
	hp(const int&);
	hp operator*(const int&) const;
	hp operator/(const int&) const;
	hp& operator*=(const int&);

	bool operator>(const hp&) const;
};

hp::hp() {
	memset(num, 0, sizeof(num));
	len = 1;
}
hp::hp(const int& n) {
	num[1] = n;
	len = 1;
}
hp hp::operator*(const int& b) const {
	hp c;
	c.len = len + 1;
	for (int i = 1; i <= len; ++i) {
		c.num[i] += num[i] * b;
		c.num[i + 1] += c.num[i] / 10000;
		c.num[i] %= 10000;
	}
	while (c.num[c.len] == 0 && c.len > 1)
		--c.len;
	return c;
}
hp hp::operator/(const int& b) const {
	hp c;
	int d = 0;
	c.len = len;
	for (int i = len; i >= 1; --i) {
		d = d * 10000 + num[i];
		c.num[i] = d / b;
		d %= b;
	}
	while (c.num[c.len] == 0 && c.len > 1)
		--c.len;
	return c;
}
hp & hp::operator*=(const int &b) {
	return *this = *this * b;
}
bool hp::operator>(const hp& b) const {
	if (len != b.len)
		return len > b.len;
	for (int i = len; i >= 1; --i)
		if (num[i] != b.num[i])
			return num[i] > b.num[i];
	return false;
}
ostream& operator<<(ostream& ost, const hp& hp) {
	cout << hp.num[hp.len];
	for (int i = hp.len - 1; i >= 1; --i)
		cout << setw(4) << setfill('0') << hp.num[i];
	return ost;
}

int main() {
	ios::sync_with_stdio(false);
	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 0; i < n; ++i)
		cin >> minister[i].left >> minister[i].right;
	sort(minister, minister + n, [](const Minister& a, Minister& b) { return a.left * a.right < b.left * b.right; });
	hp sum = a;
	hp Max = 0;
	for (int i = 0; i < n; ++i) {
		if (sum / minister[i].right > Max)
			Max = sum / minister[i].right;
		sum *= minister[i].left;
	}
	cout << Max << endl;
	return 0;
}