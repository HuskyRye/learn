/*
	Author: 刘臣轩
	Date: 2017.11.5
*/

#include <iostream>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

map<string, int> number;
void init() {
	number["one"] = number["a"] = number["another"] = number["first"] = 1;
	number["two"] = number["both"] = number["second"] = 2;
	number["three"] = number["third"] = 3;
	number["four"] = 4;
	number["five"] = 5;
	number["six"] = 6;
	number["seven"] = 7;
	number["eight"] = 8;
	number["nine"] = 9;
	number["ten"] = 10;
	number["eleven"] = 11;
	number["twelve"] = 12;
	number["thirteen"] = 13;
	number["fourteen"] = 14;
	number["fifteen"] = 15;
	number["sixteen"] = 16;
	number["seventeen"] = 17;
	number["eighteen"] = 18;
	number["nineteen"] = 19;
	number["twenty"] = 20;
}
int a[10];
int main() {
	ios::sync_with_stdio(false);
	init();
	for (int i = 0; i < 6; ++i) {
		string temp;
		cin >> temp;
		a[i] = pow(number[temp], 2);
	}
	sort(a, a + 6);
	bool first = true;
	for (int i = 0; i < 6; ++i) {
		if (a[i] == 0)
			continue;
		if (first) {
			cout << a[i];
			first = false;
		}
		else
			cout << setw(2) << setfill('0') << a[i];
	}
	if (first)
		cout << 0;
	cout << endl;
	return 0;
}