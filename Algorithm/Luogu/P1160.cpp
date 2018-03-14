/*
Author: 刘臣轩
Date: 2017.11.8
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct student
{
	int left;
	int right;
} li[100005];
bool kick[100005];
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	li[0].right = 1;
	li[1].left = 0;
	for (int i = 2; i <= n; ++i) {
		int k, p;
		cin >> k >> p;
		if (p == 0) {
			li[li[k].left].right = i;
			li[i].left = li[k].left;
			li[i].right = k;
			li[k].left = i;
		}
		else {
			li[li[k].right].left = i;
			li[i].right = li[k].right;
			li[i].left = k;
			li[k].right = i;
		}
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		if (kick[x])
			continue;
		kick[x] = true;
		li[li[x].left].right = li[x].right;
		li[li[x].right].left = li[x].left;
	}
	while (li[0].right) {
		cout << li[0].right << ' ';
		li[0].right = li[li[0].right].right;
	}
	return 0;
}