/*
	Author: 刘臣轩
	Date: 2017.11.7
*/

#include <iostream>
using namespace std;

int n, m;

struct node
{
	int parent;
	int count;
} set[10010];

int Find(int x) {
	return set[x].parent == x ? x : set[x].parent = Find(set[x].parent);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y)
		return;
	if (set[x].count > set[y].count) {
		set[y].parent = x;
		set[x].count += set[y].count;
	}
	else {
		set[x].parent = y;
		set[y].count += set[x].count;
	}
}

void init() {
	for (int i = 1; i <= n; ++i) {
		set[i].parent = i;
		set[i].count = 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	init();
	for (int i = 1; i <= m; ++i) {
		int x, y, z;
		cin >> z >> x >> y;
		if (z == 1)
			Union(x, y);
		else
			cout << (Find(x) == Find(y) ? 'Y' : 'N') << endl;
	}
	return 0;
}