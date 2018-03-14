/*
	Author: 刘臣轩
	Date: 2017.11.9
	Source: NOIP 提高
*/

#include <iostream>
using namespace std;

int n, k;
int ans = 0;
void dfs(int prev, int sum, int depth) {
	if (depth == k) {
		++ans;
		return;
	}
	for (int i = prev; i <= n-k+1; ++i) {
		if (sum-i >= prev && sum-i >= i)
			dfs(i, sum-i, depth+1);
		else
			return;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	dfs(1, n, 1);
	cout << ans << endl;
	return 0;
}