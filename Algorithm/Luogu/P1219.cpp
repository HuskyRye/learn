/*
    Author: 刘臣轩
    Date: 2017.10.23
	Source: USACO Training Section 1.5
*/

#include <iostream>
using namespace std;

bool rows[14];
bool cross1[28];
bool cross2[28];

int answer[14];
int sum = 0;
int n;

void dfs(int row)
{
	if (row == n+1)
	{
		++sum;
		if (sum <= 3) {
			for (int i = 1; i <= n; ++i)
				cout << answer[i] << ' ';
			cout << endl;
		}
		return;
	}
	
	for (int i = 1; i <= n; ++i) {
		if (rows[i] || cross1[i-row+n] || cross2[i+row-1])
			continue;
		rows[i] = cross1[i-row+n] = cross2[i+row-1] = true;
		answer[row] = i;
		dfs(row+1);
		rows[i] = cross1[i-row+n] = cross2[i+row-1] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	dfs(1);
	cout << sum;
	return 0;
}
