/*
	Author: 刘臣轩
	Date: 2017.10.30
	Source: NOIP 2005
*/

#include <iostream>
#include <algorithm>
using namespace std;

int stone[110];
int bridge[100010];
int f[100010];
int main() {
	ios::sync_with_stdio(false);
	int L;
	cin >> L;
	int s, t, m;
	cin >> s >> t >> m;
	for (int i = 1; i <= m; ++i)
		cin >> stone[i];
	sort(stone + 1, stone + m + 1);
	int pos = 0;
	for (int i = 1; i <= m; ++i) {
		L = stone[i] - stone[i - 1];
		if (L <= 2 * t)
			pos += L;
		else if (L % t == 0)
			pos += 2 * t;
		else
			pos += t + L % t;
		bridge[pos] = 1;
	}
	for (int i = 1; i <= pos + t; ++i) {
		f[i] = 150;
		for (int k = s; k <= t; ++k) {
			if (i - k >= 0)
				f[i] = min(f[i], f[i - k] + bridge[i]);
		}
	}
	int ans = 150;
	for (int i = pos+1; i <= pos + t; ++i)
		ans = min(ans, f[i]);
	cout << ans << endl;
	return 0;
}