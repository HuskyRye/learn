/*
	Author: 刘臣轩
	Date: 2017.11.8
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int sum = 0;
	int ans = -100000;
	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		sum += a;
		ans = max(ans, sum);
		if (sum < 0)
			sum = 0;
	}
	cout << ans << endl;
	return 0;
}