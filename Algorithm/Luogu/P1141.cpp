/*
	Author: 刘臣轩
	Date: 2017.11.6
*/

#include <iostream>
using namespace std;

int n, m;
char map[1005][1005];
int ans[1005][1005];
int answer[1000010];
int index = 1;
void dfs(int x, int y) {
	ans[x][y] = index;
	++answer[index];
	char require = (map[x][y] == '0' ? '1' : '0');
	if (ans[x-1][y] == 0 && map[x-1][y] == require)
		dfs(x-1, y);
	if (ans[x][y-1] == 0 && map[x][y-1] == require)
		dfs(x, y-1);
	if (ans[x+1][y] == 0 && map[x+1][y] == require)
		dfs(x + 1, y);
	if (ans[x][y+1] == 0 && map[x][y+1] == require)
		dfs(x, y + 1);
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> map[i] + 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (!ans[i][j])
				dfs(i, j), ++index;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		cout << answer[ans[a][b]] << endl;
	}
	return 0;
}