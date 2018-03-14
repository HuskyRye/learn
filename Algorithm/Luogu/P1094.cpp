/*
	Author: 刘臣轩
	Date: 2017.11.5
*/

#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int price[30010];
int main() {
	ios::sync_with_stdio(false);
	int w, n;
	cin >> w >> n;
	for (int i = 1; i <= n; ++i)
		cin >> price[i];
	sort(price + 1, price + 1 + n, greater<int>());
	int begin = 1;
	int end = n;
	int ans = 0;
	while (begin <= end)
	{
		++ans;
		if (price[end] + price[begin] > w)
			++begin;
		else {
			++begin;
			--end;
		}
	}
	cout << ans << endl;
	return 0;
}