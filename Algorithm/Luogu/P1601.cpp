/*
	Author: 刘臣轩
	Date: 2017.11.5
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

struct Hp
{
	int num[100];
	int len;
	Hp();
	Hp& operator=(const char* c);
	Hp operator+(const Hp& b) const;
};

Hp::Hp() {
	memset(num, 0, sizeof(num));
	len = 1;
}
Hp& Hp::operator=(const char* c) {
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
Hp Hp::operator+(const Hp& b) const {
	Hp c;
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
istream& operator>>(istream& ist, Hp& hp) {
	string temp;
	ist >> temp;
	hp = temp.c_str();
	return ist;
}
ostream& operator<<(ostream& ost, const Hp& hp) {
	cout << hp.num[hp.len];
	for (int i = hp.len - 1; i >= 1; --i)
		ost << setw(4) << setfill('0') << hp.num[i];
	return ost;
}

int main() {
	ios::sync_with_stdio(false);
	Hp a, b;
	cin >> a >> b;
	cout << a + b << endl;
	return 0;
}
