/*
	Author: 刘臣轩
	Date: 2017.11.8
*/

#include <iostream>
#include <queue>
using namespace std;
#define INF 2147483647

struct node
{
	int v, w;
	int next;
} edge[500005];
int head[10005];

int n, m, s;
int d[500005];
bool inqueue[500005];
queue<int> q;
void SPFA() {
	for (int i = 1; i <= n; ++i)
		d[i] = INF;
	d[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		inqueue[x] = false;
		for (int e = head[x]; e != 0; e = edge[e].next) {
			int v = edge[e].v;
			int w = edge[e].w;
			if (d[x] + w < d[v]) {
				d[v] = d[x] + w;
				if (!inqueue[v])
					q.push(v), inqueue[v] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> s;
	for (int i = 1; i <= m; ++i) {
		int u;
		cin >> u >> edge[i].v >> edge[i].w;
		edge[i].next = head[u];
		head[u] = i;
	}
	SPFA();
	for (int i = 1; i <= n; ++i)
		cout << d[i] << ' ';
	return 0;
}