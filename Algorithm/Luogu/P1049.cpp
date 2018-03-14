/*
	Author: 刘臣轩
	Date: 2017.11.11 
*/

#include <iostream>
#include <algorithm>
using namespace std;

int f[35][20005];
int main() {
	ios::sync_with_stdio(false);
	int v, n;
	cin >> v >> n;
	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		for (int j = 1; j <= v; ++j) {
			f[i][j] = f[i-1][j];
			if (j >= a)
				f[i][j] = max(f[i][j], f[i-1][j-a]+a);
		}
	}
	cout << v-f[n][v] << endl;
	return 0;
}
