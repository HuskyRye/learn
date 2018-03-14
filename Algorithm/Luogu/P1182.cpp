/*
	Author: 刘臣轩
	Date: 2017.11.10
*/

#include <iostream>
#include <algorithm>
using namespace std;
int sum[100005];
int n, m;
bool check(int Max) {
	int prev = 0;
	int count = 0;
	for (int i = 1; i <= n; ++i) {
		if (sum[i]-sum[prev] > Max) {
			++count;
			if (count == m)
				break;
			prev = i-1;
		}
	}
	return count < m;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int l = 0, r;
	for (int i = 1; i <= n; ++i) {
		cin >> sum[i];
		l = max(l, sum[i]);
		sum[i] += sum[i-1];
	}
	r = sum[n];
	while (l < r) {
		int mid = l+r>>1;
		if (check(mid))
			r = mid;
		else
			l = mid+1;
	}
	cout << l << endl;
	return 0;
}