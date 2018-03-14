/*
	Author: 刘臣轩
	Date: 2017.11.7
*/

#include <iostream>
#include <queue>
using namespace std;

struct point
{
	int x, y;
	int time;
	char face;
};

int n, m;
int sx, sy, fx, fy;
char pos;
char map[55][55];
bool visit[55][55][4];
queue<point> q;

void north(point& p) {
	for (int i = 1; i <= 3; ++i) {
		if (p.x >= 1 + i && map[p.x-i][p.y] == '0' && map[p.x-i][p.y+1] == '0')
			q.push(point{ p.x-i, p.y, p.time + 1, 'N' });
		else
			return;
	}
}
void south(point& p) {
	for (int i = 1; i <= 3; ++i) {
		if (p.x+1+i <= n && map[p.x+1+i][p.y] == '0' && map[p.x+1+i][p.y+1] == '0')
			q.push(point{ p.x+i, p.y, p.time + 1, 'S' });
		else
			return;
	}
}
void west(point& p) {
	for (int i = 1; i <= 3; ++i) {
		if (p.y >= i+1 && map[p.x][p.y-i] == '0' && map[p.x+1][p.y-i] == '0')
			q.push(point{ p.x, p.y-i, p.time + 1, 'W' });
		else
			return;
	}
}
void east(point& p) {
	for (int i = 1; i <= 3; ++i) {
		if (p.y+1+i <= m && map[p.x][p.y+1+i] == '0' && map[p.x+1][p.y+1+i] == '0')
			q.push(point{ p.x, p.y+i, p.time + 1, 'E' });
		else
			return;
	}
}

int bfs() {
	if (map[fx][fy] == '0')
		q.push(point{ sx, sy, 0, pos });
	while (!q.empty()) {
		point p = q.front();
		q.pop();
		if (p.x == fx && p.y == fy)
			return p.time;
		// creep walk run
		if (p.face == 'N') {
			if (visit[p.x][p.y][0])
				continue;
			visit[p.x][p.y][0] = true;
			north(p);
		}
		else if (p.face == 'S') {
			if (visit[p.x][p.y][1])
				continue;
			visit[p.x][p.y][1] = true;
			south(p);
		}
		else if (p.face == 'W') {
			if (visit[p.x][p.y][2])
				continue;
			visit[p.x][p.y][2] = true;
			west(p);
		}
		else {
			if (visit[p.x][p.y][3])
				continue;
			visit[p.x][p.y][3] = true;
			east(p);
		}
		// turn
		switch (p.face) {
		case 'N':
		{
			if (!visit[p.x][p.y][2])
				q.push(point{ p.x, p.y, p.time + 1, 'W' });
			if (!visit[p.x][p.y][3])
				q.push(point{ p.x, p.y, p.time + 1, 'E' });
			break;
		}
		case 'S':
		{
			if (!visit[p.x][p.y][2])
				q.push(point{ p.x, p.y, p.time + 1, 'W' });
			if (!visit[p.x][p.y][3])
				q.push(point{ p.x, p.y, p.time + 1, 'E' });
			break;
		}
		case 'W':
		{
			if (!visit[p.x][p.y][0])
				q.push(point{ p.x, p.y, p.time + 1, 'N' });
			if (!visit[p.x][p.y][1])
				q.push(point{ p.x, p.y, p.time + 1, 'S' });
			break;
		}
		case 'E':
		{
			if (!visit[p.x][p.y][0])
				q.push(point{ p.x, p.y, p.time + 1, 'N' });
			if (!visit[p.x][p.y][1])
				q.push(point{ p.x, p.y, p.time + 1, 'S' });
			break;
		}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> map[i][j];
	cin >> sx >> sy >> fx >> fy >> pos;
	cout << bfs() << endl;
	return 0;
}
