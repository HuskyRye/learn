/*
	Author: 刘臣轩
	Date: 2017.11.5
	Source: USACO Training Section 1.3
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct Milk {
	int price;
	int amount;
}milk[5010];

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
		cin >> milk[i].price >> milk[i].amount;
	sort(milk, milk + m, [](const Milk& a, const Milk& b) { return a.price < b.price; });
	int sum = 0;
	int i = 0;
	while (n > 0)
	{
		if (milk[i].amount >= n) {
			sum += n *= milk[i].price;
			break;
		}
		else {
			sum += milk[i].amount * milk[i].price;
			n -= milk[i].amount;
			++i;
		}
	}
	cout << sum << endl;
	return 0;
}