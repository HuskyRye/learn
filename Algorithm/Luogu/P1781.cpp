/*
	Author: 刘臣轩
	Date: 2017.10.28
*/

#include <iostream>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <cstring>
using namespace std;

struct hp
{
	int num[30];	// 10000
	int len;

	hp& operator=(const char*);
	bool operator<(const hp& b) const;

};

hp& hp::operator=(const char* c)
{
	int n = strlen(c);
	int j = 0, k = 1;
	for (int i = n-1; i >= 0; --i) {
		if (k == 10000)
			++j, k = 1;
		num[j] += k*(c[i] - '0');
		k *= 10;
	}
	len = j;
	return *this;
}

bool hp::operator<(const hp& b) const
{
	if (len != b.len)
		return len < b.len;
	for (int i = len; i >= 0; --i)
		if (num[i] != b.num[i])
			return (num[i] < b.num[i]);
	return false;
}

istream& operator>>(istream& ist, hp& hp) {
	char temp[110];
	cin >> temp;
	hp = temp;
	return ist;
}

ostream& operator<<(ostream& ost, hp& hp) {
	ost << hp.num[hp.len];
	for (int i = hp.len - 1; i >= 0; --i) {
		ost << setw(4) << setfill('0') << hp.num[i];
	}
	return ost;
}

hp a[25];
int main()
{
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	hp* Max = max_element(a, a + n);
	cout << Max - a + 1 << endl << *Max << endl;

	return 0;
}