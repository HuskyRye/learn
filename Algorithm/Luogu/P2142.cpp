/*
	Author: 刘臣轩
	Date: 2017.11.5
*/

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

struct hp
{
	int num[2510];
	int len;

	hp();
	hp& operator=(const char* c);
	hp operator-(const hp& b);
	bool operator>(const hp& b) const;
	bool operator>=(const hp& b) const;
};

hp::hp() {
	memset(num, 0, sizeof(num));
	len = 1;
}
hp& hp::operator=(const char* c) {
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
hp hp::operator-(const hp& b) {
	hp c;
	c.len = len;
	for (int i = 1; i <= len; ++i) {
		c.num[i] += num[i] - b.num[i];
		if (c.num[i] < 0) {
			c.num[i] += 10000;
			--c.num[i + 1];
		}
	}
	while (c.num[c.len] == 0 && c.len > 1)
		--c.len;
	return c;
}
bool hp::operator>(const hp& b) const {
	if (len != b.len)
		return len > b.len;
	for (int i = len; i >=1; --i) {
		if (num[i] != b.num[i])
			return num[i] > b.num[i];
	}
	return false;
}
bool hp::operator>=(const hp& b) const {
	return !(b > *this);
}

istream& operator>>(istream& ist, hp& hp) {
	string temp;
	cin >> temp;
	hp = temp.c_str();
	return ist;
}
ostream& operator<<(ostream& ost, const hp& hp) {
	cout << hp.num[hp.len];
	for (int i = hp.len - 1; i >= 1; --i)
		cout << setw(4) << setfill('0') << hp.num[i];
	return ost;
}

int main() {
	ios::sync_with_stdio(false);
	hp a, b;
	cin >> a >> b;
	if (a >= b)
		cout << a - b << endl;
	else
		cout << '-' << b - a << endl;
	return 0;
}