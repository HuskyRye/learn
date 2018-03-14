/*
	Author: 刘臣轩
	Date: 2017.10.28
	Source: NOIP 2000
*/

#include <iostream>
#include <algorithm>
using namespace std;

int a[15][15];
bool visit[15][15];
int f[15][15][15][15];
int main()
{
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int x, y, z;
	while (cin >> x >> y >> z && z != 0)
		a[x][y] = z;

	for (int x1 = 1; x1 <= n; ++x1) {
		for (int y1 = 1; y1 <= n; ++y1) {
			for (int x2 = 1; x2 <= n; ++x2) {
				int y2 = x1 + y1 - x2;
				f[x1][y1][x2][y2] = max(max(f[x1-1][y1][x2-1][y2], f[x1][y1-1][x2-1][y2]), max(f[x1-1][y1][x2][y2-1], f[x1][y1-1][x2][y2-1]));
				if (x1 == x2 && y1 == y2)
					f[x1][y1][x2][y2] += a[x1][y1];
				else
					f[x1][y1][x2][y2] += a[x1][y1] + a[x2][y2];
			}
		}
	}

	cout << f[n][n][n][n] << endl;

	return 0;
}