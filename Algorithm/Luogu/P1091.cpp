/*
	Author: 刘臣轩
	Date: 2017.11.11
	Source: NOIP 2004 提高
*/

#include <iostream>
#include <algorithm>
#include <functional>
#include <cstring>
#include <algorithm>
using namespace std;
int a[105];
int b[105];
int l[105];
int r[105];
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int len = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] > b[len])
			b[++len] = a[i];
		else
			*lower_bound(b+1, b+len+1, a[i]) = a[i];
		l[i] = len;
	}
	memset(b, 0, sizeof(0));
	len = 0;
	for (int i = n; i >= 1; --i) {
		if (a[i] > b[len])
			b[++len] = a[i];
		else
			*lower_bound(b+1, b+len+1, a[i]) = a[i];
		r[i] = len;
	}
	int k = 0;
	for (int i = 1; i <= n; ++i)
		k = max(k, l[i]+r[i]);
	cout << n-k+1 << endl;
	return 0;
}