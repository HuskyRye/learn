/*
	Author: 刘臣轩
	Date: 2017.11.9
	Source: NOIP 2008 普及 Task3
*/

#include <iostream>
using namespace std;
int f[35][35];
int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	f[1][0] = 1;
	for (int j = 1; j <= m; ++j)
		for (int i = 1; i <= n; ++i)
			f[i][j] = f[(i-n-1)%n+n][j-1]+f[i%n+1][j-1];
	cout << f[1][m] << endl;
	return 0;
}