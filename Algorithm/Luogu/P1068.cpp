/*
	Author: 刘臣轩
	Date: 2017.10.28
	Source: NOIP 2009 普及
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

pair<int, int> a[5010];
int main()
{
	ios::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int k, s;
		cin >> k >> s;
		a[i] = make_pair(k, s);
	}

	sort(a, a + n, [](const pair<int, int>&a, const pair<int, int>&b) { return (a.second != b.second) ? a.second > b.second : a.first < b.first; });

	int score = a[static_cast<int>((m * 1.5)-1)].second;
	int count = 0;
	while (a[count++].second >= score);
	
	count -= 1;
	cout << score << ' ' << count << endl;
	for (int i = 0; i < count; ++i)
		cout << a[i].first << ' ' << a[i].second << endl;

	return 0;
}