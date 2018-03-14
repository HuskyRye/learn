/*
	Author: 刘臣轩
	Date: 2017.10.29
	Source: NOIP 2003
*/

#include <iostream>
#include <algorithm>
using namespace std;

int a[35];
long long int f[35][35];
int root[35][35];

void preorder(int i, int j) {
	int k = root[i][j];
	if (k == 0)
		return;
	cout << k << ' ';
	preorder(i, k - 1);
	preorder(k + 1, j);
}

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	for (int i = 0; i <= n; ++i) {
		f[i][i] = a[i];
		f[i + 1][i] = 1;
		root[i][i] = i;
	}

	for (int d = 1; d < n; ++d) {
		for (int i = 1; i <= n; ++i) {
			int j = i + d;
			for (int k = i; k <= j; ++k) {
				long long int temp = f[i][k - 1] * f[k + 1][j] + a[k];
				if (temp > f[i][j]) {
					f[i][j] = temp;
					root[i][j] = k;
				}
			}
		}
	}

	cout << f[1][n] << endl;
	preorder(1, n);
	return 0;
}