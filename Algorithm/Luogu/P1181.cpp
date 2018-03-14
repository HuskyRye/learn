/*
	Author: 刘臣轩
	Date: 2017.11.5
*/

#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int ans = 1;
	int temp;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		if (sum + temp > m) {
			++ans;
			sum = temp;
		}
		else
			sum += temp;
	}
	cout << ans << endl;
	return 0;
}