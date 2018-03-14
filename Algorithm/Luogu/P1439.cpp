/*
	Author: 刘臣轩
	Date: 2017.10.28
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int a[100010];
int b[100010];
int c[100010];

int main()
{
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	
	for (int i = 1; i <= n; ++i) {
		int temp;
		cin >> temp;
		a[temp] = i;
	}
	
	memset(c, 0x3f, sizeof(c));
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		*lower_bound(c, c + n, a[b[i]]) = a[b[i]];
	}
	cout << lower_bound(c, c + n, 0x3f3f3f3f) - c;	

	/*
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	memset(c, 0x3f, sizeof(c));
	for (int i = 1; i <= n; ++i)
		*lower_bound(c, c + n, a[i]) = a[i];
	cout << lower_bound(c, c + n, 0x3f3f3f3f) - c;
	*/

	return 0;
}