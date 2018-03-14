/*
	Author: 刘臣轩
	Date: 2017.11.8
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<int> s;
int main() {
	ios::sync_with_stdio(false);
	string exp;
	cin >> exp;
	for (int i = 0; i < exp.size()-1; ++i) {
		if (isdigit(exp[i])) {
			auto p = exp.find('.', i);
			s.push(atoi(exp.substr(i, p-i).c_str()));
			i = p;
		}
		else {
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();
			int c;
			switch (exp[i]) {
			case '+':
				c = b + a;
				break;
			case '-':
				c = b - a;
				break;
			case '*':
				c = b * a;
				break;
			case '/':
				c = b / a;
				break;
			}
			s.push(c);
		}
	}
	cout << s.top() << endl;
	return 0;
}