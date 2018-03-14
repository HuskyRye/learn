/*
	Author: 刘臣轩
	Date: 2017.11.7
	Source: USACO 06 FEB
*/

#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int triangle[13][13] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 4, 6, 4, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 5, 10, 10, 5, 1, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 6, 15, 20, 15, 6, 1, 0, 0, 0, 0, 0 },
	{ 0, 1, 7, 21, 35, 35, 21, 7, 1, 0, 0, 0, 0 },
	{ 0, 1, 8, 28, 56, 70, 56, 28, 8, 1, 0, 0, 0 },
	{ 0, 1, 9, 36, 84, 126, 126, 84, 36, 9, 1, 0, 0 },
	{ 0, 1, 10, 45, 120, 210, 252, 210, 120, 45, 10, 1, 0 },
	{ 0, 1, 11, 55, 165, 330, 462, 462, 330, 165, 55, 11, 1 },
};

int a[15];
int main() {
	int n, sum;
	cin >> n >> sum;
	for (int i = 1; i <= n; ++i)
		a[i] = i;
	do {
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			ans += a[i] * triangle[n][i];
			if (ans > sum) {
				sort(a+i, a+n+1, greater<int>());
				break;
			}
		}
		if (ans == sum) {
			for (int i = 1; i <= n; ++i)
				cout << a[i] << ' ';
			return 0;
		}
	} while (next_permutation(a+1, a+1+n));
	return 0;
}