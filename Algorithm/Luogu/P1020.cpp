/*
	Author: 刘臣轩
	Date: 2017.11.11
	Source: NOIP 1999 普及 
*/

#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;
int a[100005];
int b[100005];
int c[100005];
int main() {
	ios::sync_with_stdio(false);
	int top = 0;
	int sys = 0;
	int temp;
	while (cin >> temp) {
		a[++top] = temp;
		*lower_bound(b+1, b+top+1, temp, greater_equal<int>()) = temp;
		if (temp > c[sys])
			c[++sys] = temp;
		else
			*lower_bound(c+1, c+sys+1, temp) = temp;
	}
	cout << find(b+1, b+top+1, 0) - b - 1 << endl;
	cout << sys << endl;
	return 0;
}
