/*
	Author: 刘臣轩
	Date: 2017.11.10
*/

#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int a[1000005];
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; j += i)
			++a[j];
	cout << accumulate(a+1, a+n+1, 0) << endl;
	return 0;
}