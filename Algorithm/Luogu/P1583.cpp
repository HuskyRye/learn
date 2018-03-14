/*
	Author: 刘臣轩
	Date: 2017.11.5
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct people
{
	int id;
	int weight;
}P[20010];

int E[11];
int main() {
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= 10; ++i)
		cin >> E[i];
	for (int i = 1; i <= n; ++i) {
		P[i].id = i;
		cin >> P[i].weight;
	}
	sort(P + 1, P + n + 1, [](people& a, people& b) {return a.weight != b.weight ? a.weight > b.weight : a.id < b.id; });
	for (int i = 1; i <= n; ++i)
		P[i].weight += E[(i - 1) % 10 + 1];
	sort(P + 1, P + n + 1, [](people& a, people& b) {return a.weight != b.weight ? a.weight > b.weight : a.id < b.id; });
	for (int i = 1; i <= k; ++i)
		cout << P[i].id << ' ';
	return 0;
}