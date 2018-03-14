/*
	Author: 刘臣轩
	Date: 2017.11.5
	Source: NOIP 2004
*/

#include <iostream>
#include <queue>
#include <functional>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		pq.push(temp);
	}

	int sum = 0;
	while (pq.size() > 1)
	{
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		pq.push(a + b);
		sum += a + b;
	}
	cout << sum << endl;
	return 0;
}