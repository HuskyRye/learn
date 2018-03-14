/*
	Author: 刘臣轩
	Date: 2017.10.27
	Source: NOIP 2008
*/

#include <iostream>
#include <algorithm>
using namespace std;

int a[60][60];
int f[60][60][60][60];
int main()
{
	ios::sync_with_stdio(false);

	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}

	for (int x1 = 2; x1 <= m; ++x1) {
		for (int y1 = 1; y1 <= n; ++y1) {
			for (int x2 = 1; x2 <= m; ++x2) {
				if (x2 >= x1)
					continue;
				int y2 = x1 + y1 - x2;
				f[x1][y1][x2][y2] = max(max(f[x1-1][y1][x2-1][y2], f[x1][y1-1][x2-1][y2]), max(f[x1-1][y1][x2][y2-1], f[x1][y1-1][x2][y2-1])) + a[x1][y1] + a[x2][y2];
			}
		}
	}

	cout << f[m][n-1][m-1][n] << endl;

	return 0;
}