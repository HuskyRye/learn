/*
	Author: 刘臣轩
	Date: 2017.11.6
*/

#include <iostream>
using namespace std;

bool map[10][10];
int fx, fy;
int ans = 0;
void dfs(int x, int y) {
	if (x == fx && y == fy) {
		++ans;
		return;
	}
	map[x][y] = true;
	if (!map[x][y-1])
		dfs(x, y-1);
	if (!map[x][y+1])
		dfs(x, y+1);
	if (!map[x-1][y])
		dfs(x-1, y);
	if (!map[x+1][y])
		dfs(x+1, y);
	map[x][y] = false;
}

int main() {
	ios::sync_with_stdio(false);
	int n, m, t;
	cin >> n >> m >> t;
	for (int i = 0; i <= m + 1; ++i)
		map[0][i] = map[n + 1][i] = 1;
	for (int i = 0; i <= n + 1; ++i)
		map[i][0] = map[i][m + 1] = 1;
	int sx, sy;
	cin >> sx >> sy >> fx >> fy;
	for (int i = 0; i < t; ++i) {
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
	}
	dfs(sx, sy);
	cout << ans << endl;
	return 0;
}