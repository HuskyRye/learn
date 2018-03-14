/*
	Author: 刘臣轩
	Date: 2017.10.27
	Source: NOI 95
*/

#include <iostream>
#include <algorithm>
using namespace std;

int a[210];
int s[210];
int f1[210][210];
int f2[210][210];
int main()
{
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i + n] = a[i];
	}

	for (int i = 1; i <= n + n; ++i)
		s[i] = s[i - 1] + a[i];

	for (int len = 1; len < n; ++len) {
		for (int i = 1; i < 2 * n - len; ++i) {
			int j = i + len;
			f2[i][j] = 2147483647;
			for (int k = i; k < j; ++k) {
				f1[i][j] = max(f1[i][j], f1[i][k] + f1[k + 1][j] + s[j] - s[i - 1]);
				f2[i][j] = min(f2[i][j], f2[i][k] + f2[k + 1][j] + s[j] - s[i - 1]);
			}
		}
	}
	
	int Max = 0;
	int Min = 2147483647;
	for (int i = 1; i <= n; ++i) {
		if (f1[i][i + n - 1] > Max)
			Max = f1[i][i + n - 1];
		if (f2[i][i + n - 1] < Min)
			Min = f2[i][i + n - 1];
	}
	cout << Min << endl << Max << endl;

	return 0;
}