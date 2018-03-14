/*
	Author: 刘臣轩
	Date: 2017.11.6
*/

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;

int n;
struct hp
{
	int num[2010];
	int len;
	hp();
	hp operator+(const hp&) const;
};
hp::hp() {
	memset(num, 0, sizeof(num));
	num[1] = 0;
	len = 1;
}
hp hp::operator+(const hp& b) const {
	hp c;
	c.len = max(len, b.len);
	for (int i = 1; i <= c.len; ++i) {
		c.num[i] += num[i] + b.num[i];
		if (c.num[i] >= n) {
			c.num[i] -= n;
			++c.num[i + 1];
		}
	}
	if (c.num[c.len + 1] > 0)
		++c.len;
	return c;
}
istream& operator>>(istream& ist, hp& hp) {
	string temp;
	cin >> temp;
	int j = 0;
	for (int i = temp.size() - 1; i >= 0; --i)
		hp.num[++j] = (temp[i] >= '0' && temp[i] <= '9' ? temp[i] - '0' : temp[i] - 'A' + 10);
	hp.len = (j == 0 ? 1 : j);
	return ist;
}
ostream& operator<<(ostream& ost, const hp& hp) {
	for (int i = hp.len; i >= 1; --i) {
		if (hp.num[i] >= 0 && hp.num[i] <= 9)
			cout << hp.num[i];
		else
			cout << static_cast<char>(hp.num[i] - 10 + 'A');
	}
	return ost;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	hp a, b;
	cin >> a >> b;
	cout << a + b << endl;
	return 0;
}