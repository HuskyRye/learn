/*
	Author: 刘臣轩
	Date: 2017.10.24
*/

#include <iostream>
#include <cmath>
using namespace std;

int peanutes[21][21];

int main()
{
	ios::sync_with_stdio(false);

	int m, n, k;
	cin >> m >> n >> k;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> peanutes[i][j];
	
	int x = 0, y = 0;
	int sum = 0;

	while (true)
	{
		// find the max element
		int max_x = 1, max_y = 1;
		int max = peanutes[1][1];
		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j)
				if (peanutes[i][j] > max) {
					max = peanutes[i][j];
					max_x = i;
					max_y = j;
				}

		int time;
		if (x == 0)
			time = max_x;
		else
			time = abs(x - max_x) + abs(y - max_y);

		if (k - time - max_x > 0) {
			k -= time;
			sum += peanutes[max_x][max_y];
			--k;
			peanutes[max_x][max_y] = 0;
			x = max_x;
			y = max_y;
		}
		else {
			cout << sum << endl;
			return 0;
		}
	} 
}