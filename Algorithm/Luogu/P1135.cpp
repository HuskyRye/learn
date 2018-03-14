/*
	Author: 刘臣轩
	Date: 2017.11.9
*/

#include <iostream>
#include <queue>
using namespace std;

int k[205];
queue<pair<int, int>> q;
bool visit[205];
int main() {
	ios::sync_with_stdio(false);
	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 1; i <= n; ++i)
		cin >> k[i];
	q.push(make_pair(a, 0));
	while (!q.empty()) {
		int x = q.front().first;
		int step = q.front().second;
		q.pop();
		if (x == b) {
			cout << step << endl;
			return 0;
		}
		visit[x] = true;
		if (x+k[x] <= n && !visit[x+k[x]])
			q.push(make_pair(x+k[x], step+1));
		if (x-k[x] >= 1 && !visit[x-k[x]])
			q.push(make_pair(x-k[x], step+1));
	}
	cout << -1 << endl;
	return 0;
}