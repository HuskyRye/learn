/*
	Author: 刘臣轩
	Date: 2017.10.22
	Source: NOIP 2011
*/

#include <iostream>
using namespace std;

int hotel[50][200000];
int top[50];

int main()
{
	int n, k, p;
	cin >> n >> k >> p;
	int prev = false;
	int count = 0;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		if (y <= p || prev)
			++count;
		hotel[x][top[x]++] = count;
		prev = (y <= p);
	}

	int sum = 0;
	for (int i = 0; i < k; ++i) {
		prev = hotel[i][0];
		int temp = 0;
		for (int j = 0; j < top[i]; ++j) {
			if (hotel[i][j] > prev)
				temp = j;
			sum += temp;
			prev = hotel[i][j];
		}
	}
	cout << sum << '\n';
}
