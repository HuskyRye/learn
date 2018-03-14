/*
	Author: 刘臣轩
	Date: 2017.10.26
	Source: NOIP 2011 day1 Mayan
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int mayan[7][5][8];
int x[6], y[6], g[6];

void fall(int depth)
{
	for (int i = 0; i < 5; ++i) {
		int temp[8] = { 0 }, k = 0;
		for (int j = 0; j < 7; ++j) {
			if (mayan[depth][i][j]) {
				temp[k++] = mayan[depth][i][j];
			}
		}
		memcpy(mayan[depth][i], temp, sizeof(temp));
	}
}

bool mark[5][7];
bool check(int depth)
{
	bool changed = false;
	memset(mark, 0, sizeof(mark));
	// 横向
	for (int i = 0; i < 7; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (mayan[depth][j][i]) {
				int color = mayan[depth][j][i];
				int count = 1;
				for (int k = j + 1; k < 5; ++k) {
					if (mayan[depth][k][i] == color)
						++count;
					else
						break;
				}
				if (count >= 3) {
					while (count-- > 0)
						mark[j++][i] = true;
					--j;
				}
			}
		}
	}
	//  纵向
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (mayan[depth][i][j]) {
				int color = mayan[depth][i][j];
				int count = 1;
				for (int k = j + 1; k < 7; ++k) {
					if (mayan[depth][i][k] == color)
						++count;
					else
						break;
				}
				if (count >= 3) {
					while (count-- > 0)
						mark[i][j++] = true;
					--j;
				}
			}
		}
	}
	// change
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 7; ++j) {
			if (mark[i][j]) {
				mayan[depth][i][j] = 0;
				changed = true;
			}
		}

	return changed;
}

bool dfs(int depth)
{
	if (depth > n) {
		for (int i = 0; i < 5; ++i)
			if (mayan[depth][i][0])
				return false;
		return true;
	}

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 7; ++j) {
			if (mayan[depth][i][j]) {
				x[depth] = i;
				y[depth] = j;
				// right
				if (i < 4) {
					g[depth] = 1;
					memcpy(mayan[depth + 1], mayan[depth], sizeof(mayan[depth]));
					swap(mayan[depth + 1][i][j], mayan[depth + 1][i + 1][j]);
					do {
						fall(depth + 1);
					} while (check(depth + 1));
					if (dfs(depth + 1))
						return true;
				}
				// left
				if (i > 0 && !mayan[depth][i - 1][j]) {
					memcpy(mayan[depth + 1], mayan[depth], sizeof(mayan[depth]));
					swap(mayan[depth + 1][i][j], mayan[depth + 1][i - 1][j]);
					g[depth] = -1;
					do
					{
						fall(depth + 1);
					} while (check(depth + 1));
					if (dfs(depth + 1))
						return true;
				}
			}
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < 5; ++i) {
		int k = 0;
		while (cin >> mayan[1][i][k] && mayan[1][i][k++]);
	}

	if (dfs(1)) {
		for (int i = 1; i <= n; ++i)
			cout << x[i] << ' ' << y[i] << ' ' << g[i] << endl;
	}
	else
		cout << -1 << endl;
	return 0;
}