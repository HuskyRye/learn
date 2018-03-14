/*
	Author: 刘臣轩
	Date: 2017.11.9
*/

#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>
using namespace std;
char map[1024][2048];

void draw(int n) {
	if (n == 1) {
		memcpy(map[1022], " /\\ ", 4);
		memcpy(map[1023], "/__\\", 4);
		return;
	}
	draw(n-1);
	int h = pow(2, n-1);
	for (int i = 1024-h; i < 1024; ++i)
		memcpy(map[i]+2*h, map[i], 2*h);
	for (int i = 1024-2*h; i < 1024-h; ++i)
		memcpy(map[i]+h, map[i+h], 2*h);
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	memset(map, ' ', sizeof(map));
	int h = pow(2, n);
	draw(n);
	for (int i = 1024-h; i < 1024; ++i) {
		for (int j = 0; j < 2*h; ++j)
			cout << map[i][j];
		cout << endl;
	}
	return 0;
}