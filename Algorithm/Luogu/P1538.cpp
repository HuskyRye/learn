/*
	Author: 刘臣轩
	Date: 2017.11.5
*/

#include <iostream>
#include <string>
using namespace std;

bool up[10]			{ 1, 0, 1, 1, 0, 1, 1, 1, 1, 1 };
bool up_left[10]	{ 1, 0, 0, 0, 1, 1, 1, 0, 1, 1 };
bool up_right[10]	{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 };
bool middle[10]		{ 0, 0, 1, 1, 1, 1, 1, 0, 1, 1 };
bool down_left[10]	{ 1, 0, 1, 0, 0, 0, 1, 0, 1, 0 };
bool down_right[10]	{ 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 };
bool down[10]		{ 1, 0, 1, 1, 0, 1, 1, 0, 1, 1 };

int main() {
	ios::sync_with_stdio(false);
	int k;
	cin >> k;
	string s;
	cin >> s;
	int len = s.size();
	// up
	for (int i = 0; i < len; ++i) {
		cout << ' ';
		char temp = (up[s[i] - '0'] ? '-' : ' ');
		for (int j = 0; j < k; ++j)
			cout << temp;
		cout << "  ";
	}
	cout << endl;
	// middle-up
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < len; ++j) {
			cout << (up_left[s[j] - '0'] ? '|' : ' ');
			for (int g = 0; g < k; ++g)
				cout << ' ';
			cout << (up_right[s[j] - '0'] ? '|' : ' ') << ' ';
		}
		cout << endl;
	}
	// middle
	for (int i = 0; i < len; ++i) {
		cout << ' ';
		char temp = (middle[s[i] - '0'] ? '-' : ' ');
		for (int j = 0; j < k; ++j)
			cout << temp;
		cout << "  ";
	}
	cout << endl;
	// middle-down
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < len; ++j) {
			cout << (down_left[s[j] - '0'] ? '|' : ' ');
			for (int g = 0; g < k; ++g)
				cout << ' ';
			cout << (down_right[s[j] - '0'] ? '|' : ' ') << ' ';
		}
		cout << endl;
	}
	// down
	for (int i = 0; i < len; ++i) {
		cout << ' ';
		char temp = (down[s[i] - '0'] ? '-' : ' ');
		for (int j = 0; j < k; ++j)
			cout << temp;
		cout << "  ";
	}
	cout << endl;
	return 0;
}