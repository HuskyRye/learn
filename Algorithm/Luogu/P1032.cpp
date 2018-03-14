/*
	Author: 刘臣轩
	Date: 2017.11.6
*/

#include <iostream>
#include <string>
#include <queue>
#include <map>;
using namespace std;

string a[6], b[6];
queue<pair<string, int>> q;
map<string, int> m;
int main() {
	ios::sync_with_stdio(false);
	string A, B;
	cin >> A >> B;
	int n = 0;
	while (cin >> a[n] >> b[n])
		++n;
	q.push(make_pair(A, 0));
	do {
		string str = q.front().first;
		int step = q.front().second;
		q.pop();
		if (m[str] == 1)
			continue;
		m[str] = 1;
		if (step > 10) {
			cout << "NO ANSWER!" << endl;
			return 0;
		}
		if (str == B) {
			cout << step << endl;
			return 0;
		}
		for (int i = 0; i < n; ++i) {
			int pos = 0;
			while (str.find(a[i], pos) != string::npos) {
				string temp = str;
				temp.replace(temp.find(a[i], pos), a[i].size(), b[i]);
				q.push(make_pair(temp, step + 1));
				++pos;
			}
		}
	} while (q.size() > 0);
	cout << "NO ANSWER!" << endl;
	return 0;
}
