/*
	Author: 刘臣轩
	Date: 2017.11.8
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int ans = 0;
int map[105][105];
int f[105][105];
const int stepx[] = { -1, 1, 0, 0 };
const int stepy[] = { 0, 0, -1, 1 };
void dfs(int x, int y) {
	if (f[x][y])
		return;
	f[x][y] = 1;
	for (int i = 0; i < 4; ++i)
		if (map[x+stepx[i]][y+stepy[i]] < map[x][y]) {
			dfs(x+stepx[i], y+stepy[i]);
			f[x][y] = max(f[x][y], f[x+stepx[i]][y+stepy[i]] + 1);
		}
	ans = max(ans, f[x][y]);
}
int main() {
	ios::sync_with_stdio(false);
	int r, c;
	cin >> r >> c;
	memset(map, 0x3f, sizeof(map));
	for (int i = 1; i <= r; ++i)
		for (int j = 1; j <= c; ++j)
			cin >> map[i][j];
	for (int i = 1; i <= r; ++i)
		for (int j = 1; j <= c; ++j)
			dfs(i, j);
	cout << ans << endl;
	return 0;
}