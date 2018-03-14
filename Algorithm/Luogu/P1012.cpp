/*
	Author: 刘臣轩
	Date: 2017.11.5
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string number[25];
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> number[i];
	sort(number, number + n, [](const string& a, const string& b) { return a + b > b + a; });
	for (int i = 0; i < n; ++i)
		cout << number[i];
	cout << endl;
	return 0;
}