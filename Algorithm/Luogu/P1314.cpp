/*
	Author: 刘臣轩
	Date: 2017.10.26
	Source: NOIP 2011 day2
*/

#include <iostream>
using namespace std;

#define N 200010
int n, m;
int w[N], v[N];
int L[N], R[N];

int sumN[N] = { 0 };
long long sumV[N] = { 0 };
long long int Y(int W)
{
	long long result = 0;

	for (int i = 1; i <= n; ++i) {
		if (w[i] >= W) {
			sumN[i] = sumN[i - 1] + 1;
			sumV[i] = sumV[i - 1] + v[i];
		}
		else {
			sumN[i] = sumN[i - 1];
			sumV[i] = sumV[i - 1];
		}
	}

	for (int i = 1; i <= m; ++i) {
		result += (sumN[R[i]] - sumN[L[i] - 1]) * (sumV[R[i]] - sumV[L[i] - 1]);
		if (result > 10000000000000LL)
			return 10000000000000LL;
	}
	return result;
}

int main()
{
	ios::sync_with_stdio(false);

	long long int S;
	cin >> n >> m >> S;
	for (int i = 1; i <= n; ++i)
		cin >> w[i] >> v[i];
	for (int i = 1; i <= m; ++i)
		cin >> L[i] >> R[i];

	int x = 0, y = 200000;
	while (x < y)
	{
		int mid = (x + y) / 2;
		if (Y(mid) >= S)
			x = mid + 1;
		else
			y = mid;
	}
	long long a = (S - Y(x) > 0  ? S - Y(x) : -(S - Y(x)));
	long long b = (S - Y(x - 1) > 0 ? S - Y(x - 1) : -(S - Y(x - 1)));
	cout << (a > b ? b : a) << endl;

	return 0;
}