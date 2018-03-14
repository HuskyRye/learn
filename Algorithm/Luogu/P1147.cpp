/*
	Author: 刘臣轩
	Date: 2017.11.8
*/

#include <iostream>
using namespace std;

long long sum[2000005];
int main() {
	ios::sync_with_stdio(false);
	int m;
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		sum[i] = sum[i-1] + i;
		for (int j = i - 1; j >= 1; --j) {
			if (sum[i] - sum[j-1] == m) {
				cout << j << ' ' << i << endl;
				break;
			}
			if (sum[i] - sum[j-1] > m)
				break;
		}
	}
	return 0;
}