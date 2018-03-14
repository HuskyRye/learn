/*
	Author: 刘臣轩
	Date: 2017.11.12
*/

#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int b[5005];
int c[5005];
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	// c[0] = 1;
	int a;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		int* p = lower_bound(b+1, b+n+1, a, greater<int>());
		if (*p != a)
			// c[p-b] += c[p-b-1];
		*p = a;
	}
	int len = lower_bound(b+1, b+n+1, 0, greater<int>())-b-1;
	cout << len << endl;
	cout << c[len] << endl;
	return 0;
}