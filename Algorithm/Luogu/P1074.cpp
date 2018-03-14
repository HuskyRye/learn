/*
	Author: 刘臣轩
	Date: 2017.11.8
	Source: NOIP 2009 提高 Task4
*/

#include <iostream>
#include <algorithm>
using namespace std;

int ans = -1;
int map[10][10];
int score[10][10] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 6, 6, 6, 6, 6, 6, 6, 6, 6 },
	{ 0, 6, 7, 7, 7, 7, 7, 7, 7, 6 },
	{ 0, 6, 7, 8, 8, 8, 8, 8, 7, 6 },
	{ 0, 6, 7, 8, 9, 9, 9, 8, 7, 6 },
	{ 0, 6, 7, 8, 9, 10, 9, 8, 7, 6 },
	{ 0, 6, 7, 8, 9, 9, 9, 8, 7, 6 },
	{ 0, 6, 7, 8, 8, 8, 8, 8, 7, 6 },
	{ 0, 6, 7, 7, 7, 7, 7, 7, 7, 6 },
	{ 0, 6, 6, 6, 6, 6, 6, 6, 6, 6 },
};
int get_area[10][10] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 1, 1, 2, 2, 2, 3, 3, 3 },
	{ 0, 1, 1, 1, 2, 2, 2, 3, 3, 3 },
	{ 0, 1, 1, 1, 2, 2, 2, 3, 3, 3 },
	{ 0, 4, 4, 4, 5, 5, 5, 6, 6, 6 },
	{ 0, 4, 4, 4, 5, 5, 5, 6, 6, 6 },
	{ 0, 4, 4, 4, 5, 5, 5, 6, 6, 6 },
	{ 0, 7, 7, 7, 8, 8, 8, 9, 9, 9 },
	{ 0, 7, 7, 7, 8, 8, 8, 9, 9, 9 },
	{ 0, 7, 7, 7, 8, 8, 8, 9, 9, 9 },
};
bool row[10][10];
bool column[10][10];
bool area[10][10];
int row_count[10];
int column_count[10];
int next_x, next_y;
void find_next() {
	next_x = 0, next_y = 0;
	int r_max = -1, c_max = -1;
	for (int i = 1; i <= 9; ++i)
		if (row_count[i] > r_max && row_count[i] < 9)
			r_max = row_count[i], next_x = i;
	for (int i = 1; i <= 9; ++i)
		if (column_count[i] > c_max && !map[next_x][i])
			c_max = column_count[i], next_y = i;
}
void dfs(int x, int y, int count) {
	if (count == 81) {
		int sum = 0;
		for (int i = 1; i <= 9; ++i)
			for (int j = 1; j <= 9; ++j)
				sum += map[i][j]*score[i][j];
		ans = max(ans, sum);
		return;
	}
	for (int i = 1; i <= 9; ++i) {
		if (row[x][i] || column[y][i] || area[get_area[x][y]][i])
			continue;
		map[x][y] = i;
		row[x][i] = column[y][i] = area[get_area[x][y]][i] = true;
		++row_count[x], ++column_count[y];
		find_next();
		dfs(next_x, next_y, count + 1);
		map[x][y] = 0;
		row[x][i] = column[y][i] = area[get_area[x][y]][i] = false;
		--row_count[x], --column_count[y];
	}
}
int main() {
	ios::sync_with_stdio(false);
	int count = 0;
	for (int i = 1; i <= 9; ++i)
		for (int j = 1; j <= 9; ++j) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				row[i][map[i][j]] = column[j][map[i][j]] = area[get_area[i][j]][map[i][j]] = true;
				++row_count[i];
				++column_count[j];
				++count;
			}
		}
	find_next();
	dfs(next_x, next_y, count);
	cout << ans << endl;
	return 0;
}