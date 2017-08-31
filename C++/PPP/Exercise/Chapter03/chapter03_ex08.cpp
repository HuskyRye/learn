/*
8.编写一个程序，测试一个整数值是奇数还是偶数
例: 输入: 4
输出: The value 4 is an even number.
*/

#include "std_lib_facilities.h"

int main()
{
	cout << "Please enter an integer: ";
	int val;
	cin >> val;
	string res = "even";
	if (val%2) res = "odd";
	cout << "The value " << val << " is an " << res << " number\n";

	keep_window_open();
	return 0;
}