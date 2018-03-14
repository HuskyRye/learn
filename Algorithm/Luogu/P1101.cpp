/*
	Author: 刘臣轩
	Date: 2017.11.6
*/

#include <iostream>
using namespace std;

int n;
char map[110][110];
bool temp[110][110];
char yizhong[] = "yizhong";

void up_left(int i, int j) {
	int x = i, y = j;
	bool flag = true;
	for (int k = 1; k <= 6; ++k)
		if (map[--x][--y] != yizhong[k]) {
			flag = false;
			break;
		}
	if (flag)
		for (int k = 0; k <= 6; ++k)
			temp[i--][j--] = true;
}
void up(int i, int j) {
	int x = i;
	bool flag = true;
	for (int k = 1; k <= 6; ++k)
		if (map[--x][j] != yizhong[k]) {
			flag = false;
			break;
		}
	if (flag)
		for (int k = 0; k <= 6; ++k)
			temp[i--][j] = true;
}
void up_right(int i, int j) {
	int x = i, y = j;
	bool flag = true;
	for (int k = 1; k <= 6; ++k)
		if (map[--x][++y] != yizhong[k]) {
			flag = false;
			break;
		}
	if (flag)
		for (int k = 0; k <= 6; ++k)
			temp[i--][j++] = true;
}
void left(int i, int j) {
	int y = j;
	bool flag = true;
	for (int k = 1; k <= 6; ++k)
		if (map[i][--y] != yizhong[k]) {
			flag = false;
			break;
		}
	if (flag)
		for (int k = 0; k <= 6; ++k)
			temp[i][j--] = true;
}
void right(int i, int j) {
	int y = j;
	bool flag = true;
	for (int k = 1; k <= 6; ++k)
		if (map[i][++y] != yizhong[k]) {
			flag = false;
			break;
		}
	if (flag)
		for (int k = 0; k <= 6; ++k)
			temp[i][j++] = true;
}
void down_left(int i, int j) {
	int x = i, y = j;
	bool flag = true;
	for (int k = 1; k <= 6; ++k)
		if (map[++x][--y] != yizhong[k]) {
			flag = false;
			break;
		}
	if (flag)
		for (int k = 0; k <= 6; ++k)
			temp[i++][j--] = true;
}
void down_right(int i, int j) {
	int x = i, y = j;
	bool flag = true;
	for (int k = 1; k <= 6; ++k)
		if (map[++x][++y] != yizhong[k]) {
			flag = false;
			break;
		}
	if (flag)
		for (int k = 0; k <= 6; ++k)
			temp[i++][j++] = true;
}
void down(int i, int j) {
	int x = i;
	bool flag = true;
	for (int k = 1; k <= 6; ++k)
		if (map[++x][j] != yizhong[k]) {
			flag = false;
			break;
		}
	if (flag)
		for (int k = 0; k <= 6; ++k)
			temp[i++][j] = true;
}
void search() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (map[i][j] != 'y')
				continue;
			if (i >= 6 && j >= 6)
				up_left(i, j);
			if (i >= 6)
				up(i, j);
			if (i >= 6 && j + 6 <= n)
				up_right(i, j);
			if (j >= 6)
				left(i, j);
			if (j + 6 <= n)
				right(i, j);
			if (i + 6 <= n && j >= 6)
				down_left(i, j);
			if (i + 6 <= n && j + 6 <= n)
				down_right(i, j);
			if (i + 6 <= n)
				down(i, j);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> map[i][j];
	search();
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j)
			cout << (temp[i][j] ? map[i][j] : '*');
		cout << endl;
	}
	return 0;
}