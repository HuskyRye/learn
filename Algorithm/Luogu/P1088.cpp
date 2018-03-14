/*
	Author: 刘臣轩
	Date: 2017.11.10
	Source: NOIP 2004 普及
*/

#include <iostream>
#include <algorithm>
using namespace std;

int a[10005];
int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < m; ++i)
		next_permutation(a, a+n);
	for (int i = 0; i < n; ++i)
		cout << a[i] << ' ';
	cout << endl;
	return 0;
}