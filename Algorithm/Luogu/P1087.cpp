/*
	Author: 刘臣轩
	Date: 2017.11.8
	Source: NOIP 2004 普及 Task3
*/

#include <iostream>
#include <string>
using namespace std;

void solve(string a) {
	if (a.size() > 1) {
		solve(a.substr(0, a.size() / 2));
		solve(a.substr(a.size() / 2, a.size()/ 2));
	}
	bool i = a.find('1') != string::npos;
	bool b = a.find('0') != string::npos;
	cout << (i && b ? 'F' : i ? 'I' : 'B');
}

int main() {
	int n;
	string a;
	cin >> n >> a;
	solve(a);
}