/*
	Author: 刘臣轩
	Date: 2017.11.8
*/

#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		q.push(i);
	while (!q.empty()) {
		for (int i = 1; i < m; ++i) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front() << ' ';
		q.pop();
	}
	return 0;
}