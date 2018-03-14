/*
	Author: 刘臣轩
	Date: 2017.10.27
	Source: NOIP 2006
*/

#include <iostream>
#include <algorithm>
using namespace std;

int a[210];
int s[210];
int f[210][210];

int main()
{
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i + n] = a[i];
	}

	for (int len = 1; len < n; ++len) {
		for (int i = 1; i < n * 2 - len; ++i) {
			int j = i + len;
			for (int k = i; k < j; ++k)
				f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + a[i] * a[k + 1] * a[j + 1]);
		}
	}

	int Max = 0;
	for (int i = 1; i <= n; ++i) {
		if (f[i][i + n - 1] > Max)
			Max = f[i][i + n - 1];
	}
	cout << Max << endl;

	return 0;
}