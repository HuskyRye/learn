/*
	Author: 刘臣轩
	Date: 2017.11.6
*/

#include <iostream>
#include <queue>;
using namespace std;

int map[30][30];
int n;
int x, y;
queue<int> qx, qy;
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	bool start = false;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
			if (!start && !map[i][j] && map[i-1][j-1] && map[i-1][j] && map[i][j-1])
				x = i, y = j, start = true;
		}
	}
	qx.push(x), qy.push(y);
	do {
		int a = qx.front(), b = qy.front();
		qx.pop(), qy.pop();
		if (map[a][b] != 0)
			continue;
		map[a][b] = 2;
		qx.push(a-1), qy.push(b);
		qx.push(a), qy.push(b-1);
		qx.push(a+1), qy.push(b);
		qx.push(a), qy.push(b+1);
	} while (qx.size() > 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << map[i][j] << ' ';
		cout << endl;
	}
	return 0;
}