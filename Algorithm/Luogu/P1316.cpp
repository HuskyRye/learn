/*
	Author: 刘臣轩
	Date: 2017.11.10
*/

#include <iostream>
#include <algorithm>
using namespace std;

int a[100005];
int A, B;
bool check(int mid) {
	int prev = 1;
	int count = 1;
	for (int i = 2; i <= A; ++i) {
		if (a[i]-a[prev] >= mid) {
			++count;
			if (count == B)
				break;
			prev = i;
		}
	}
	return count < B;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> A >> B;
	for (int i = 1; i <= A; ++i)
		cin >> a[i];
	sort(a+1, a+A+1);
	int l = 1, r = a[A] - a[1];
	while (l < r) {
		int mid = l+r+1>>1;
		if (check(mid))
			r = mid-1;
		else
			l = mid;
	}
	cout << l << endl;
	return 0;
}