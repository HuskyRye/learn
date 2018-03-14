/*
	Author: 刘臣轩
	Date: 2017.11.9
*/

#include <iostream>
#include <cstring>
using namespace std;

int a[40005];
int c[40005];
int solve(int left, int right) {
	int count = 0;
	if (left == right) {
		return 0;
	}
	int mid = (left + right) / 2;
	count += solve(left, mid) + solve(mid+1, right);
	int i = left, j = mid+1, index = left;
	while (i <= mid && j <= right) {
		if (a[i] > a[j]) {
			c[index++] = a[j++];
			count += mid+1-i;
		}
		else
			c[index++] = a[i++];
	}
	while (i <= mid)
		c[index++] = a[i++];
	while (j <= right)
		c[index++] = a[j++];
	memcpy(a+left, c+left, (index - left) * sizeof(int));
	return count;
}
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	cout << solve(1, n) << endl;
	return 0;
}