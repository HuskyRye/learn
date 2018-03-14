/*
	Author: 刘臣轩
	Date: 2017.11.11
	Source: NOIP 2005 普及 
*/

#include <iostream>
#include <algorithm>
using namespace std;
int f[105][1005];
int main() {
	ios::sync_with_stdio(false);
	int t, m;
	cin >> t >> m;
	for (int i = 1; i <= m; ++i) {
		int a, b;
		cin >> a >> b;
		for (int j = 1; j <= t; ++j) {
			f[i][j] = f[i-1][j];
			if (j >= a)
				f[i][j] = max(f[i][j], f[i-1][j-a]+b);
		}
	}
	cout << f[m][t] << endl;
	return 0;
}
