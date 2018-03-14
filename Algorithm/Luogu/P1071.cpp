/*
	Author: 刘臣轩
	Date: 2017.11.5
	Source: NOIP 2009 提高
*/

#include <iostream>
#include <string>
using namespace std;

char dictionary[30];
int main() {
	ios::sync_with_stdio(false);
	string encrypted;
	string source;
	string require;
	cin >> encrypted >> source >> require;
	for (int i = 0; i < encrypted.size(); ++i) {
		if (!dictionary[encrypted[i] - 'A'])
			dictionary[encrypted[i] - 'A'] = source[i];
		else if (dictionary[encrypted[i] - 'A'] != source[i]){
			cout << "Failed\n";
			return 0;
		}
	}
	bool temp[30] = { false };
	for (int i = 0; i < 26; ++i) {
		if (!dictionary[i] || temp[dictionary[i] - 'A']) {
			cout << "Failed\n";
			return 0;
		}
		temp[dictionary[i] - 'A'] = true;
	}
	for (int i = 0; i < require.size(); ++i)
		cout << dictionary[require[i] - 'A'];
	cout << endl;
	return 0;
}