/*
	Author: 刘臣轩
	Date: 2017.10.28
	Source: NOIP 2006 普及
*/

#include <iostream>
#include <algorithm>
using namespace std;

int a[1010];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	int m = unique(a, a + n) - a;	// unique 指向处理后第一个重复元素的地址
	cout << m << endl;
	for (int i = 0; i < m; ++i)
		cout << a[i] << ' ';
	return 0;
}