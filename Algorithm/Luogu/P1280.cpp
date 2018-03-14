/*
	Author: 刘臣轩
	Date: 2017.11.12
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[10005];
int f[10005];
int main() {
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int p, t;
	for (int i = 0; i < k; ++i) {
		cin >> p >> t;
		v[p].push_back(t);
	}
	for (int i = n; i >= 1; --i) {
		if (v[i].size())
			for (int j = 0; j < v[i].size(); ++j)
				f[i] = max(f[i], f[i+v[i][j]]);
		else
			f[i] = max(f[i], f[i+1]+1);
	}
	cout << f[1] << endl;
	return 0;
}