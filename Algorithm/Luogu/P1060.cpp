/*
	Author: 刘臣轩
	Date: 2017.11.9
*/

#include <iostream>
#include <algorithm>
using namespace std;

int f[30][30000];
int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int w, v;
		cin >> w >> v;
		for (int c = 0; c <= n; ++c) {
			f[i][c] = f[i-1][c];
			if (c >= w)
				f[i][c] = max(f[i][c], f[i-1][c-w]+v*w);
		}
	}
	cout << f[m][n] << endl;
	return 0;
}