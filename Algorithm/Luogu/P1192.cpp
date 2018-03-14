/*
	Author: 刘臣轩
	Date: 2017.11.9
*/

#include <iostream>
using namespace std;
int f[100005];
int main() {
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	f[0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= k; ++j)
			if (i-j >= 0)
				f[i] += f[i-j] % 100003;
	cout << f[n] % 100003 << endl;
	return 0;
}