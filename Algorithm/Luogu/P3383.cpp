/*
	Author: 刘臣轩
	Date: 2017.11.7
*/

#include <iostream>
using namespace std;

bool prime[10000005];
bool visit[10000005];
int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 2; i <= n; ++i) {
		if (!visit[i]) {
			prime[i] = true;
			for (int j = i + i; j <= n; j += i)
				visit[j] = true;
		}
	}
	for (int i = 0; i < m; ++i) {
		int question;
		cin >> question;
		cout << (prime[question] ? "Yes" : "No") << endl;
	}
	return 0;
}