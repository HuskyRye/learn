/*
	Author: 刘臣轩
	Date: 2017.11.6
	Source: NOIP 2000 Task3
*/

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
char start;
string words[25];
int dragon[25][25];
int visit[25];
int Max = 0;

void init_dragon() {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k < min(words[i].size(), words[j].size()); ++k)
				if (words[i].substr(words[i].size() - k, k) == words[j].substr(0, k)) {
					dragon[i][j] = words[j].size() - k;
					break;
				}
}

void dfs(int prev, int length) {
	Max = max(Max, length);
	for (int i = 1; i <= n; ++i) {
		if (visit[i] != 2 && dragon[prev][i]) {
			++visit[i];
			dfs(i, length + dragon[prev][i]);
			--visit[i];
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> words[i];
	cin >> start;
	init_dragon();
	for (int i = 1; i <= n; ++i) {
		if (words[i][0] == start) {
			visit[i] = 1;
			dfs(i, words[i].size());
			visit[i] = 0;
		}
	}
	cout << Max << endl;
	return 0;
}