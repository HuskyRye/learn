/*
	Author: 刘臣轩
	Date: 2017.11.8
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(')
			++ans;
		if (s[i] == ')') {
			if (ans > 0)
				--ans;
			else {
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << (ans == 0 ? "YES\n" : "NO\n");
	return 0;
}