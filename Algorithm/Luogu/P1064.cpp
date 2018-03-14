/*
	Author: 刘臣轩
	Date: 2017.11.9
	Source: NOIP 2006 提高 Task2
*/

#include <iostream>
#include <algorithm>
using namespace std;

int v[65][3], p[65][3];
int f[65][32005];
int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int vi, pi, qi;
		cin >> vi >> pi >> qi;
		if (qi) {
			v[qi][(v[qi][1] ? 2 : 1)] = vi;
			p[qi][(p[qi][1] ? 2 : 1)] = pi;
		}
		else {
			v[i][0] = vi;
			p[i][0] = pi;
		}
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j <= n; ++j) {
			f[i][j] = f[i-1][j];
			if (j >= v[i][0])
				f[i][j] = max(f[i][j], f[i-1][j-v[i][0]] + v[i][0]*p[i][0]);
			if (v[i][1] && j >= v[i][0] + v[i][1])
				f[i][j] = max(f[i][j], f[i-1][j-v[i][0]-v[i][1]] + v[i][0]*p[i][0] + v[i][1]*p[i][1]);
			if (v[i][2] && j >= v[i][0] + v[i][2]) {
				f[i][j] = max(f[i][j], f[i-1][j-v[i][0]-v[i][2]] + v[i][0]*p[i][0] + v[i][2]*p[i][2]);
				if (j >= v[i][0] + v[i][1] + v[i][2])
					f[i][j] = max(f[i][j], f[i-1][j-v[i][0]-v[i][1]-v[i][2]] + v[i][0]*p[i][0] + v[i][1]*p[i][1] + v[i][2]*p[i][2]);
			}
		}
	}
	cout << f[m][n] << endl;
	return 0;
}