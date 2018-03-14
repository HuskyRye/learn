/*
	Author: 刘臣轩
	Date: 2017.11.5
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Water
{
	int id;
	double time;
}water[1010];

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	double temp;
	for (int i = 1; i <= n; ++i) {
		water[i].id = i;
		cin >> temp;
		water[i].time = temp;
	}
	sort(water + 1, water + 1 + n, [](const Water& a, const Water& b) { return a.time != b.time ? a.time < b.time : a.id < b.id; });
	double sum = 0;
	for (int i = 1; i <= n; ++i) {
		cout << water[i].id << ' ';
		sum += water[i].time * (n - i);
	}
	cout << endl << fixed << setprecision(2) << sum / n << endl;
	return 0;
}