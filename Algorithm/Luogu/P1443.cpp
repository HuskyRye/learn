/*
	Author: 刘臣轩
	Date: 2017.11.7
*/

#include <iostream>
#include <iomanip>
#include <queue>
#include <cstring>
using namespace std;

const int stepx[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
const int stepy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
struct horse
{
	int x, y, step;
};

int n, m, sx, sy;
int map[405][405];
bool visit[405][405];
queue<horse> q;
void bfs() {
	q.push(horse{ sx, sy, 0 });
	visit[sx][sy] = true;
	while (!q.empty()) {
		horse h = q.front();
		q.pop();
		map[h.x][h.y] = h.step;
		for (int i = 0; i < 8; ++i) {
			if (h.x+stepx[i] >= 1 && h.x+stepx[i]<= n && h.y+stepy[i] >= 1 && h.y+stepy[i] <= m && !visit[h.x+stepx[i]][h.y+stepy[i]]) {
				q.push(horse{ h.x+stepx[i], h.y+stepy[i], h.step+1 });
				visit[h.x+stepx[i]][h.y+stepy[i]] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> sx >> sy;
	memset(map, -1, sizeof(map));
	bfs();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			cout << setw(5) << setiosflags(ios::left) << map[i][j];
		cout << endl;
	}
	return 0;
}


