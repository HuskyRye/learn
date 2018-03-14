/*
	Author: 刘臣轩
	Date: 2017.10.26
	Source: USACO Training Section
*/

#include <iostream>
#include <algorithm>
using namespace std;

int a[1010][1010];
int f[1010][1010];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j)
			cin >> a[i][j];

	for (int i = n; i > 0; --i)
		for (int j = 1; j <= i; ++j)
			f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + a[i][j];

	cout << f[1][1] << endl;
	
	return 0;
}