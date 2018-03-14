/*
	Author: 刘臣轩
	Date: 2017.11.8
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

struct chess
{
	double x, y;
};
chess map[16];
bool visit[15];
double d[16][16];
double distance(int a, int b) {
	if (d[a][b] != 0)
		return d[a][b];
	else
		return d[a][b] = d[b][a] = sqrt(pow(map[a].x-map[b].x, 2)+pow(map[a].y-map[b].y, 2));
}

int n;
double ans = 10000000;
void dfs(int a, double d, int depth) {
	if (depth == n) {
		ans = min(ans, d);
		return;
	}
	if (d >= ans)
		return;
	visit[a] = true;
	for (int i = 1; i <= n; ++i)
		if (!visit[i])
			dfs(i, d + distance(a, i), depth + 1);
	visit[a] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> map[i].x >> map[i].y;
	dfs(0, 0, 0);
	cout << fixed << setprecision(2) << ans << endl;
}