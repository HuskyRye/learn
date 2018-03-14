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
	int num[1010];
	int len;
	hp();
	hp& operator=(const char*);
	hp operator*(const hp&) const;
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
	cout << a * b << endl;
	return 0;
}