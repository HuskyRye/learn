/*
	Author: 刘臣轩
	Date: 2017.11.5
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct Competition
{
	int start;
	int end;
}competition[1000010];

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> competition[i].start >> competition[i].end;
	sort(competition, competition + n, [](const Competition& a, const Competition& b) { return a.end < b.end; });
	int temp = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		if (competition[i].start >= temp) {
			++ans;
			temp = competition[i].end;
		}
	}
	cout << ans << endl;
	return 0;
}