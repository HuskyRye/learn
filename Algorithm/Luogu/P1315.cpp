/*
	Author: 刘臣轩
	Date: 2017.11.9
	Source: NOIP 1998 普及
*/

#include <iostream>
using namespace std;

void solve(int n) {
	bool prev = false;
	for (int i = 14; i >= 0; --i) {
		if (n & 1 << i) {
			if (prev)
				cout << '+';
			prev = true;
			if (i == 2)
				cout << "2(2)";
			else if (i == 1)
				cout << '2';
			else if (i == 0)
				cout << "2(0)";
			else {
				cout << "2(";
				solve(i);
				cout << ')';
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	solve(n);
	cout << endl;
	return 0;
}